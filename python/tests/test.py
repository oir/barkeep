from barkeep import Animation, AnimationStyle, Counter, DType, ProgressBar
import pytest

import io
import time


def check_and_get_parts(s: str, no_tty: bool = False) -> list[str]:
    if not no_tty:
        assert s[0] == "\r"
    assert s[-1] == "\n"
    parts = s[0:-1].split("\n") if no_tty else s[1:-1].split("\r")
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
def test_animation(i:int, sty:AnimationStyle):

    out = io.StringIO()

    anim = Animation(message="Working", style=sty, interval=0.1, file=out)
    anim.show()
    time.sleep(1)
    anim.done()

    check_anim(check_and_get_parts(out.getvalue()), "Working", animation_stills[i])


@pytest.mark.parametrize("dtype", [DType.Int, DType.Float, DType.AtomicInt, DType.AtomicFloat])
@pytest.mark.parametrize("amount", [0, 3])
@pytest.mark.parametrize("discount", [None, 1])
@pytest.mark.parametrize("unit", ["", "thing/10ms"])
def test_constant_counter(dtype, amount, discount, unit):
    out = io.StringIO()

    ctr = Counter(
        value=amount,
        message="Doing things",
        interval=0.001,
        speed=discount,
        speed_unit=unit,
        file=out,
        dtype=dtype,
    )
    ctr.show()
    for i in range(101):
        time.sleep(0.00013)
        # no work
    ctr.done()

    parts = check_and_get_parts(out.getvalue())

    amountstr = f"{amount:.2f}" if dtype in [DType.Float, DType.AtomicFloat] else f"{amount:d}"

    expected = f"Doing things {amountstr} "
    if discount == 1:
        if unit == "":
            expected += "(0.00) "
        else:
            expected += f"(0.00 {unit}) "

    for part in parts:
        assert part == expected


def extract_counts(prefix:str, parts:list[str], py_dtype):
    rval = []
    for part in parts:
        assert part.startswith(prefix)
        i = part.find(" ", len(prefix))
        countstr = part[len(prefix):i]
        rval.append(py_dtype(countstr))
    return rval


@pytest.mark.parametrize("dtype", [DType.Int, DType.Float, DType.AtomicInt, DType.AtomicFloat])
@pytest.mark.parametrize("amount", [0, 3])
@pytest.mark.parametrize("discount", [None, 1])
@pytest.mark.parametrize("unit", ["", "thing/10ms"])
def test_counter(dtype, amount, discount, unit):
    out = io.StringIO()

    ctr = Counter(
        value=amount,
        message="Doing things",
        interval=0.01,
        speed=discount,
        speed_unit=unit,
        file=out,
        dtype=dtype,
    )
    ctr.show()

    increment = 1.2 if dtype in [DType.Float, DType.AtomicFloat] else 1
    py_dtype = float if dtype in [DType.Float, DType.AtomicFloat] else int

    for i in range(101):
        time.sleep(0.0013)
        ctr += increment
    ctr.done()

    parts = check_and_get_parts(out.getvalue())
    counts = extract_counts("Doing things ", parts, py_dtype)

    for i in range(1, len(counts)):
        assert counts[i] >= counts[i - 1]
    
    expected = amount
    if dtype in [DType.Float, DType.AtomicFloat]:
        expected += 121.2
    else:
        expected += 101
    assert counts[-1] == expected



@pytest.mark.parametrize("dtype", [DType.Int, DType.Float, DType.AtomicInt, DType.AtomicFloat])
def test_decreasing_counter(dtype):
    out = io.StringIO()

    ctr = Counter(
        value=101,
        message="Doing things",
        interval=0.01,
        file=out,
        dtype=dtype,
    )
    ctr.show()

    for i in range(101):
        time.sleep(0.0013)
        ctr -= 1
    ctr.done()

    parts = check_and_get_parts(out.getvalue())
    py_dtype = float if dtype in [DType.Float, DType.AtomicFloat] else int
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

@pytest.mark.parametrize("display_type", ["animation", "counter", "progressbar", "composite"])
def test_running_compose(display_type):
    orig = factory_helper(display_type)
    orig.show()
    with pytest.raises(Exception):
        composite = orig | orig
        composite.done()

@pytest.mark.parametrize("display_type", ["animation", "counter", "progressbar", "composite"])
def test_running_compose_extra(display_type):
    orig = factory_helper(display_type)
    orig.show()
    with pytest.raises(Exception):
        composite = orig | orig | orig
        composite.done()
