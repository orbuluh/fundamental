"""
Check you cpp implementaiton for explanation
"""


class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        nums = sorted(zip(nums1, nums2), key=lambda p: p[1], reverse=True)
        n1vals = []
        cur_sum = 0
        max_seen = sum(nums1[:k]) * min(nums2[:k])
        for n1, n2 in nums:
            if len(n1vals) == k:
                cur_sum -= heapq.heappop(n1vals)
            heapq.heappush(n1vals, n1)
            cur_sum += n1
            if len(n1vals) == k:
                max_seen = max(max_seen, cur_sum * n2)
        return max_seen
