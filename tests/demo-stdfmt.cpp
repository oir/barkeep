#include <atomic>
#include <iostream>

#undef BARKEEP_ENABLE_FMT_FORMAT
#ifndef BARKEEP_ENABLE_STD_FORMAT
#define BARKEEP_ENABLE_STD_FORMAT
#endif

#include <barkeep/barkeep.h>

int main(int /*argc*/, char** /*argv*/) {
  using namespace std::chrono_literals;
  namespace bk = barkeep;

  for (double speed : {0., 0.1, 1.}) {
    for (
        std::string fmtstr : {
            "Picked up {0} flowers, at a speed of {1:.1f} flowers per second",
            "Picked up {5}{0}{8} flowers, at a speed of {3}{1:.1f}{8} flowers per second",
        }) {
      int work{0};
      auto c = bk::Counter(&work, {.format = fmtstr, .speed = speed});
      c.show();
      for (int i = 0; i < 1010; i++) {
        std::this_thread::sleep_for(13ms);
        work++;
      }
      c.done();
    }
  }

}
