class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.strip().split()[::-1]
        return " ".join(s)
