#include <barkeep/barkeep.h>
#include <pybind11/operators.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;
using namespace barkeep;
using namespace py::literals;

using Int = std::int64_t;
using AtomicInt = std::atomic<Int>;
using Float = double;
using AtomicFloat = std::atomic<Float>; // Requires C++20 AND gcc (tested with
                                        // gcc11) (clang 15.0.0 did not work)

enum class DType { Int, Float, AtomicInt, AtomicFloat };

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

  Animation_(py::object file = py::none()) {
    if (not file.is_none()) {
      file_ = std::make_shared<PyFileStream>(std::move(file));
    }
    out_ = file_ ? (std::ostream*)&*file_ : &std::cout;
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

  void init() {
    Counter<T>::init(&*work, file_ ? (std::ostream*)&*file_ : &std::cout);
  }

 public:
  std::shared_ptr<T> work = std::make_shared<T>(0);
  std::shared_ptr<PyFileStream> file_ = nullptr;

  Counter_(py::object file = py::none()) {
    if (not file.is_none()) {
      file_ = std::make_shared<PyFileStream>(std::move(file));
    }
    init();
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
std::unique_ptr<AsyncDisplay> make_counter(value_t<T> value,
                                           py::object file,
                                           std::string msg,
                                           std::optional<double> interval,
                                           std::optional<double> discount,
                                           std::string speed_unit) {
  auto counter = std::make_unique<Counter_<T>>(file);
  *counter->work = value;
  counter->message(msg);
  if (interval) { counter->interval(*interval); }
  counter->speed(discount);
  counter->speed_unit(speed_unit);
  return counter;
};

template <typename T>
void bind_template_counter(py::module& m, char const* name) {
  py::class_<Counter_<T>, AsyncDisplay>(m, name)
      .def_property(
          "work",
          [](Counter_<T>& c) -> value_t<T> { return *c.work; },
          [](Counter_<T>& c, value_t<T> v) { *c.work = v; })
      .def(py::self += value_t<T>())
      .def(py::self -= value_t<T>())
      .def(py::self > value_t<T>())
      .def(py::self < value_t<T>())
      .def(py::self >= value_t<T>())
      .def(py::self <= value_t<T>())
      .def(py::self == value_t<T>())
      .def(py::self != value_t<T>());
}

template <typename T>
class ProgressBar_ : public ProgressBar<T> {
 protected:
  using ProgressBar<T>::render_;
  using ProgressBar<T>::default_interval_;

  void init() {
    ProgressBar<T>::init(&*work, file_ ? (std::ostream*)&*file_ : &std::cout);
  }

 public:
  std::shared_ptr<T> work = std::make_shared<T>(0);
  std::shared_ptr<PyFileStream> file_ = nullptr;

  ProgressBar_(py::object file = py::none()) {
    if (not file.is_none()) {
      file_ = std::make_shared<PyFileStream>(std::move(file));
    }
    init();
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

template <typename T>
std::unique_ptr<AsyncDisplay> make_progress_bar(value_t<T> value,
                                                value_t<T> total,
                                                py::object file,
                                                std::string msg,
                                                std::optional<double> interval,
                                                ProgressBarStyle style,
                                                std::optional<double> discount,
                                                std::string speed_unit) {
  auto bar = std::make_unique<ProgressBar_<T>>(file);
  *bar->work = value;
  bar->total(total);
  bar->message(msg);
  if (interval) { bar->interval(*interval); }
  bar->style(style);
  bar->speed(discount);
  bar->speed_unit(speed_unit);
  return bar;
};

template <typename T>
void bind_template_progress_bar(py::module& m, char const* name) {
  py::class_<ProgressBar_<T>, AsyncDisplay>(m, name)
      .def_property(
          "work",
          [](ProgressBar_<T>& c) -> value_t<T> { return *c.work; },
          [](ProgressBar_<T>& c, value_t<T> v) { *c.work = v; })
      .def(py::self += value_t<T>())
      .def(py::self -= value_t<T>())
      .def(py::self > value_t<T>())
      .def(py::self < value_t<T>())
      .def(py::self >= value_t<T>())
      .def(py::self <= value_t<T>())
      .def(py::self == value_t<T>())
      .def(py::self != value_t<T>());
}

class Composite_ : public Composite {
 public:
  using Composite::Composite;

  void join() override {
    py::gil_scoped_release release;
    AsyncDisplay::join();
  }
};

PYBIND11_MODULE(barkeep, m) {
  m.doc() = "Python bindings for barkeep";

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
      .value("AtomicFloat", DType::AtomicFloat)
      .export_values();

  auto async_display = py::class_<AsyncDisplay>(m, "AsyncDisplay")
                           .def("show", &AsyncDisplay::show)
                           .def("done", &AsyncDisplay::done);

  py::class_<Animation_, AsyncDisplay>(m, "Animation")
      .def(py::init([](py::object file,
                       std::string msg,
                       double interval,
                       AnimationStyle style) {
             Animation_ a(file);
             a.message(msg);
             a.interval(interval);
             a.style(style);
             return a;
           }),
           "file"_a = py::none(),
           "message"_a = "",
           "interval"_a = 1.,
           "style"_a = AnimationStyle::Ellipsis,
           py::keep_alive<0, 1>()); // keep file alive while the animation is
                                    // alive);

  bind_template_counter<Int>(m, "IntCounter");
  bind_template_counter<Float>(m, "FloatCounter");
  bind_template_counter<AtomicInt>(m, "AtomicIntCounter");
  bind_template_counter<AtomicFloat>(m, "AtomicFloatCounter");

  // Factory function for all instantiations of Counter_

  m.def(
      "Counter",
      [](double value, // TODO: Make value match the specified dtype
         py::object file,
         std::string msg,
         std::optional<double> interval,
         std::optional<double> speed,
         std::string speed_unit,
         DType dtype) -> std::unique_ptr<AsyncDisplay> {
        std::unique_ptr<AsyncDisplay> rval;
        switch (dtype) {
        case DType::Int:
          return make_counter<Int>(
              value, file, msg, interval, speed, speed_unit);
        case DType::Float:
          return make_counter<Float>(
              value, file, msg, interval, speed, speed_unit);
        case DType::AtomicInt:
          return make_counter<AtomicInt>(
              value, file, msg, interval, speed, speed_unit);
        case DType::AtomicFloat:
          return make_counter<AtomicFloat>(
              value, file, msg, interval, speed, speed_unit);
        default: throw std::runtime_error("Unknown dtype"); return {};
        }
      },
      "value"_a = 0,
      "file"_a = py::none(),
      "message"_a = "",
      "interval"_a = py::none(),
      "speed"_a = py::none(),
      "speed_unit"_a = "",
      "dtype"_a = DType::Int,
      py::keep_alive<0, 2>()); // keep file alive while the counter is alive

  bind_template_progress_bar<Int>(m, "IntProgressBar");
  bind_template_progress_bar<Float>(m, "FloatProgressBar");
  bind_template_progress_bar<AtomicInt>(m, "AtomicIntProgressBar");
  bind_template_progress_bar<AtomicFloat>(m, "AtomicFloatProgressBar");

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
         DType dtype) -> std::unique_ptr<AsyncDisplay> {
        switch (dtype) {
        case DType::Int:
          return make_progress_bar<Int>(
              value, total, file, msg, interval, style, speed, speed_unit);
        case DType::Float:
          return make_progress_bar<Float>(
              value, total, file, msg, interval, style, speed, speed_unit);
        case DType::AtomicInt:
          return make_progress_bar<AtomicInt>(
              value, total, file, msg, interval, style, speed, speed_unit);
        case DType::AtomicFloat:
          return make_progress_bar<AtomicFloat>(
              value, total, file, msg, interval, style, speed, speed_unit);
        default: throw std::runtime_error("Unknown dtype"); return {};
        }
      },
      "value"_a = 0,
      "total"_a = 100,
      "file"_a = py::none(),
      "message"_a = "",
      "interval"_a = py::none(),
      "style"_a = ProgressBarStyle::Blocks,
      "speed"_a = py::none(),
      "speed_unit"_a = "",
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