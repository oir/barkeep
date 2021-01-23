<p align="center">
  <img src="docs/meanwhile.png" width="300">
</p>

Small header to display async counters and progress bars. Use it by
including `meanwhile.h` in your project.

[![Build Status](https://travis-ci.com/oir/meanwhile.svg?branch=main)](https://travis-ci.com/oir/meanwhile)

---

Display a waiting animation with a message:
```C++
using namespace std::chrono_literals;
using namespace mew;

auto anim = Animation().message("Working");
anim.start();
/* do work */ std::this_thread::sleep_for(10s);
anim.done();
```
<img src="docs/anim1.gif" width="700">

Supports several styles:
```C++
auto anim = Animation().message("Downloading...").style(Earth);
```
<img src="docs/anim2.gif" width="700">

Display a counter to monitor a numeric variable while waiting:
```C++
int work{0};
auto c = Counter(work)
  .message("Reading lines")
  .speed(Speed::Last)
  .unit_of_speed("line/s");
c.start();
for (int i = 0; i < 505; i++) {
  std::this_thread::sleep_for(13ms); // read & process line
  work++;
}
c.done();
```
<img src="docs/counter.gif" width="700">

Display a progress bar to monitor a numeric variable and measure its completion by comparing against a total:

```C++
int work{0};
auto bar = ProgressBar(work)
  .message("Reading lines")
  .speed(Speed::Last)
  .unit_of_speed("line/s")
  .total(505);
bar.start();
for (int i = 0; i < 505; i++) {
  std::this_thread::sleep_for(13ms); // read & process line
  work++;
}
bar.done();
```
<img src="docs/bar.gif" width="700">

Combine diplays using `|` operator to monitor multiple variables:
```C++
std::atomic<size_t> sents{0}, toks{0};
auto bar =
  ProgressBar(sents).total(1010).message("Sents") |
  Counter(toks).message("Toks").unit_of_speed("tok/s").speed(Speed::Last);
bar.start();
for (int i = 0; i < 1010; i++) {
  // do work
  std::this_thread::sleep_for(13ms);
  sents++;
  toks += (1 + rand() % 5);
}
bar.done();
```
<img src="docs/composite.gif" width="700">

Use "no tty" mode to, e.g., output to log files:
```C++
std::atomic<size_t> sents{0}, toks{0};
auto bar = ProgressBar(sents)
               .total(401)
               .message("Sents")
               .speed(Speed::Last)
               .interval(1.)
               .no_tty();
bar.start();
for (int i = 0; i < 401; i++) {
  std::this_thread::sleep_for(13ms);
  sents++;
  toks += (1 + rand() % 5);
}
bar.done();
```
<img src="docs/notty.gif" width="700">

`no_tty` achieves two things:

- Change the delimiter from `\r` to `\n` to avoid wonky looking output in your log files
- Change the default interval to a minute to avoid overwhelming logs (in the example above, we set the interval ourselves explicitly)

See `demo.cpp` for more examples. 

### Notes

- Progress variables (and total for progress bar) can be floating point types too. They can also be negative and/or decreasing (careful with the numeric type to avoid underflows).
- Note that progress variable is taken by reference, which means it needs to outlive the display.

## Building
```
make -j2
./demo
```
