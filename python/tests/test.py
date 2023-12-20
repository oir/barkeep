from barkeep import (
    Animation,
    AnimationStyle,
    Counter,
    DType,
    ProgressBar,
    ProgressBarStyle,
)
import pytest
import random

import io
import time

if not hasattr(DType, "AtomicFloat"):
    DType.AtomicFloat = None

dtypes = [
    DType.Int,
    DType.Float,
    DType.AtomicInt,
    DType.AtomicFloat,
]


@pytest.fixture()
def dtype(request):
    if request.param == DType.AtomicFloat:
        if request.config.getoption("--no-atomic-float"):
            pytest.skip("AtomicFloat tests disabled.")
    return request.param


def check_and_get_parts(s: str, no_tty: bool = False) -> list[str]:
    if not no_tty:
        assert s[0] == "\r"
    assert s[-1] == "\n"
    parts = s[0:-2].split("\n") if no_tty else s[1:-1].split("\r")
    assert len(parts) > 0
    return parts


def check_anim(parts: list[str], msg: str, stills: list[str]):
    for i in range(len(parts) - 1):
        j = i % len(stills)
        part = parts[i]
        assert part == (msg + " " + stills[j] + " ")


animation_styles = [
    AnimationStyle.Ellipsis,
    AnimationStyle.Clock,
    AnimationStyle.Moon,
    AnimationStyle.Earth,
    AnimationStyle.Bar,
    AnimationStyle.Square,
]
animation_stills = [
    [".  ", ".. ", "..."],
    ["🕐", "🕜", "🕑", "🕝", "🕒", "🕞", "🕓", "🕟", "🕔", "🕠", "🕕", "🕡",
    "🕖", "🕢", "🕗", "🕣", "🕘", "🕤", "🕙", "🕥", "🕚", "🕦", "🕛", "🕧"],
    ["🌕", "🌖", "🌗", "🌘", "🌑", "🌒", "🌓", "🌔"],
    ["🌎", "🌍", "🌏"],
    ["-", "/", "|", "\\"],
    ["▖", "▘", "▝", "▗"],
]  # fmt: skip


@pytest.mark.parametrize("i,sty", enumerate(animation_styles))
def test_animation(i: int, sty: AnimationStyle):
    out = io.StringIO()

    anim = Animation(message="Working", style=sty, interval=0.1, file=out)
    anim.show()
    time.sleep(1)
    anim.done()

    check_anim(check_and_get_parts(out.getvalue()), "Working", animation_stills[i])


@pytest.mark.parametrize("dtype", dtypes, indirect=True)
@pytest.mark.parametrize("amount", [0, 3])
@pytest.mark.parametrize("discount", [None, 1])
@pytest.mark.parametrize("unit", ["", "thing/10ms"])
@pytest.mark.parametrize("no_tty", [True, False])
def test_constant_counter(dtype, amount, discount, unit, no_tty):
    out = io.StringIO()

    ctr = Counter(
        value=amount,
        message="Doing things",
        interval=0.001,
        speed=discount,
        speed_unit=unit,
        file=out,
        no_tty=no_tty,
        dtype=dtype,
    )
    ctr.show()
    for i in range(101):
        time.sleep(0.00013)
        # no work
    ctr.done()

    parts = check_and_get_parts(out.getvalue(), no_tty=no_tty)

    amountstr = (
        f"{amount:d}" if dtype in [DType.Int, DType.AtomicInt] else f"{amount:.2f}"
    )

    expected = f"Doing things {amountstr} "
    if discount == 1:
        if unit == "":
            expected += "(0.00) "
        else:
            expected += f"(0.00 {unit}) "

    for part in parts:
        assert part == expected


def extract_counts(prefix: str, parts: list[str], py_dtype):
    rval = []
    for part in parts:
        assert part.startswith(prefix)
        i = part.find(" ", len(prefix))
        countstr = part[len(prefix) : i]
        rval.append(py_dtype(countstr))
    return rval


@pytest.mark.parametrize("dtype", dtypes, indirect=True)
@pytest.mark.parametrize("amount", [0, 3])
@pytest.mark.parametrize("discount", [None, 1])
@pytest.mark.parametrize("unit", ["", "thing/10ms"])
@pytest.mark.parametrize("no_tty", [True, False])
def test_counter(dtype, amount, discount, unit, no_tty):
    out = io.StringIO()

    ctr = Counter(
        value=amount,
        message="Doing things",
        interval=0.01,
        speed=discount,
        speed_unit=unit,
        file=out,
        no_tty=no_tty,
        dtype=dtype,
    )
    ctr.show()

    increment = 1 if dtype in [DType.Int, DType.AtomicInt] else 1.2
    py_dtype = int if dtype in [DType.Int, DType.AtomicInt] else float

    for i in range(101):
        time.sleep(0.0013)
        ctr += increment
    ctr.done()

    parts = check_and_get_parts(out.getvalue(), no_tty=no_tty)
    counts = extract_counts("Doing things ", parts, py_dtype)

    for i in range(1, len(counts)):
        assert counts[i] >= counts[i - 1]

    expected = amount
    if dtype in [DType.Int, DType.AtomicInt]:
        expected += 101
    else:
        expected += 121.2
    assert counts[-1] == expected


@pytest.mark.parametrize("dtype", dtypes, indirect=True)
@pytest.mark.parametrize("no_tty", [True, False])
def test_decreasing_counter(dtype, no_tty):
    out = io.StringIO()

    ctr = Counter(
        value=101,
        message="Doing things",
        interval=0.01,
        file=out,
        no_tty=no_tty,
        dtype=dtype,
    )
    ctr.show()

    for i in range(101):
        time.sleep(0.0013)
        ctr -= 1
    ctr.done()

    parts = check_and_get_parts(out.getvalue(), no_tty=no_tty)
    py_dtype = int if dtype in [DType.Int, DType.AtomicInt] else float
    counts = extract_counts("Doing things ", parts, py_dtype)

    for i in range(1, len(counts)):
        assert counts[i] <= counts[i - 1]
    assert counts[-1] == 0


def factory_helper(display_type):
    hide = io.StringIO()
    if display_type == "animation":
        return Animation(file=hide)
    if display_type == "counter":
        return Counter(file=hide)
    if display_type == "progressbar":
        return ProgressBar(file=hide)
    if display_type == "composite":
        return Animation(file=hide) | Counter(file=hide) | ProgressBar(file=hide)
    raise Exception("Invalid display type!")


@pytest.mark.parametrize(
    "display_type", ["animation", "counter", "progressbar", "composite"]
)
def test_running_compose(display_type):
    orig = factory_helper(display_type)
    orig.show()
    with pytest.raises(Exception):
        composite = orig | orig
        composite.done()


@pytest.mark.parametrize(
    "display_type", ["animation", "counter", "progressbar", "composite"]
)
def test_running_compose_extra(display_type):
    orig = factory_helper(display_type)
    orig.show()
    with pytest.raises(Exception):
        composite = orig | orig | orig
        composite.done()


@pytest.mark.parametrize("Display", [Counter, ProgressBar])
@pytest.mark.parametrize("discount", [-1, 1.1])
def test_invalid_speed_discount(Display, discount):
    with pytest.raises(Exception):
        Display(speed=discount)


@pytest.mark.parametrize("dtype", dtypes, indirect=True)
@pytest.mark.parametrize(
    "sty", [ProgressBarStyle.Bars, ProgressBarStyle.Blocks, ProgressBarStyle.Arrow]
)
@pytest.mark.parametrize("no_tty", [True, False])
def test_progress_bar(dtype, sty, no_tty):
    out = io.StringIO()

    bar = ProgressBar(
        value=0,
        total=50,
        message="Computing",
        interval=0.001,
        file=out,
        dtype=dtype,
        style=sty,
        no_tty=no_tty,
    )
    bar.show()
    for i in range(50):
        time.sleep(0.0013)
        bar += 1
    bar.done()

    parts = check_and_get_parts(out.getvalue(), no_tty=no_tty)

    # Check that space is shrinking
    last_spaces = 100000
    for part in parts:
        spaces = part.count(" ")
        assert spaces <= last_spaces
        last_spaces = spaces


@pytest.mark.parametrize("dtype", dtypes, indirect=True)
@pytest.mark.parametrize("above", [True, False])
@pytest.mark.parametrize("no_tty", [True, False])
def test_progress_bar_overflow(dtype, above, no_tty):
    out = io.StringIO()

    bar = ProgressBar(
        value=50 if above else 0,
        total=50,
        message="Computing",
        interval=0.001,
        file=out,
        dtype=dtype,
        style=ProgressBarStyle.Bars,
        no_tty=no_tty,
    )
    bar.show()
    for i in range(50):
        time.sleep(0.0013)
        bar += 1 if above else -1
    bar.done()

    parts = check_and_get_parts(out.getvalue(), no_tty=no_tty)
    expected = "|" * 32 if above else "|" + " " * 30 + "|"
    for part in parts:
        assert expected in part


@pytest.mark.parametrize("no_tty", [True, False])
def test_composite_bar_counter(no_tty):
    out = io.StringIO()

    sents = 0
    toks = 0
    bar = ProgressBar(
        value=sents,
        total=505,
        message="Sents",
        interval=0.01,
        file=out,
        style=ProgressBarStyle.Bars,
        no_tty=no_tty,
    ) | Counter(
        value=toks,
        message="Toks",
        speed_unit="tok/s",
        speed=1,
        file=out,
    )
    bar.show()
    for i in range(505):
        time.sleep(0.0013)
        sents += 1
        toks += 1 + random.randrange(5)
    bar.done()

    parts = check_and_get_parts(out.getvalue(), no_tty=no_tty)
    last_spaces = 100000
    last_count = 0

    for part in parts:
        assert part.startswith("Sents ")
        assert part[54:61] == "  Toks "
        part = part.rstrip()
        assert part[-7:] == " tok/s)"

        # check bar correctness
        bar_part = part[14:46]
        spaces = bar_part.count(" ")
        assert spaces <= last_spaces
        last_spaces = spaces
        i = 1
        while bar_part[i] != " " and i < 31:
            assert bar_part[i] == "|"
            i += 1
        while i < 31:
            assert bar_part[i] == " "
            i += 1

        # check counter correctness
        count_part = part[61:]
        i = count_part.find(" ")
        count = int(count_part[:i])
        assert count >= last_count
        last_count = count
