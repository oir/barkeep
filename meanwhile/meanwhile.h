// Author: Ozan Irsoy

#ifndef MEANWHILE_H
#define MEANWHILE_H

#include <cassert>
#include <chrono>
#include <condition_variable>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <type_traits>
#include <vector>

namespace mew {

using Strings = std::vector<std::string>;
using StringsList = std::vector<Strings>;

// double precision seconds
using Duration = std::chrono::duration<double, std::ratio<1>>;

// Enum: AnimationStyle
// Kind of animation being displayed for <Animation>
enum AnimationStyle : unsigned short {
  Ellipsis,
  Clock,
  Moon,
  Earth,
  Bar,
  Square,
};

// Var: animation_stills_
// Definitions of various stills for <Animation>. <AnimationStyle> indexes into
// this.
const static StringsList animation_stills_{
    {".  ", ".. ", "..."},
    {"🕐", "🕜", "🕑", "🕝", "🕒", "🕞", "🕓", "🕟", "🕔", "🕠", "🕕", "🕡",
     "🕖", "🕢", "🕗", "🕣", "🕘", "🕤", "🕙", "🕥", "🕚", "🕦", "🕛", "🕧"},
    {"🌕", "🌖", "🌗", "🌘", "🌑", "🌒", "🌓", "🌔"},
    {"🌎", "🌍", "🌏"},
    {"-", "/", "|", "\\"},
    {"▖", "▘", "▝", "▗"},
};

// Enum: ProgressBarStyle
// Kind of bar being displayed for <ProgressBar>
enum ProgressBarStyle : unsigned short { Bars, Blocks, Arrow };

// Var: progress_partials_
// Definitions of various partial bars for <ProgressBar>.
// <ProgressBarStyle> indexes into this.
const static StringsList progress_partials_{
    {"|"},
    {"▏", "▎", "▍", "▌", "▋", "▊", "▉", "█"},
    {">", "="},
};

// Enum: Speed
// How to display speed. None displays no speed. Last computes speed in the last
// interval. Overall computes from the beginning. Both displays both kinds.
enum class Speed : unsigned short { None, Last, Overall, Both };

// Class: AsyncDisplay
// Base class to handle asynchronous displays.
class AsyncDisplay {
 private:
  Duration interval_{0.0};
  std::unique_ptr<std::thread> displayer_;
  std::condition_variable completion_;
  std::mutex completion_m_;
  bool complete_ = false;

  std::string message_;
  std::ostream& out_;

  size_t max_rendered_len_ = 0;

 protected:
  // Method: render_
  // Render a display: animation, progress bar, etc.
  virtual size_t render_(std::ostream& out) = 0;

  virtual Duration default_interval_() const = 0;

  // Method: display_
  // Display everything (message, maybe with animation, progress bar, etc)
  void display_() {
    if (no_tty_) {
      render_(out_);
      out_ << std::endl;
    } else {
      out_ << "\r";
      size_t len = render_(out_);
      if (len < max_rendered_len_) { // hide previous render if smaller
        out_ << std::string(max_rendered_len_ - len, ' ');
      } else {
        max_rendered_len_ = len;
      }
      out_ << std::flush;
    }
  }

 protected:
  bool no_tty_ = false;

  // Method: render_message_
  // Display the message to output stream
  size_t render_message_(std::ostream& out) const {
    if (not message_.empty()) {
      out << message_ << " ";
      return message_.size() + 1;
    }
    return 0;
  }

 public:
  AsyncDisplay(std::ostream& out = std::cout) : out_(out) {}

  AsyncDisplay(const AsyncDisplay& other)
      : interval_(other.interval_),
        complete_(other.complete_),
        message_(other.message_),
        out_(other.out_),
        no_tty_(other.no_tty_) {
    if (other.displayer_) {
      throw std::runtime_error("A running display cannot be copied");
    }
  }

  AsyncDisplay(AsyncDisplay&& other)
      : interval_(other.interval_),
        complete_(other.complete_),
        out_(other.out_),
        no_tty_(other.no_tty_) {
    if (other.displayer_) {
      throw std::runtime_error("A running display cannot be moved");
    }
    message_ = std::move(other.message_);
  }

  virtual ~AsyncDisplay() { done(); }

  // Method: start
  // Start the display. This starts writing the display in the output stream,
  // and computing speed if applicable.
  virtual void start() {
    if (displayer_) {
      throw std::runtime_error("Display was already started!");
    }
    displayer_ = std::make_unique<std::thread>([this]() {
      display_();
      while (true) {
        std::unique_lock<std::mutex> lock(completion_m_);
        auto interval =
            interval_ != Duration{0.} ? interval_ : default_interval_();
        completion_.wait_for(lock, interval);
        display_();
        if (complete_) { break; }
      }
    });
  }

  // Method: done
  // End the display. This adds a newline to the output stream and stops
  // writing.
  virtual void done() {
    if (not displayer_) { return; } // noop if already done() before
    {
      std::lock_guard<std::mutex> lock(completion_m_);
      complete_ = true;
    }
    completion_.notify_all();
    displayer_->join();
    displayer_.reset();
    out_ << std::endl;
  }

  /* Methods: Setters

     message          - Set message
     interval(Duration) - Set the interval in which the display is refreshed.
     This is also the interval in which speed is measured if applicable.
     interval(double)
     - Set the interval by seconds as a double argument
  */

 protected:
  void message(const std::string& msg) { message_ = msg; }
  void interval(Duration pd) { interval_ = pd; }
  void interval(double pd) { interval_ = Duration(pd); }
  void no_tty() { no_tty_ = true; }

  friend class Composite;
};

// Class: Animation
// Displays a simple animation with a message.
class Animation : public AsyncDisplay {
 private:
  unsigned short frame_ = 0;
  Strings stills_;

 protected:
  size_t render_(std::ostream& out) override {
    size_t len = render_message_(out);
    out << stills_[frame_] << " ";
    len += (stills_[frame_].size() + 1);
    frame_ = (frame_ + 1) % stills_.size();
    return len;
  }

  Duration default_interval_() const override {
    if (no_tty_) { return Duration{60.}; }
    return Duration{1.};
  }

 public:
  using Style = AnimationStyle;

  /* Constructor: Animation

     Parameters:

       out  - Output stream to print
  */
  Animation(std::ostream& out = std::cout)
      : AsyncDisplay(out),
        stills_(animation_stills_[static_cast<unsigned short>(Ellipsis)]) {}

  Animation(const Animation& other) = default;
  Animation(Animation&&) = default;
  ~Animation() { done(); }

  // Methods: Setters
  //
  // style - Set animation style using one of <AnimationStyle>.
  auto& style(Style sty) {
    stills_ = animation_stills_[static_cast<unsigned short>(sty)];
    return *this;
  }

  /* Methods: Setters

     message          - Set message
     interval(Duration) - Set the interval in which the display is refreshed.
     This is also the interval in which speed is measured if applicable.
     interval(double)
     - Set the interval by seconds as a double argument
  */
  auto& message(const std::string& msg) {
    AsyncDisplay::message(msg);
    return *this;
  }

  auto& interval(Duration pd) {
    AsyncDisplay::interval(pd);
    return *this;
  }

  auto& interval(double pd) {
    AsyncDisplay::interval(pd);
    return *this;
  }

  auto& no_tty() {
    AsyncDisplay::no_tty();
    return *this;
  }
};

// Class: Composite
// Creates a composite display out of two display that shows them side by side.
// For instance, you can combine two <Counter>s to monitor two variables.
class Composite : public AsyncDisplay {
 protected:
  std::unique_ptr<AsyncDisplay> left_, right_;

  size_t render_(std::ostream& out) override {
    size_t len = left_->render_(out);
    out << " ";
    len += right_->render_(out);
    return len + 1;
  }

  Duration default_interval_() const override {
    return left_->default_interval_();
  }

 public:
  Composite(std::unique_ptr<AsyncDisplay> left,
            std::unique_ptr<AsyncDisplay> right)
      : AsyncDisplay(left->out_),
        left_(std::move(left)),
        right_(std::move(right)) {
    if (left_->displayer_ or right_->displayer_) {
      throw std::runtime_error("Running displays cannot be composed!");
    }
    AsyncDisplay::interval(min(left_->interval_, right_->interval_));
    if (left_->no_tty_ or right_->no_tty_) { AsyncDisplay::no_tty(); }
  }
  ~Composite() { done(); }

  auto& no_tty() {
    AsyncDisplay::no_tty();
    left_->no_tty();
    right_->no_tty();
    return *this;
  }
};

// Function: operator|
// Pipe operator can be used to combine two displays into a <Composite>.
template <typename LeftDisplay, typename RightDisplay>
auto operator|(LeftDisplay left, RightDisplay right) {
  return Composite(std::make_unique<LeftDisplay>(left),
                   std::make_unique<RightDisplay>(right));
}

// Trait class to extract underlying value type from numerics and
// std::atomics of numerics.
template <typename T>
struct AtomicTraits {
  using value_type = T;
};

template <typename T>
struct AtomicTraits<std::atomic<T>> {
  using value_type = T;
};

template <typename T>
using value_t = typename AtomicTraits<T>::value_type;

template <typename T>
using signed_t = typename std::conditional_t<std::is_integral_v<T>,
                                             std::make_signed<T>,
                                             std::common_type<T>>::type;

// Class: Speedometer
// Helper class to measure and display speed of progress.
template <typename Progress>
class Speedometer {
 private:
  Progress& progress_;        // Current amount of work done
  Speed speed_ = Speed::None; // Time interval to compute speed over
  std::string unit_of_speed_; // unit (message) to display alongside speed

  using Clock = std::chrono::system_clock;
  using Time = std::chrono::time_point<Clock>;

  Time start_time_, last_start_time_;

  value_t<Progress> first_progress_{}, last_progress_{};

 public:
  // Method: render_speed
  // Write speed to given output stream. Speed is a double (written with
  // precision 2), possibly followed by a unit of speed.
  size_t render_speed(std::ostream& out) {
    if (speed_ != Speed::None) {
      std::stringstream ss; // use local stream to avoid disturbing `out` with
                            // std::fixed and std::setprecision
      Duration dur = (Clock::now() - start_time_);
      Duration dur2 = (Clock::now() - last_start_time_);

      using ValueType = value_t<Progress>;
      using SignedType = signed_t<ValueType>;

      auto speed = double(SignedType(progress_) - SignedType(first_progress_)) /
                   dur.count();
      auto speed2 = double(SignedType(progress_) - SignedType(last_progress_)) /
                    dur2.count();

      ss << std::fixed << std::setprecision(2) << "(";
      if (speed_ == Speed::Overall or speed_ == Speed::Both) { ss << speed; }
      if (speed_ == Speed::Both) { ss << " | "; }
      if (speed_ == Speed::Last or speed_ == Speed::Both) { ss << speed2; }
      if (unit_of_speed_.empty()) {
        ss << ") ";
      } else {
        ss << " " << unit_of_speed_ << ") ";
      }

      auto s = ss.str();
      out << s;

      last_progress_ = progress_;
      last_start_time_ = Clock::now();
      return s.size();
    }
    return 0;
  }

  // Method: start
  // Start computing the speed based on the amount of change in progress
  void start() {
    first_progress_ = progress_;
    start_time_ = Clock::now();
  }

  /* Methods: Setters
   *
   * speed(Speed)                      - Set how to compute speed among <Speed>
   *                                     options.
   * unit_of_speed(const std::string&) - Set text for unit of speed.
   */

  void speed(Speed sp) { speed_ = sp; }

  void unit_of_speed(const std::string& msg) { unit_of_speed_ = msg; }

  // Constructor: Speedometer
  //
  // Parameters:
  //   progress  - Reference to numeric to measure the change of.
  Speedometer(Progress& progress) : progress_(progress) {}
};

// Class: Counter
// Monitors and displays a single numeric variable
template <typename Progress = size_t>
class Counter : public AsyncDisplay {
 private:
  Progress& progress_; // current amount of work done
  Speedometer<Progress> speedom_;

  // Method: render_counts_
  // Write the value of progress to the output stream
  size_t render_counts_(std::ostream& out) {
    std::stringstream ss;
    if (std::is_floating_point<Progress>::value) {
      ss << std::fixed << std::setprecision(2);
    }
    ss << progress_ << " ";
    auto s = ss.str();
    out << s;
    return s.size();
  }

 private:
  // Method: render_
  // Write the value of progress with the message to the output stream
  size_t render_(std::ostream& out) override {
    size_t len = render_message_(out);
    len += render_counts_(out);
    len += speedom_.render_speed(out);
    return len;
  }

  Duration default_interval_() const override {
    if (no_tty_) { return Duration{60.}; }
    return Duration{.1};
  }

 public:
  // Constructor: Counter
  //
  // Parameters:
  //   progress - Variable to be monitored and displayed
  //   out      - Output stream to write to
  Counter(Progress& progress, std::ostream& out = std::cout)
      : AsyncDisplay(out), progress_(progress), speedom_(progress) {}

  Counter(const Counter<Progress>& other)
      : AsyncDisplay(other),
        speedom_(other.speedom_),
        progress_(other.progress_) {}

  Counter(Counter<Progress>&& other)
      : AsyncDisplay(std::move(other)),
        speedom_(std::move(other.speedom_)),
        progress_(other.progress_) {}

  ~Counter() { done(); }

  // Method: start
  // Start displaying the counter
  void start() override {
    AsyncDisplay::start();
    speedom_.start();
  }

  // Methods: Setters
  //
  // speed(Speed)                       - Set how to compute speed, among
  //                                      <Speed> options
  // unit_of_speed(const std::string&)  - Set unit of speed text next to speed
  auto& speed(Speed sp) {
    speedom_.speed(sp);
    return *this;
  }
  auto& unit_of_speed(const std::string& msg) {
    speedom_.unit_of_speed(msg);
    return *this;
  }
  auto& message(const std::string& msg) {
    AsyncDisplay::message(msg);
    return *this;
  }
  auto& interval(Duration pd) {
    AsyncDisplay::interval(pd);
    return *this;
  }
  auto& interval(double pd) {
    AsyncDisplay::interval(pd);
    return *this;
  }
  auto& no_tty() {
    AsyncDisplay::no_tty();
    return *this;
  }
};

// Class: ProgressBar
// Displays a progress bar, by comparing the progress value being monitored to a
// given total value. Optionally reports speed.
template <typename Progress>
class ProgressBar : public AsyncDisplay {
 private:
  using ValueType = value_t<Progress>;

  Speedometer<Progress> speedom_;
  Progress& progress_; // work done so far
  static constexpr ValueType width_ =
      30;                // width of progress bar (TODO: make customizable?)
  ValueType total_{100}; // total work
  bool counts_ = true;   // whether to display counts

  Strings partials_; // progress bar display strings

  // Method: render_progress_bar_
  // Compute the shape of the progress bar based on progress and write to output
  // stream.
  size_t render_progress_bar_(std::ostream& out) {
    ValueType progress_copy =
        progress_; // to avoid progress_ changing during computations below
    ValueType on = width_ * progress_copy / total_;
    ValueType partial = partials_.size() * width_ * progress_copy / total_ -
                        partials_.size() * on;
    if (on >= width_) {
      on = width_;
      partial = 0;
    } else if (on < 0) {
      on = 0;
      partial = 0;
    }
    assert(partial != partials_.size());
    auto off = width_ - on - ValueType(partial > 0);

    // draw progress bar
    out << "|";
    for (size_t i = 0; i < on; i++) { out << partials_.back(); }
    if (partial > 0) { out << partials_.at(partial - 1); }
    out << std::string(off, ' ') << "| ";
    return width_ + 3;
  }

  // Method: render_counts_
  // Write progress value with the total, e.g. 50/100, to output stream.
  // Progress width is expanded (and right justified) to match width of total.
  size_t render_counts_(std::ostream& out) {
    if (counts_) {
      std::stringstream ss, totals;
      if (std::is_floating_point<Progress>::value) {
        ss << std::fixed << std::setprecision(2);
        totals << std::fixed << std::setprecision(2);
      }
      totals << total_;
      auto width = totals.str().size();
      ss.width(width);
      ss << std::right << progress_ << "/" << total_ << " ";
      auto s = ss.str();
      out << s;
      return s.size();
    }
    return 0;
  }

  // Method: render_percentage_
  // Write the percent completed to output stream
  size_t render_percentage_(std::ostream& out) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2);
    ss.width(6);
    ss << std::right << progress_ * 100. / total_ << "% ";
    auto s = ss.str();
    out << s;
    return s.size();
  }

  // Method: render_
  // Run all of the individual render methods to write everything to stream
  size_t render_(std::ostream& out) override {
    size_t len = render_message_(out);
    len += render_percentage_(out);
    len += render_progress_bar_(out);
    len += render_counts_(out);
    len += speedom_.render_speed(out);
    return len;
  }

  Duration default_interval_() const override {
    if (no_tty_) { return Duration{60.}; }
    return Duration{.1};
  }

 public:
  using Style = ProgressBarStyle;

  // Constructor: ProgressBar
  //
  // Parameters:
  //   progress - Variable to be monitored to measure completion
  //   out      - Output stream to write to
  ProgressBar(Progress& progress, std::ostream& out = std::cout)
      : AsyncDisplay(out),
        speedom_(progress),
        progress_(progress),
        partials_(progress_partials_[static_cast<unsigned short>(Blocks)]) {}

  ~ProgressBar() { done(); }

  // Method: start
  // Start displaying the bar
  void start() override {
    AsyncDisplay::start();
    speedom_.start();
  }

  // Methods: Setters
  //
  // speed(Speed)                       - Set how to compute speed, among
  //                                      <Speed> options
  // unit_of_speed(const std::string&)  - Set unit of speed text next to speed
  // total(ValueType)                   - Set total amount, cannot be 0
  // style(Style)                       - Set style from <ProgressBarStyle>
  //                                      options
  auto& speed(Speed sp) {
    speedom_.speed(sp);
    return *this;
  }

  auto& unit_of_speed(const std::string& msg) {
    speedom_.unit_of_speed(msg);
    return *this;
  }

  auto& total(ValueType tot) {
    if (tot == 0) {
      throw std::runtime_error("Progress total cannot be zero!");
    }
    total_ = tot;
    return *this;
  }

  auto& style(Style sty) {
    partials_ = progress_partials_[static_cast<unsigned short>(sty)];
    return *this;
  }

  auto& message(const std::string& msg) {
    AsyncDisplay::message(msg);
    return *this;
  }

  auto& interval(Duration pd) {
    AsyncDisplay::interval(pd);
    return *this;
  }

  auto& interval(double pd) {
    AsyncDisplay::interval(pd);
    return *this;
  }

  auto& no_tty() {
    AsyncDisplay::no_tty();
    return *this;
  }
};

} // namespace mew

#endif
