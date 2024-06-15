class Solution:
    # check you cpp solution for detail explanation...
    def maxArea(self, height: List[int]) -> int:
        n = len(height)
        area, l, r = 0, 0, n - 1
        while l < r:
            area = max(area, (r - l) * min(height[l], height[r]))
            # how do we shrink? we shrink to find a better solution.
            # how can the area grow while we shrink the width? we must have
            # better height. What's the height that decide the area?
            # min(left height, right height). So we should move the bar with
            # lower bar. And when we do so, we are not losing any potential
            # better area
            if height[l] <= height[r]:
                l += 1
            else:
                r -= 1
        return area