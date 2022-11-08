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
    filepath = posix_file_path.as_posix()
    folder = filepath[filepath.find("../") + 3: filepath.rfind("/")]
    #print(f"{filepath} -> {folder}")
    if not folder or folder == "notes": continue
    with open(filepath, "r") as f:
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
                    # if it's a subsection with relative link, we need to adjust
                    # the relative location to the project root. Just easier to
                    # hardcode...
                    subsection = f"## {m.group(1)}"
                    subsection = subsection.replace("dp_", "dp/dp_")
                    subsection = subsection.replace("segment_tree/", "range_query/segment_tree/")
                    subsection = subsection.replace("binary_indexed_tree/", "binary_indexed_tree/segment_tree/")
                    subsection = subsection.replace("meeting_room_like/", "greedy/meeting_room_like/")
                    content_dump[folder] += [subsection]
                #else:
                    #print(f"not processing: {line}")
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