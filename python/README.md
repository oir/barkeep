<p align="center">
  <picture>
    <img src="https://raw.githubusercontent.com/oir/barkeep/main/docs/img/barkeep-logo-black.png" width="300">
  </picture>
</p>

Small, C++-based python library to display async animations, counters, and progress bars.


<a href="https://github.com/oir/barkeep/actions/workflows/build-wheels.yml/badge.svg"><img src="https://github.com/oir/barkeep/actions/workflows/build-wheels.yml/badge.svg" alt="Build status"></a>
<a href="https://pypi.python.org/pypi/barkeep"><img src="https://img.shields.io/badge/python-3.9_|_3.10_|_3.11_|_3.12-blue.svg" alt="pypi"></a>

__Installation:__ `pip install barkeep`


---

- Display a waiting animation with a message:

  ```python
  import time
  import barkeep as bk
  
  anim = bk.Animation(message="Working")
  anim.show()
  time.sleep(10)  # do work
  anim.done()
  ```
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/anim1-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/anim1-light.svg" width="700">
    <img src="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/anim1-light.svg" width="700">
  </picture>

- Supports several styles:

  ```python
  anim = bk.Animation(message="Working", style=bk.Earth)
  ```
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/anim2-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/anim2-light.svg" width="700">
    <img src="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/anim2-light.svg" width="700">
  </picture>

- Display a counter to monitor a numeric variable while waiting:

  ```python
  c = bk.Counter(message="Reading lines", speed=1.0, speed_unit="line/s")
  c.show()
  for i in range(505):
      time.sleep(0.013)  # read & process line
      c += 1
  c.done()
  ```
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/counter-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/counter-light.svg" width="700">
    <img src="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/counter-light.svg" width="700">
  </picture>

- Display a progress bar to monitor a numeric variable and measure its completion by comparing against a total:

  ```python
  bar = bk.ProgressBar(message="Reading lines", speed=1.0, speed_unit="line/s", total=505)
  bar.show()
  for i in range(505):
      time.sleep(0.013)  # read & process line
      bar += 1
  bar.done()
  ```
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/bar-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/bar-light.svg" width="700">
    <img src="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/bar-light.svg" width="700">
  </picture>

- Combine diplays using `|` operator to monitor multiple variables:

  ```python
  import random
  
  sents = bk.ProgressBar(total=1010, message="Sents")
  toks = bk.Counter(message="Toks", speed_unit="tok/s", speed=1.0)
  bar = sents | toks
  bar.show()
  for i in range(1010):
      # do work
      time.sleep(0.013)
      sents += 1
      toks += 1 + random.randrange(5)
  bar.done()
  ```
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/composite-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/composite-light.svg" width="700">
    <img src="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/composite-light.svg" width="700">
  </picture>

- Use "no tty" mode to, e.g., output to log files:

  ```python
  bar = bk.ProgressBar(total=401, message="Sents", speed=1.0, interval=1.0, no_tty=True)
  bar.show()
  for i in range(401):
      time.sleep(0.013)
      bar += 1
  bar.done()
  ```
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/notty-dark.svg" width="700">
    <source media="(prefers-color-scheme: light)" srcset="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/notty-light.svg" width="700">
    <img src="https://raw.githubusercontent.com/oir/barkeep/main/docs/rec/notty-light.svg" width="700">
  </picture>

  `no_tty` achieves two things:
  
  - Change the delimiter from `\r` to `\n` to avoid wonky looking output in your log files.
  - Change the default interval to a minute to avoid overwhelming logs (in the example above, we set the interval ourselves explicitly).
