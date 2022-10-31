/*
Say dp[i][j] store the max len of palindromic subsequence in s[i:j] (inclusive)

dp[i][i] = 1
dp[i][i+1] = 2 ... if s[i] == s[i + 1]
             1 ... otherwise

Then we try to expand 2 chars from each side till we can't

dp[i][j] =
    dp[i + 1][j - 1] + 2                  ... if s[i] == s[j]
    std::max(dp[i + 1][j], dp[i][j - 1])  ... otherwise

The "otherwise" logic is the critical part to figure out...

as even though s[i] != s[j],
- maybe s[i] forms a longer palindrome with s[i + 1] or
- maybe s[j] forms a longer palindrome with s[j - 1]

Consider the example:

0 1 2 3 4
b b b a b

dp[2][2] = 1 How about dp[1][3]?
- since s[0] != s[3], it's not dp[2][2] + 2
- but would it equal to dp[2][2] == 1? also no! as s[1] forms a longer
  palindrome "bb" with s[2]
- the same thing could have happen, if substring is _baa_ instead of _bba_,
  where s[3] forms a longer palindrome "bb" with s[2]
- So you can imagine: dp[1][3] = std::max(dp[1][2], dp[2][3]) = 2

Then dp[0][4] = dp[1][3] + 2 = 4!

Overall you cans see that you will be building a 2D dp. But how to travel to
ensure it's bottom up and creating the solution for subproblem before building a
bigger one?

You can either do this: making sure it's checking range of string in an
increasing way.

(Or - you can also use dfs - listed as commented code below. It would basically
 become a top-down approach)
*/

class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    const int sz = s.size();
    std::vector<std::vector<int>> dp(sz, std::vector<int>(sz, 0));
    for (int i = 0; i < sz; ++i) {
      dp[i][i] = 1;  // size 1 substring
    }
    for (int i = 0; i < sz - 1; ++i) {  // size 2 substring
      dp[i][i + 1] = 1 + (s[i] == s[i + 1]);
    }
    for (int d = 2; d < sz; ++d) {        // check each size >= 3 substring
      for (int i = 0; i + d < sz; ++i) {  // for each searching from index 0
        if (s[i] == s[i + d]) {
          // 2 + shrink 1 from left (i -> i + 1) and
          // shrink 1 from right (i + d -> i + d - 1)
          dp[i][i + d] = 2 + dp[i + 1][i + d - 1];
        } else {
          // larger of shrink 1 from left or shrink 1 from right
          dp[i][i + d] = std::max(dp[i + 1][i + d], dp[i][i + d - 1]);
        }
      }
    }
    return dp[0][sz - 1];
  }
};

/*
// DFS top down ... Actually quicker in OJ!!!

class Solution {
 public:
  std::vector<std::vector<int>> dp;
  int longestPalindromeSubseq(const string& s) {
    const int sz = s.size();
    dp = std::vector<std::vector<int>>(sz, std::vector<int>(sz, 0));
    return dfs(s, 0, sz - 1);
  }
  int dfs(std::string_view s, int i, int j) {
    if (i > j) {
      return 0;
    }
    if (i == j) {
      return 1;
    }
    if (dp[i][j] != 0) {
      return dp[i][j];
    }
    if (s[i] == s[j]) {
      return dp[i][j] = dfs(s, i + 1, j - 1) + 2;
    }
    return dp[i][j] = max(dfs(s, i + 1, j), dfs(s, i, j - 1));
  }
};
*/