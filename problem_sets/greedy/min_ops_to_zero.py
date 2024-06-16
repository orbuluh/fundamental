class Solution:
    """
    From lee215 ... holy ... the intuition is ...

    Case 1: Lone 1 at the end:

    If n has a lone 1 in its binary representation (e.g., ...00001),
    we only need one operation is needed to remove this 1.

    Case 2: Multiple 1s at the end:

    If n contains multiple consecutive 1s (e.g., ...0000111), what we
    need is adding 1 to make it flip to 0001000, then deal the lone 1
    """

    def minOperations(self, n: int) -> int:
        ops = 0
        while n:
            if n & 1 == 0:
                n >>= 1
                continue
            elif n & 3 == 3:
                # it must be ....11, there are multiple
                # 1s at the end, it's case 2. We will
                # remove this resulting 1 next time
                # when 1 surface as a lone 1
                ops += 1
                n += 1
            else:  # it must be ...01
                ops += 1
                n >>= 1
        return ops
