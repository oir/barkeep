from barkeep import (
    Animation,
    AnimationStyle,
    Counter,
    DType,
    ProgressBar,
    ProgressBarStyle,
)
from argparse import ArgumentParser
from collections import OrderedDict
import time
import random


def animation():
    styles = [AnimationStyle.Ellipsis, AnimationStyle.Bar, AnimationStyle.Moon]

    for sty in styles:
        anim = Animation(message="Working", style=sty, interval=0.5)
        anim.show()
        time.sleep(10)
        anim.done()


def counter():
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


def progress_bar():
    speeds = [None, 0, 0.1, 1]
    styles = [ProgressBarStyle.Bars, ProgressBarStyle.Arrow, ProgressBarStyle.Blocks]

    for speed in speeds:
        for sty in styles:
            work = ProgressBar(
                total=1010,
                message="Doing stuff",
                speed=speed,
                speed_unit="tk/s",
                style=sty,
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


def composite():
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


demos = OrderedDict(
    [
        ("animation", animation),
        ("counter", counter),
        ("progress_bar", progress_bar),
        ("composite", composite),
    ]
)


if __name__ == "__main__":
    parser = ArgumentParser()
    parser.add_argument(
        "demo",
        choices=["animation", "counter", "progress_bar", "composite", []],
        nargs="*",
    )

    args = parser.parse_args()
    demos_to_run = args.demo or demos.keys()
    for i, demo in enumerate(demos_to_run):
        if i > 0:
            print()
        print(f"Running {demo}...")
        demos[demo]()
        print(f"Finished {demo}.")
