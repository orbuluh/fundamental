class SolutionRecur:
    @cache
    def isPowerOfFour(self, n: int) -> bool:
        if n <= 1:
            return n == 1
        if n % 4:
            return False
        return self.isPowerOfFour(n / 4)


class Solution:
    @cache
    def isPowerOfFour(self, n: int) -> bool:
        if n <= 0:
            return False
        """
        n & (n - 1) == 0: This condition checks if n is a power of two.
        For any power of two, n & (n - 1) will be zero because there is
        only one bit set in n. For example: For n = 4 (which is 100 in
        binary), n - 1 = 3 (which is 011 in binary). 4 & 3 results in 0.
        For n = 16 (which is 10000 in binary), n - 1 = 15 (which is 01111
        in binary). 16 & 15 results in 0.

        (n & 0x55555555) != 0: This condition ensures that the single set
        bit in n (from the first condition) is at an odd position. In
        binary, 0x55555555 is 01010101010101010101010101010101, which
        has bits set at odd positions.

        This condition is specific to powers of four because in binary
        representation: Powers of four have their single set bit at
        positions like 1, 100, 10000, etc., which corresponds to odd
        positions when checked against 0x55555555.
        """
        return n & (n - 1) == 0 and (n & 0x55555555) != 0
