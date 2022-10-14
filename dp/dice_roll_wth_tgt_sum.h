class Solution {
  /*
  adding once dice a time...
  dp_1[t] records #ways to use 1 dice for a target value t
  dp_2[t] records #ways to use 2 dice for a target value t

  --> dp_2[t]
       = dp_1[t - 1]   ...(new dice use val 1, previous dice form t - 1)
       + dp_1[t - 2]   ...(new dice use val 2, previous dice form t - 1)
       ...
       + dp_1[0]       ...(new dice use val t, previous dice form 0)

  --> base case, dp_0[t] is just 0 for everything,
      except that dp_0[0] is 1
      e.g: 0 dice has 1 way to form value 0
  */

 public:
  static constexpr int mod_ = 1'000'000'007;
  int numRollsToTarget(int n, int k, int target) {
    std::vector<int> dp(target + 1);
    dp[0] = 1;
    for (int diceCnt = 1; diceCnt <= n; ++diceCnt) {
      std::vector<int> dpNxt(target + 1);
      for (int val = 1; val <= k; ++val) {
        for (auto t = val; t <= target; ++t) {
          dpNxt[t] = (dpNxt[t] + dp[t - val]) % mod_;
        }
      }
      swap(dp, dpNxt);
    }
    return dp[target];
  }
};