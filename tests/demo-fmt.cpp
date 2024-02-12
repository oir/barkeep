#include <atomic>
#include <iostream>

#define FMT_HEADER_ONLY
#ifndef BARKEEP_ENABLE_FMT
#define BARKEEP_ENABLE_FMT
#endif
#include <barkeep/barkeep.h>

int main(int /*argc*/, char** /*argv*/) {
  using namespace std::chrono_literals;
  namespace bk = barkeep;

  for (double speed : {0., 0.1, 1.}) {
    for (
        std::string fmtstr : {
            "Picked up {value} flowers, at a speed of {speed:.1f} flowers per second",
            "Picked up {blue}{value}{reset} flowers, at a speed of {green}{speed:.1f}{reset} flowers per second",
        }) {
      int work{0};
      auto c = bk::Counter(&work).fmt(fmtstr).speed(speed);
      c.show();
      for (int i = 0; i < 1010; i++) {
        std::this_thread::sleep_for(13ms);
        work++;
      }
      c.done();
    }
  }

  for (double speed : {0., 0.1, 1.}) {
    for (
        std::string fmtstr : {
            "Picking flowers {value:4d}/1010  {bar}  ({speed:.1f} flo/s)",
            "Picking flowers {blue}{value:4d}/1010  {green}{bar} {yellow}{percent:3.0f}%{reset}  ({speed:.1f} flo/s)",
        }) {
      std::atomic<size_t> work{0};
      auto bar = bk::ProgressBar(&work).total(1010).fmt(fmtstr).speed(speed);
      bar.show();
      for (int i = 0; i < 1010; i++) {
        std::this_thread::sleep_for(13ms);
        work++;
      }
      bar.done();
    }
  }
}