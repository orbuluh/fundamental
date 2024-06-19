"""
dp[i][j] means whether we can use p[:j] to match s[:i]
(note - not include j or i- as you want to use dp[0][0]
 to represent empty v.s empty)

init: dp[0][0] = 1 - empty matches empty
      dp[0][:] = 0 - unless p == "*" (or **...) 
      dp[:][0] = 0 - nothing in pattern, can't match anything

You are actually considering s[i - 1] v.s. p[j - 1] when calculating dp[i][j]
check answer for recursion ...

can use 1-D but anyway
"""


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        n, m = len(s), len(p)
        dp = [[False] * (m + 1) for _ in range(n + 1)]
        dp[0][0] = True
        for j in range(1, m + 1):
            if p[j - 1] != "*":
                break
            dp[0][j] = True
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if p[j - 1] in {s[i - 1], "?"}:
                    dp[i][j] = dp[i - 1][j - 1]
                elif p[j - 1] == "*":
                    # if p[j - 1] is *, then the question is
                    # whether p[:j - 1] can match anything.
                    # If not, the, star can't match what's in
                    # front anyway.
                    # or if we can find a match with s[:i - 1]
                    # with p[:j], then * basically can match one
                    # more to make s[:i] match with p[:k]
                    dp[i][j] = dp[i][j - 1] or dp[i - 1][j]
        return dp[-1][-1]
