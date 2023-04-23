/*

it's like painting house

dp[i] = number of ways having a number ending at i
    idx = 0123
for val = 1327, k = 40
then dp[3] = dp[1] + dp[2], as 27 and 7 are all valid choices to end at 3.
So dp[1] (ending at val 3)　and dp[2] (ending at val 2) will lead to the case of
dp[3] (ending at val 7)

(TODO: there are some optimization available, didn't check it this time.)
*/

class Solution {
  static constexpr int mod = 1e9 + 7;

 public:
  int numberOfArrays(string s, int k) {
    const int sz = s.size();
    vector<int> dp(sz, 0);
    for (int i = 0; i < sz; ++i) {
      // j: including j into the case of consideration
      // it's like 1327, when we check val = 7 at i = 3
      // we search backward for j from 3 to 0 if no early termination
      for (long j = i, val = 0, mul = 1; j >= 0 && val <= k && mul <= k; --j) {
        val += mul * (s[j] - '0');
        mul *= 10;
        // required the array isn't start with 0
        if (s[j] != '0' && val > 0 && val <= k) {
          // when j - 1 is -1, it basically means we are forming the result from
          // empty (or, start of the) array, there is always 1 way to do that.
          dp[i] = (dp[i] + (j >= 1 ? dp[j - 1] : 1)) % mod;
        }
      }
    }
    return dp.back();
  }
};