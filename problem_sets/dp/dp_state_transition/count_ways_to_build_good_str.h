/*
Let dp[i] to store number of good string with length i.
(Noted that regardless of ending with 0 or 1)

Then the dp recursion should equal to

dp[i] += dp[i - zero] + dp[i - one]
(as long as i >= zero and i >= one)
something like creating a length i string is from length - zero string appending
0 and from length - one string appending 1.
*/

class Solution {
  static constexpr int mod = 1e9 + 7;

 public:
  int countGoodStrings(int low, int high, int zero, int one) {
    std::vector<int> dp(high + 1, 0);
    dp[0] = 1;
    int res = 0;
    for (int i = 1; i <= high; ++i) {
      if (i >= zero) {
        dp[i] = (dp[i] + dp[i - zero]) % mod;
      }
      if (i >= one) {
        dp[i] = (dp[i] + dp[i - one]) % mod;
      }
      if (i >= low) {
        res = (res + dp[i]) % mod;
      }
    }
    return res;
  }
};