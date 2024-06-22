"""
idea is for either max_end_here, max_start_here, it's similar to normal Kadane
and once you have it, then you can try for the deletion case, where

max_with_delete[i] can be observed from
max_end_here[i - 1] + max_start_here[i + 1], as long as i is not 0 or n - 1
(which should have been observed already)

there is a dp state transition solution that is really nice..
check it out
"""


class Solution:
    def maximumSum(self, arr: List[int]) -> int:
        n = len(arr)
        max_start_here = [0] * n
        max_end_here = [0] * n
        max_end_here[0] = arr[0]
        max_start_here[-1] = arr[-1]
        max_sum = max(max_end_here[0], max_start_here[-1])
        for i in range(1, n):
            max_end_here[i] = max(arr[i], max_end_here[i - 1] + arr[i])
            max_start_here[n - 1 - i] = max(
                arr[n - 1 - i], max_start_here[n - i] + arr[n - 1 - i]
            )
            max_sum = max(max_sum, max_end_here[i], max_start_here[n - 1 - i])
        for i in range(1, n - 1):
            max_sum = max(max_sum, max_end_here[i - 1] + max_start_here[i + 1])
        return max_sum
