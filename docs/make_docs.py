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

os.remove("docs/api/Namespaces/README.md") # remove the index file

def content_fixes(content: str) -> str:
    content = content.replace("operator|", "operator\|") # TODO: avoid for code blocks

    return content
  
# apply minor content fixes to each file
for f in glob.glob("docs/api/Classes/*.md") + glob.glob("docs/api/Namespaces/*.md"):
    fixed = content_fixes(open(f).read())
    open(f, "w").write(fixed)

# update sidebar with class list
class_files = [f for f in sorted(glob.glob("docs/api/Classes/*.md")) if not f.endswith("README.md")]

class_list_str = ""
for fname in class_files:
    content = open(fname).read()
    m = re.match(r"# barkeep::(.+)", content)
    class_name = m.group(1)
    path = fname.removeprefix("docs/")
    class_list_str += f"    * [{class_name}]({path})\n"

sidebar = "docs/_sidebar.md"
content = open(sidebar).read()
content = re.sub(r"<!-- api -->.*<!-- /api -->",
                 f"<!-- api -->\n{class_list_str}<!-- /api -->", content, flags=re.DOTALL)
open(sidebar, "w").write(content)