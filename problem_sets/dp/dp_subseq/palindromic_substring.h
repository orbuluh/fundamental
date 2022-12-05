/*
making dp[i][j] == 1 iff s[i:j] (i to j inclusive) is palindrome

dp[i][i] == 1 // single char is palindrome
dp[i][i+1] == 1 iff s[i] == s[i+1] // 2 chars with same value is palindrome

for d > 1: // substring.size() is d + 1
  dp[i][i + d] == 1 iff dp[i] == dp[i + d] and dp[i + 1][i + d - 1] is 1
  (apply to d being odd or even!)

result is the sum of the matrix basically.

How to build this bottom up? As you are building substring with longer length
based on the result of shorter length - e.g. the subproblem is substring with
shorter length. You can basically traverse using the length of substring, doing
so will make sure you are building subproblem before larger problem!

Note: DP is not really faster than the brute force, and even have worse space
complexity though, check commented solution below for a more direct way. Still
doing a DP here as it's a good base for other problem!
*/
class Solution {
 public:
  int countSubstrings(string s) {
    int sz = s.size();
    std::vector<std::vector<int>> dp(sz, std::vector<int>(sz, 0));
    int res = 0;
    for (int i = 0; i < sz; ++i) {
      res += (dp[i][i] = 1);
    }
    for (int i = 0; i < sz - 1; ++i) {
      res += (dp[i][i + 1] = s[i] == s[i + 1]);
    }
    for (int d = 2; d < sz; ++d) {
      for (int i = 0; i + d < sz; ++i) {
        if (s[i] != s[i + d]) continue;
        res += (dp[i][i + d] = dp[i + 1][i + d - 1]);
      }
    }
    return res;
  }
};

/*
// Note: DP is not really faster than the brute force, and even have worse space
// complexity though:

class Solution {
public:
    int countSubstrings(string s) {
        const auto sz = s.size();
        int res = 0;
        for (int i = 0; i < sz; ++i) {
            res += extendPalindrome(s, i, i);
            res += extendPalindrome(s, i, i + 1);
        }
        return res;
    }
    inline int extendPalindrome(std::string_view s, int left, int right) {
        int res = 0;
        while (right < s.size() && left >= 0 && s[left] == s[right]) {
            res++; left--; right++;
        }
        return res;
    }
};
*/
