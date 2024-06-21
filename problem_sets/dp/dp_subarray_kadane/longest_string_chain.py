# from @lee125
# sort the list first, make dp a dictionary so that it's easier to check if a
# word even exists, and for a word w, just try to remove one char a time to see
# if predecessor exists. If predecessor exists, then the longest chain of that
# word w must be max(dp[w's predecessor]) + 1


class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        dp = {}
        for w in sorted(words, key=len):
            dp[w] = max(dp.get(w[:i] + w[i + 1 :], 0) + 1 for i in range(len(w)))
        return max(dp.values())
