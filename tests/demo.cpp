#include <atomic>
#include <iostream>
#include <numeric>
#include <unordered_map>

#include <barkeep/barkeep.h>

using namespace std::chrono_literals;
namespace bk = barkeep;

// cosmetic
const static std::string reset = "\033[0m";
const static std::string bold = "\033[1m";
const static std::string dim = "\033[2m";

std::vector<std::optional<double>> speeds{std::nullopt, 0, 0.1, 1};

class Demo {
 private:
  std::string name;       // unique name for CLI option
  std::string help;       // a title or a sentence about the demo
  void (*func)();         // body of the demo
  std::string brief = ""; // Extra info in addition to help

  static std::vector<std::string> all_demo_names;
  static std::unordered_map<std::string, Demo*> all_demos;

 public:
  Demo(std::string name, std::string help, void (*func)())
      : name(name), help(help), func(func) {
    all_demo_names.push_back(name);
    all_demos[name] = this;
  }

  Demo(std::string name, std::string help, std::string brief, void (*func)())
      : name(name), help(help), func(func), brief(brief) {
    all_demo_names.push_back(name);
    all_demos[name] = this;
  }

  void run() {
    std::cout << bold << help << reset << "\n";
    if (not brief.empty()) { std::cout << dim << brief << reset << "\n"; }
    func();
  }

  static void run_all(std::vector<std::string> names = {}) {
    bool first = true;
    for (auto name : names.empty() ? all_demo_names : names) {
      if (not first) {
        std::cout << dim << "────────────────────────────────────────" << reset
                  << "\n";
      }
      if (all_demos.find(name) == all_demos.end()) {
        std::cout << "Demo not found: " << name << "\n";
      } else {
        all_demos[name]->run();
      }
      first = false;
    }
  }
};

std::vector<std::string> Demo::all_demo_names;
std::unordered_map<std::string, Demo*> Demo::all_demos;

// ----------------- Demos -----------------

Demo animations("animations", "Animations", []() {
  for (auto sty : {bk::Ellipsis, bk::Bounce, bk::Bar, bk::Moon}) {
    auto anim = bk::Animation({.message = "Working", .style = sty});
    anim->show();
    std::this_thread::sleep_for(10s);
    anim->done();
  }
});

Demo custom_animations("custom_animations", "Custom animation stills", []() {
  std::vector<std::string> stills{"⠋", "⠙", "⠸", "⠴", "⠦", "⠇"};
  auto anim =
      bk::Animation({.message = "Working", .style = stills, .interval = 0.5s});
  std::this_thread::sleep_for(10s);
});

Demo status("status", "Status display", []() {
  auto s = bk::Status({.message = "Working"});
  std::this_thread::sleep_for(2.5s);
  s->message("Still working");
  std::this_thread::sleep_for(2.5s);
  s->message("Almost done");
  std::this_thread::sleep_for(2.5s);
  s->message("Done");
  s->done();
});

Demo int_counter("int_counter", "Integral counter", []() {
  for (auto speed : speeds) {
    std::atomic<size_t> work{0};
    auto c = bk::Counter(&work,
                         {
                             .message = "Doing stuff",
                             .speed = speed,
                             .speed_unit = "tk/s",
                         });
    for (int i = 0; i < 1010; i++) {
      std::this_thread::sleep_for(13ms);
      work++;
    }
  }
});

Demo float_counter("float_counter", "Floating point counter", []() {
  for (auto speed : speeds) {
    float work{0};
    auto c = bk::Counter(&work,
                         {
                             .message = "Doing stuff",
                             .speed = speed,
                             .speed_unit = "tk/s",
                         });
    for (int i = 0; i < 1010; i++) {
      std::this_thread::sleep_for(13ms);
      work += 0.213;
    }
  }
});

Demo decreasing_counter("decreasing_counter", "Decreasing counter", []() {
  for (auto speed : speeds) {
    unsigned long long work{677};
    auto c = bk::Counter(&work,
                         {
                             .message = "Decreasing",
                             .speed = speed,
                             .speed_unit = "",
                         });
    while (work > 0) {
      std::this_thread::sleep_for(13ms);
      work--;
    }
    c->done(); // let's explicitly end this time
  }
});

Demo bars("bars", "Progress bars", []() {
  for (auto speed : speeds) {
    for (auto sty : {bk::Rich, bk::Blocks, bk::Bars, bk::Line}) {
      std::atomic<size_t> work{0};
      auto bar = bk::ProgressBar(&work,
                                 {
                                     .total = 1010,
                                     .message = "Doing stuff",
                                     .speed = speed,
                                     .speed_unit = "tk/s",
                                     .style = sty,
                                 });
      for (int i = 0; i < 1010; i++) {
        std::this_thread::sleep_for(7ms);
        work++;
      }
    }
  }
});

Demo custom_bar("custom_bar", "Custom bar style", []() {
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
  for (int i = 0; i < 1010; i++) {
    std::this_thread::sleep_for(7ms);
    work++;
  }
});

Demo decreasing_bar( // ...
    "decreasing_bar",
    "Decreasing progress bar",
    []() {
      unsigned long work{1010};
      auto bar = bk::ProgressBar(&work,
                                 {
                                     .total = 1010,
                                     .speed = 1.,
                                 });
      for (int i = 0; i < 1010; i++) {
        std::this_thread::sleep_for(7ms);
        work--;
      }
    });

Demo bar_and_counter(
    "bar_and_counter",
    "Composite display of a ProgressBar and Counter",
    "We want to measure"
    " completion in terms of #sentences but we are also interested in speed"
    " in terms of tokens per second.",
    []() {
      std::atomic<size_t> sents{0}, toks{0};
      // TODO: clang-format makes this very ugly
      auto bar = bk::ProgressBar(&sents,
                                 {
                                     .total = 1010,
                                     .message = "Sents",
                                     .speed = 1,
                                     .show = false,
                                 }) |
                 bk::Counter(&toks,
                             {
                                 .message = "Toks",
                                 .speed = 1,
                                 .speed_unit = "tok/s",
                                 .show = false,
                             });
      bar->show();
      for (int i = 0; i < 1010; i++) {
        std::this_thread::sleep_for(13ms);
        sents++;
        toks += (1 + size_t(rand()) % 5);
      }
      bar->done();
    });

Demo three_counters(
    "three_counters",
    "Composite display of three counters",
    []() {
      std::atomic<size_t> squares{0}, cubes{0}, hypercubes{0};
      // clang-format off
      auto counters = 
          bk::Counter(&squares, { .message = "Squares", .speed = 0.1, .show = false }) |
          bk::Counter(&cubes, { .message = "Cubes", .speed = 0.1, .show = false }) |
          bk::Counter(&hypercubes, { .message = "Hypercubes", .speed = 0.1, .show = false });
      // clang-format on
      counters->show();
      for (int i = 0; i < 1010; i++) {
        std::this_thread::sleep_for(13ms);
        squares += (1 + size_t(rand()) % 5);
        cubes += (1 + size_t(rand()) % 10);
        hypercubes += (1 + size_t(rand()) % 20);
      }
      counters->done();
    });

Demo three_counters_delim(
    "three_counters_delim",
    "Composite display of three counters with custom delimiter",
    []() {
      static const std::string blue = "\033[34m";
      static const std::string reset = "\033[0m";
      std::atomic<size_t> squares{0}, cubes{0}, hypercubes{0};
      // clang-format off
      auto counters = bk::Composite(
          {bk::Counter(&squares, { .message = "Squares", .speed = 0.1, .show = false }),
           bk::Counter(&cubes, { .message = "Cubes", .speed = 0.1, .show = false }),
           bk::Counter(&hypercubes, { .message = "Hypercubes", .speed = 0.1, .show = false })},
          blue + " | " + reset);
      // clang-format on
      counters->show();
      for (int i = 0; i < 1010; i++) {
        std::this_thread::sleep_for(13ms);
        squares += (1 + size_t(rand()) % 5);
        cubes += (1 + size_t(rand()) % 10);
        hypercubes += (1 + size_t(rand()) % 20);
      }
      counters->done();
    });

Demo three_counters_lines(
    "three_counters_lines",
    "Composite display of three counters with newline delimiter",
    []() {
      std::atomic<size_t> squares{0}, cubes{0}, hypercubes{0};
      // clang-format off
      auto counters = bk::Composite(
        {bk::Counter(&squares, { .message = "Squares", .speed = 0.1, .show = false }),
         bk::Counter(&cubes, { .message = "Cubes", .speed = 0.1, .show = false }),
         bk::Counter(&hypercubes, { .message = "Hypercubes", .speed = 0.1, .show = false })},
        "\n");
      // clang-format on
      counters->show();
      for (int i = 0; i < 1010; i++) {
        std::this_thread::sleep_for(13ms);
        squares += (1 + size_t(rand()) % 5);
        cubes += (1 + size_t(rand()) % 10);
        hypercubes += (1 + size_t(rand()) % 20);
      }
      counters->done();
    });

Demo three_bars( // ...
    "three_bars",
    "Composite display of three newline-delimited progress bars",
    []() {
      std::atomic<size_t> linear{0}, quad{0}, cubic{0};
      // clang-format off
      auto bars = bk::Composite(
        {bk::ProgressBar(&linear, {
             .total = 100,
             .message = "Linear   ",
             .speed = 0,
             .style = bk::Rich,
             .show = false,
         }),
         bk::ProgressBar(&quad, {
             .total = 5050,
             .message = "Quadratic",
             .speed = 0,
             .style = bk::Rich,
             .show = false,
         }),
         bk::ProgressBar(&cubic, {
             .total = 171700,
             .message = "Cubic    ",
             .speed = 0,
             .style = bk::Rich,
             .show = false,
         })},
        "\n");
      // clang-format on
      bars->show();
      for (int i = 0; i < 100; i++) {
        std::this_thread::sleep_for(130ms);
        linear++;
        quad += linear;
        cubic += quad;
      }
      bars->done();
    });

Demo iterable_bar("iterable_bar", "Iterable progress bar", []() {
  std::vector<float> v(300, 0);
  std::iota(v.begin(), v.end(), 1); // 1, 2, 3, ..., 300
  float sum = 0;
  for (auto x : bk::IterableBar(v, {.message = "Summing", .interval = .02})) {
    std::this_thread::sleep_for(1.s / x);
    sum += x;
  }
  std::cout << "Sum: " << sum << std::endl;
});

Demo bar_no_tty(
    "bar_no_tty",
    "Progress bar with no-tty mode",
    "⚠️ Warning: To illustrate infrequent writes with the default options, no-tty"
    " demos take long (several minutes)... 😅",
    []() {
      std::atomic<size_t> sents{0}, toks{0};
      auto bar = bk::ProgressBar(&sents,
                                 {
                                     .total = 20100,
                                     .message = "Sents",
                                     .speed = 1,
                                     .no_tty = true,
                                 });
      for (int i = 0; i < 20100; i++) {
        std::this_thread::sleep_for(13ms);
        sents++;
        toks += (1 + size_t(rand()) % 5);
      }
    });

Demo bar_counter_no_tty(
    "bar_counter_no_tty",
    "Composite display of a ProgressBar and Counter with no-tty mode",
    "⚠️ Warning: To illustrate infrequent writes with the default options, no-tty"
    " demos take long (several minutes)... 😅",
    []() {
      std::atomic<size_t> sents{0}, toks{0};
      auto bar = bk::ProgressBar(&sents,
                                 {
                                     .total = 20100,
                                     .message = "Sents",
                                     .no_tty = true,
                                     .show = false,
                                 }) |
                 bk::Counter(&toks,
                             {
                                 .message = "Toks",
                                 .speed = 1,
                                 .speed_unit = "tok/s",
                                 .no_tty = true,
                                 .show = false,
                             });
      bar->show();
      for (int i = 0; i < 20100; i++) {
        std::this_thread::sleep_for(13ms);
        sents++;
        toks += (1 + size_t(rand()) % 5);
      }
      bar->done();
    });

int main(int argc, char** argv) {
  Demo::run_all(std::vector<std::string>(argv + 1, argv + argc));

  return 0;
}
