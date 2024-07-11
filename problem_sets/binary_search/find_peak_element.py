class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1
        while left < right:
            mid = left + (right - left) // 2
            if nums[mid] > nums[mid + 1]:
                # If mid element is greater than its right neighbor,
                # then the peak lies on the left side (including mid)
                right = mid
            else:
                # If mid element is smaller than or equal to its right neighbor,
                # then the peak lies on the right side (excluding mid)
                left = mid + 1
        return left
