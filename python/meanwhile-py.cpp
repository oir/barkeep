#include <meanwhile/meanwhile.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

class Counter_ {
 public:
  std::shared_ptr<int> work = std::make_shared<int>(0);
  mew::Counter<int> counter_;
  Counter_() : counter_(*work) {}
};

PYBIND11_MODULE(mewpy, m) {
  using namespace mew;
  using namespace py::literals;

  m.doc() = "Python bindings for meanwhile";

  py::enum_<AnimationStyle>(m, "AnimationStyle")
      .value("Ellipsis", AnimationStyle::Ellipsis)
      .value("Clock", AnimationStyle::Clock)
      .value("Moon", AnimationStyle::Moon)
      .value("Earth", AnimationStyle::Earth)
      .value("Bar", AnimationStyle::Bar)
      .value("Square", AnimationStyle::Square)
      .export_values();

  py::class_<Animation>(m, "Animation")
      .def(py::init([](std::string msg, double interval, AnimationStyle style) {
             return Animation().message(msg).interval(interval).style(style);
           }),
           "message"_a = "",
           "interval"_a = 1.,
           "style"_a = AnimationStyle::Ellipsis)
      .def("show", &Animation::show)
      .def("done", &Animation::done);

  py::class_<Counter_>(m, "Counter")
      .def(py::init([](std::string msg, double interval) {
             auto c = Counter_();
             c.counter_.message(msg);
             c.counter_.interval(interval);
             return c;
           }),
           "message"_a = "",
           "interval"_a = 1.)
      .def("show", [](Counter_& c) { c.counter_.show(); })
      .def("done", [](Counter_& c) { c.counter_.done(); })
      .def_property(
          "work",
          [](Counter_& c) { return *c.work; },
          [](Counter_& c, int v) { *c.work = v; });

}