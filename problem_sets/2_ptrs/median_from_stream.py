from heapq import heappush, heappushpop

"""
conceptually easy to understand ... 2 pQ
with same or 1 diff size.
first half using maxQ to surface middle
second half using minQ to surface middle

but once your ordering of operation
is wrong, or the comparison formula is wrong ...

this is flow from stephan...

push pop to second half and put it back to first
then you can ensure what is on 1st half is always
something less than what is on the second half.

and because you are using the 2nd half to check
the number relationship, second half should always
have len >= 1st half. Hence you can then check ...
if len(second) < len(first), then you should move
middle number back to second half
"""


class MedianFinder:
    def __init__(self):
        self.nums = [], []

    def addNum(self, num: int) -> None:
        first, second = self.nums
        heappush(first, -heappushpop(second, num))
        if len(second) < len(first):
            heappush(second, -heappop(first))

    def findMedian(self) -> float:
        first, second = self.nums
        if len(second) > len(first):
            return float(second[0])
        return (-first[0] + second[0]) / 2.0
