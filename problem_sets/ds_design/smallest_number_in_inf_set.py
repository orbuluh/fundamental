""""
the self.vals could be an order set, or o min heap

how to track stuff? the smallest infinite set should basically include
everything larger than some number x. So when add a number >= x, since it's set
it't not going in. Say x = 5,
   [5 ...]
you could keep add 1, for example, then the set should be like
   1, 1, ...1, [5 ...]
   <--------> everything smaller than x stores in minQ

but it should have been a set, hence when pop'ing from minQ, need to pop
all val == smallest in the minQ
"""


class SmallestInfiniteSet:

    def __init__(self):
        self.smallest = 1
        self.vals = []

    def popSmallest(self) -> int:
        if self.vals:
            val = heappop(self.vals)
            while self.vals and self.vals[0] == val:
                heappop(self.vals)
            return val
        val = self.smallest
        self.smallest += 1
        return val

    def addBack(self, num: int) -> None:
        if num >= self.smallest:
            return
        heappush(self.vals, num)
