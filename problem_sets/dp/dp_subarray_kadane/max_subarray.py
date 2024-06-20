class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_sum = cur_sum = nums[0]
        for v in nums[1:]:
            if cur_sum < 0:
                cur_sum = 0
            cur_sum += v
            max_sum = max(max_sum, cur_sum)
        return max_sum
