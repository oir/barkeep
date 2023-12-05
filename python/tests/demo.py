from barkeep import (
    Animation,
    AnimationStyle,
    Counter,
    DType,
    ProgressBar,
    ProgressBarStyle,
)
import time
import random

styles = [AnimationStyle.Ellipsis, AnimationStyle.Bar, AnimationStyle.Moon]

for sty in styles:
    anim = Animation(message="Working", style=sty, interval=0.5)
    anim.show()
    time.sleep(10)
    anim.done()


speeds = [None, 0, 0.1, 1]

for speed in speeds:
    work = Counter(message="Doing stuff", speed=speed, speed_unit="tk/s")
    work.show()
    for i in range(1010):
        time.sleep(0.013)
        work += 1
    work.done()

for speed in speeds:
    work = Counter(
        message="Doing stuff", speed=speed, speed_unit="tk/s", dtype=DType.Float
    )
    work.show()
    for i in range(1010):
        time.sleep(0.013)
        work += 0.213
    work.done()

for speed in speeds:
    work = Counter(
        value=677,
        message="Decreasing",
        speed=speed,
        speed_unit="",
        dtype=DType.AtomicInt,
    )
    work.show()
    while work > 0:
        time.sleep(0.013)
        work -= 1
    work.done()

styles = [ProgressBarStyle.Bars, ProgressBarStyle.Arrow, ProgressBarStyle.Blocks]

for speed in speeds:
    for sty in styles:
        work = ProgressBar(
            total=1010, message="Doing stuff", speed=speed, speed_unit="tk/s", style=sty
        )
        work.show()
        for i in range(1010):
            time.sleep(0.013)
            work += 1
        work.done()

# Decreasing bar
bar = ProgressBar(value=1010, total=1010, speed=1)
bar.show()
for i in range(1010):
    time.sleep(0.013)
    bar -= 1
bar.done()

sents = ProgressBar(total=1010, message="Sents", speed=1)
toks = Counter(message="Toks", speed_unit="tok/s", speed=1)
bar = sents | toks

bar.show()
for i in range(1010):
    time.sleep(0.013)
    sents += 1
    toks += 1 + random.randrange(5)
bar.done()


squares = Counter(message="Squares", speed=0.1)
cubes = Counter(message="Cubes", speed=0.1)
hypercubes = Counter(message="Hypercubes", speed=0.1)

counters = squares | cubes | hypercubes

counters.show()
for i in range(1010):
    time.sleep(0.013)
    squares += 1 + random.randrange(5)
    cubes += 1 + random.randrange(10)
    hypercubes += 1 + random.randrange(20)
counters.done()

squares = Counter(message="Squares", speed=0.1)
squares.show()
for i in range(1010):
    time.sleep(0.013)
    squares += 1 + random.randrange(5)
squares.done()
