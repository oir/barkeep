<p align="center">
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="img/barkeep-logo-white.png" width="300">
    <source media="(prefers-color-scheme: light)" srcset="img/barkeep-logo-black.png" width="300">
    <img src="img/barkeep-logo-black.png" width="300">
  </picture>
</p>

Small, single C++ header to display async animations, counters, and progress bars.
Use it by including `barkeep.h` in your project.
__barkeep__ also has [python bindings](https://pypi.python.org/pypi/barkeep).


<img style="vertical-align:middle" src="img/C++.svg" height="22"> 
<a href="https://github.com/oir/barkeep/actions/workflows/build-test.yml/badge.svg"><img style="vertical-align:middle" src="https://github.com/oir/barkeep/actions/workflows/build-test.yml/badge.svg" alt="Build status"></a>
<a href="https://coveralls.io/github/oir/barkeep?branch=main"><img style="vertical-align:middle" src="https://coveralls.io/repos/github/oir/barkeep/badge.svg?branch=main" alt="Coverage status"></a>
<a><img style="vertical-align:middle" src="https://img.shields.io/badge/std-c++17-blue.svg" alt="c++17"></a>
<code>#include &lt;barkeep/barkeep.h&gt;</code>
<br/>
<img style="vertical-align:middle" src="img/python.svg" height="22">
<a href="https://github.com/oir/barkeep/actions/workflows/build-wheels.yml/badge.svg"><img style="vertical-align:middle" src="https://github.com/oir/barkeep/actions/workflows/build-wheels.yml/badge.svg" alt="Build status"></a>
<a href="https://pypi.python.org/pypi/barkeep"><img style="vertical-align:middle" src="https://img.shields.io/badge/python-3.9_|_3.10_|_3.11_|_3.12-blue.svg" alt="pypi"></a>
<code>pip install barkeep</code>


---

<div style="visibility: hidden; height: 0">

## Showcase

</div>

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
    <source media="(prefers-color-scheme: dark)" srcset="rec/anim1-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="rec/anim1-light.svg" width="700">
    <img src="rec/anim1-light.svg" width="700">
  </picture>

- Supports several styles:

  ```cpp
  auto anim = bk::Animation().message("Downloading...").style(bk::Earth);
  ```
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="rec/anim2-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="rec/anim2-light.svg" width="700">
    <img src="rec/anim2-light.svg" width="700">
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
    <source media="(prefers-color-scheme: dark)" srcset="rec/counter-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="rec/counter-light.svg" width="700">
    <img src="rec/counter-light.svg" width="700">
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
    <source media="(prefers-color-scheme: dark)" srcset="rec/bar-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="rec/bar-light.svg" width="700">
    <img src="rec/bar-light.svg" width="700">
  </picture>

- Bars can also be styled. Some styles have color:

  ```cpp
  int work{0};
  auto bar = bk::ProgressBar(&work)
    .message("Reading lines")
    .speed(1.)
    .speed_unit("line/s")
    .total(505)
    .style(bk::ProgressBarStyle::Pip);
  bar.show();
  for (int i = 0; i < 505; i++) {
    std::this_thread::sleep_for(13ms); // read & process line
    work++;
  }
  bar.done();
  ```

  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="rec/bar-pip-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="rec/bar-pip-light.svg" width="700">
    <img src="rec/bar-pip-light.svg" width="700">
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
    <source media="(prefers-color-scheme: dark)" srcset="rec/composite-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="rec/composite-light.svg" width="700">
    <img src="rec/composite-light.svg" width="700">
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
    <source media="(prefers-color-scheme: dark)" srcset="rec/notty-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="rec/notty-light.svg" width="700">
    <img src="rec/notty-light.svg" width="700">
  </picture>

  `no_tty` achieves two things:
  
  - Change the delimiter from `\r` to `\n` to avoid wonky looking output in your log files.
  - Change the default interval to a minute to avoid overwhelming logs (in the example above, we set the interval ourselves explicitly).

See `demo.cpp` for more examples. 


## Advanced formatting

You can enable advanced formatting by defining the `BARKEEP_ENABLE_FMT` compile-time flag, at the expense of introducing a dependency to [`fmt`](https://github.com/fmtlib/fmt) (which has an optional header-only mode).

In this case, `Counter`s and `ProgressBar`s have an additional method `fmt()` which can be used to format the display using a `fmt`-like format string:

- A counter:

  ```cpp
  size_t work{0};
  auto c = bk::Counter(&work)
                .fmt("Picked up {value} flowers, at {speed:.1f} flo/s")
                .speed(0.1);
  c.show();
  for (int i = 0; i < 1010; i++) { std::this_thread::sleep_for(13ms), work++; }
  c.done();
  ```

  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="rec/fmt-counter-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="rec/fmt-counter-light.svg" width="700">
    <img src="rec/fmt-counter-light.svg" width="700">
  </picture>

- A bar:

  ```cpp
  size_t work{0};
  auto bar =
      bk::ProgressBar(&work)
          .total(1010)
          .fmt("Picking flowers {value:4d}/{total}  {bar}  ({speed:.1f} flo/s)")
          .speed(0.1);
  bar.show();
  for (int i = 0; i < 1010; i++) { std::this_thread::sleep_for(9ms), work++; }
  bar.done();
  ```

  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="rec/fmt-bar-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="rec/fmt-bar-light.svg" width="700">
    <img src="rec/fmt-bar-light.svg" width="700">
  </picture>

When `fmt()` is used, other textual parameters, such as the ones passed by `message()` or `speed_unit()` are ignored.

- For counters, you can use the predefined identifiers `{value}`, and `{speed}`.
- With bars, you can use `{value}`, `{bar}`, `{percent}`, `{total}`, and `{speed}`.

Additionally, some basic ansi color sequences are predefined as identifiers which could be used to add color:
```cpp
std::atomic<size_t> work{0};
auto bar = bk::ProgressBar(&work)
               .total(1010)
               .fmt("Picking flowers {blue}{value:4d}/{total}  {green}{bar} "
                    "{yellow}{percent:3.0f}%{reset}  ({speed:.1f} flo/s)")
               .speed(0.1);
bar.show();
for (int i = 0; i < 1010; i++) { std::this_thread::sleep_for(9ms), work++; }
bar.done();
```

<picture>
  <source media="(prefers-color-scheme: dark)" srcset="rec/fmt-color-dark.svg" width="700">
  <source media="(prefers-color-scheme: light)" srcset="rec/fmt-color-light.svg" width="700">
  <img src="rec/fmt-color-light.svg" width="700">
</picture>

- You can use `{red}`, `{green}`, `{yellow}`, `{blue}`, `{magenta}`, `{cyan}`, and `{reset}`.

See `demo-fmt.cpp` for more examples.


## Notes

- Progress variables (and `total` for progress bar) can be floating point types too. They can also be negative and/or decreasing (careful with the numeric type to avoid underflows).
- Note that progress variable is taken by pointer, which means it needs to outlive the display.

## Building
```
make demo
./demo
```
