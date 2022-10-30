class Solution {
 public:
  static constexpr int noWay = INT_MAX;
  int coinChange(vector<int>& coins, int amount) {
    std::vector<int> dp(amount + 1, noWay);
    dp[0] = 0;
    for (int newCoinVal : coins) {
      for (int tgt = 1; tgt <= amount; ++tgt) {
        // if (tgt == newCoinVal) will be included
        if (tgt >= newCoinVal && dp[tgt - newCoinVal] != noWay) {
          dp[tgt] = std::min(dp[tgt], 1 + dp[tgt - newCoinVal]);
        }
      }
    }
    return dp[amount] == noWay ? -1 : dp[amount];
  }
};