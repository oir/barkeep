// Author: Ozan Irsoy

#include <atomic>
#include <iostream>
#include <barkeep/barkeep.h>

int main(int /*argc*/, char** /*argv*/) {
  using namespace std::chrono_literals;
  namespace bk = barkeep;

  for (auto sty : {bk::Ellipsis, bk::Bar, bk::Moon}) {
    auto anim = bk::Animation().message("Working").style(sty).interval(0.5s);
    anim.show();
    std::this_thread::sleep_for(10s);
    anim.done();
  }

  std::vector<std::optional<double>> speeds{std::nullopt, 0, 0.1, 1};
  for (auto speed : speeds) {
    std::atomic<size_t> work{0};
    auto c = bk::Counter(&work)
                 .message("Doing stuff")
                 .speed_unit("tk/s")
                 .speed(speed);
    c.show();
    for (int i = 0; i < 1010; i++) {
      std::this_thread::sleep_for(13ms);
      work++;
    }
    c.done();
  }

  for (auto speed : speeds) {
    float work{0};
    auto c = bk::Counter(&work)
                 .message("Doing stuff")
                 .speed_unit("tk/s")
                 .speed(speed);
    c.show();
    for (int i = 0; i < 1010; i++) {
      std::this_thread::sleep_for(13ms);
      work += 0.213;
    }
    c.done();
  }

  for (auto speed : speeds) {
    unsigned long long work{677};
    auto c =
        bk::Counter(&work).message("Decreasing").speed_unit("").speed(speed);
    c.show();
    while (work > 0) {
      std::this_thread::sleep_for(13ms);
      work--;
    }
    // Let destructor do the c.done() this time
  }

  for (auto speed : speeds) {
    for (auto sty : {bk::Blocks, bk::Bars, bk::Arrow}) {
      std::atomic<size_t> work{0};
      auto bar = bk::ProgressBar(&work)
                     .total(1010)
                     .message("Doing stuff")
                     .speed_unit("tk/s")
                     .style(sty)
                     .speed(speed);
      bar.show();
      for (int i = 0; i < 1010; i++) {
        std::this_thread::sleep_for(13ms);
        work++;
      }
      bar.done();
    }
  }

  { // Decreasing progress
    unsigned long work{1010};
    auto bar = bk::ProgressBar(&work).total(1010).speed(1);
    bar.show();
    for (int i = 0; i < 1010; i++) {
      std::this_thread::sleep_for(13ms);
      work--;
    }
    bar.done();
  }

  { // Composite display of a ProgressBar and Counter. We want to measure
    // completion in terms of #sentences but we are also interested in speed
    // in terms of tokens per second.'
    std::atomic<size_t> sents{0}, toks{0};
    auto bar = bk::ProgressBar(&sents).total(1010).message("Sents").speed(1) |
               bk::Counter(&toks).message("Toks").speed(1);
    bar.show();
    for (int i = 0; i < 1010; i++) {
      std::this_thread::sleep_for(13ms);
      sents++;
      toks += (1 + size_t(rand()) % 5);
    }
    bar.done();
  }

  { // Composite display of three counters
    std::atomic<size_t> squares{0}, cubes{0}, hypercubes{0};
    auto counters = bk::Counter(&squares).message("Squares").speed(0.1) |
                    bk::Counter(&cubes).message("Cubes").speed(0.1) |
                    bk::Counter(&hypercubes).message("Hypercubes").speed(0.1);
    counters.show();
    for (int i = 0; i < 1010; i++) {
      std::this_thread::sleep_for(13ms);
      squares += (1 + size_t(rand()) % 5);
      cubes += (1 + size_t(rand()) % 10);
      hypercubes += (1 + size_t(rand()) % 20);
    }
    counters.done();
  }

  std::cout << "\nWarning: To illustrate infrequent writes, no-tty"
               " demos take long (several minutes)... 😅"
            << std::endl;

  { // Progress bar with no-tty mode
    std::atomic<size_t> sents{0}, toks{0};
    auto bar =
        bk::ProgressBar(&sents).total(20100).message("Sents").speed(1).no_tty();
    bar.show();
    for (int i = 0; i < 20100; i++) {
      std::this_thread::sleep_for(13ms);
      sents++;
      toks += (1 + size_t(rand()) % 5);
    }
    bar.done();
  }

  { // Composite display of a ProgressBar and Counter with no-tty mode
    std::atomic<size_t> sents{0}, toks{0};
    auto bar = bk::ProgressBar(&sents).total(20100).message("Sents") |
               bk::Counter(&toks).message("Toks").speed_unit("tok/s").speed(1);
    bar.no_tty();
    bar.show();
    for (int i = 0; i < 20100; i++) {
      std::this_thread::sleep_for(13ms);
      sents++;
      toks += (1 + size_t(rand()) % 5);
    }
    bar.done();
  }

  return 0;
}
