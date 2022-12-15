/*
dp[i][j] = length of longest common subsequence using s1[i:] and s2[j:]
(Note, doesn't say s1[i] and s2[j] need to be included to the matched subseq.
 overall when thinking about the below recursion, think about what dp[i][j]
 represents!)

The recursion is
- if s1[i] == s2[j], dp[i][j] = dp[i+1][j+1] + 1
- else, since s1[i] or s2[j] won't contribute longer result, it should be
  either maximum of ...
    - dp[i+1][j] --> s1[i] won't contribute longer result,
                        so s1[i+1:] match s2[j] equal to s1[i] match s2[j]
    - dp[i][j+1] --> s2[j] won't contribute longer result
                        so s2[j] match with s1[i] equal to s2[j+1] match s1[i]

Note 1: you could (but dont need to) add dp[i+1][j+1] into the max equation
of the else branch. Why not need to? Because dp[i][j] doesn't mean that s1[i]
and s2[j] need to be used, which means:

dp[i+1][j] or dp[i][j+1] must >= dp[i+1][j+1], (as each means one more char is
used to compare for the longest common)
*/

class Solution {
 public:
  int longestCommonSubsequence(string s1, string s2) {
    int dp[s1.size()][s2.size()];
    auto getVal = [&](int x, int y) {
      if (x >= s1.size() || y >= s2.size()) return 0;
      return dp[x][y];
    };
    for (int i = s1.size() - 1; i >= 0; --i) {
      for (int j = s2.size() - 1; j >= 0; --j) {
        dp[i][j] = (s1[i] == s2[j]) ? 1 + getVal(i + 1, j + 1)
                                    : max(getVal(i + 1, j), getVal(i, j + 1));
      }
    }
    return dp[0][0];
  }
};