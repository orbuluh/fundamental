"""
All whole numbers can be represented by 2N (even) and 2N+1 (odd).
For a given binary number ...
- multiplying by 2 is a left shift, no more 1 appended
- a even number and its next odd number must differ one 1

countBits[N] == countBits[2N]
countBits[N] + 1 == countBits[2N + 1]
e.g.

countBits[6] == countBits[6/2] + 0
countBits[7] == countBits[7/2] + 1

"""


class Solution:
    def countBits(self, n: int) -> List[int]:
        res = [0]
        for i in range(1, n + 1):
            res += [res[i >> 1] + i % 2]
        return res
