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
  virtual void show() {
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

  virtual std::unique_ptr<AsyncDisplay> clone() const = 0;

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

  std::unique_ptr<AsyncDisplay> clone() const override {
    return std::make_unique<Animation>(*this);
  }

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
    AsyncDisplay::interval(min(left_->interval_, right_->interval_));
    if (left_->no_tty_ or right_->no_tty_) { AsyncDisplay::no_tty(); }
  }
  // Copy constructor
  Composite(const Composite& other)
      : AsyncDisplay(other),
        left_(other.left_->clone()),
        right_(other.right_->clone()) {}
  Composite(Composite&& other) = default;
  ~Composite() { done(); }

  std::unique_ptr<AsyncDisplay> clone() const override {
    return std::make_unique<Composite>(*this);
  }

  auto& no_tty() {
    AsyncDisplay::no_tty();
    left_->no_tty();
    right_->no_tty();
    return *this;
  }
};

// Function: operator|
// Pipe operator can be used to combine two displays into a <Composite>.
auto operator|(const AsyncDisplay& left, const AsyncDisplay& right) {
  return Composite(left.clone(), right.clone());
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
  Progress& progress_; // Current amount of work done
  double alpha_;

  using ValueType = value_t<Progress>;
  using SignedType = signed_t<ValueType>;
  using Clock = std::chrono::system_clock;
  using Time = std::chrono::time_point<Clock>;

  double progress_increment_sum_ = 0; // (weighted) sum of progress increments
  Duration duration_increment_sum_{}; // (weighted) sum of duration increments

  Time last_start_time_;
  ValueType last_progress_;

 public:
  // Method: render_speed
  // Write speed to given output stream. Speed is a double (written with
  // precision 2), possibly followed by a unit of speed.
  size_t render_speed(std::ostream& out, const std::string& speed_unit) {
    std::stringstream ss; // use local stream to avoid disturbing `out` with
                          // std::fixed and std::setprecision
    Time now = Clock::now();
    Duration dur = now - last_start_time_;
    last_start_time_ = now;

    ValueType progress_copy = progress_; // to avoid progress_ changing below
    SignedType progress_increment =
        SignedType(progress_copy) - SignedType(last_progress_);
    last_progress_ = progress_copy;

    progress_increment_sum_ =
        (1 - alpha_) * progress_increment_sum_ + progress_increment;
    duration_increment_sum_ = (1 - alpha_) * duration_increment_sum_ + dur;
    double speed = progress_increment_sum_ / duration_increment_sum_.count();

    ss << std::fixed << std::setprecision(2) << "(" << speed;
    if (speed_unit.empty()) {
      ss << ") ";
    } else {
      ss << " " << speed_unit << ") ";
    }

    auto s = ss.str();
    out << s;

    return s.size();
  }

  // Method: start
  // Start computing the speed based on the amount of change in progress
  void start() {
    last_progress_ = progress_;
    last_start_time_ = Clock::now();
  }

  // Constructor: Speedometer
  //
  // Parameters:
  //   progress  - Reference to numeric to measure the change of.
  Speedometer(Progress& progress, double alpha)
      : progress_(progress), alpha_(alpha) {}
};

// Class: Counter
// Monitors and displays a single numeric variable
template <typename Progress = size_t>
class Counter : public AsyncDisplay {
 private:
  Progress* progress_ = nullptr; // current amount of work done
  std::unique_ptr<Speedometer<Progress>> speedom_;
  std::string speed_unit_ = "it/s"; // unit of speed text next to speed

  std::ostringstream ss_;

 protected:
  // Method: render_counts_
  // Write the value of progress to the output stream
  size_t render_counts_(std::ostream& out) {
    ss_ << *progress_ << " ";
    auto s = ss_.str();
    out << s;
    ss_.str("");
    ss_.clear();
    return s.size();
  }

  // Method: render_
  // Write the value of progress with the message to the output stream
  size_t render_(std::ostream& out) override {
    size_t len = render_message_(out);
    len += render_counts_(out);
    if (speedom_) { len += speedom_->render_speed(out, speed_unit_); }
    return len;
  }

  Duration default_interval_() const override {
    return no_tty_ ? Duration{60.} : Duration{.1};
  }

  void init(Progress* progress) { progress_ = progress; }

  Counter(std::ostream& out = std::cout) : AsyncDisplay(out) {}

 public:
  // Constructor: Counter
  //
  // Parameters:
  //   progress - Variable to be monitored and displayed
  //   out      - Output stream to write to
  Counter(Progress* progress, std::ostream& out = std::cout)
      : AsyncDisplay(out) {
    init(progress);
  }

  Counter(const Counter<Progress>& other)
      : AsyncDisplay(other),
        progress_(other.progress_),
        speed_unit_(other.speed_unit_) {
    if (other.speedom_) {
      speedom_ = std::make_unique<Speedometer<Progress>>(*other.speedom_);
    } else {
      speedom_.reset();
    }
  }

  Counter(Counter<Progress>&& other)
      : AsyncDisplay(std::move(other)),
        progress_(other.progress_),
        speedom_(std::move(other.speedom_)),
        speed_unit_(other.speed_unit_) {}

  ~Counter() { done(); }

  std::unique_ptr<AsyncDisplay> clone() const override {
    return std::make_unique<Counter>(*this);
  }

  // Method: start
  // Start displaying the counter
  void show() override {
    if constexpr (std::is_floating_point_v<Progress>) {
      ss_ << std::fixed << std::setprecision(2);
    }
    AsyncDisplay::show();
    if (speedom_) { speedom_->start(); }
  }

  // Methods: Setters
  //
  // speed(Speed)                       - Set how to compute speed, among
  //                                      <Speed> options
  // speed_unit(const std::string&)  - Set unit of speed text next to speed
  auto& speed(std::optional<double> alpha) {
    if (alpha) {
      speedom_ = std::make_unique<Speedometer<Progress>>(*progress_, *alpha);
    } else {
      speedom_.reset();
    }
    return *this;
  }
  auto& speed_unit(const std::string& msg) {
    speed_unit_ = msg;
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

  Progress* progress_; // work done so far
  std::unique_ptr<Speedometer<Progress>> speedom_;
  std::string speed_unit_ = "it/s"; // unit of speed text next to speed
  static constexpr size_t width_ = 30; // width of progress bar
                                       // (TODO: make customizable?)
  ValueType total_{100};               // total work

  Strings partials_; // progress bar display strings

 protected:
  // Method: render_progress_bar_
  // Compute the shape of the progress bar based on progress and write to output
  // stream.
  size_t render_progress_bar_(std::ostream& out) {
    ValueType progress_copy = *progress_; // to avoid progress_ changing
                                          // during computations below
    int on = int(ValueType(width_) * progress_copy / total_);
    size_t partial = size_t(ValueType(partials_.size()) * ValueType(width_) *
                                progress_copy / total_ -
                            ValueType(partials_.size()) * ValueType(on));
    if (on >= int(width_)) {
      on = width_;
      partial = 0;
    } else if (on < 0) {
      on = 0;
      partial = 0;
    }
    assert(partial < partials_.size());
    auto off = width_ - size_t(on) - size_t(partial > 0);

    // draw progress bar
    out << "|";
    for (int i = 0; i < on; i++) { out << partials_.back(); }
    if (partial > 0) { out << partials_.at(partial - 1); }
    out << std::string(off, ' ') << "| ";
    return width_ + 3;
  }

  // Method: render_counts_
  // Write progress value with the total, e.g. 50/100, to output stream.
  // Progress width is expanded (and right justified) to match width of total.
  size_t render_counts_(std::ostream& out) {
    std::stringstream ss, totals;
    if (std::is_floating_point_v<Progress>) {
      ss << std::fixed << std::setprecision(2);
      totals << std::fixed << std::setprecision(2);
    }
    totals << total_;
    auto width = static_cast<std::streamsize>(totals.str().size());
    ss.width(width);
    ss << std::right << *progress_ << "/" << total_ << " ";
    auto s = ss.str();
    out << s;
    return s.size();
  }

  // Method: render_percentage_
  // Write the percent completed to output stream
  size_t render_percentage_(std::ostream& out) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2);
    ss.width(6);
    ss << std::right << *progress_ * 100. / total_ << "% ";
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
    if (speedom_) { len += speedom_->render_speed(out, speed_unit_); }
    return len;
  }

  Duration default_interval_() const override {
    return no_tty_ ? Duration{60.} : Duration{.1};
  }

 protected:
  void init(Progress* progress) {
    progress_ = progress;
  }

  ProgressBar(std::ostream& out = std::cout) : AsyncDisplay(out) {}

 public:
  using Style = ProgressBarStyle;

  // Constructor: ProgressBar
  //
  // Parameters:
  //   progress - Variable to be monitored to measure completion
  //   out      - Output stream to write to
  ProgressBar(Progress* progress, std::ostream& out = std::cout)
      : AsyncDisplay(out),
        partials_(progress_partials_[static_cast<unsigned short>(Blocks)]) {
    init(progress);
  }

  // move constructor
  ProgressBar(ProgressBar<Progress>&& other)
      : AsyncDisplay(std::move(other)),
        progress_(other.progress_),
        speedom_(std::move(other.speedom_)),
        total_(other.total_),
        partials_(std::move(other.partials_)) {}

  // copy constructor
  ProgressBar(const ProgressBar<Progress>& other)
      : AsyncDisplay(other),
        progress_(other.progress_),
        total_(other.total_),
        partials_(other.partials_) {
    if (other.speedom_) {
      speedom_ = std::make_unique<Speedometer<Progress>>(*other.speedom_);
    } else {
      speedom_.reset();
    }
  }

  ~ProgressBar() { done(); }

  std::unique_ptr<AsyncDisplay> clone() const override {
    return std::make_unique<ProgressBar>(*this);
  }

  // Method: start
  // Start displaying the bar
  void show() override {
    AsyncDisplay::show();
    if (speedom_) { speedom_->start(); }
  }

  // Methods: Setters
  //
  // speed(Speed)                       - Set how to compute speed, among
  //                                      <Speed> options
  // speed_unit(const std::string&)  - Set unit of speed text next to speed
  // total(ValueType)                   - Set total amount, cannot be 0
  // style(Style)                       - Set style from <ProgressBarStyle>
  //                                      options
  auto& speed(std::optional<double> alpha) {
    if (alpha) {
      speedom_ = std::make_unique<Speedometer<Progress>>(*progress_, *alpha);
    } else {
      speedom_.reset();
    }
    return *this;
  }

  auto& speed_unit(const std::string& msg) {
    speed_unit_ = msg;
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
