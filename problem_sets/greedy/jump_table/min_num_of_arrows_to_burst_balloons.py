"""
You can basically check the 435. Non-overlapping Intervals solution
this should also be meeting room like question...

ideal is that eventually every ballon has to be shoot
c
sort with end, then see how many ballon we can taken down
with a new end value. (All the ballon before this new end should be taken care
of previously already)
"""


class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x: x[1])
        prev_end = points[0][0] - 1
        cnt = 0
        for p in points:
            if p[0] <= prev_end:
                # overlap with prev, no new arraow
                # needed
                continue
            else:
                # non-overlap, must shoot
                prev_end = p[1]
                cnt += 1
        return cnt
