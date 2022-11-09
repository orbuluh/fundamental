/*
[6] [2] [4]

You can basically make a 2D dp to record

dp[i][j] is (x, y) where
- x = the max leaf value of using arr[i:j] (inclusive) as a subtree
- y = the non-leaf sum of subtree

[6 2 4]

dp[i][i] = arr[i]
--> dp[0][0] = 6, 0
--> dp[1][1] = 2, 0
--> dp[2][2] = 4, 0

then merge:

dp[0][1] = 6, 12
dp[1][2] = 4, 8

dp[0][2] = ..

dp[i][j] = (x, y)... from i to j, find a cut where left of cut is left subtree
and right of cut is right subtree

The cut should make a minimum of ... if you choose c, where i < c < j as cut.
dp[i][c] is the left subtree, dp[c+1][j] is the right subtree

then x should equal to max(dp[i][c][0], dp[c+1][j][0])
e.g. the larger leaf of left or right subtree and

y should equal to dp[i][c][0] * dp[c+1][j][0] + dp[i][c][1] + dp[c+1][j][1]

and you would want to find a c s.t. y will be minimized

*/
class Solution {
  struct SubTreeData {
    int maxLeafVal = 0;
    int nonLeafSum = 0;
  };

 public:
  int mctFromLeafValues(vector<int>& arr) {
    int n = arr.size();
    std::vector<std::vector<SubTreeData>> dp(
        n, std::vector<SubTreeData>(n, SubTreeData{}));
    for (int i = 0; i < n; ++i) {
      dp[i][i].maxLeafVal = arr[i];
    }
    for (int d = 1; d < n; ++d) {
      // starting from 0, 1 to 0, n - 1
      for (int i = 0; i + d < n; ++i) {
        int start = i;
        int end = i + d;
        int minNonLeafSum = INT_MAX;
        int cutMaxLeafVal = 0;
        for (int cut = i; cut < end; ++cut) {
          int nonLeafSum =
              dp[start][cut].maxLeafVal * dp[cut + 1][end].maxLeafVal +
              dp[start][cut].nonLeafSum + dp[cut + 1][end].nonLeafSum;
          if (nonLeafSum < minNonLeafSum) {
            minNonLeafSum = nonLeafSum;
            cutMaxLeafVal = std::max(dp[start][cut].maxLeafVal,
                                     dp[cut + 1][end].maxLeafVal);
          }
        }
        dp[start][end].nonLeafSum = minNonLeafSum;
        dp[start][end].maxLeafVal = cutMaxLeafVal;
      }
    }
    return dp[0][n - 1].nonLeafSum;
  }
};