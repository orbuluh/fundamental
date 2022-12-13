/*
Once you finish the DFS + memorization implementation, you will see that, in the
dfs recursion, at the bottom, it's basically return the last row's value. As
there can't be something beneath. So the row before next row will simply get
a bottom up relationship:

dp[i][j] = mat[i][j] + min(dp[i + 1][j - 1], dp[i + 1][j], dp[i + 1][j + 1])

And because when we do i-th row, we only rely  on i+1-th row, and we don't need
i+1-th row later. So we don't even need the dp structure, we can just use
original matrix to record the recursion result.
*/

class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    if (m == 1) {
      return *std::min_element(matrix.back().begin(), matrix.back().end());
    }
    auto minRes = INT_MAX;
    for (int i = m - 2; i >= 0; i--) {
      for (int j = 0; j < n; ++j) {
        int minNxt = matrix[i + 1][j];
        if (j - 1 >= 0) {
          minNxt = std::min(minNxt, matrix[i + 1][j - 1]);
        }
        if (j + 1 < n) {
          minNxt = std::min(minNxt, matrix[i + 1][j + 1]);
        }
        matrix[i][j] += minNxt;
        if (i == 0) {
          minRes = std::min(minRes, matrix[i][j]);
        }
      }
    }
    return minRes;
  }
};