"""
dp[i][j] == longest length of subsequence using s1[i:] and s2[j:]
"""


class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m, n = len(text1), len(text2)
        # make a n + 1 / m + 1 array so that we don't need special
        # branching for the base case. E.g. dp[m - 1][:], dp[:][n - 1]
        # can all be derived the same way
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if text1[i] == text2[j]:
                    dp[i][j] = dp[i + 1][j + 1] + 1
                else:
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1])
        return dp[0][0]
