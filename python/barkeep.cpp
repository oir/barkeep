#include <iostream>
#include <pybind11/operators.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#ifndef BARKEEP_ENABLE_FMT_FORMAT
#define BARKEEP_ENABLE_FMT_FORMAT
#endif
#include <barkeep/barkeep.h>

#ifndef BARKEEP_ENABLE_ATOMIC_FLOAT
#define BARKEEP_ENABLE_ATOMIC_FLOAT 1
#endif

namespace py = pybind11;
using namespace barkeep;
using namespace py::literals;

using Int = std::int64_t;
using AtomicInt = std::atomic<Int>;
using Float = double;

#if BARKEEP_ENABLE_ATOMIC_FLOAT
using AtomicFloat = std::atomic<Float>; // Requires C++20 AND gcc (tested with
                                        // gcc11) (clang 15.0.0 did not work)

enum class DType { Int, Float, AtomicInt, AtomicFloat };
#else
enum class DType { Int, Float, AtomicInt };
#endif

struct PyFileStream : public std::stringbuf, public std::ostream {
  py::object file_;

  int sync() override {
    py::gil_scoped_acquire acquire;
    py::print(str(),
              py::arg("file") = file_,
              py::arg("flush") = true,
              py::arg("end") = "");
    str("");
    return 0;
  }

  PyFileStream(py::object file)
      : std::stringbuf(), std::ostream(this), file_(std::move(file)) {}
};

class AsyncDisplayer_ : public AsyncDisplayer {
 public:
  std::shared_ptr<PyFileStream> file_ = nullptr;

  AsyncDisplayer_(BaseDisplay* parent,
                  std::shared_ptr<PyFileStream> file,
                  Duration interval,
                  bool no_tty)
      : AsyncDisplayer(parent, nullptr, interval, no_tty), file_(file) {
    out_ = file_ ? (std::ostream*)file_.get() : &std::cout;
  }

  void join() override {
    if (file_) {
      // release gil because displayer thread needs it to write
      py::gil_scoped_release release;
      AsyncDisplayer::join();
    } else {
      AsyncDisplayer::join();
    }
  }
};

class Animation_ : public AnimationDisplay {
 public:
  Animation_(py::object file = py::none(),
             std::string message = "",
             std::variant<AnimationStyle, Strings> style = Ellipsis,
             double interval = 0.,
             bool no_tty = false)
      : AnimationDisplay({.out = nullptr,
                          .message = message,
                          .style = style,
                          .interval = interval,
                          .no_tty = no_tty,
                          .show = false}) {
    std::shared_ptr<PyFileStream> fp = nullptr;
    if (not file.is_none()) {
      fp = std::make_shared<PyFileStream>(std::move(file));
    }
    auto interval_ =
        interval == 0. ? this->default_interval_(no_tty) : Duration(interval);
    displayer_ = std::make_shared<AsyncDisplayer_>(this, fp, interval_, no_tty);
  }
};

class Status_ : public StatusDisplay {
 public:
  Status_(py::object file = py::none(),
          std::string message = "",
          std::variant<AnimationStyle, Strings> style = Ellipsis,
          double interval = 0.,
          bool no_tty = false)
      : StatusDisplay({.out = nullptr,
                       .message = message,
                       .style = style,
                       .interval = interval,
                       .no_tty = no_tty,
                       .show = false}) {
    std::shared_ptr<PyFileStream> fp = nullptr;
    if (not file.is_none()) {
      fp = std::make_shared<PyFileStream>(std::move(file));
    }
    auto interval_ =
        interval == 0. ? this->default_interval_(no_tty) : Duration(interval);
    displayer_ = std::make_shared<AsyncDisplayer_>(this, fp, interval_, no_tty);
  }

  std::string message() { return message_; }
  void message(const std::string& msg) { message_ = msg; }
};

template <typename T>
class Counter_ : public CounterDisplay<T> {
 protected:
  using CounterDisplay<T>::render_;
  using CounterDisplay<T>::default_interval_;

 public:
  std::shared_ptr<T> work = std::make_shared<T>(0);

  Counter_(py::object file = py::none(),
           std::string format = "",
           std::string message = "",
           std::optional<double> speed = std::nullopt,
           std::string speed_unit = "it/s",
           double interval = 0.,
           bool no_tty = false)
      : CounterDisplay<T>(nullptr,
                          {.out = nullptr,
                           .format = format,
                           .message = message,
                           .speed = std::nullopt,
                           .speed_unit = speed_unit,
                           .interval = interval,
                           .no_tty = no_tty,
                           .show = false}) {
    if (speed) {
      this->speedom_ = std::make_unique<Speedometer<T>>(work.get(), *speed);
    }
    std::shared_ptr<PyFileStream> fp = nullptr;
    if (not file.is_none()) {
      fp = std::make_shared<PyFileStream>(std::move(file));
    }
    auto interval_ =
        interval == 0. ? this->default_interval_(no_tty) : Duration(interval);
    this->displayer_ =
        std::make_shared<AsyncDisplayer_>(this, fp, interval_, no_tty);
    this->progress_ = work.get();
    assert(this->progress_ != nullptr);
  }

  auto& operator+=(value_t<T> v) {
    *work += v;
    return *this;
  }
  auto& operator-=(value_t<T> v) {
    *work -= v;
    return *this;
  }
  bool operator>(value_t<T> v) const { return *work > v; }
  bool operator<(value_t<T> v) const { return *work < v; }
  bool operator>=(value_t<T> v) const { return *work >= v; }
  bool operator<=(value_t<T> v) const { return *work <= v; }
  bool operator==(value_t<T> v) const { return *work == v; }
  bool operator!=(value_t<T> v) const { return *work != v; }
};

template <typename T>
class ProgressBar_ : public ProgressBarDisplay<T> {
 protected:
  using ProgressBarDisplay<T>::render_;
  using ProgressBarDisplay<T>::default_interval_;

 public:
  std::shared_ptr<T> work = std::make_shared<T>(0);

  ProgressBar_(py::object file = py::none(),
               value_t<T> total = 100,
               std::string format = "",
               std::string message = "",
               std::optional<double> speed = std::nullopt,
               std::string speed_unit = "it/s",
               std::variant<ProgressBarStyle, BarParts> style = Blocks,
               double interval = 0.,
               bool no_tty = false)
      : ProgressBarDisplay<T>(nullptr,
                              {.out = nullptr,
                               .total = total,
                               .format = format,
                               .message = message,
                               .speed = std::nullopt,
                               .speed_unit = speed_unit,
                               .style = style,
                               .interval = interval,
                               .no_tty = no_tty,
                               .show = false}) {
    if (speed) {
      this->speedom_ = std::make_unique<Speedometer<T>>(work.get(), *speed);
    }
    std::shared_ptr<PyFileStream> fp = nullptr;
    if (not file.is_none()) {
      fp = std::make_shared<PyFileStream>(std::move(file));
    }
    auto interval_ =
        interval == 0. ? this->default_interval_(no_tty) : Duration(interval);
    this->displayer_ =
        std::make_shared<AsyncDisplayer_>(this, fp, interval_, no_tty);
    this->progress_ = work.get();
    assert(this->progress_ != nullptr);
  }

  auto& operator+=(value_t<T> v) {
    *work += v;
    return *this;
  }
  auto& operator-=(value_t<T> v) {
    *work -= v;
    return *this;
  }
  bool operator>(value_t<T> v) const { return *work > v; }
  bool operator<(value_t<T> v) const { return *work < v; }
  bool operator>=(value_t<T> v) const { return *work >= v; }
  bool operator<=(value_t<T> v) const { return *work <= v; }
  bool operator==(value_t<T> v) const { return *work == v; }
  bool operator!=(value_t<T> v) const { return *work != v; }
};

PYBIND11_MODULE(barkeep, m) {
  m.doc() =
      "Small, C++-based python library to display async animations, counters, and progress bars.";
  m.attr("__version__") = BARKEEP_VERSION;

  py::enum_<AnimationStyle>(m, "AnimationStyle")
      .value("Ellipsis", AnimationStyle::Ellipsis)
      .value("Clock", AnimationStyle::Clock)
      .value("Moon", AnimationStyle::Moon)
      .value("Earth", AnimationStyle::Earth)
      .value("Bar", AnimationStyle::Bar)
      .value("Bounce", AnimationStyle::Bounce)
      .export_values();

  py::enum_<ProgressBarStyle>(m, "ProgressBarStyle")
      .value("Bars", ProgressBarStyle::Bars)
      .value("Blocks", ProgressBarStyle::Blocks)
      .value("Rich", ProgressBarStyle::Rich)
      .value("Line", ProgressBarStyle::Line)
      .export_values();

  py::enum_<DType>(m, "DType")
      .value("Int", DType::Int)
      .value("Float", DType::Float)
      .value("AtomicInt", DType::AtomicInt)
#if BARKEEP_ENABLE_ATOMIC_FLOAT
      .value("AtomicFloat", DType::AtomicFloat)
#endif
      .export_values();

  py::class_<BarParts>(m, "BarParts")
      .def(py::init<std::string,
                    std::string,
                    std::vector<std::string>,
                    std::vector<std::string>,
                    std::string,
                    std::string,
                    std::string,
                    std::string,
                    std::string,
                    std::string,
                    std::string,
                    std::string,
                    std::string,
                    std::string>(),
           "left"_a,
           "right"_a,
           "fill"_a,
           "empty"_a,
           "incomplete_left_modifier"_a = "",
           "complete_left_modifier"_a = "",
           "middle_modifier"_a = "",
           "right_modifier"_a = "",
           "percent_left_modifier"_a = "",
           "percent_right_modifier"_a = "",
           "value_left_modifier"_a = "",
           "value_right_modifier"_a = "",
           "speed_left_modifier"_a = "",
           "speed_right_modifier"_a = "");

  auto base_display =
      py::class_<BaseDisplay, std::shared_ptr<BaseDisplay>>(m, "AsyncDisplay")
          .def("show", &BaseDisplay::show)
          .def("done", &BaseDisplay::done);

  py::class_<Animation_, std::shared_ptr<Animation_>, BaseDisplay>(m,
                                                                   "Animation")
      .def(py::init([](py::object file,
                       std::string msg,
                       double interval,
                       std::variant<AnimationStyle, Strings> style,
                       bool no_tty,
                       bool show) {
             auto a = std::make_shared<Animation_>(
                 file, msg, style, interval, no_tty);
             if (show) { a->show(); }
             return a;
           }),
           R"docstr(
            Displays a simple animation with a message.

            Parameters
            ----------
            file : file-like object, optional
                File to write to. Defaults to stdout.
            message : str, optional
                Message to display. Defaults to "".
            interval : float, optional
                Interval between frames in seconds. If None, defaults to 1 if
                not no_tty, 60 otherwise.
            style : AnimationStyle, optional
                Animation style. Defaults to AnimationStyle.Ellipsis.
            no_tty : bool, optional
                If True, use no-tty mode (no \r, slower refresh). Defaults to False.
            show : bool, optional
                If True, show the animation immediately. Defaults to True.
           )docstr",
           "file"_a = py::none(),
           "message"_a = "",
           "interval"_a = 0.,
           "style"_a = AnimationStyle::Ellipsis,
           "no_tty"_a = false,
           "show"_a = true,
           py::keep_alive<0, 1>()); // keep file alive while the animation is
                                    // alive

  py::class_<Status_, std::shared_ptr<Status_>, BaseDisplay>(m, "Status")
      .def(py::init([](py::object file,
                       std::string msg,
                       double interval,
                       std::variant<AnimationStyle, Strings> style,
                       bool no_tty,
                       bool show) {
             auto a =
                 std::make_shared<Status_>(file, msg, style, interval, no_tty);
             if (show) { a->show(); }
             return a;
           }),
           R"docstr(
            Status is an Animation where it is possible to update the message
            while the animation is running.

            Parameters
            ----------
            file : file-like object, optional
                File to write to. Defaults to stdout.
            message : str, optional
                Message to display. Defaults to "".
            interval : float, optional
                Interval between frames in seconds. If None, defaults to 1 if
                not no_tty, 60 otherwise.
            style : AnimationStyle, optional
                Animation style. Defaults to AnimationStyle.Ellipsis.
            no_tty : bool, optional
                If True, use no-tty mode (no \r, slower refresh). Defaults to False.
            show : bool, optional
                If True, show the animation immediately. Defaults to True.
           )docstr",
           "file"_a = py::none(),
           "message"_a = "",
           "interval"_a = 0.,
           "style"_a = AnimationStyle::Ellipsis,
           "no_tty"_a = false,
           "show"_a = true,
           py::keep_alive<0, 1>()) // keep file alive while the animation is
                                   // alive
      .def_property("message",
                    py::overload_cast<>(&Status_::message),
                    py::overload_cast<const std::string&>(&Status_::message));

  auto bind_display = [&](auto& m, auto disp, auto pv, const char* name) {
    using T = decltype(pv);
    using Disp = decltype(disp);
    py::class_<Disp, std::shared_ptr<Disp>, BaseDisplay>(m, name)
        .def_property(
            "value",
            [](std::shared_ptr<Disp> c) -> value_t<T> { return *c->work; },
            [](std::shared_ptr<Disp> c, value_t<T> v) { *c->work = v; })
        .def(py::self += value_t<T>())
        .def(py::self -= value_t<T>())
        .def(py::self > value_t<T>())
        .def(py::self < value_t<T>())
        .def(py::self >= value_t<T>())
        .def(py::self <= value_t<T>())
        .def(py::self == value_t<T>())
        .def(py::self != value_t<T>());
  };

  auto bind_counter = [&](auto& m, auto pv, const char* name) {
    bind_display(m, Counter_<decltype(pv)>(), decltype(pv)(), name);
  };

  bind_counter(m, Int(), "IntCounter");
  bind_counter(m, Float(), "FloatCounter");
  bind_counter(m, AtomicInt(), "AtomicIntCounter");
#if BARKEEP_ENABLE_ATOMIC_FLOAT
  bind_counter(m, AtomicFloat(), "AtomicFloatCounter");
#endif

  // Factory function for all instantiations of Counter_
  m.def(
      "Counter",
      [](double value, // TODO: Make value match the specified dtype
         py::object file,
         std::string msg,
         std::optional<double> interval,
         std::optional<double> speed,
         std::string speed_unit,
         std::optional<std::string> fmt,
         bool no_tty,
         DType dtype,
         bool show) -> std::shared_ptr<BaseDisplay> {
        std::shared_ptr<BaseDisplay> rval;

        auto make_counter = [&](auto pv) {
          using T = decltype(pv);
          auto c = std::make_shared<Counter_<T>>(file,
                                                 fmt.value_or(""),
                                                 msg,
                                                 speed,
                                                 speed_unit,
                                                 interval.value_or(0.),
                                                 no_tty);
          *c->work = value;
          if (show) { c->show(); }
          return c;
        };

        switch (dtype) {
        case DType::Int: return make_counter(Int());
        case DType::Float: return make_counter(Float());
        case DType::AtomicInt: return make_counter(AtomicInt());
#if BARKEEP_ENABLE_ATOMIC_FLOAT
        case DType::AtomicFloat: return make_counter(AtomicFloat());
#endif
        default: throw std::runtime_error("Unknown dtype"); return {};
        }
      },
      R"docstr(
        Monitors and displays a single numeric value with a message.

        Parameters
        ----------
        value : int or float, optional
            Initial value of the counter. Defaults to 0.
        file : file-like object, optional
            File to write to. Defaults to stdout.
        message : str, optional
            Message to display. Defaults to "".
        interval : float, optional
            Interval between frames in seconds. If None, defaults to 1 if
            not no_tty, 60 otherwise.
        speed : float, optional
            Discount factor in [0, 1] to use in computing the speed.
            Previous increments are weighted by (1-discount).
            If discount is 0, all increments are weighted equally.
            If discount is 1, only the most recent increment is
            considered. If discount is None (default), speed is not
            computed.
        speed_unit : str, optional
            Unit of speed. Defaults to "".
        fmt : str, optional
            Set formatting string to be used to display the message and speed.
            If provided, message and speed_unit are ignored.
        no_tty : bool, optional
            If True, use no-tty mode (no \r, slower refresh). Defaults to False.
        dtype : DType, optional
            Data type of the value. Defaults to DType.Int.
        show : bool, optional
            If True, show the counter immediately. Defaults to True.
       )docstr",
      "value"_a = 0,
      "file"_a = py::none(),
      "message"_a = "",
      "interval"_a = py::none(),
      "speed"_a = py::none(),
      "speed_unit"_a = "",
      "fmt"_a = py::none(),
      "no_tty"_a = false,
      "dtype"_a = DType::Int,
      "show"_a = true,
      py::keep_alive<0, 2>()); // keep file alive while the counter is alive

  auto bind_progress_bar = [&](auto& m, auto pv, const char* name) {
    bind_display(m, ProgressBar_<decltype(pv)>(), decltype(pv)(), name);
  };

  bind_progress_bar(m, Int(), "IntProgressBar");
  bind_progress_bar(m, Float(), "FloatProgressBar");
  bind_progress_bar(m, AtomicInt(), "AtomicIntProgressBar");
#if BARKEEP_ENABLE_ATOMIC_FLOAT
  bind_progress_bar(m, AtomicFloat(), "AtomicFloatProgressBar");
#endif

  // Factory function for all instantiations of ProgressBar_
  m.def(
      "ProgressBar",
      [](double value, // TODO: Make value match the specified dtype
         double total,
         py::object file,
         std::string msg,
         std::optional<double> interval,
         std::variant<ProgressBarStyle, BarParts> style,
         std::optional<double> speed,
         std::string speed_unit,
         std::optional<std::string> fmt,
         bool no_tty,
         DType dtype,
         bool show) -> std::shared_ptr<BaseDisplay> {
        auto make_progress_bar = [&](auto pv) {
          using T = decltype(pv);
          auto bar = std::make_shared<ProgressBar_<T>>(file,
                                                       total,
                                                       fmt.value_or(""),
                                                       msg,
                                                       speed,
                                                       speed_unit,
                                                       style,
                                                       interval.value_or(0.),
                                                       no_tty);
          *bar->work = value;
          if (show) { bar->show(); }
          return bar;
        };

        switch (dtype) {
        case DType::Int: return make_progress_bar(Int());
        case DType::Float: return make_progress_bar(Float());
        case DType::AtomicInt: return make_progress_bar(AtomicInt());
#if BARKEEP_ENABLE_ATOMIC_FLOAT
        case DType::AtomicFloat: return make_progress_bar(AtomicFloat());
#endif
        default: throw std::runtime_error("Unknown dtype"); return {};
        }
      },
      R"docstr(
        Displays a progress bar, by comparing the progress value being monitored to
        a given total value.

        Parameters
        ----------
        value : int or float, optional
            Initial value of the progress bar value. Defaults to 0.
        total : int or float, optional
            Total value of the bar. Defaults to 100.
        file : file-like object, optional
            File to write to. Defaults to stdout.
        message : str, optional
            Message to display. Defaults to "".
        interval : float, optional
            Interval between frames in seconds. If None, defaults to 1 if
            not no_tty, 60 otherwise.
        style : ProgressBarStyle, optional
            Progress bar style. Defaults to ProgressBarStyle.Blocks.
        speed : float, optional
            Discount factor in [0, 1] to use in computing the speed.
            Previous increments are weighted by (1-discount).
            If discount is 0, all increments are weighted equally.
            If discount is 1, only the most recent increment is
            considered. If discount is None (default), speed is not
            computed.
        speed_unit : str, optional
            Unit of speed. Defaults to "".
        fmt : str, optional
            Set formatting string to be used to display the message and speed.
            If provided, message and speed_unit are ignored.
        no_tty : bool, optional
            If True, use no-tty mode (no \r, slower refresh). Defaults to False.
        dtype : DType, optional
            Data type of the value. Defaults to DType.Int.
        show : bool, optional
            If True, show the progress bar immediately. Defaults to True.
       )docstr",
      "value"_a = 0,
      "total"_a = 100,
      "file"_a = py::none(),
      "message"_a = "",
      "interval"_a = py::none(),
      "style"_a = ProgressBarStyle::Blocks,
      "speed"_a = py::none(),
      "speed_unit"_a = "",
      "fmt"_a = py::none(),
      "no_tty"_a = false,
      "dtype"_a = DType::Int,
      "show"_a = true,
      py::keep_alive<0, 3>()); // keep file alive while the bar is alive

  py::class_<CompositeDisplay, std::shared_ptr<CompositeDisplay>, BaseDisplay>(
      m, "Composite");

  base_display.def("__or__",
                   [](std::shared_ptr<BaseDisplay> self,
                      std::shared_ptr<BaseDisplay> other) {
                     if (self->running() or other->running()) {
                       throw std::runtime_error(
                           "Cannot combine running AsyncDisplay objects!");
                     }
                     return Composite({self, other});
                   });
}