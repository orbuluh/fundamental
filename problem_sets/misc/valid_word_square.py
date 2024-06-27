"""
simply need to make sure the index you are going to access
is valid ... but ... you might stuck
"""


class Solution:
    def validWordSquare(self, words: List[str]) -> bool:
        n = len(words)
        for i in range(n):
            k = len(words[i])
            for j in range(k):
                if j >= n:
                    return False
                if len(words[j]) <= i:
                    return False
                if words[i][j] != words[j][i]:
                    return False
        return True
