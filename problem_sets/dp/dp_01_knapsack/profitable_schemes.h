/*
zero knapsack problem ... to take or not to take

dp[i][j] stores number of scheme to achieve
- profit at least i with j ppl still available

And in each iteration, we consider extra crime to commit and build the dp table
(e.g. for each iteration, we introduced one extra option to build the result,
so it's considering independent state along the way)

for a new crime with (p, g), what should happen?

When without that new crime, say we have create profit i and still have j ppl
available, now we can pass that number of scheme to i + p, j - g in this
iteration, (and i + p should be capped at minProfit, as more than minProfit is
consider the same case in this problem.

so overall dp[i+p][j-g] += dp[i][j]


The ordering of loop and how it iterate matters though, haven't really figure
out the clear idea of bottom up. Need to think this later...
*/

class Solution {
  static constexpr int mod = 1e9 + 7;

 public:
  int profitableSchemes(int n, int minProfit, vector<int>& group,
                        vector<int>& profit) {
    std::vector<std::vector<int>> dp(minProfit + 1, std::vector<int>(n + 1, 0));
    dp[0][0] = 1;

    const int crimeSz = group.size();
    for (int c = 0; c < crimeSz; ++c) {
      // each iteration, we consider one extra crime
      const int g = group[c];
      const int p = profit[c];
      for (int j = n; j >= g; --j) {
        for (int i = 0; i <= minProfit; ++i) {
          const int profit = std::min(minProfit, i + p);
          dp[profit][j] = (dp[profit][j] + dp[i][j - g]) % mod;
        }
      }
    }
    int res = 0;
    for (int g = 0; g <= n; ++g) {
      res = (res + dp[minProfit][g]) % mod;
    }
    return res;
  }
};