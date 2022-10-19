#!/usr/bin/env python3
from pathlib import Path
import re
from collections import defaultdict
from jinja2 import Environment, FileSystemLoader
import os

scriptDir = os.path.dirname(os.path.realpath(__file__))
environment = Environment(loader=FileSystemLoader(scriptDir))
template = environment.get_template("readme.jinja")

context = {}
content_dump = defaultdict(list)
cnt_per_chapter = {}
total_count = 0

for posix_file_path in Path(f"{scriptDir}/..").rglob('README.md'):
    file = posix_file_path.as_posix()
    folder = file.split("/")[-2]
    if folder == "notes" or folder == "..": continue
    with open(file, "r") as f:
        count = 0
        for line in f:
            m = re.search("^#.*:.*https://leetcode.com/.*.h\)", line)
            if m:
                title = re.search("\[(.*\d+?\..*?)\]", line).group(1)
                content_dump[folder] += [title]
                count += 1
            else:
                # subsection, force it to header 2
                m = re.search("^#.*?\s(.*)", line)
                if m:
                    content_dump[folder] += [f"## {m.group(1)}"]
        cnt_per_chapter[folder] = count
        total_count += count

context = {
    "content_dump": content_dump,
    "cnt_per_chapter": cnt_per_chapter,
    "total_count": total_count,
}
filename = f"{scriptDir}/../README.md"
with open(filename, mode="w", encoding="utf-8") as fo:
    fo.write(template.render(context))