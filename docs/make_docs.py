#!/usr/bin/env python3

import glob
import subprocess
import shutil
import os
import re

# remove previous generation
shutil.rmtree("docs/api/", ignore_errors=True)
os.mkdir("docs/api/")

# generate doxygen xml
subprocess.run(["doxygen", "docs/Doxyfile"], check=True)

# convert doxygen xml to markdown
subprocess.run(
    [
        "doxybook2",
        "-i",
        "xml",
        "-o",
        "docs/api",
        "--config",
        "docs/config.json",
        "--templates",
        "docs/template/",
    ],
    check=True,
)

# remove intermediate xml
shutil.rmtree("xml/")

# make some additions to play nicely with docsify


os.remove("docs/api/Classes/README.md")
os.remove("docs/api/Namespaces/README.md")

def content_fixes(content: str) -> str:
    return content.replace("operator|", "operator\|")


def merge_files(input_glob: str, output: str, increment_title_levels: bool = True):
    # concatenate individual class pages into one page
    class_files = sorted(glob.glob(input_glob))
    classes = [open(f).read() for f in class_files]
    for i in range(len(classes) - 1):
        classes[i] = re.sub(
            r"^Updated on .+ at .+ .+$", "", classes[i], flags=re.MULTILINE
        )
    catted = content_fixes("\n\n".join(classes))

    # increase markdown title levels by one
    if increment_title_levels:
        catted = re.sub(r"^#", "##", catted, flags=re.MULTILINE)

    for f in class_files:
       fixed = content_fixes(open(f).read())
       open(f, "w").write(fixed)

    open(output, "w").write(catted)


merge_files("docs/api/Classes/*.md", "docs/api/Classes/README.md")
merge_files(
    "docs/api/Namespaces/*.md",
    "docs/api/Namespaces/README.md",
    increment_title_levels=False,
)
