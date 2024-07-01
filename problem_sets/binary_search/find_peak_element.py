class Solution:
    """
    You are either on the peak, or the road to the peak ...
    peak must exist, and around the peak, it must be increasing on the left
    and decreasing on the right. E.g. if you know the left element to you
    is greater , you can say either that is peak or there must be a greater
    element than this on the left side. likewise logic for element right to you.
    if the array is flat, then eventually converging to either side is answer
    """

    def findPeakElement(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1
        while left < right:
            mid = left + (right - left) // 2
            if nums[mid - 1] < nums[mid] and nums[mid] > nums[mid + 1]:
                return mid
            elif nums[mid] < nums[mid - 1]:
                right = mid
            else:
                left = mid + 1
        return left
