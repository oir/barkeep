<p align="center">
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="docs/img/barkeep-logo-white.png" width="300">
    <source media="(prefers-color-scheme: light)" srcset="docs/img/barkeep-logo-black.png" width="300">
    <img src="docs/img/barkeep-logo-black.png" width="300">
  </picture>
</p>

Small, single C++ header to display async animations, counters, and progress bars.
Use it by including `barkeep.h` in your project.
__barkeep__ strives to be [non-intrusive](https://oir.github.io/barkeep/#/README?id=non-intrusive-design).
**barkeep** also has [python bindings](https://pypi.python.org/pypi/barkeep).

<img style="vertical-align:bottom" src="docs/img/C++.svg" height="22"> <a href="https://github.com/oir/barkeep/actions/workflows/build-test.yml/badge.svg"><img style="vertical-align:bottom" src="https://github.com/oir/barkeep/actions/workflows/build-test.yml/badge.svg" alt="Build status"></a> <a href="https://coveralls.io/github/oir/barkeep?branch=main"><img style="vertical-align:bottom" src="https://coveralls.io/repos/github/oir/barkeep/badge.svg?branch=main" alt="Coverage status"></a> <a><img style="vertical-align:bottom" src="https://img.shields.io/badge/std-c++20-blue.svg" alt="c++20"></a> <code>#include &lt;barkeep/barkeep.h&gt;</code>
<br/>
<img style="vertical-align:bottom" src="docs/img/python.svg" height="22"> <a href="https://github.com/oir/barkeep/actions/workflows/build-wheels.yml/badge.svg"><img style="vertical-align:bottom" src="https://github.com/oir/barkeep/actions/workflows/build-wheels.yml/badge.svg" alt="Build status"></a> <a href="https://pypi.python.org/pypi/barkeep"><img style="vertical-align:bottom" src="https://img.shields.io/badge/python-3.9_|_3.10_|_3.11_|_3.12-blue.svg" alt="pypi"></a> <code>pip install barkeep</code>

---

- Display a waiting animation with a message:

  ```cpp
  using namespace std::chrono_literals;
  namespace bk = barkeep;
  
  auto anim = bk::Animation({.message = "Working"});
  /* do work */ std::this_thread::sleep_for(10s);
  anim.done();
  ```

  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="docs/rec/anim1-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="docs/rec/anim1-light.svg" width="700">
    <img src="docs/rec/anim1-light.svg" width="700">
  </picture>

- Supports several styles:

  ```cpp
  auto anim = bk::Animation({.message = "Downloading...", .style = bk::Earth});
  ```

  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="docs/rec/anim2-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="docs/rec/anim2-light.svg" width="700">
    <img src="docs/rec/anim2-light.svg" width="700">
  </picture>

- Display a counter to monitor a numeric variable while waiting:

  ```cpp
  int work{0};
  auto c = bk::Counter(&work, {
    .message = "Reading lines",
    .speed = 1.,
    .speed_unit = "line/s"
  });
  for (int i = 0; i < 505; i++) {
    std::this_thread::sleep_for(13ms); // read & process line
    work++;
  }
  c.done();
  ```

  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="docs/rec/counter-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="docs/rec/counter-light.svg" width="700">
    <img src="docs/rec/counter-light.svg" width="700">
  </picture>

- Display a progress bar to monitor a numeric variable and measure its completion by comparing against a total:

  ```cpp
  int work{0};
  auto bar = bk::ProgressBar(&work, {
    .total = 505,
    .message = "Reading lines",
    .speed = 1.,
    .speed_unit = "line/s",
  });
  for (int i = 0; i < 505; i++) {
    std::this_thread::sleep_for(13ms); // read & process line
    work++;
  }
  bar.done();
  ```

  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="docs/rec/bar-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="docs/rec/bar-light.svg" width="700">
    <img src="docs/rec/bar-light.svg" width="700">
  </picture>

- Bars can also be styled. Some styles have color:

  ```cpp
  int work{0};
  auto bar = bk::ProgressBar(&work, {
    .total = 505,
    .message = "Reading lines",
    .speed = 1.,
    .speed_unit = "line/s",
    .style = bk::ProgressBarStyle::Pip,
  });
  for (int i = 0; i < 505; i++) {
    std::this_thread::sleep_for(13ms); // read & process line
    work++;
  }
  bar.done();
  ```

  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="docs/rec/bar-pip-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="docs/rec/bar-pip-light.svg" width="700">
    <img src="docs/rec/bar-pip-light.svg" width="700">
  </picture>

- Displaying can be deferred with `.show = false`, and explicitly invoked by calling
  `show()`, instead of at construction time.
  
  Finishing the display can be done implicitly by the
  destructor, instead of calling `done()` (this allows RAII-style use).
  
  The following are equivalent: 

  ```cpp
  int work{0};
  auto bar = bk::ProgressBar(&work, {.total = 505});
  for (int i = 0; i < 505; i++) {
    std::this_thread::sleep_for(13ms);
    work++;
  }
  bar.done();
  ```

  ```cpp
  int work;
  auto bar = bk::ProgressBar(&work, {.total = 505, .show = false});
  work = 0;
  bar.show();
  for (int i = 0; i < 505; i++) {
    std::this_thread::sleep_for(13ms);
    work++;
  }
  bar.done();
  ```

  ```cpp
  int work{0};
  {
    auto bar = bk::ProgressBar(&work, {.total = 505});
    for (int i = 0; i < 505; i++) {
      std::this_thread::sleep_for(13ms);
      work++;
    }
  }
  ```

- Combine diplays using `|` operator to monitor multiple variables:

  ```cpp
  std::atomic<size_t> sents{0}, toks{0};
  auto bar =
      bk::ProgressBar(&sents, {
        .total = 1010, 
        .message = "Sents",
        .show = false}) |
      bk::Counter(&toks, {
        .message = "Toks", 
        .speed = 1., 
        .speed_unit = "tok/s",
        .show = false});
  bar.show();
  for (int i = 0; i < 1010; i++) {
    // do work
    std::this_thread::sleep_for(13ms);
    sents++;
    toks += (1 + rand() % 5);
  }
  bar.done();
  ```

  (Observe the non-running initialization of components using `.show = false`, which is needed for composition.)

  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="docs/rec/composite-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="docs/rec/composite-light.svg" width="700">
    <img src="docs/rec/composite-light.svg" width="700">
  </picture>

- Use "no tty" mode to, e.g., output to log files:

  ```cpp
  std::atomic<size_t> sents{0};
  auto bar = bk::ProgressBar(&sents, {
    .total = 401,
    .message = "Sents",
    .speed = 1.,
    .interval = 1.,
    .no_tty = true,
  });
  for (int i = 0; i < 401; i++) {
    std::this_thread::sleep_for(13ms);
    sents++;
  }
  bar.done();
  ```

  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="docs/rec/notty-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="docs/rec/notty-light.svg" width="700">
    <img src="docs/rec/notty-light.svg" width="700">
  </picture>

  `no_tty` achieves two things:

  - Change the delimiter from `\r` to `\n` to avoid wonky looking output in your log files.
  - Change the default interval to a minute to avoid overwhelming logs (in the example above, we set the interval ourselves explicitly).

See `demo.cpp` for more examples.

## Advanced formatting

You can enable advanced formatting by either
  - defining the `BARKEEP_ENABLE_FMT_FORMAT` compile-time flag, at the expense of introducing a dependency to [`fmt`](https://github.com/fmtlib/fmt) (which has an optional header-only mode), or
  - defining the `BARKEEP_ENABLE_STD_FORMAT` flag, which uses the standard `std::format` from `<format>`, which might require a more recent compiler version (e.g. gcc >= 13.1) despite not introducing external dependencies.

Unlike `fmt::format`, `std::format` does not support named arguments, which is a limitation you might consider.
Thus, `std::format` requires to use integer identifiers to refer to bar components as you will see below.

In either of these cases, `Counter`s and `ProgressBar`s have an additional `Config` option "`format`".
This option can be used to format the entire display using a `fmt`-like format string instead of using textual options like `message` or `speed_unit`:

- A counter:
  - with `fmt` enabled:

    ```cpp
    size_t work{0};
    auto c = bk::Counter(&work, {
      .format = "Picked up {value} flowers, at {speed:.1f} flo/s",
      .speed = 0.1
    });
    for (int i = 0; i < 1010; i++) { std::this_thread::sleep_for(13ms), work++; }
    c.done();
    ```

  - with standard `<format>` enabled:

    ```cpp
    size_t work{0};
    auto c = bk::Counter(&work, {
      .format = "Picked up {0} flowers, at {1:.1f} flo/s",
      .speed = 0.1
    });
    for (int i = 0; i < 1010; i++) { std::this_thread::sleep_for(13ms), work++; }
    c.done();
    ```

  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="docs/rec/fmt-counter-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="docs/rec/fmt-counter-light.svg" width="700">
    <img src="docs/rec/fmt-counter-light.svg" width="700">
  </picture>

- A bar:
  - with `fmt` enabled:

    ```cpp
    size_t work{0};
    auto bar = bk::ProgressBar(&work, {
        .total = 1010,
        .format = "Picking flowers {value:4d}/{total}  {bar}  ({speed:.1f} flo/s)",
        .speed = 0.1
    });
    for (int i = 0; i < 1010; i++) { std::this_thread::sleep_for(9ms), work++; }
    bar.done();
    ```

  - with standard `<format>` enabled:

    ```cpp
    size_t work{0};
    auto bar = bk::ProgressBar(&work, {
        .total = 1010,
        .format = "Picking flowers {0:4d}/{3}  {1}  ({4:.1f} flo/s)",
        .speed = 0.1
    });
    for (int i = 0; i < 1010; i++) { std::this_thread::sleep_for(9ms), work++; }
    bar.done();
    ```

  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="docs/rec/fmt-bar-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="docs/rec/fmt-bar-light.svg" width="700">
    <img src="docs/rec/fmt-bar-light.svg" width="700">
  </picture>

When `format` is used, other textual parameters, such as `message` or `speed_unit` are ignored.

- For counters, you can use the predefined identifiers `{value}` (`{0}`), and `{speed}` (`{1}`) with `fmt` (`<format>`).
- With bars, you can use `{value}` (`{0}`), `{bar}` (`{1}`), `{percent}` (`{2}`), `{total}` (`{3}`), and `{speed}` (`{4}`) with `fmt` (`<format>`).

Additionally, some basic ansi color sequences are predefined as identifiers which could be used to add color:

- with `fmt` enabled:

  ```cpp
  std::atomic<size_t> work{0};
  auto bar = bk::ProgressBar(&work, {
      .total = 1010,
      .format = "Picking flowers {blue}{value:4d}/{total}  {green}{bar} "
                "{yellow}{percent:3.0f}%{reset}  ({speed:.1f} flo/s)",
      .speed = 0.1});
  for (int i = 0; i < 1010; i++) { std::this_thread::sleep_for(9ms), work++; }
  bar.done();
  ```

- with standard `<format>` enabled:

  ```cpp
  std::atomic<size_t> work{0};
  auto bar = bk::ProgressBar(&work, {
      .total = 1010,
      .format = "Picking flowers {8}{0:4d}/{3}  {6}{1} "
                "{7}{2:3.0f}%{11}  ({4:.1f} flo/s)",
      .speed = 0.1});
  for (int i = 0; i < 1010; i++) { std::this_thread::sleep_for(9ms), work++; }
  bar.done();
  ```

<picture>
  <source media="(prefers-color-scheme: dark)" srcset="docs/rec/fmt-color-dark.svg" width="700">
  <source media="(prefers-color-scheme: light)" srcset="docs/rec/fmt-color-light.svg" width="700">
  <img src="docs/rec/fmt-color-light.svg" width="700">
</picture>

- You can use `{red}`, `{green}`, `{yellow}`, `{blue}`, `{magenta}`, `{cyan}`, and `{reset}` with `fmt`.
- With the standard `<format>` you can use the following, based on whether you are specifying a `Counter` or a `ProgressBar`:

  | | red | green | yellow | blue | magenta | cyan | reset |
  | - | - | - | - | - | - | - | - |
  | `Counter` | `{2}` | `{3}` | `{4}` | `{5}` | `{6}` | `{7}` | `{8}` |
  | `ProgressBar` | `{5}` | `{6}` | `{7}` | `{8}` | `{9}` | `{10}` | `{11}` |


See `demo-fmtlib.cpp` or `demo-stdfmt.cpp` for more examples.

## Notes

- Progress variables (and `total` for progress bar) can be floating point types too. They can also be negative and/or decreasing (careful with the numeric type to avoid underflows).
- Note that progress variable is taken by pointer, which means it needs to outlive the display.

## Building

```
make demo
./demo
```
