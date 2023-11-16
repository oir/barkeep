// Author: Ozan Irsoy

#include <atomic>
#include <iostream>
#include <meanwhile/meanwhile.h>

int main(int /*argc*/, char** /*argv*/) {
  using namespace std::chrono_literals;
  using namespace mew;

  for (auto sty : {Ellipsis, Bar, Moon, Square}) {
    auto anim = Animation().message("Working").style(sty).interval(0.5s);
    anim.show();
    std::this_thread::sleep_for(10s);
    anim.done();
  }

  for (auto speed : {Speed::None, Speed::Overall, Speed::Last, Speed::Both}) {
    std::atomic<size_t> work{0};
    auto c =
        Counter(work).message("Doing stuff").speed_unit("tk/s").speed(speed);
    c.show();
    for (int i = 0; i < 1010; i++) {
      std::this_thread::sleep_for(13ms);
      work++;
    }
    c.done();
  }

  for (auto speed : {Speed::None, Speed::Overall, Speed::Last, Speed::Both}) {
    float work{0};
    auto c =
        Counter(work).message("Doing stuff").speed_unit("tk/s").speed(speed);
    c.show();
    for (int i = 0; i < 1010; i++) {
      std::this_thread::sleep_for(13ms);
      work += 0.213;
    }
    c.done();
  }

  for (auto speed : {Speed::None, Speed::Overall, Speed::Last, Speed::Both}) {
    unsigned long long work{677};
    auto c = Counter(work)
                 .message("Decreasing")
                 .speed_unit("")
                 .speed(speed);
    c.show();
    while (work > 0) {
      std::this_thread::sleep_for(13ms);
      work--;
    }
    // Let destructor do the c.done() this time
  }

  for (auto speed : {Speed::None, Speed::Overall, Speed::Last, Speed::Both}) {
    for (auto sty : {Blocks, Bars}) {
      std::atomic<size_t> work{0};
      auto bar = ProgressBar(work)
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

  { // Composite display of a ProgressBar and Counter. We want to measure
    // completion in terms of #sentences but we are also interested in speed
    // in terms of tokens per second.'
    std::atomic<size_t> sents{0}, toks{0};
    auto bar =
        ProgressBar(sents).total(1010).message("Sents") |
        Counter(toks).message("Toks").speed_unit("tok/s").speed(Speed::Last);
    bar.show();
    for (int i = 0; i < 1010; i++) {
      std::this_thread::sleep_for(13ms);
      sents++;
      toks += (1 + size_t(rand()) % 5);
    }
    bar.done();
  }

  { // Decreasing progress
    // WARN: negative speeds will underflow if you use an unsigned progress type
    long work{1010};
    auto bar = ProgressBar(work).total(1010).speed(Speed::Last);
    bar.show();
    for (int i = 0; i < 1010; i++) {
      std::this_thread::sleep_for(13ms);
      work--;
    }
    bar.done();
  }

  { // Progress bar with no-tty mode
    std::atomic<size_t> sents{0}, toks{0};
    auto bar = ProgressBar(sents)
                   .total(20100)
                   .message("Sents")
                   .speed(Speed::Last)
                   .no_tty();
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
    auto bar =
        ProgressBar(sents).total(20100).message("Sents") |
        Counter(toks).message("Toks").speed_unit("tok/s").speed(Speed::Last);
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
