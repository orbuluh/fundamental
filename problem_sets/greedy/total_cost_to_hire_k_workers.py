"""
idea is to get the first x and last x members into a minheap
then gradually update the minheap
index is what is hard here though, use left and right to indicate the
left bound index that you "have" moved into minheap, and vise versa.
when we've include everyone into minheap? When left < right - 1!
(not just "left < right" - otherwise when left + 1 == right, you are basically
 push right twice!!)
"""


class Solution:
    def totalCost(self, costs: List[int], k: int, x: int) -> int:
        n = len(costs)
        left, right = x - 1, n - x
        min_heap = []
        for i in range(x):
            heappush(min_heap, (costs[i], i))
        for j in range(max(left + 1, right), n):
            heappush(min_heap, (costs[j], j))
        total_cost = 0
        while k:
            k -= 1
            cost, idx = heappop(min_heap)
            total_cost += cost
            # note, if left + 1 == right, then it has been pushed!
            # so the condition here is left < right - 1
            if left < right - 1:
                if idx <= left:
                    left += 1
                    heappush(min_heap, (costs[left], left))
                else:
                    right -= 1
                    heappush(min_heap, (costs[right], right))
        return total_cost
