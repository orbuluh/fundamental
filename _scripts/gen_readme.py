#!/usr/bin/env python3
import glob
import re
from collections import defaultdict
from jinja2 import Environment, FileSystemLoader
import os

scriptDir = os.path.dirname(os.path.realpath(__file__))
environment = Environment(loader=FileSystemLoader(scriptDir))
template = environment.get_template("readme.jinja")

context = {}
content_dump = defaultdict(list)
count = 0

for file in glob.glob(f"{scriptDir}/../**/README.md"):
    folder = file.split("/")[-2]
    with open(file, "r") as f:
        for line in f:
            m = re.search("^#.*:.*https://leetcode.com/.*.h\)", line)
            if m:
                content_dump[folder] += [line.strip()]
                count += 1

context = {
    "content_dump": content_dump,
    "count": count,
}
filename = f"{scriptDir}/../README.md"
with open(filename, mode="w", encoding="utf-8") as fo:
    fo.write(template.render(context))