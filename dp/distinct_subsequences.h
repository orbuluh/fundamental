/*
Basic idea:

rabbit
vvvv__
rabbbit
vvvv-__

if s[i] == t[j] - it's a match, so we can build a dp with ...
  dp[i][j] = dp[i + 1][j + 1]
else
  dp[i][j] = dp[i+1][j]  // as s[i] != t[j], we just try next i with same j

With something like this -
dp[i][j] basically means: the way to match s[i:] with t[j:], and we build this
from the back of string.

E.g. you can imagine:
- if s = 'a' and t = 'a', you can match this single char from the back, which
  yield a 1.
- if s = 'a', y = 'b', the single char have no match and yield 0.
Now adding one char in the matching case
- if s = 'ba' and t = 'ba', you can see it's like b and b match, and the result
  should be the same as subproblem s = 'a' and t = 'a'. E.g. there is only one
  way to match 'ba' and 'ba', like there is only one way to match 'a' and 'a'.


However, as the example suggests ...
when s[i] == s[j], we are not necessarily need to use i to match j, as there
could be k > i, where s[k] == s[j] as well. (Like the rabbbit) - we could use
                                                        ^^^
second b and third b to match, instead of the first and the second.

So we will need to do:

if s[i] == t[j]:
  dp[i][j] = dp[i + 1][j + 1]        (use i to match)
           + dp[i+1][j]              (skip i to match)
else
  dp[i][j] = dp[i+1][j]              (skip i as there is no match)

or simply do:
  dp[i][j] = dp[i+1][j]
  if s[i] == t[j]: dp[i][j] += dp[i + 1][j + 1]

Also base case:
- making dp has size (sizeof(s) + 1) * (sizeof(t) + 1)
- dp[:sizeof(s)][:] = 0  ... empty match with anything in t has 0 way
- dp[:][sizeof(t)] = 1   ... any substring in s match with empty has 1 way
*/
class Solution {
 public:
  int numDistinct(string s, string t) {
    const int m = s.size();
    const int n = t.size();
    std::vector<std::vector<unsigned long>> dp(
        m + 1, std::vector<unsigned long>(n + 1, 0));
    for (int i = 0; i <= m; ++i) {
      dp[i][n] = 1;
    }
    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        dp[i][j] = dp[i + 1][j];
        if (s[i] == t[j]) {
          dp[i][j] += dp[i + 1][j + 1];
        }
      }
    }

    return dp[0][0];
  }
};