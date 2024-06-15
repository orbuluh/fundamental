class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        """
        seems like subsequence can be different order ...

        after sorting, we use minimum number as the unique
        sub-solution identifier ... in each iteration, it's like
        for the subsequence that must include this nums[i]
        as minimum, how many combinations could it generates.

        so for each iteration, we need to find the maximum
        nums[r] where nums[l] + nums[r] <= target. As nums[l]
        must present, the combination we will add is basically
        chose or to not chose from nums[l+1] -> nums[r], so
        adding 2 ** (r - l)

        for example [3, 4, 5] sub-solution. min is 3, max is 5
        valid subsequence are [3], [3, 4],  [3, 5], [3, 4, 5]
        """
        l, r, res = 0, len(nums) - 1, 0
        mod = 10**9 + 7
        while r >= l:
            if nums[l] + nums[r] > target:
                r -= 1
            else:
                res += pow(2, (r - l), mod)
                l += 1
        return res % mod
