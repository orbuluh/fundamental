class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums = sorted(nums)
        n = len(nums)
        closet = sum(nums[:3])
        for i in range(n - 2):
            j, k = i + 1, n - 1
            while (j < k):
                s = nums[i] + nums[j] + nums[k]
                if s == target:
                    return target
                if abs(s - target) < abs(closet - target):
                    closet = s
                if s > target:
                    k -= 1
                else:
                    j += 1
        return closet


class SolutionTryHard:
    # The try hard version inspired from solution distribution ...
    # generalize with kSumCLoset

    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        return self.KSumClosest(nums, 3, target)

    def KSumClosest(self, nums: List[int], k: int, target: int) -> int:
        # base case - we basically return 0, and let the parent k == 1
        # problem to iterate the nums and find the closest
        if k == 0:
            return 0
        n = len(nums)
        if n == k:
            return sum(nums)
        # optimization - smallest sum >= target - no need to check further
        closest = sum(nums[:k])
        if closest >= target:
            return closest
        # optimization - largest sum <= target - no need to check further
        closest = sum(nums[-k:])
        if closest <= target:
            return closest
        # recursion using one element plus remaining elements of k - 1 problem
        for i, v in enumerate(nums):
            if n - i < k:
                break
            rec_res = v + self.KSumClosest(nums[i + 1:], k - 1, target - v)
            if rec_res == target:
                return target
            if abs(rec_res - target) < abs(closest - target):
                closest = rec_res
        return closest
