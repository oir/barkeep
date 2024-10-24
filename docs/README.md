<p align="center">
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="img/barkeep-logo-white.png" width="300">
    <source media="(prefers-color-scheme: light)" srcset="img/barkeep-logo-black.png" width="300">
    <img src="img/barkeep-logo-black.png" width="300">
  </picture>
</p>

Small, single C++ header to display async animations, counters, and progress bars.
Use it by including `barkeep.h` in your project.
__barkeep__ strives to be [non-intrusive](#Non-intrusive-design).
__barkeep__ also has [python bindings](https://pypi.python.org/pypi/barkeep).

<div class="badges">

<icon prefix="C++"></icon>
<a href="https://github.com/oir/barkeep/actions/workflows/build-test.yml/badge.svg"><img style="vertical-align:middle" src="https://github.com/oir/barkeep/actions/workflows/build-test.yml/badge.svg" alt="Build status"></a>
<a href="https://coveralls.io/github/oir/barkeep?branch=main"><img style="vertical-align:middle" src="https://coveralls.io/repos/github/oir/barkeep/badge.svg?branch=main" alt="Coverage status"></a>
<a><img style="vertical-align:middle" src="https://img.shields.io/badge/std-c++20-blue.svg" alt="c++20"></a>
<code>#include &lt;barkeep/barkeep.h&gt;</code>
<br/>
<icon prefix="python"></icon>
<a href="https://github.com/oir/barkeep/actions/workflows/build-wheels.yml/badge.svg"><img style="vertical-align:middle" src="https://github.com/oir/barkeep/actions/workflows/build-wheels.yml/badge.svg" alt="Build status"></a>
<a href="https://pypi.python.org/pypi/barkeep"><img style="vertical-align:middle" src="https://img.shields.io/badge/python-3.9_|_3.10_|_3.11_|_3.12-blue.svg" alt="pypi"></a>
<code>pip install barkeep</code>

</div>

---

<div style="visibility: hidden; height: 0">

## Showcase

</div>

- Display a waiting animation with a message:

  ```cpp
  using namespace std::chrono_literals;
  namespace bk = barkeep;
  
  auto anim = bk::Animation({.message = "Working"});
  /* do work */ std::this_thread::sleep_for(10s);
  anim->done();
  ```
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="rec/anim1-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="rec/anim1-light.svg" width="700">
    <img src="rec/anim1-light.svg" width="700">
  </picture>

- Supports several styles:

  ```cpp
  auto anim = bk::Animation({.message = "Downloading...", .style = bk::Earth});
  ```
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="rec/anim2-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="rec/anim2-light.svg" width="700">
    <img src="rec/anim2-light.svg" width="700">
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
  c->done();
  ```
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="rec/counter-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="rec/counter-light.svg" width="700">
    <img src="rec/counter-light.svg" width="700">
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
  bar->done();
  ```
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="rec/bar-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="rec/bar-light.svg" width="700">
    <img src="rec/bar-light.svg" width="700">
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
  bar->done();
  ```

  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="rec/bar-pip-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="rec/bar-pip-light.svg" width="700">
    <img src="rec/bar-pip-light.svg" width="700">
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
  bar->done();
  ```

  ```cpp
  int work;
  auto bar = bk::ProgressBar(&work, {.total = 505, .show = false});
  work = 0;
  bar->show();
  for (int i = 0; i < 505; i++) {
    std::this_thread::sleep_for(13ms);
    work++;
  }
  bar->done();
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

- Automatically iterate over a container with a progress bar display
  (instead of monitoring an explicit progress variable):
  
  ```cpp
    std::vector<float> v(300, 0);
    std::iota(v.begin(), v.end(), 1); // 1, 2, 3, ..., 300
    float sum = 0;
    for (auto x : bk::IterableBar(v, {.message = "Summing", .interval = .02})) {
      std::this_thread::sleep_for(1.s/x);
      sum += x;
    }
    std::cout << "Sum: " << sum << std::endl;
  ```

  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="rec/iter-bar-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="rec/iter-bar-light.svg" width="700">
    <img src="rec/iter-bar-light.svg" width="700">
  </picture>

  <blockquote class="warn">
  <details>
  <summary>
  Detail: IterableBar starts the display not at the time of construction, ...  
  </summary>
  
  ... but at the time of the first call to `begin()`.
  Thus, it is possible to set it up prior to loop execution.
 
  Similarly, it ends the display not at the time of destruction, but at the
  first increment of the iterator past the end. Thus, even if the object stays
  alive after the loop, the display will be stopped.

  Therefore, you could initialize it earlier than the loop execution, and destroy
  it late afterwards:

  ```cpp
  std::vector<float> v(300, 0);
  std::iota(v.begin(), v.end(), 1); // 1, 2, 3, ..., 300
  float sum = 0;
  bk::IterableBar bar(v, {.message = "Summing", .interval = .02});
  // <-- At this point, display is not yet shown.
  //     Thus, more work can be done here.
  for (auto x : bar) { // <-- Display starts showing.
    std::this_thread::sleep_for(1.s/x);
    sum += x;
  }
  // <-- Display stops here even if `bar` object is still alive.
  //     Thus, more work can be done here.
  std::cout << "Sum: " << sum << std::endl;
  ```

  </details>
  </blockquote>
  
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
  bar->show();
  for (int i = 0; i < 1010; i++) {
    // do work
    std::this_thread::sleep_for(13ms);
    sents++;
    toks += (1 + rand() % 5);
  }
  bar->done();
  ```

  (Observe the non-running initialization of components using `.show = false`, which is needed for composition.)

  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="rec/composite-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="rec/composite-light.svg" width="700">
    <img src="rec/composite-light.svg" width="700">
  </picture>

  Instead of using `|` operator, you can also call `Composite()` with the components explicitly, which also accepts an additional string argument as the delimiter between the components.
  See the example below.

- If your display is multiline (has `\n` appear in it), all lines are automatically rerendered during animations.
  The example below combines three bars similarly to the example above, however uses `\n` as the delimiter:
  ```cpp
  std::atomic<size_t> linear{0}, quad{0}, cubic{0};
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
  bars->show();
  for (int i = 0; i < 100; i++) {
    std::this_thread::sleep_for(130ms);
    linear++;
    quad += linear;
    cubic += quad;
  }
  bars->done();
  ```

  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="rec/three-bars-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="rec/three-bars-light.svg" width="700">
    <img src="rec/three-bars-light.svg" width="700">
  </picture>


- Display status messages:
  
  ```cpp
  auto s = bk::Status({.message = "Working"});
  std::this_thread::sleep_for(2.5s);
  s->message("Still working");
  std::this_thread::sleep_for(2.5s);
  s->message("Almost done");
  std::this_thread::sleep_for(2.5s);
  s->message("Done");
  s->done();
  ```

  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="rec/status-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="rec/status-light.svg" width="700">
    <img src="rec/status-light.svg" width="700">
  </picture>

  Unlike other displays, `Status` display does not monitor a string variable but instead expects it as an argument to `message()` calls.
  This is because a string is too big of an object to have unguarded concurrent access (see [this section](#caveat)).


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
  bar->done();
  ```
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="rec/notty-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="rec/notty-light.svg" width="700">
    <img src="rec/notty-light.svg" width="700">
  </picture>

  `no_tty` achieves two things:
  
  - Change the delimiter from `\r` to `\n` to avoid wonky looking output in your log files.
  - Change the default interval to a minute to avoid overwhelming logs (in the example above, we set the interval ourselves explicitly for the sake of quicker exposition here).

See `demo.cpp` for more examples. 

## Non-intrusive design

Usually when you get to a point where you think you might want a waiting animation, you probably already have some variables you are monitoring and maybe even occasionally printing to screen. Displaying an animation comes as an afterthought. 

__barkeep__ strives to be minimally intrusive by monitoring existing variables using pointers, so that in such situations you can start using it with very little code change.

<div class="dual-code" style="position: relative; left: 50%; width: 109%; transform: translateX(-50%);">
<table>
<tr>
</tr>
<tr>
<td>

Before

[before](before.cpp ':include :type=code')

</td>
<td>

After

[after](after.cpp ':include :type=code')

</td>
</tr>
</table>
</div>

In the example above, we add a display to monitor the loop variable `i`, `total_chars`, and `total_tokens`.
For-loop changes slightly (because `i` needs to be declared earlier), but the way in which these variables are used in code stays the same.
For instance, we do not use a custom data structure to call `operator++()` to increment progress.
As a result, signature of `process_document()` does not change.

We start and stop the display and __barkeep__ is out of the way.

### Caveat

Since displaying thread typically works concurrently, reads of progress variables (`i`, `total_chars`, `total_tokens`) is always racing with your own modifications.
Even though theoretically it is possible that a read can interleave a write in the middle such that you read e.g. a 4 byte float where 2 byte of is fresh and 2 byte is stale, this kind of concurrent access seems to be almost always okay in practice (see, e.g. [this](https://stackoverflow.com/questions/54188/are-c-reads-and-writes-of-an-int-atomic), and [this](https://stackoverflow.com/questions/36624881/why-is-integer-assignment-on-a-naturally-aligned-variable-atomic-on-x86) thread).
It has always been okay in my own anecdotal experience.
If not, a race condition would result in momentarily displaying a garbage value.

Given the practical rarity of encountering this, its minimal impact outcome, and the desire to be as non-intrusive as possible, __barkeep__ does not introduce any lock guards (which would require a custom type as the progress variables instead of, e.g. an `int` or `float`). 

If you still want to be extra safe and __guarantee__ non-racing read and writes, you can use `std::atomic<T>` for your progress variables, as can be seen in some of the examples above.

## Advanced formatting

You can enable advanced formatting by either
  - defining the `BARKEEP_ENABLE_FMT_FORMAT` compile-time flag, at the expense of introducing a dependency to [`fmt`](https://github.com/fmtlib/fmt) (which has an optional header-only mode), or
  - defining the `BARKEEP_ENABLE_STD_FORMAT` flag, which uses the standard `std::format` from `<format>`, which might require a more recent compiler version (e.g. gcc >= 13.1) despite not introducing external dependencies.

Unlike `fmt::format`, `std::format` does not support named arguments, which is a limitation you might consider.
Thus, `std::format` requires to use integer identifiers to refer to bar components as you will see below.

In either of these cases, `Counter`s and `ProgressBar`s have an additional `Config` option "`format`".
This option can be used to format the entire display using a `fmt`-like format string instead of using textual options like `message` or `speed_unit`:

- A counter

  <!-- tabs:start -->
  #### **with `fmt`enabled**

  ```cpp
  size_t work{0};
  auto c = bk::Counter(&work, {
    .format = "Picked up {value} flowers, at {speed:.1f} flo/s",
    .speed = 0.1
  });
  for (int i = 0; i < 1010; i++) { std::this_thread::sleep_for(13ms), work++; }
  c->done();
  ```

  #### **with standard `<format>` enabled**

  ```cpp
  size_t work{0};
  auto c = bk::Counter(&work, {
    .format = "Picked up {0} flowers, at {1:.1f} flo/s",
    .speed = 0.1
  });
  for (int i = 0; i < 1010; i++) { std::this_thread::sleep_for(13ms), work++; }
  c->done();
  ```
  <!-- tabs:end -->

  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="rec/fmt-counter-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="rec/fmt-counter-light.svg" width="700">
    <img src="rec/fmt-counter-light.svg" width="700">
  </picture>

- A bar:
  <!-- tabs:start -->
  #### **with `fmt`enabled**

  ```cpp
  size_t work{0};
  auto bar = bk::ProgressBar(&work, {
      .total = 1010,
      .format = "Picking flowers {value:4d}/{total}  {bar}  ({speed:.1f} flo/s)",
      .speed = 0.1
  });
  for (int i = 0; i < 1010; i++) { std::this_thread::sleep_for(9ms), work++; }
  bar->done();
  ```

  #### **with standard `<format>` enabled**

  ```cpp
  size_t work{0};
  auto bar = bk::ProgressBar(&work, {
      .total = 1010,
      .format = "Picking flowers {0:4d}/{3}  {1}  ({4:.1f} flo/s)",
      .speed = 0.1
  });
  for (int i = 0; i < 1010; i++) { std::this_thread::sleep_for(9ms), work++; }
  bar->done();
  ```
  <!-- tabs:end -->

  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="rec/fmt-bar-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="rec/fmt-bar-light.svg" width="700">
    <img src="rec/fmt-bar-light.svg" width="700">
  </picture>

When `format` is used, other textual parameters, such as `message` or `speed_unit` are ignored.

- For counters, you can use the predefined identifiers `{value}` (`{0}`), and `{speed}` (`{1}`) with `fmt` (`<format>`).
- With bars, you can use `{value}` (`{0}`), `{bar}` (`{1}`), `{percent}` (`{2}`), `{total}` (`{3}`), and `{speed}` (`{4}`) with `fmt` (`<format>`).

Additionally, some basic ansi color sequences are predefined as identifiers which could be used to add color:

<!-- tabs:start -->
#### **with `fmt`enabled**

```cpp
std::atomic<size_t> work{0};
auto bar = bk::ProgressBar(&work, {
    .total = 1010,
    .format = "Picking flowers {blue}{value:4d}/{total}  {green}{bar} "
              "{yellow}{percent:3.0f}%{reset}  ({speed:.1f} flo/s)",
    .speed = 0.1});
for (int i = 0; i < 1010; i++) { std::this_thread::sleep_for(9ms), work++; }
bar->done();
```

#### **with standard `<format>` enabled**

```cpp
std::atomic<size_t> work{0};
auto bar = bk::ProgressBar(&work, {
    .total = 1010,
    .format = "Picking flowers {8}{0:4d}/{3}  {6}{1} "
              "{7}{2:3.0f}%{11}  ({4:.1f} flo/s)",
    .speed = 0.1});
for (int i = 0; i < 1010; i++) { std::this_thread::sleep_for(9ms), work++; }
bar->done();
```
<!-- tabs:end -->

<picture>
  <source media="(prefers-color-scheme: dark)" srcset="rec/fmt-color-dark.svg" width="700">
  <source media="(prefers-color-scheme: light)" srcset="rec/fmt-color-light.svg" width="700">
  <img src="rec/fmt-color-light.svg" width="700">
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
- Display runs on a concurrent, separate thread, doing concurrent reads on your progress variable.
  See [this section above](#caveat) for what that might imply.
- The examples above use C++20's designated initializers.
  If you prefer to use an older C++ version, you can simply initialize the config classes (e.g. `ProgressBarConfig`) the regular way to pass options into display classes (e.g. `ProgressBar`).

## Building

**barkeep** is header only, so you can simply include the header in your C++ project.
Still, this section details how to build the demos, tests and python bindings and can be used for reference.

### No tooling

If you don't want to deal with even a Makefile, you can simply invoke the compiler on the corresponding `.cpp` files.

- First clone with submodules:
  ```bash
  git clone --recursive https://github.com/oir/barkeep
  cd barkeep
  ```
  Or if you already cloned without the `recursive` option, you can init the submodules:
  ```bash
  git clone https://github.com/oir/barkeep
  cd barkeep
  git submodule update --init
  ```
- Then, build & run the demo like:
  ```bash
  g++ -std=c++20 -I./ tests/demo.cpp -o demo.out
  ./demo.out
  ```
  (You can replace `g++` with your choice of compiler like `clang`.)
- Or, build the tests like:
  ```bash
  g++ -std=c++20 -I./ -I./subprojects/Catch2_/single_include/ tests/test.cpp -o test.out
  g++ -std=c++20 -I./ -I./subprojects/Catch2_/single_include/ tests/test-stdfmt.cpp -o test-stdfmt.out
  g++ -std=c++20 -I./ -I./subprojects/Catch2_/single_include/ -I./subprojects/fmt_/include/ tests/test-fmtlib.cpp -o test-fmtlib.out
  ./test.out
  ./test-stdfmt.out
  ./test-fmtlib.out
  ```

?> Detail: Github submodules are staged in folders that end with a `_` to avoid clashing with Meson's subproject downloading.

_Python bindings are slightly more involved, therefore a proper build system is recommended, [see below](#build-system-meson)._


### Minimal tooling: Make

If you don't want to deal with a complex build system, but also don't want to invoke raw compiler commands, you can use `make`.

Clone the repo with submodules as in the [previous section](#no-tooling) and `cd` into it.

Build demo and tests:
```bash
make all
```

...and run:
```bash
./demo.out
./test.out
./test-stdfmt.out
./test-fmtlib.out
```

_Python bindings are slightly more involved, therefore a proper build system is recommended, [see below](#build-system-meson)._

### Build system: Meson

Meson has its own subproject staging logic, thus cloning the submodules is not needed.

- Get [Meson](https://mesonbuild.com/Getting-meson.html) and [ninja](https://ninja-build.org/), e.g.:
  ```bash
  pip install meson
  sudo apt install ninja-build  # could be a different cmd for your OS
  ```
- Configure (from the root repo directory):
  ```bash
  meson setup build
  ```
- Then the target `tests` can be used to build all demos and tests:
  ```bash
  meson compile -C build tests
  ./build/tests/test.out
  ./build/tests/test-stdfmt.out
  ./build/tests/test-fmtlib.out
  ./build/tests/demo.out
  ./build/tests/demo-stdfmt.out
  ./build/tests/demo-fmtlib.out
  ```

- If you have python dev dependencies available, all python binding targets are collected under the `python` target.
  The output of `configure` command will list those, e.g.:
  ```
  Message: Python targets:
  Message:   barkeep.cpython-39-darwin
  Message:   barkeep.cpython-310-darwin
  Message:   barkeep.cpython-311-darwin
  Message:   barkeep.cpython-312-darwin
  ```
  ```bash
  meson compile -C build python
  ```

  Then you can run python tests or demos, e.g.:
  ```bash
  PYTHONPATH=build/python/ python3.11 -m pytest -s python/tests/test.py
  PYTHONPATH=build/python/ python3.11 python/tests/demo.py
  ```

  <div class="tip">

  By default, python bindings assume `std::atomic<double>` support.
  This requires availability of supporting compilers, e.g. g++-13 instead of Clang 15.0.0. Such compilers can be specified during `configure` step:
  ```bash
  CXX=g++-13 meson setup build
  ```
  Alternatively, you can disable atomic float support by providing the appropriate compile flag if you don't have a supporting compiler:
  ```bash
  CXXFLAGS="-DBARKEEP_ENABLE_ATOMIC_FLOAT=0" meson setup build
  ```
  
  </div>

## Similar projects

- <icon prefix="C++"></icon> [indicators](https://github.com/p-ranav/indicators)
- <icon prefix="C++"></icon> [progressbar](https://github.com/gipert/progressbar)
- <icon prefix="python"></icon> [tqdm](https://github.com/tqdm/tqdm)