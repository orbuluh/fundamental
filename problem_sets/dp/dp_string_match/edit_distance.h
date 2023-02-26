
/*

Say f(s1, s2) being the min operations to make s1 and s2 the same.

Say s1 = aX where a is single char and X is the remainder of s1
    s2 = bY where b is single char and Y is the remainder of s2

To calculate f(aX, bY):

if a == b:
  - f(aX, aY) = f(X, Y)
if a != b:
  through insertion:
  - insert b in s1: f(aX, bY) = 1 + f(abX, bY) = 1 + f(aX, Y)
  - insert a in s2: f(aX, bY) = 1 + f(aX, abY) = 1 + f(X, bY)

  through deletion:
  - delete a in s1: f(aX, bY) = 1 + f(X, bY)
  - delete b in s2: f(aX, bY) = 1 + f(aX, Y)

  through replacement:
  - f(aX, bY) = 1 + f(aX, aY) = 1 + f(bX, bY) = 1 + f(X, Y)

=> overall, effect of insert in s1/s2 == delete in s2/s1
   so we can conclude ... for "min" operations, it should equal to
   the result of either the 3 operations:
   - 1 + f(aX, Y),
   - 1 + f(X, bY),
   - 1 + f(X, Y)

=> what's the bottom case in this recursion?

- f("", "") = 0
- f(X, "") = len(X)
- f("", Y) = len(Y)

How to model f(s1, s2)?

say dp[i][j] is min operations to match s1[i:] and s2[j:]
then f(s1, s2) = dp[0][0], and we build the dp from the bottom case:

The bottom case is: dp[s1sz:][:] => case of f("", Y)
                    dp[:][s2Sz:] => case of f(X, "")

then, dp[s1sz:][j] = s2sz - j (e.g. Y is substr(s2[j:], with len s2Sz - j)
same, dp[i][s2sz:] = s1sz - i (e.g. X is substr(s1[i:], with len s1Sz - i)

then dp[i][j] can be built from the bottom case with:

dp[i][j] = if s1[i] = s2[j]: dp[i+1][j+1]  //e.g. f(X, Y)
           else: 1 + min(
             dp[i][j+1],                   //e.g. f(aX, Y)
             dp[i+1][j],                   //e.g. f(X, bY)
             dp[i+1][j+1]                  //e.g. f(X, Y)
           )
*/
class Solution {
 public:
  int minDistance(string s1, string s2) {
    const int s1Sz = s1.size();
    const int s2Sz = s2.size();
    std::vector<std::vector<int>> dp =
        std::vector<std::vector<int>>(s1Sz + 1, std::vector<int>(s2Sz + 1, 0));
    for (int i = 0; i < s1Sz; ++i) {
      dp[i][s2Sz] = s1Sz - i;
    }
    for (int j = 0; j < s2Sz; ++j) {
      dp[s1Sz][j] = s2Sz - j;
    }
    for (int i = s1Sz - 1; i >= 0; --i) {
      for (int j = s2Sz - 1; j >= 0; --j) {
        dp[i][j] = dp[i + 1][j + 1];
        if (s1[i] != s2[j]) {
          dp[i][j] =
              1 + std::min(dp[i][j], std::min(dp[i][j + 1], dp[i + 1][j]));
        }
      }
    }
    return dp[0][0];
  }
};