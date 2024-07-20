from barkeep import (
    Animation,
    AnimationStyle,
    Counter,
    DType,
    ProgressBar,
    ProgressBarStyle,
    Status,
)
from argparse import ArgumentParser
from collections import OrderedDict
import time
import random


def animation():
    styles = [AnimationStyle.Ellipsis, AnimationStyle.Bar, AnimationStyle.Moon]

    for sty in styles:
        anim = Animation(message="Working", style=sty, interval=0.5)
        time.sleep(10)
        anim.done()


def counter():
    speeds = [None, 0, 0.1, 1]

    for speed in speeds:
        work = Counter(message="Doing stuff", speed=speed, speed_unit="tk/s")
        for i in range(1010):
            time.sleep(0.013)
            work += 1
        work.done()

    for speed in speeds:
        work = Counter(
            message="Doing stuff", speed=speed, speed_unit="tk/s", dtype=DType.Float
        )
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
        while work > 0:
            time.sleep(0.013)
            work -= 1
        work.done()


def progress_bar():
    speeds = [None, 0, 0.1, 1]
    styles = [ProgressBarStyle.Bars, ProgressBarStyle.Blocks]

    for speed in speeds:
        for sty in styles:
            work = ProgressBar(
                total=1010,
                message="Doing stuff",
                speed=speed,
                speed_unit="tk/s",
                style=sty,
            )
            for i in range(1010):
                time.sleep(0.013)
                work += 1
            work.done()

    # Decreasing bar
    bar = ProgressBar(value=1010, total=1010, speed=1)
    for i in range(1010):
        time.sleep(0.013)
        bar -= 1
    bar.done()


def composite():
    sents = ProgressBar(total=1010, message="Sents", speed=1, show=False)
    toks = Counter(message="Toks", speed_unit="tok/s", speed=1, show=False)
    bar = sents | toks

    bar.show()
    for i in range(1010):
        time.sleep(0.013)
        sents += 1
        toks += 1 + random.randrange(5)
    bar.done()

    squares = Counter(message="Squares", speed=0.1, show=False)
    cubes = Counter(message="Cubes", speed=0.1, show=False)
    hypercubes = Counter(message="Hypercubes", speed=0.1, show=False)

    counters = squares | cubes | hypercubes

    counters.show()
    for i in range(1010):
        time.sleep(0.013)
        squares += 1 + random.randrange(5)
        cubes += 1 + random.randrange(10)
        hypercubes += 1 + random.randrange(20)
    counters.done()


def fmt():
    for fmtstr in [
        "Doing stuff {value} ({speed:.1f} thing/s)",
        "Doing stuff {cyan}{value}{reset} {red}({speed:.1f} thing/s){reset}",
    ]:
        work = Counter(fmt=fmtstr, speed=0.1)
        for i in range(1010):
            time.sleep(0.013)
            work += 1
        work.done()

    for fmtstr in [
        "Picking flowers {value:4d}/1010  {bar} {percent:3.0f}%  ({speed:.1f} flo/s)",
        "Picking flowers {blue}{value:4d}/1010  {green}{bar} {yellow}{percent:3.0f}%{reset}  ({speed:.1f} flo/s)",
    ]:
        work = ProgressBar(
            fmt=fmtstr,
            total=1010,
            speed=0.1,
        )
        for i in range(1010):
            time.sleep(0.013)
            work += 1
        work.done()


def status():
    s = Status(message="Working")
    time.sleep(2.5)
    s.message = "Still working"
    time.sleep(2.5)
    s.message = "Almost done"
    time.sleep(2.5)
    s.message = "Done"
    s.done()


demos = OrderedDict(
    [
        ("animation", animation),
        ("status", status),
        ("counter", counter),
        ("progress_bar", progress_bar),
        ("composite", composite),
        ("fmt", fmt),
    ]
)


if __name__ == "__main__":
    parser = ArgumentParser()
    parser.add_argument(
        "demo",
        choices=[
            "animation",
            "status",
            "counter",
            "progress_bar",
            "composite",
            "fmt",
            [],
        ],
        nargs="*",
    )

    # cosmetic
    reset = "\033[0m"
    bold = "\033[1m"
    dim = "\033[2m"

    args = parser.parse_args()
    demos_to_run = args.demo or demos.keys()
    for i, demo in enumerate(demos_to_run):
        if i > 0:
            print(dim + "─" * 80 + reset)
        print(f"{dim}Running{reset} {bold}{demo}{reset}{dim}...{reset}")
        demos[demo]()
