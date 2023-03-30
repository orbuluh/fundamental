/*

The isScrambleDFS shows the brute force recursive solution that will get TLE.

But the crucial part is how to put index for scrambling:

say s1 with size = sz, and we are scrambling s1 with 2 parts.
  first part with size = k, second part with size = sz - k

  The scramble behavior is like checking
    Prefix of size k in s1 with prefix of size k in s2, and remaining
    - s1[0 ... k - 1] and s2[0 ... k - 1]
    - s1[k ... sz - 1] and s2 [k ... sz - 1]
  OR:
    Prefix of size k in s1 with suffix of size k in s2, and remaining
    - s1[0 ... k - 1] and s2[sz - k ... sz - 1]
    - s1[k ... sz - 1] and s2[0 ... sz - k - 1]


Indicies is critical to build the correct recursion... (and pretty hard to wrap
around my head...)

How the dp way of recording the scramble is not intuitive ... but basically
you are building the comparison result of each individual substring

e.g. dp[len][i][j] , which indicates whether
     s1[i...i+len-1] is a scramble of s2[j..j+len-1].

Means: now we only compare substring with size len in s1/s2:
  s1 substring indicies from i -> i + len - 1
  s2 substring indices from j -> j + len - 1

The scramble behavior is like checking:
  Prefix of size k in s1 with prefix of size k in s2, and remaining
    - s1[i ... i + k - 1] and s2[j ... j + k - 1]
        => e.g. dp[k][i][j]
    - s1[i + k ... i + len - 1] and s2 [j + k ... j + len - 1]
        => e.g. dp[len - k][i + k][j + k]
  OR:
    Prefix of size k in s1 with suffix of size k in s2, and remaining
    - s1[i + len - k ... i + len - 1] and s2[j ... j + k - 1]
        => e.g. dp[k][i + len - k][j]
    - s1[i ... i + len - k - 1] and s2[j + k ... j + len - 1]
        => e.g. dp[len - k][i][j + k]

And we are building the result bottom up where comparing the substring of
shorter len in s1/s2 till the full len.

*/

class Solution {
 public:
  bool isScramble(string s1, string s2) {
    const int sz = s1.size();
    using Bool1D = std::vector<bool>;
    using Bool2D = std::vector<Bool1D>;
    using Bool3D = std::vector<Bool2D>;
    auto dp = Bool3D(sz + 1, Bool2D(sz, Bool1D(sz, false)));
    for (int i = 0; i < sz; ++i) {
      for (int j = 0; j < sz; ++j) {
        dp[1][i][j] = s1[i] == s2[j];
      }
    }
    for (int len = 2; len <= sz; ++len) { // build the result bottom up
      for (int i = 0; i <= sz - len; ++i) {
        for (int j = 0; j <= sz - len; ++j) {
          for (int k = 1; k < len && !dp[len][i][j]; ++k) {
            // comparing s1[i ... i + len - 1] and s2[j ... j + len - 1]
            // and we exhaust all the break point with len k
            dp[len][i][j] = dp[len][i][j] ||
                            (dp[k][i][j] && dp[len - k][i + k][j + k]) ||
                            (dp[k][i + len - k][j] && dp[len - k][i][j + k]);
          }
        }
      }
    }

    return dp[sz][0][0];
  }
  bool isAnagram(std::string_view s1, std::string_view s2) {
    std::array<int, 26> counter = {};
    const int sz = s1.size();
    for (int i = 0; i < sz; ++i) {
      counter[s1[i] - 'a']++;
      counter[s2[i] - 'a']--;
    }
    for (int i = 0; i < 26; ++i) {
      if (counter[i] != 0) {
        return false;
      }
    }
    return true;
  }
  bool isScrambleDFS(std::string_view s1, std::string_view s2) {
    if (s1 == s2) {
      return true;
    }
    const int sz = s1.size();
    if (sz <= 1) {
      return false;
    }
    if (!isAnagram(s1, s2)) {
      return false;
    }
    for (int len = 1; len <= sz - 1; ++len) {
      if (isScrambleDFS(s1.substr(0, len), s2.substr(sz - len, len)) &&
          isScrambleDFS(s1.substr(len), s2.substr(0, sz - len))) {
        return true;
      }
      if (isScrambleDFS(s1.substr(0, len), s2.substr(0, len)) &&
          isScrambleDFS(s1.substr(len), s2.substr(len))) {
        return true;
      }
    }
    return false;
  }
};