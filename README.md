## barkeep

Small C++ header to display async counters and progress bars. Use it by
including `barkeep.h` in your project.

[![build](https://github.com/oir/meanwhile/actions/workflows/build-test.yml/badge.svg)](https://github.com/oir/meanwhile/actions/workflows/build-test.yml)
[![Coverage Status](https://coveralls.io/repos/github/oir/meanwhile/badge.svg?branch=main)](https://coveralls.io/github/oir/meanwhile?branch=main)

---

- Display a waiting animation with a message:

  ```C++
  using namespace std::chrono_literals;
  using namespace mew;
  
  auto anim = Animation().message("Working");
  anim.show();
  /* do work */ std::this_thread::sleep_for(10s);
  anim.done();
  ```
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="docs/anim1-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="docs/anim1-light.svg" width="700">
    <img src="docs/anim1-light.svg" width="700">
  </picture>

- Supports several styles:

  ```C++
  auto anim = Animation().message("Downloading...").style(Earth);
  ```
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="docs/anim2-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="docs/anim2-light.svg" width="700">
    <img src="docs/anim2-light.svg" width="700">
  </picture>

- Display a counter to monitor a numeric variable while waiting:

  ```C++
  int work{0};
  auto c = Counter(&work)
    .message("Reading lines")
    .speed(Speed::Last)
    .speed_unit("line/s");
  c.show();
  for (int i = 0; i < 505; i++) {
    std::this_thread::sleep_for(13ms); // read & process line
    work++;
  }
  c.done();
  ```
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="docs/counter-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="docs/counter-light.svg" width="700">
    <img src="docs/counter-light.svg" width="700">
  </picture>

- Display a progress bar to monitor a numeric variable and measure its completion by comparing against a total:

  ```C++
  int work{0};
  auto bar = ProgressBar(&work)
    .message("Reading lines")
    .speed(Speed::Last)
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
    <source media="(prefers-color-scheme: dark)" srcset="docs/bar-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="docs/bar-light.svg" width="700">
    <img src="docs/bar-light.svg" width="700">
  </picture>

- Combine diplays using `|` operator to monitor multiple variables:

  ```C++
  std::atomic<size_t> sents{0}, toks{0};
  auto bar =
    ProgressBar(&sents).total(1010).message("Sents") |
    Counter(&toks).message("Toks").speed_unit("tok/s").speed(Speed::Last);
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
    <source media="(prefers-color-scheme: dark)" srcset="docs/composite-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="docs/composite-light.svg" width="700">
    <img src="docs/composite-light.svg" width="700">
  </picture>

- Use "no tty" mode to, e.g., output to log files:

  ```C++
  std::atomic<size_t> sents{0}, toks{0};
  auto bar = ProgressBar(&sents)
                 .total(401)
                 .message("Sents")
                 .speed(Speed::Last)
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
    <source media="(prefers-color-scheme: dark)" srcset="docs/notty-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="docs/notty-light.svg" width="700">
    <img src="docs/notty-light.svg" width="700">
  </picture>

  `no_tty` achieves two things:
  
  - Change the delimiter from `\r` to `\n` to avoid wonky looking output in your log files
  - Change the default interval to a minute to avoid overwhelming logs (in the example above, we set the interval ourselves explicitly)

See `demo.cpp` for more examples. 

### Notes

- Progress variables (and `total` for progress bar) can be floating point types too. They can also be negative and/or decreasing (careful with the numeric type to avoid underflows).
- Note that progress variable is taken by reference, which means it needs to outlive the display.

## Building
```
make -j2
./demo
```
