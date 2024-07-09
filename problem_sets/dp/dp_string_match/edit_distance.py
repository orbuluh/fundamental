"""

dp[i][j] = convert word1[:i] to word2[:j] (e.g. non-inclusive of i and j)

dp[0][0] = 0 (convert empty to empty need no operations)

dp[0][:] means from empty to match each len of word2 (insert into word1 to match)
         so dp[0][1] = 1
            dp[0][2] = 2
            ...
            dp[0][len(word2)] = len(word2)
dp[:][0] means from certain len to match empty (remove from word1 to match)
          so dp[1][0] = 1
             dp[2][0] = 2
             ...
             dp[len(word1)][0] = len(word1)

dp[i][j] = dp[i - 1][j - 1] iff w1[i - 1] == w2[j - 1]
           or
           1 + min(dp[i - 1][j] ...    delete s1[i - 1]
                   dp[i][j - 1] ...    insert s1[i - 1] to be same as s2[j - 1]
                   dp[i - 1][j - 1] ... replace s1[i - 1] to be s2[j - 1]
           )
"""


class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            dp[i][0] = i
        for j in range(1, n + 1):
            dp[0][j] = j
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if word1[i - 1] == word2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1])
        return dp[m][n]
