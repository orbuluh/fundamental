"""
Is sorting begin the right way? Think, if there is a span
with earlier start, but with much larger span, it won't be
a better choice, simple case
[0, 100] [1, 2] [3, 4] ... [101, 102]
And how do we keep more interval?

From @stefanporchmann
Which interval would be the best first (leftmost) interval
to keep? One that ends first, as it leaves the most room for
the rest.


So, for 2 intervals with different end ...

if they are going to overlap with each other, and if we are
going to keep one, we will just take the one with smaller
end. [9, 11][3, 20], we take [10,10], as it's going to have
smaller impact for later.

if they are not overlapping, we will just take both. (no need
to erase.)

Can we have something like keeping the one with smaller end
and end up removing more? Not really

[9, 11] [10, 20][10, 21][10, 22]

in this case, if there are multiple intervals that would have
overlapped with smaller end [9, 11], they must overlap with each other
so they all have to be eliminated with each other anyway.
"""


class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda p: p[1])
        prev_end = intervals[0][0] - 1  # just make it smaller than first begin
        cnt = 0
        for interval in intervals:
            if interval[0] < prev_end:
                cnt += 1
            else:
                prev_end = interval[1]
        return cnt
