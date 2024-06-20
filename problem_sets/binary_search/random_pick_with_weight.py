class Solution:
    """
    1 2 3
    1 3 6 - cdf + binary search
    bisect_right to get first element > random value
    for example, r = 1.3 -> we should chose idx 1
    r = 4, we should chose idx 2
    how about last index? should be included. Like you rand 5 - it should point
    you to take the last index. so it's all good
    """

    def __init__(self, w: List[int]):
        self.w = w
        for i in range(1, len(w)):
            self.w[i] += w[i - 1]

    def pickIndex(self) -> int:
        r = random.uniform(0, self.w[-1])
        i = bisect.bisect_right(self.w, r)
        return i
