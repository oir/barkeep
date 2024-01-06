// Author: Ozan Irsoy

#ifndef BARKEEP_H
#define BARKEEP_H

#include <atomic>
#include <cassert>
#include <chrono>
#include <condition_variable>
#include <iomanip>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <thread>
#include <type_traits>
#include <vector>

#define BARKEEP_VERSION "0.0.6"

#ifdef BARKEEP_ENABLE_FMT
#include <fmt/format.h>
#include <fmt/ostream.h>
#endif

namespace barkeep {

using Strings = std::vector<std::string>;
using StringsList = std::vector<Strings>;

// double precision seconds
using Duration = std::chrono::duration<double, std::ratio<1>>;

/// Kind of animation being displayed for Animation.
enum AnimationStyle : unsigned short {
  Ellipsis,
  Clock,
  Moon,
  Earth,
  Bar,
  Square,
};

/// Definitions of various stills for Animation. AnimationStyle indexes into
/// this.
const static StringsList animation_stills_{
    {".  ", ".. ", "..."},
    {"🕐", "🕜", "🕑", "🕝", "🕒", "🕞", "🕓", "🕟", "🕔", "🕠", "🕕", "🕡",
     "🕖", "🕢", "🕗", "🕣", "🕘", "🕤", "🕙", "🕥", "🕚", "🕦", "🕛", "🕧"},
    {"🌕", "🌖", "🌗", "🌘", "🌑", "🌒", "🌓", "🌔"},
    {"🌎", "🌍", "🌏"},
    {"-", "/", "|", "\\"},
    {"▖", "▘", "▝", "▗"},
};

/// Kind of bar being displayed for ProgressBar.
enum ProgressBarStyle : unsigned short { Bars, Blocks, Arrow, Pip };

struct BarParts {
  std::string left;
  std::string right;
  Strings fill;
  Strings empty;

  // below are optionally used for coloring
  std::string incomplete_left_modifier = "";
  std::string complete_left_modifier = "";
  std::string middle_modifier = "";
  std::string right_modifier = "";

  std::string percent_left_modifier = "";
  std::string percent_right_modifier = "";

  std::string value_left_modifier = "";
  std::string value_right_modifier = "";

  std::string speed_left_modifier = "";
  std::string speed_right_modifier = "";
};

const static std::string red = "\033[31m";
const static std::string green = "\033[32m";
const static std::string yellow = "\033[33m";
const static std::string blue = "\033[34m";
const static std::string magenta = "\033[35m";
const static std::string cyan = "\033[36m";
const static std::string reset = "\033[0m";

/// Definitions of various partial bars for ProgressBar.
/// ProgressBarStyle indexes into this.
const static std::vector<BarParts> progress_bar_parts_{
    {"|", "|", {"|"}, {" "}},
    {"|", "|", {"▏", "▎", "▍", "▌", "▋", "▊", "▉", "█"}, {" "}},
    {"|", "|", {">", "="}, {" "}},
    {"",
     "",
     {"╸", "━"},
     {"╺", "━"},
     "\033[38;2;249;38;114m",
     "\033[38;2;114;156;31m",
     "\033[38;5;237m",
     reset,
     cyan,
     reset,
     green,
     reset,
     red,
     reset},
};

/// Base class to handle all asynchronous displays.
class AsyncDisplay {
 protected:
  Duration interval_{0.0};
  std::unique_ptr<std::thread> displayer_;
  std::condition_variable completion_;
  std::mutex completion_m_;
  std::atomic<bool> complete_ = false;

  std::string message_;
  std::string fmtstr_;

 protected:
  std::ostream* out_;

 protected:
  /// Render a display: animation, progress bar, etc.
  virtual void render_() = 0;

  virtual Duration default_interval_() const = 0;

  /// Display everything (message, maybe with animation, progress bar, etc).
  void display_() {
    if (not no_tty_) { *out_ << "\r\033[K"; } // CR, clear line
    render_();
    if (no_tty_) { *out_ << "\n"; }
    *out_ << std::flush;
  }

 protected:
  bool no_tty_ = false;

  /// Display the message to output stream.
  void render_message_() const {
    if (not message_.empty()) { *out_ << message_ << " "; }
  }

  /// Start the display but do not show.
  /// This typically means start measuring speed if applicable, without
  /// displaying anything.
  virtual void start() {}

  /// Join the display thread. Protected because python bindings need to
  /// override to handle GIL.
  virtual void join() {
    displayer_->join();
    displayer_.reset();
  }

 public:
  AsyncDisplay(std::ostream* out = &std::cout) : out_(out) {}

  AsyncDisplay(const AsyncDisplay& other)
      : interval_(other.interval_),
        complete_(bool(other.complete_)),
        message_(other.message_),
        fmtstr_(other.fmtstr_),
        out_(other.out_),
        no_tty_(other.no_tty_) {
    if (other.running()) {
      throw std::runtime_error("A running display cannot be copied");
    }
  }

  AsyncDisplay(AsyncDisplay&& other)
      : interval_(other.interval_),
        complete_(bool(other.complete_)),
        out_(other.out_),
        no_tty_(other.no_tty_) {
    if (other.running()) {
      throw std::runtime_error("A running display cannot be moved");
    }
    message_ = std::move(other.message_);
    fmtstr_ = std::move(other.fmtstr_);
  }

  virtual ~AsyncDisplay() { done(); }

  /// Start the display. This starts writing the display in the output stream,
  /// and computing speed if applicable.
  virtual void show() {
    if (running()) {
      return; // noop if already show()n before
    }
    start();

    displayer_ = std::make_unique<std::thread>([&]() {
      display_();
      while (true) {
        bool complete = false;
        auto interval =
            interval_ != Duration{0.} ? interval_ : default_interval_();
        {
          std::unique_lock<std::mutex> lock(completion_m_);
          complete = complete_;
          if (not complete) {
            completion_.wait_for(lock, interval);
            complete = complete_;
          }
        }
        display_();
        if (complete) {
          // Final newline to avoid overwriting the display
          *out_ << std::endl;
          break;
        }
      }
    });
  }

  /// End the display.
  virtual void done() {
    if (not running()) { return; } // noop if already done() before
    complete_ = true;
    completion_.notify_all();
    join();
  }

  bool running() const { return displayer_ != nullptr; }

  virtual std::unique_ptr<AsyncDisplay> clone() const = 0;

 protected:
  void ensure_not_running() const {
    if (running()) {
      throw std::runtime_error("Cannot modify a running display");
    }
  }

#ifdef BARKEEP_ENABLE_FMT
  /// Set formatting string to be used to display the message and speed.
  /// @param fmtstr
  void fmt(const std::string& fmtstr) {
    ensure_not_running();
    fmtstr_ = fmtstr + " "; // extra space for separating the cursor
  }
#endif

  /// Set message to be displayed
  /// @param msg message to be displayed
  void message(const std::string& msg) {
    ensure_not_running();
    message_ = msg;
  }

  /// Set the interval in which the display is refreshed. This is also the
  /// interval in which speed is measured if applicable.
  /// @param pd interval as a Duration
  void interval(Duration pd) {
    ensure_not_running();
    interval_ = pd;
  }

  /// Overload of interval(Duration) to accept a double argument
  /// @param pd interval as a double
  void interval(double pd) {
    ensure_not_running();
    interval_ = Duration(pd);
  }

  /// Enable no-tty mode.
  void no_tty() {
    ensure_not_running();
    no_tty_ = true;
  }

  friend class Composite;
};

/// Displays a simple animation with a message.
class Animation : public AsyncDisplay {
 private:
  unsigned short frame_ = 0;
  Strings stills_;

 protected:
  void render_() override {
    render_message_();
    *out_ << stills_[frame_] << " ";
    frame_ = (frame_ + 1) % stills_.size();
  }

  Duration default_interval_() const override {
    return no_tty_ ? Duration{60.} : Duration{.1};
  }

 public:
  using Style = AnimationStyle;

  /// Constructor.
  /// @param out output stream to write to
  Animation(std::ostream* out = &std::cout)
      : AsyncDisplay(out),
        stills_(animation_stills_[static_cast<unsigned short>(Ellipsis)]) {}

  Animation(const Animation& other) = default;
  Animation(Animation&&) = default;
  ~Animation() { done(); }

  std::unique_ptr<AsyncDisplay> clone() const override {
    return std::make_unique<Animation>(*this);
  }

  /// Set animation style using one of AnimationStyle.
  /// @param sty
  /// @return reference to self
  auto& style(Style sty) {
    ensure_not_running();
    stills_ = animation_stills_[static_cast<unsigned short>(sty)];
    return *this;
  }

  /// Set message to be displayed.  @param msg  @return reference to self
  auto& message(const std::string& msg) {
    AsyncDisplay::message(msg);
    return *this;
  }

  /// Set interval in which the animation is refreshed.
  /// @param pd  @return reference to self
  auto& interval(Duration pd) {
    AsyncDisplay::interval(pd);
    return *this;
  }

  /// Overload of interval(Duration) to accept a double argument
  /// @param pd  @return reference to self
  auto& interval(double pd) {
    AsyncDisplay::interval(pd);
    return *this;
  }

  /// Enable no-tty mode.  @return reference to self
  auto& no_tty() {
    AsyncDisplay::no_tty();
    return *this;
  }
};

/// Creates a composite display out of two display that shows them side by side.
/// For instance, you can combine two Counter objects to monitor two variables.
class Composite : public AsyncDisplay {
 protected:
  std::unique_ptr<AsyncDisplay> left_, right_;

  void render_() override {
    left_->render_();
    *out_ << " ";
    right_->render_();
  }

  Duration default_interval_() const override {
    // TODO: maybe make this the min of the two?
    return left_->default_interval_();
  }

  void start() override {
    left_->start();
    right_->start();
  }

 public:
  Composite(std::unique_ptr<AsyncDisplay> left,
            std::unique_ptr<AsyncDisplay> right)
      : AsyncDisplay(left->out_),
        left_(std::move(left)),
        right_(std::move(right)) {
    AsyncDisplay::interval(min(left_->interval_, right_->interval_));
    right_->out_ = left_->out_;
    if (left_->no_tty_ or right_->no_tty_) { AsyncDisplay::no_tty(); }
  }
  /// Copy constructor clones child displays.
  Composite(const Composite& other)
      : AsyncDisplay(other),
        left_(other.left_->clone()),
        right_(other.right_->clone()) {
    right_->out_ = left_->out_;
  }
  ~Composite() { done(); }

  std::unique_ptr<AsyncDisplay> clone() const override {
    return std::make_unique<Composite>(*this);
  }

  /// Enable no-tty mode.  @return reference to self
  auto& no_tty() {
    AsyncDisplay::no_tty();
    left_->no_tty();
    right_->no_tty();
    return *this;
  }
};

/// Pipe operator can be used to combine two displays into a Composite.
auto operator|(const AsyncDisplay& left, const AsyncDisplay& right) {
  return Composite(left.clone(), right.clone());
}

/// Trait class to extract underlying value type from numerics and
/// std::atomics of numerics.
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

/// Helper class to measure and display speed of progress.
template <typename Progress>
class Speedometer {
 private:
  Progress& progress_; // Current amount of work done
  double discount_;

  using ValueType = value_t<Progress>;
  using SignedType = signed_t<ValueType>;
  using Clock = std::chrono::system_clock;
  using Time = std::chrono::time_point<Clock>;

  double progress_increment_sum_ = 0; // (weighted) sum of progress increments
  Duration duration_increment_sum_{}; // (weighted) sum of duration increments

  Time last_start_time_;
  ValueType last_progress_;

 public:
  double speed() {
    Time now = Clock::now();
    Duration dur = now - last_start_time_;
    last_start_time_ = now;

    ValueType progress_copy = progress_; // to avoid progress_ changing below
    SignedType progress_increment =
        SignedType(progress_copy) - SignedType(last_progress_);
    last_progress_ = progress_copy;

    progress_increment_sum_ =
        (1 - discount_) * progress_increment_sum_ + progress_increment;
    duration_increment_sum_ = (1 - discount_) * duration_increment_sum_ + dur;
    return duration_increment_sum_.count() == 0
               ? 0
               : progress_increment_sum_ / duration_increment_sum_.count();
  }

  /// Write speed to given output stream. Speed is a double (written with
  /// precision 2), possibly followed by a unit of speed.
  void render_speed(std::ostream* out, const std::string& speed_unit) {
    std::stringstream ss; // use local stream to avoid disturbing `out` with
                          // std::fixed and std::setprecision
    double speed = this->speed();
    ss << std::fixed << std::setprecision(2) << "(" << speed;
    if (speed_unit.empty()) {
      ss << ") ";
    } else {
      ss << " " << speed_unit << ") ";
    }

    auto s = ss.str();
    *out << s;
  }

  /// Start computing the speed based on the amount of change in progress.
  void start() {
    last_progress_ = progress_;
    last_start_time_ = Clock::now();
  }

  /// Constructor.
  /// @param progress Reference to numeric to measure the change of.
  /// @param discount Discount factor in [0, 1] to use in computing the speed.
  ///                 Previous increments are weighted by (1-discount).
  ///                 If discount is 0, all increments are weighted equally.
  ///                 If discount is 1, only the most recent increment is
  ///                 considered.
  Speedometer(Progress& progress, double discount)
      : progress_(progress), discount_(discount) {
    if (discount < 0 or discount > 1) {
      throw std::runtime_error("Discount must be in [0, 1]");
    }
  }
};

/// Monitors and displays a single numeric variable
template <typename Progress = size_t>
class Counter : public AsyncDisplay {
 private:
  Progress* progress_ = nullptr; // current amount of work done
  std::unique_ptr<Speedometer<Progress>> speedom_;
  std::string speed_unit_ = "it/s"; // unit of speed text next to speed

  std::stringstream ss_;

 protected:
  /// Write the value of progress to the output stream
  void render_counts_() {
    ss_ << *progress_;
    *out_ << ss_.str() << " ";
    ss_.str("");
  }

  /// Write the value of progress with the message to the output stream
  void render_() override {
#ifdef BARKEEP_ENABLE_FMT
    if (not fmtstr_.empty()) {
      using namespace fmt::literals;
      value_t<Progress> progress = *progress_;
      if (speedom_) {
        fmt::print(*out_,
                   fmt::runtime(fmtstr_),
                   "value"_a = progress,
                   "speed"_a = speedom_->speed());
      } else {
        fmt::print(*out_, fmt::runtime(fmtstr_), "value"_a = progress);
      }
      return;
    }
#endif
    render_message_();
    render_counts_();
    if (speedom_) { speedom_->render_speed(out_, speed_unit_); }
  }

  /// Default interval in which the display is refreshed, if interval() is not
  /// invoked.
  /// @return default interval
  Duration default_interval_() const override {
    return no_tty_ ? Duration{60.} : Duration{.1};
  }

  void init(Progress* progress, std::ostream* out) {
    progress_ = progress;
    out_ = out;
  }

  void start() override {
    if constexpr (std::is_floating_point_v<value_t<Progress>>) {
      ss_ << std::fixed << std::setprecision(2);
    }
    if (speedom_) { speedom_->start(); }
  }

  Counter(std::ostream* out = &std::cout) : AsyncDisplay(out) {}

 public:
  /// Constructor.
  /// @param progress Variable to be monitored and displayed
  /// @param out Output stream to write to
  Counter(Progress* progress, std::ostream* out = &std::cout) : AsyncDisplay() {
    init(progress, out);
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

  /// Set how to compute speed.
  /// @param discount Discount factor in [0, 1] to use in computing the speed.
  ///                 Previous increments are weighted by (1-discount).
  ///                 If discount is 0, all increments are weighted equally.
  ///                 If discount is 1, only the most recent increment is
  ///                 considered. If discount is `std::nullopt`, speed is not
  ///                 computed.
  /// @return reference to self
  auto& speed(std::optional<double> discount) {
    ensure_not_running();
    if (discount) {
      speedom_ = std::make_unique<Speedometer<Progress>>(*progress_, *discount);
    } else {
      speedom_.reset();
    }
    return *this;
  }

  /// Set unit of speed text next to speed.
  /// @param msg unit of speed  @return reference to self
  auto& speed_unit(const std::string& msg) {
    ensure_not_running();
    speed_unit_ = msg;
    return *this;
  }

  /// Set message to be displayed. @param msg Message  @return reference to self
  auto& message(const std::string& msg) {
    AsyncDisplay::message(msg);
    return *this;
  }

  /// Set interval in which the display is refreshed.
  /// @param pd interval as a Duration  @return reference to self
  auto& interval(Duration pd) {
    AsyncDisplay::interval(pd);
    return *this;
  }

  /// Overload of interval(Duration) to accept a double argument
  /// @param pd interval as a double  @return reference to self
  auto& interval(double pd) {
    AsyncDisplay::interval(pd);
    return *this;
  }

  /// Enable no-tty mode.  @return reference to self
  auto& no_tty() {
    AsyncDisplay::no_tty();
    return *this;
  }

#ifdef BARKEEP_ENABLE_FMT
  /// Set formatting string to be used to display the message and speed.
  /// @param fmtstr
  auto& fmt(const std::string& fmtstr) {
    AsyncDisplay::fmt(fmtstr);
    return *this;
  }
#endif
};

/// Displays a progress bar, by comparing the progress value being monitored to
/// a given total value. Optionally reports speed.
template <typename Progress>
class ProgressBar : public AsyncDisplay {
 private:
  using ValueType = value_t<Progress>;

  Progress* progress_; // work done so far
  std::unique_ptr<Speedometer<Progress>> speedom_;
  std::string speed_unit_ = "it/s";    // unit of speed text next to speed
  static constexpr size_t width_ = 30; // width of progress bar
                                       // (TODO: make customizable?)
  ValueType total_{100};               // total work

  BarParts bar_parts_; // progress bar display strings

 protected:
  /// Compute the shape of the progress bar based on progress and write to
  /// output stream.
  void render_progress_bar_(std::ostream* out = nullptr) {
    ValueType progress_copy = *progress_; // to avoid progress_ changing
                                          // during computations below
    bool complete = progress_copy >= total_;
    int on = int(ValueType(width_) * progress_copy / total_);
    size_t partial = size_t(ValueType(bar_parts_.fill.size()) *
                                ValueType(width_) * progress_copy / total_ -
                            ValueType(bar_parts_.fill.size()) * ValueType(on));
    if (on >= int(width_)) {
      on = width_;
      partial = 0;
    } else if (on < 0) {
      on = 0;
      partial = 0;
    }
    assert(partial < bar_parts_.fill.size());
    auto off = width_ - size_t(on) - size_t(partial > 0);

    // draw progress bar
    if (out == nullptr) { out = out_; }

    // left end
    *out << bar_parts_.left;
    *out << (complete ? bar_parts_.complete_left_modifier
                      : bar_parts_.incomplete_left_modifier);

    // filled portion
    for (int i = 0; i < on; i++) { *out << bar_parts_.fill.back(); }

    // partially filled character
    if (partial > 0) { *out << bar_parts_.fill.at(partial - 1); }

    *out << bar_parts_.middle_modifier;

    // partially empty character if available
    if (off > 0) {
      if (bar_parts_.empty.size() > 1) {
        assert(bar_parts_.empty.size() == bar_parts_.fill.size());
        *out << bar_parts_.empty.at(partial);
      } else {
        *out << bar_parts_.empty.back();
      }
    }

    // empty portion
    for (size_t i = 1; i < off; i++) { *out << bar_parts_.empty.back(); }

    // right end
    *out << bar_parts_.right_modifier;
    *out << bar_parts_.right;
  }

  /// Write progress value with the total, e.g. 50/100, to output stream.
  /// Progress width is expanded (and right justified) to match width of total.
  void render_counts_() {
    std::stringstream ss, totals;
    if (std::is_floating_point_v<Progress>) {
      ss << std::fixed << std::setprecision(2);
      totals << std::fixed << std::setprecision(2);
    }
    totals << total_;
    auto width = static_cast<std::streamsize>(totals.str().size());
    ss.width(width);
    ss << std::right << *progress_ << "/" << total_ << " ";
    *out_ << ss.str();
  }

  /// Write the percent completed to output stream
  void render_percentage_() {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2);
    ss.width(6);
    ss << std::right << *progress_ * 100. / total_ << "% ";
    *out_ << ss.str();
  }

  /// Run all of the individual render methods to write everything to stream
  void render_() override {
#ifdef BARKEEP_ENABLE_FMT
    if (not fmtstr_.empty()) {
      using namespace fmt::literals;
      value_t<Progress> progress = *progress_;

      std::stringstream bar_ss;
      render_progress_bar_(&bar_ss);

      double percent = progress * 100. / total_;

      if (speedom_) {
        fmt::print(*out_,
                   fmt::runtime(fmtstr_),
                   "value"_a = progress,
                   "bar"_a = bar_ss.str(),
                   "percent"_a = percent,
                   "total"_a = total_,
                   "speed"_a = speedom_->speed(),
                   "red"_a = red,
                   "green"_a = green,
                   "yellow"_a = yellow,
                   "blue"_a = blue,
                   "magenta"_a = magenta,
                   "cyan"_a = cyan,
                   "reset"_a = reset);
      } else {
        fmt::print(*out_,
                   fmt::runtime(fmtstr_),
                   "value"_a = progress,
                   "bar"_a = bar_ss.str(),
                   "percent"_a = percent,
                   "total"_a = total_,
                   "red"_a = red,
                   "green"_a = green,
                   "yellow"_a = yellow,
                   "blue"_a = blue,
                   "magenta"_a = magenta,
                   "cyan"_a = cyan,
                   "reset"_a = reset);
      }
      return;
    }
#endif
    render_message_();

    *out_ << bar_parts_.percent_left_modifier;
    render_percentage_();
    *out_ << bar_parts_.percent_right_modifier;

    render_progress_bar_();
    *out_ << " ";

    *out_ << bar_parts_.value_left_modifier;
    render_counts_();
    *out_ << bar_parts_.value_right_modifier;

    if (speedom_) {
      *out_ << bar_parts_.speed_left_modifier;
      speedom_->render_speed(out_, speed_unit_);
      *out_ << bar_parts_.speed_right_modifier;
    }
  }

  Duration default_interval_() const override {
    return no_tty_ ? Duration{60.} : Duration{.1};
  }

  void start() override {
    if (speedom_) { speedom_->start(); }
  }

 protected:
  void init(Progress* progress, std::ostream* out) {
    progress_ = progress;
    out_ = out;
  }

  ProgressBar(std::ostream* out = &std::cout) : AsyncDisplay(out) {}

 public:
  using Style = ProgressBarStyle;

  /// Constructor.
  /// @param progress Variable to be monitored to measure completion
  /// @param out      Output stream to write to
  ProgressBar(Progress* progress, std::ostream* out = &std::cout)
      : AsyncDisplay(),
        bar_parts_(progress_bar_parts_[static_cast<unsigned short>(Blocks)]) {
    init(progress, out);
  }

  /// move constructor
  ProgressBar(ProgressBar<Progress>&& other)
      : AsyncDisplay(std::move(other)),
        progress_(other.progress_),
        speedom_(std::move(other.speedom_)),
        total_(other.total_),
        bar_parts_(std::move(other.bar_parts_)) {}

  /// copy constructor
  ProgressBar(const ProgressBar<Progress>& other)
      : AsyncDisplay(other),
        progress_(other.progress_),
        total_(other.total_),
        bar_parts_(other.bar_parts_) {
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

  /// Set how to compute speed.
  /// @param discount Discount factor in [0, 1] to use in computing the speed.
  ///                 Previous increments are weighted by (1-discount).
  ///                 If discount is 0, all increments are weighted equally.
  ///                 If discount is 1, only the most recent increment is
  ///                 considered. If discount is `std::nullopt`, speed is not
  ///                 computed.
  /// @return reference to self
  auto& speed(std::optional<double> discount) {
    ensure_not_running();
    if (discount) {
      speedom_ = std::make_unique<Speedometer<Progress>>(*progress_, *discount);
    } else {
      speedom_.reset();
    }
    return *this;
  }

  /// Set unit of speed text next to speed.
  /// @param msg unit of speed  @return reference to self
  auto& speed_unit(const std::string& msg) {
    ensure_not_running();
    speed_unit_ = msg;
    return *this;
  }

  /// Set total amount of work to be done, for the progress bar to be full.
  /// @param tot total amount of work  @return reference to self
  auto& total(ValueType tot) {
    ensure_not_running();
    if (tot == 0) {
      throw std::runtime_error("Progress total cannot be zero!");
    }
    total_ = tot;
    return *this;
  }

  /// Set progress bar style.  @param sty Style  @return reference to self
  auto& style(Style sty) {
    ensure_not_running();
    bar_parts_ = progress_bar_parts_[static_cast<unsigned short>(sty)];
    return *this;
  }

  /// Set message to be displayed.
  /// @param msg Message  @return reference to self
  auto& message(const std::string& msg) {
    AsyncDisplay::message(msg);
    return *this;
  }

  /// Set interval in which the display is refreshed.
  /// @param pd interval as a Duration  @return reference to self
  auto& interval(Duration pd) {
    AsyncDisplay::interval(pd);
    return *this;
  }

  /// Overload of interval(Duration) to accept a double argument
  /// @param pd interval as a double  @return reference to self
  auto& interval(double pd) {
    AsyncDisplay::interval(pd);
    return *this;
  }

  /// Enable no-tty mode.  @return reference to self
  auto& no_tty() {
    AsyncDisplay::no_tty();
    return *this;
  }

#ifdef BARKEEP_ENABLE_FMT
  /// Set formatting string to be used to display the message and parts.
  /// @param fmtstr
  auto& fmt(const std::string& fmtstr) {
    AsyncDisplay::fmt(fmtstr);
    return *this;
  }
#endif
};

} // namespace barkeep

#endif
