#include <pybind11/operators.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#ifndef BARKEEP_ENABLE_FMT
#define BARKEEP_ENABLE_FMT
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

#include <iostream>

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

class Animation_ : public Animation {
 public:
  std::shared_ptr<PyFileStream> file_ = nullptr;

  Animation_(py::object file = py::none(),
             std::string message = "",
             AnimationStyle style = Ellipsis,
             double interval = 0.,
             bool no_tty = false)
      : Animation({.out = nullptr,
                   .message = message,
                   .style = style,
                   .interval = interval,
                   .no_tty = no_tty}) {
    if (not file.is_none()) {
      file_ = std::make_shared<PyFileStream>(std::move(file));
    }
    out_ = file_ ? (std::ostream*)file_.get() : &std::cout;
  }

  void join() override {
    if (file_) {
      // release gil because displayer thread needs it to write
      py::gil_scoped_release release;
      AsyncDisplay::join();
    } else {
      AsyncDisplay::join();
    }
  }

  std::unique_ptr<AsyncDisplay> clone() const override {
    return std::make_unique<Animation_>(*this);
  }
};

template <typename T>
class Counter_ : public Counter<T> {
 protected:
  using Counter<T>::render_;
  using Counter<T>::default_interval_;

 public:
  std::shared_ptr<T> work = std::make_shared<T>(0);
  std::shared_ptr<PyFileStream> file_ = nullptr;

  Counter_(py::object file = py::none(),
           std::string format = "",
           std::string message = "",
           std::optional<double> speed = std::nullopt,
           std::string speed_unit = "it/s",
           double interval = 0.,
           bool no_tty = false) 
           : Counter<T>(nullptr, {.out = nullptr,
                         .format = format,
                         .message = message,
                         .speed = std::nullopt,
                         .speed_unit = speed_unit,
                         .interval = interval,
                         .no_tty = no_tty}) {
    if (speed) {
      this->speedom_ = std::make_unique<Speedometer<T>>(*work.get(), *speed);
    }
    if (not file.is_none()) {
      file_ = std::make_shared<PyFileStream>(std::move(file));
    }
    this->progress_ = work.get();
    assert(this->progress_ != nullptr);
    this->out_ = file_ ? (std::ostream*)file_.get() : &std::cout;
    assert(this->out_ != nullptr);
  }

  void join() override {
    if (file_) {
      // release gil because displayer thread needs it to write
      py::gil_scoped_release release;
      AsyncDisplay::join();
    } else {
      AsyncDisplay::join();
    }
  }

  std::unique_ptr<AsyncDisplay> clone() const override {
    return std::make_unique<Counter_>(*this);
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
class ProgressBar_ : public ProgressBar<T> {
 protected:
  using ProgressBar<T>::render_;
  using ProgressBar<T>::default_interval_;

 public:
  std::shared_ptr<T> work = std::make_shared<T>(0);
  std::shared_ptr<PyFileStream> file_ = nullptr;

  ProgressBar_(py::object file = py::none(),
               value_t<T> total = 100,
               std::string format = "",
               std::string message = "",
               std::optional<double> speed = std::nullopt,
               std::string speed_unit = "it/s",
               ProgressBarStyle style = Blocks,
               double interval = 0.,
               bool no_tty = false) 
        : ProgressBar<T>(nullptr, {.out = nullptr,
                         .total = total,
                         .format = format,
                         .message = message,
                         .speed = std::nullopt,
                         .speed_unit = speed_unit,
                         .style = style,
                         .interval = interval,
                         .no_tty = no_tty}) {
    if (speed) {
      this->speedom_ = std::make_unique<Speedometer<T>>(*work.get(), *speed);
    }
    if (not file.is_none()) {
      file_ = std::make_shared<PyFileStream>(std::move(file));
    }
    this->progress_ = work.get();
    assert(this->progress_ != nullptr);
    this->out_ = file_ ? (std::ostream*)file_.get() : &std::cout;
    assert(this->out_ != nullptr);
  }

  void join() override {
    if (file_) {
      // release gil because displayer thread needs it to write
      py::gil_scoped_release release;
      AsyncDisplay::join();
    } else {
      AsyncDisplay::join();
    }
  }

  std::unique_ptr<AsyncDisplay> clone() const override {
    return std::make_unique<ProgressBar_>(*this);
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

class Composite_ : public Composite {
 public:
  using Composite::Composite;

  void join() override {
    py::gil_scoped_release release;
    AsyncDisplay::join();
  }
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
      .value("Square", AnimationStyle::Square)
      .export_values();

  py::enum_<ProgressBarStyle>(m, "ProgressBarStyle")
      .value("Bars", ProgressBarStyle::Bars)
      .value("Blocks", ProgressBarStyle::Blocks)
      .value("Arrow", ProgressBarStyle::Arrow)
      .export_values();

  py::enum_<DType>(m, "DType")
      .value("Int", DType::Int)
      .value("Float", DType::Float)
      .value("AtomicInt", DType::AtomicInt)
#if BARKEEP_ENABLE_ATOMIC_FLOAT
      .value("AtomicFloat", DType::AtomicFloat)
#endif
      .export_values();

  auto async_display = py::class_<AsyncDisplay>(m, "AsyncDisplay")
                           .def("show", &AsyncDisplay::show)
                           .def("done", &AsyncDisplay::done);

  py::class_<Animation_, AsyncDisplay>(m, "Animation")
      .def(py::init([](py::object file,
                       std::string msg,
                       double interval,
                       AnimationStyle style,
                       bool no_tty) {
             return Animation_(file, msg, style, interval, no_tty);
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
           )docstr",
           "file"_a = py::none(),
           "message"_a = "",
           "interval"_a = 1.,
           "style"_a = AnimationStyle::Ellipsis,
           "no_tty"_a = false,
           py::keep_alive<0, 1>()); // keep file alive while the animation is
                                    // alive);

  auto bind_display = [&](auto& m, auto disp, auto pv, const char* name) {
    using T = decltype(pv);
    using Disp = decltype(disp);
    py::class_<Disp, AsyncDisplay>(m, name)
        .def_property(
            "value",
            [](Disp& c) -> value_t<T> { return *c.work; },
            [](Disp& c, value_t<T> v) { *c.work = v; })
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
         DType dtype) -> std::unique_ptr<AsyncDisplay> {
        std::unique_ptr<AsyncDisplay> rval;

        auto make_counter = [&](auto pv) {
          using T = decltype(pv);
          auto c = std::make_unique<Counter_<T>>(file,
                                                 fmt.value_or(""),
                                                 msg,
                                                 speed,
                                                 speed_unit,
                                                 interval.value_or(0.),
                                                 no_tty);
          *c->work = value;
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
         ProgressBarStyle style,
         std::optional<double> speed,
         std::string speed_unit,
         std::optional<std::string> fmt,
         bool no_tty,
         DType dtype) -> std::unique_ptr<AsyncDisplay> {
        auto make_progress_bar = [&](auto pv) {
          using T = decltype(pv);
          auto bar = std::make_unique<ProgressBar_<T>>(file,
                                                       total,
                                                       fmt.value_or(""),
                                                       msg,
                                                       speed,
                                                       speed_unit,
                                                       style,
                                                       interval.value_or(0.),
                                                       no_tty);
          *bar->work = value;
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
      py::keep_alive<0, 3>()); // keep file alive while the bar is alive

  py::class_<Composite_, AsyncDisplay>(m, "Composite");

  async_display.def("__or__", [](AsyncDisplay& self, AsyncDisplay& other) {
    if (self.running() or other.running()) {
      // not sure why this is necessary, but it prevents segfaults.
      // maybe pybind11 implicit copies are causing problems when destructor
      // attempts a done() ?
      self.done();
      other.done();
      throw std::runtime_error("Cannot combine running AsyncDisplay objects!");
    }
    return Composite_(self.clone(), other.clone());
  });
}