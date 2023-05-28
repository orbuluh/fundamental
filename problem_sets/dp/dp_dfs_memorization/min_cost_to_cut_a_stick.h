/*

https://leetcode.com/problems/minimum-cost-to-cut-a-stick/solutions/780880/dp-with-picture-burst-balloons/

Every time you make a cut, the cut point becomes sub-stick's endpoint.
Imagine you have a range [x, z], you make a cut at y, where x < y < z
the cost will be z - x, and the subproblem will be [x, y] and [y, z]

To help with this idea where cut[i] also specify the endpoint of sticks
(or, the boundary of subproblem), we insert 0 and n into the cuts

Then we can sort the cuts, so that when we search, we are basically
maintaining searching on valid subproblem, e.g. for sub-stick[x..z], we
will only check a cut y where x < y < z

And then we can basically make

dp[i][j] to store the value of subproblem/stick starting with
i = cut[x] and j = cut[y]
*/
class Solution {
  std::vector<std::vector<int>> dp;
  int dfs(const vector<int>& cuts, int i, int j) {
    if (j - i <= 1) {
      return 0;
    }
    if (dp[i][j]) {
      return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    for (int k = i + 1; k < j; ++k) {
      dp[i][j] = std::min(
          dp[i][j], cuts[j] - cuts[i] + (dfs(cuts, i, k) + dfs(cuts, k, j)));
    }
    return dp[i][j];
  }

 public:
  int minCost(int n, vector<int>& cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    std::sort(cuts.begin(), cuts.end());
    const int sz = cuts.size();
    dp = std::vector<std::vector<int>>(sz, std::vector<int>(sz, 0));
    return dfs(cuts, 0, sz - 1);
  }
};