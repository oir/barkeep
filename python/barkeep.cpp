#include <barkeep/barkeep.h>
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

class PyFileStream : public std::stringbuf, public std::ostream {
 private:
  py::object file_;

  int sync() override {
    py::gil_scoped_acquire acquire;
    file_.attr("write")(str());
    file_.attr("flush")();
    str("");
    return 0;
  }

 public:
  PyFileStream(py::object file) : std::stringbuf(), std::ostream(this), file_(std::move(file)) {}
};

template <typename T>
class Counter_ : public Counter<T> {
 protected:
  using Counter<T>::render_;
  using Counter<T>::default_interval_;

 public:
  std::unique_ptr<T> work = std::make_unique<T>(0);
  std::unique_ptr<PyFileStream> file_ = nullptr;

  Counter_(py::object file = py::none()) {
    if (file.is_none()) {
      this->init(&*work, &std::cout);
    } else {
      file_ = std::make_unique<PyFileStream>(std::move(file));
      this->init(&*work, &*file_);
    }
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
};

template <typename T>
std::unique_ptr<AsyncDisplay> make_counter(value_t<T> value,
                        py::object file,
                        std::string msg,
                        double interval,
                        std::optional<double> discount,
                        std::string speed_unit) {
  auto counter = std::make_unique<Counter_<T>>(file);
  *counter->work = value;
  counter->message(msg);
  counter->interval(interval);
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
      .def(
          "__iadd__",
          [](Counter_<T>* c, value_t<T> v) {
            *c->work += v;
            return c;
          },
          py::is_operator());
}

template <typename T>
class ProgressBar_ : public ProgressBar<T> {
 protected:
  using ProgressBar<T>::render_;
  using ProgressBar<T>::default_interval_;

 public:
  std::shared_ptr<T> work = std::make_shared<T>(0);
  ProgressBar_() { this->init(&*work, &std::cout); }
};

template <typename T>
py::object make_progress_bar(value_t<T> value,
                             value_t<T> total,
                             std::string msg,
                             double interval,
                             ProgressBarStyle style,
                             std::optional<double> discount,
                             std::string speed_unit) {
  ProgressBar_<T> bar;
  *bar.work = value;
  bar.total(total);
  bar.message(msg);
  bar.interval(interval);
  bar.style(style);
  bar.speed(discount);
  bar.speed_unit(speed_unit);
  return py::cast(bar);
};

template <typename T>
void bind_template_progress_bar(py::module& m, char const* name) {
  py::class_<ProgressBar_<T>, AsyncDisplay>(m, name)
      .def_property(
          "work",
          [](ProgressBar_<T>& c) -> value_t<T> { return *c.work; },
          [](ProgressBar_<T>& c, value_t<T> v) { *c.work = v; })
      .def(
          "__iadd__",
          [](ProgressBar_<T>* c, value_t<T> v) {
            *c->work += v;
            return c;
          },
          py::is_operator());
}

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
      .value("Bar", ProgressBarStyle::Bars)
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

  py::class_<Animation, AsyncDisplay>(m, "Animation")
      .def(py::init([](std::string msg, double interval, AnimationStyle style) {
             return Animation().message(msg).interval(interval).style(style);
           }),
           "message"_a = "",
           "interval"_a = 1.,
           "style"_a = AnimationStyle::Ellipsis);

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
         double interval,
         std::optional<double> speed,
         std::string speed_unit,
         DType dtype) -> std::unique_ptr<AsyncDisplay> {
        std::unique_ptr<AsyncDisplay> rval;
        switch (dtype) {
        case DType::Int:
          rval = make_counter<Int>(value, file, msg, interval, speed, speed_unit);
          break;
        case DType::Float:
          rval = make_counter<Float>(value, file, msg, interval, speed, speed_unit);
          break;
        case DType::AtomicInt:
          rval = make_counter<AtomicInt>(
              value, file, msg, interval, speed, speed_unit);
              break;
        case DType::AtomicFloat:
          rval = make_counter<AtomicFloat>(
              value, file, msg, interval, speed, speed_unit);
              break;
        default: throw std::runtime_error("Unknown dtype");
        }

        return rval;
      },
      "value"_a = 0,
      "file"_a = py::none(),
      "message"_a = "",
      "interval"_a = 1.,
      "speed"_a = py::none(),
      "speed_unit"_a = "",
      "dtype"_a = DType::Int,
      py::keep_alive<0, 2>());

  bind_template_progress_bar<Int>(m, "IntProgressBar");
  bind_template_progress_bar<Float>(m, "FloatProgressBar");
  bind_template_progress_bar<AtomicInt>(m, "AtomicIntProgressBar");
  bind_template_progress_bar<AtomicFloat>(m, "AtomicFloatProgressBar");

  // Factory function for all instantiations of ProgressBar_

  m.def(
      "ProgressBar",
      [](double value, // TODO: Make value match the specified dtype
         double total,
         std::string msg,
         double interval,
         ProgressBarStyle style,
         std::optional<double> speed,
         std::string speed_unit,
         DType dtype) -> py::object {
        switch (dtype) {
        case DType::Int:
          return make_progress_bar<Int>(
              value, total, msg, interval, style, speed, speed_unit);
        case DType::Float:
          return make_progress_bar<Float>(
              value, total, msg, interval, style, speed, speed_unit);
        case DType::AtomicInt:
          return make_progress_bar<AtomicInt>(
              value, total, msg, interval, style, speed, speed_unit);
        case DType::AtomicFloat:
          return make_progress_bar<AtomicFloat>(
              value, total, msg, interval, style, speed, speed_unit);
        default: throw std::runtime_error("Unknown dtype"); return py::none();
        }
      },
      "value"_a = 0,
      "total"_a = 100,
      "message"_a = "",
      "interval"_a = 0.1,
      "style"_a = ProgressBarStyle::Blocks,
      "speed"_a = py::none(),
      "speed_unit"_a = "",
      "dtype"_a = DType::Int);

  py::class_<Composite, AsyncDisplay>(m, "Composite");

  async_display.def("__or__",
                    [](AsyncDisplay& self, const AsyncDisplay& other) {
                      return Composite(self.clone(), other.clone());
                    });

  m.def("say_hi", [](py::object handle) {
    //handle.attr("write")("Hello from C++!\n");
    PyFileStream stream(handle);
    ((std::ostream&)stream) << "Hello from C++!\n" << std::flush;
  });
}