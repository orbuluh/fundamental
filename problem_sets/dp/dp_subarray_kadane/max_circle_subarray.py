# check .h version for explanation
class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        total_sum = nums[0]
        min_sum = max_sum = cur_sum_for_min = cur_sum_for_max = nums[0]
        for v in nums[1:]:
            total_sum += v

            if cur_sum_for_max < 0:
                cur_sum_for_max = 0
            cur_sum_for_max += v
            max_sum = max(max_sum, cur_sum_for_max)

            if cur_sum_for_min > 0:
                cur_sum_for_min = 0
            cur_sum_for_min += v
            min_sum = min(min_sum, cur_sum_for_min)

        # edge case: when total_sum == min_sum, array all negative
        # then, max element == max_sum == answer
        return max_sum if total_sum == min_sum else max(max_sum, total_sum - min_sum)
