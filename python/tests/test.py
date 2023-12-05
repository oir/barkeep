from barkeep import Animation, AnimationStyle

import io
import time


def check_and_get_parts(s: str, no_tty: bool = False) -> list[str]:
    if not no_tty:
        assert s[0] == "\r"
    assert s[-1] == "\n"
    parts = s[0:-1].split("\n") if no_tty else s[1:-2].split("\r")
    assert len(parts) > 0
    return parts


def check_anim(parts: list[str], msg: str, stills: list[str]):
    for i in range(len(parts) - 1):
        j = i % len(stills)
        part = parts[i]
        assert part == (msg + " " + stills[j] + " ")


def test_animation():
    stills = [
        [".  ", ".. ", "..."],
        ["🕐", "🕜", "🕑", "🕝", "🕒", "🕞", "🕓", "🕟", "🕔", "🕠", "🕕", "🕡",
        "🕖", "🕢", "🕗", "🕣", "🕘", "🕤", "🕙", "🕥", "🕚", "🕦", "🕛", "🕧"],
        ["🌕", "🌖", "🌗", "🌘", "🌑", "🌒", "🌓", "🌔"],
        ["🌎", "🌍", "🌏"],
        ["-", "/", "|", "\\"],
        ["▖", "▘", "▝", "▗"],
    ]  # fmt: skip

    for i, sty in enumerate(
        [
            AnimationStyle.Ellipsis,
            AnimationStyle.Clock,
            AnimationStyle.Moon,
            AnimationStyle.Earth,
            AnimationStyle.Bar,
            AnimationStyle.Square,
        ]
    ):
        out = io.StringIO()

        anim = Animation(message="Working", style=sty, interval=0.1, file=out)
        anim.show()
        time.sleep(1)
        anim.done()

        check_anim(check_and_get_parts(out.getvalue()), "Working", stills[i])
