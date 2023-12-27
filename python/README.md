## barkeep

Small, C++-based python library to display async animations, counters, and progress bars.


<a href="https://github.com/oir/barkeep/actions/workflows/build-wheels.yml/badge.svg"><img src="https://github.com/oir/barkeep/actions/workflows/build-wheels.yml/badge.svg" alt="Build status"></a>
<a href="https://pypi.python.org/pypi/barkeep"><img src="https://img.shields.io/badge/python-3.9_|_3.10_|_3.11_|_3.12-blue.svg" alt="pypi"></a>


---

- Display a waiting animation with a message:

  ```cpp
  using namespace std::chrono_literals;
  namespace bk = barkeep;
  
  auto anim = bk::Animation().message("Working");
  anim.show();
  /* do work */ std::this_thread::sleep_for(10s);
  anim.done();
  ```
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/anim1-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/anim1-light.svg" width="700">
    <img src="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/anim1-light.svg" width="700">
  </picture>

- Supports several styles:

  ```cpp
  auto anim = bk::Animation().message("Downloading...").style(bk::Earth);
  ```
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/anim2-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/anim2-light.svg" width="700">
    <img src="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/anim2-light.svg" width="700">
  </picture>

- Display a counter to monitor a numeric variable while waiting:

  ```cpp
  int work{0};
  auto c = bk::Counter(&work)
    .message("Reading lines")
    .speed(1.)
    .speed_unit("line/s");
  c.show();
  for (int i = 0; i < 505; i++) {
    std::this_thread::sleep_for(13ms); // read & process line
    work++;
  }
  c.done();
  ```
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/counter-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/counter-light.svg" width="700">
    <img src="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/counter-light.svg" width="700">
  </picture>

- Display a progress bar to monitor a numeric variable and measure its completion by comparing against a total:

  ```cpp
  int work{0};
  auto bar = bk::ProgressBar(&work)
    .message("Reading lines")
    .speed(1.)
    .speed_unit("line/s")
    .total(505);
  bar.show();
  for (int i = 0; i < 505; i++) {
    std::this_thread::sleep_for(13ms); // read & process line
    work++;
  }
  bar.done();
  ```
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/bar-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/bar-light.svg" width="700">
    <img src="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/bar-light.svg" width="700">
  </picture>

- Combine diplays using `|` operator to monitor multiple variables:

  ```cpp
  std::atomic<size_t> sents{0}, toks{0};
  auto bar =
    bk::ProgressBar(&sents).total(1010).message("Sents") |
    bk::Counter(&toks).message("Toks").speed_unit("tok/s").speed(1.);
  bar.show();
  for (int i = 0; i < 1010; i++) {
    // do work
    std::this_thread::sleep_for(13ms);
    sents++;
    toks += (1 + rand() % 5);
  }
  bar.done();
  ```
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/composite-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/composite-light.svg" width="700">
    <img src="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/composite-light.svg" width="700">
  </picture>

- Use "no tty" mode to, e.g., output to log files:

  ```cpp
  std::atomic<size_t> sents{0}, toks{0};
  auto bar = bk::ProgressBar(&sents)
                 .total(401)
                 .message("Sents")
                 .speed(1.)
                 .interval(1.)
                 .no_tty();
  bar.show();
  for (int i = 0; i < 401; i++) {
    std::this_thread::sleep_for(13ms);
    sents++;
    toks += (1 + rand() % 5);
  }
  bar.done();
  ```
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/notty-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/notty-light.svg" width="700">
    <img src="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/notty-light.svg" width="700">
  </picture>

  `no_tty` achieves two things:
  
  - Change the delimiter from `\r` to `\n` to avoid wonky looking output in your log files.
  - Change the default interval to a minute to avoid overwhelming logs (in the example above, we set the interval ourselves explicitly).
