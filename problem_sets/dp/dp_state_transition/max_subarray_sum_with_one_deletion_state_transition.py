class Solution:
    """
    dp state transition solution  ...

    no_drop_max[i] = max(no_drop_max[i - 1] + arr[i], arr[i])
        - e.g. normal Kadane
    has_drop_max[i] = max(has_drop_max[i - 1] + arr[i], no_drop_max[i - 1])
        - e.g. when "has drop", either you have dropped already and you can't drop at i
               or you drop at i, and you can't drop before

    initialize ...
    no_drop_max[0] = arr[0]
    has_drop_max[0] = None
    no_drop_max[1] = max(arr[0] + arr[1], arr[0])
    has_drop_max[1] = no_drop_max[0]

    and because no_drop_max won't rely on has_drop_max, you don't even need
    an array, O(1) space is good enough to keep the information
    """

    def maximumSum(self, arr: List[int]) -> int:
        # init when we've checked index 0 and 1
        # (as when index is 0, has_drop_max doesn't exist)
        if len(arr) == 1:
            return arr[0]
        no_drop_max = max(arr[0] + arr[1], arr[1])
        has_drop_max = max(arr[0], arr[1])
        max_sum = max(no_drop_max, has_drop_max)
        for i in range(2, len(arr)):
            # no_drop won't rely on has_drop, so you can calculate
            # has_drop first
            has_drop_max = max(has_drop_max + arr[i], no_drop_max)
            no_drop_max = max(no_drop_max + arr[i], arr[i])
            max_sum = max(max_sum, no_drop_max, has_drop_max)
        return max_sum
