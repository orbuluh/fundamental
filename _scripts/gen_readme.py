#!/usr/bin/env python3
from pathlib import Path
import re
from collections import defaultdict
from jinja2 import Environment, FileSystemLoader
import os

scriptDir = os.path.dirname(os.path.realpath(__file__))
environment = Environment(
    loader=FileSystemLoader(scriptDir), extensions=["jinja2.ext.loopcontrols"]
)


def finalizeFile(template_file_name, output_file_name, context):
    template = environment.get_template(template_file_name)
    with open(output_file_name, mode="w", encoding="utf-8") as fo:
        fo.write(template.render(context))


##----------------------------------------------------------------------------

content_dump = defaultdict(list)
difficulty = defaultdict(int)
folder_title = {}
cnt_per_chapter = {}
total_count = 0

for posix_file_path in Path(f"{scriptDir}/..").rglob("README.md"):
    filepath = posix_file_path.as_posix()
    folder = filepath[filepath.find("../") + 3 : filepath.rfind("/")]
    # print(f"{filepath} -> {folder}")
    problemLine = "^#.*:.*https://leetcode.com/.*.h\)"
    problemTitle = "\[(.*\d+?\..*?)\]"
    with open(filepath, "r") as f:
        count = 0
        for line in f:
            m = re.search(problemLine, line)
            if m:
                title = re.search(problemTitle, line).group(1)
                content_dump[folder] += [title]
                difficultyEmoji = re.search("(:.*?:)\s", title).group(1)
                difficulty[difficultyEmoji] += 1
                count += 1
            else:
                m = re.search("^#.*?\s(.*)", line)
                if m:
                    # if it's a subsection with relative link, we need to adjust
                    # the relative location to the project root. Just easier to
                    # hardcode...
                    subsection = m.group(1)
                    subsection = subsection.replace("dp_", "dp/dp_")
                    subsection = subsection.replace(
                        "segment_tree/", "range_query/segment_tree/"
                    )
                    subsection = subsection.replace(
                        "binary_indexed_tree/", "binary_indexed_tree/segment_tree/"
                    )
                    subsection = subsection.replace(
                        "meeting_room_like/", "greedy/meeting_room_like/"
                    )
                    subsection = subsection.replace("graph_", "graph/graph_")
                    subsection = subsection.replace(
                        "fixed_size", "sliding_window/fixed_size"
                    )
                    subsection = subsection.replace(
                        "with_2_ptrs", "sliding_window/with_2_ptrs"
                    )
                    if re.search("^##", line):
                        subsection = "## " + subsection
                        content_dump[folder] += [subsection]
                    else:  # one # H1 heading for the file
                        folder_title[folder] = subsection
                        # print(f"{folder} -> {subsection}")
                # else:
                # print(f"not processing: {line}")
        cnt_per_chapter[folder] = count
        total_count += count


finalizeFile(
    "readme.jinja",
    f"{scriptDir}/../README.md",
    {
        "folder_title": folder_title,
        "content_dump": content_dump,
        "difficulty": difficulty,
        "cnt_per_chapter": cnt_per_chapter,
        "total_count": total_count,
    },
)
