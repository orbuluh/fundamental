/*
Actually similar to edit distance...

Let dp[i + 1][j + 1] be the maximum number of connecting lines
between A[0..i] and B[0..j].

- E.g. dp[i+1][j] is result of A[0..i]   and B[j-1]
       dp[i][j+1] is result of A[0..i-1] and B[j]

So for finding the best result of For A[0..i] and B[0..j],

dp[i+1][j+1] = ...

we can differ 2 situations - if A[i] == B[j], the best result
we can get will be the best result from A[0..i-1] and B[0..j-1]
and plus 1, where we connect A[i] and B[j]

Supposed A[i] != B[j], the best result we can get is either
- the best from A[0..i-1] and B[j] (e.g. maybe A[i-1] == B[j]
  and form a better result) e.g. dp[i][j+1]
- or the best from A[0..i] and B[j-1] (e.g. maybe A[i] == B[j-1]
  and form a better result), e.g. dp[i+1][j]

So overall ...

dp[0][0] = dp[0][i] = dp[j][0] = 0          for all valid i/j
dp[i+1][j+1] = 1 + dp[i][j]                 if A[i] == B[j]
               max(dp[i+1][j], dp[i][j+1])  if A[i] != B[j]
*/
class Solution {
 public:
  int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (nums1[i - 1] != nums2[j - 1]) {
          dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
        } else {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        }
      }
    }
    return dp[m][n];
  }
};