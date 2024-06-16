"""
mimic actual calculation ...
  111
  222

  222
 2220
22200

"""


class Solution:
    def multiply_one_row(self, num1_reverse: str, m: int):
        carry = 0
        res = 0
        for i, c in enumerate(num1_reverse):
            row_mul = int(c) * m + carry
            res += 10**i * (row_mul % 10)
            carry = row_mul // 10
        res += 10 ** len(num1_reverse) * carry
        return res

    def multiply(self, num1: str, num2: str) -> str:
        res = 0
        num1_rev = num1[::-1]
        for i, c in enumerate(num2[::-1]):
            res += 10**i * self.multiply_one_row(num1_rev, int(c))
        return str(res)
