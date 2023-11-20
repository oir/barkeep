#include <meanwhile/meanwhile.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;
using namespace mew;
using namespace py::literals;

using Int = std::int64_t;
using AtomicInt = std::atomic<Int>;
using Float = double;
using AtomicFloat = std::atomic<Float>; // Requires C++20 AND gcc (tested with
                                        // gcc11) (clang 15.0.0 did not work)

enum class DType { Int, Float, AtomicInt, AtomicFloat };

template <typename T>
class Counter_ : public Counter<T> {
 protected:
  using Counter<T>::render_;
  using Counter<T>::default_interval_;

 public:
  std::shared_ptr<T> work = std::make_shared<T>(0);
  Counter_() { this->init(&*work); }
};

template <typename T>
py::object make_counter(value_t<T> value,
                        std::string msg,
                        double interval,
                        Speed speed,
                        std::string speed_unit) {
  Counter_<T> counter;
  *counter.work = value;
  counter.message(msg);
  counter.interval(interval);
  counter.speed(speed);
  counter.speed_unit(speed_unit);
  return py::cast(counter);
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
  ProgressBar_() { this->init(&*work); }
};

template <typename T>
py::object make_progress_bar(value_t<T> value,
                             value_t<T> total,
                             std::string msg,
                             double interval,
                             ProgressBarStyle style,
                             Speed speed,
                             std::string speed_unit) {
  ProgressBar_<T> bar;
  *bar.work = value;
  bar.total(total);
  bar.message(msg);
  bar.interval(interval);
  bar.style(style);
  bar.speed(speed);
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

// class Composite_ : public OwningDisplay {
//  protected:
//   std::unique_ptr<OwningDisplay> left_, right_;
//  public:
//   mew::Composite composite_;
//
//   AsyncDisplay& impl() override { return composite_; }
//
//   Composite_(std::unique_ptr<OwningDisplay> left,
//              std::unique_ptr<OwningDisplay> right)
//       : left_(std::move(left)), right_(std::move(right)),
//       composite_(left_->impl(), right_->impl()) {}
// };

PYBIND11_MODULE(mewpy, m) {
  m.doc() = "Python bindings for meanwhile";

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

  py::enum_<Speed>(m, "Speed")
      .value("No", Speed::None)
      .value("Last", Speed::Last)
      .value("Overall", Speed::Overall)
      .export_values();

  py::enum_<DType>(m, "DType")
      .value("Int", DType::Int)
      .value("Float", DType::Float)
      .value("AtomicInt", DType::AtomicInt)
      .value("AtomicFloat", DType::AtomicFloat)
      .export_values();

  py::class_<AsyncDisplay>(m, "AsyncDisplay")
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
         std::string msg,
         double interval,
         Speed speed,
         std::string speed_unit,
         DType dtype) -> py::object {
        switch (dtype) {
        case DType::Int:
          return make_counter<Int>(value, msg, interval, speed, speed_unit);
        case DType::Float:
          return make_counter<Float>(value, msg, interval, speed, speed_unit);
        case DType::AtomicInt:
          return make_counter<AtomicInt>(
              value, msg, interval, speed, speed_unit);
        case DType::AtomicFloat:
          return make_counter<AtomicFloat>(
              value, msg, interval, speed, speed_unit);
        default: throw std::runtime_error("Unknown dtype"); return py::none();
        }
      },
      "value"_a = 0,
      "message"_a = "",
      "interval"_a = 1.,
      "speed"_a = Speed::None,
      "speed_unit"_a = "",
      "dtype"_a = DType::Int);

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
         Speed speed,
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
      "interval"_a = 1.,
      "style"_a = ProgressBarStyle::Blocks,
      "speed"_a = Speed::None,
      "speed_unit"_a = "",
      "dtype"_a = DType::Int);
}