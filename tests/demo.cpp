#include <atomic>
#include <iostream>
#include <barkeep/barkeep.h>

int main(int /*argc*/, char** /*argv*/) {
  using namespace std::chrono_literals;
  namespace bk = barkeep;

  for (auto sty : {bk::Ellipsis, bk::Bar, bk::Moon}) {
    auto anim =
        bk::Animation({.message = "Working", .style = sty, .interval = 0.5s});
    anim.show();
    std::this_thread::sleep_for(10s);
    anim.done();
  }

  {
    std::vector<std::string> stills{
        "⠋", "⠙", "⠹", "⠸", "⠼", "⠴", "⠦", "⠧", "⠇", "⠏"};
    auto anim = bk::Animation(
        {.message = "Working", .style = stills, .interval = 0.5s});
    anim.show();
    std::this_thread::sleep_for(10s);
    anim.done();
  }

  std::vector<std::optional<double>> speeds{std::nullopt, 0, 0.1, 1};
  for (auto speed : speeds) {
    std::atomic<size_t> work{0};
    auto c = bk::Counter(&work,
                         {
                             .message = "Doing stuff",
                             .speed = speed,
                             .speed_unit = "tk/s",
                         });
    c.show();
    for (int i = 0; i < 1010; i++) {
      std::this_thread::sleep_for(13ms);
      work++;
    }
    c.done();
  }

  for (auto speed : speeds) {
    float work{0};
    auto c = bk::Counter(&work,
                         {
                             .message = "Doing stuff",
                             .speed = speed,
                             .speed_unit = "tk/s",
                         });
    c.show();
    for (int i = 0; i < 1010; i++) {
      std::this_thread::sleep_for(13ms);
      work += 0.213;
    }
    c.done();
  }

  for (auto speed : speeds) {
    unsigned long long work{677};
    auto c = bk::Counter(&work,
                         {
                             .message = "Decreasing",
                             .speed = speed,
                             .speed_unit = "",
                         });
    c.show();
    while (work > 0) {
      std::this_thread::sleep_for(13ms);
      work--;
    }
    // Let destructor do the c.done() this time
  }

  for (auto speed : speeds) {
    for (auto sty : {bk::Pip, bk::Blocks, bk::Bars, bk::Arrow}) {
      std::atomic<size_t> work{0};
      auto bar = bk::ProgressBar(&work,
                                 {
                                     .total = 1010,
                                     .message = "Doing stuff",
                                     .speed = speed,
                                     .speed_unit = "tk/s",
                                     .style = sty,
                                 });
      bar.show();
      for (int i = 0; i < 1010; i++) {
        std::this_thread::sleep_for(7ms);
        work++;
      }
      bar.done();
    }
  }

  { // Custom bar style
    std::atomic<size_t> work{0};
    bk::BarParts sty{"[", "]", {"/"}, {" "}};
    auto bar = bk::ProgressBar(&work,
                               {
                                   .total = 1010,
                                   .message = "Doing stuff",
                                   .speed = 0.1,
                                   .speed_unit = "tk/s",
                                   .style = sty,
                               });
    bar.show();
    for (int i = 0; i < 1010; i++) {
      std::this_thread::sleep_for(7ms);
      work++;
    }
    bar.done();
  }

  { // Decreasing progress
    unsigned long work{1010};
    auto bar = bk::ProgressBar(&work,
                               {
                                   .total = 1010,
                                   .speed = 1.,
                               });
    bar.show();
    for (int i = 0; i < 1010; i++) {
      std::this_thread::sleep_for(7ms);
      work--;
    }
    bar.done();
  }

  { // Composite display of a ProgressBar and Counter. We want to measure
    // completion in terms of #sentences but we are also interested in speed
    // in terms of tokens per second.'
    std::atomic<size_t> sents{0}, toks{0};
    // TODO: clang-format makes this very ugly
    auto bar = bk::ProgressBar(&sents,
                               {
                                   .total = 1010,
                                   .message = "Sents",
                                   .speed = 1,
                               }) |
               bk::Counter(&toks,
                           {
                               .message = "Toks",
                               .speed = 1,
                               .speed_unit = "tok/s",
                           });
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
    // TODO: clang-format makes this very ugly
    auto counters = bk::Counter(&squares,
                                {
                                    .message = "Squares",
                                    .speed = 0.1,
                                }) |
                    bk::Counter(&cubes,
                                {
                                    .message = "Cubes",
                                    .speed = 0.1,
                                }) |
                    bk::Counter(&hypercubes,
                                {
                                    .message = "Hypercubes",
                                    .speed = 0.1,
                                });
    counters.show();
    for (int i = 0; i < 1010; i++) {
      std::this_thread::sleep_for(13ms);
      squares += (1 + size_t(rand()) % 5);
      cubes += (1 + size_t(rand()) % 10);
      hypercubes += (1 + size_t(rand()) % 20);
    }
    counters.done();
  }

  { // Iterable automatic progress bar
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 0;
    for (auto x : bk::IterableBar(v, {.message = "Summing"})) {
      std::this_thread::sleep_for(1s);
      sum += x;
    }
    std::cout << "Sum: " << sum << std::endl;
  }

  std::cout << "\nWarning: To illustrate infrequent writes, no-tty"
               " demos take long (several minutes)... 😅"
            << std::endl;

  { // Progress bar with no-tty mode
    std::atomic<size_t> sents{0}, toks{0};
    auto bar = bk::ProgressBar(&sents,
                               {
                                   .total = 20100,
                                   .message = "Sents",
                                   .speed = 1,
                                   .no_tty = true,
                               });
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
    auto bar = bk::ProgressBar(&sents,
                               {
                                   .total = 20100,
                                   .message = "Sents",
                                   .no_tty = true,
                               }) |
               bk::Counter(&toks,
                           {
                               .message = "Toks",
                               .speed = 1,
                               .speed_unit = "tok/s",
                               .no_tty = true,
                           });
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
