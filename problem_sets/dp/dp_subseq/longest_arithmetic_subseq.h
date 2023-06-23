/*

dp[i][d] is ending at i with difference d
then you can just try all kind of d through O(n^2) combinations
and then build the dp accordingly.

*/
class Solution {
 public:
  int longestArithSeqLength(vector<int>& nums) {
    int res = 2;
    const int sz = nums.size();
    std::vector<std::vector<int>> dp(sz, std::vector<int>(2000, 0));
    for (int i = 0; i < sz; ++i) {
      for (int j = i + 1; j < sz; ++j) {
        int d = nums[j] - nums[i] + 1000;
        dp[j][d] = std::max(2, dp[i][d] + 1);
        res = std::max(res, dp[j][d]);
      }
    }
    return res;
  }
};