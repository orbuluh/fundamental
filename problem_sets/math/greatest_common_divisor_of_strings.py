"""
say, str1 = mGCD, str2 = nGCD,
str1 + str2 = (m + n)GCD = str2 + str1

e.g.

str1+str2 == str2+str1 if and only if str1 and str2 have a gcd

then how to find GCD?

len(str1) = m * len(gcd)
len(str2) = n * len(gcd)

so basically, max gcd portion should be equal to
gcd(len(str1), len(str2))

"""


class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        return str1[: gcd(len(str1), len(str2))] if (str1 + str2 == str2 + str1) else ""
