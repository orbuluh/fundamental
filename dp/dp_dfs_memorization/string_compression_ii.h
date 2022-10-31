/*

From: https://youtu.be/UIK00l_AiPQ

Observation 1:

a       --> a     len = 1
aa      --> a2    len = 2
a{9}    --> a9    len = 2
a{10}   --> a10   len = 3
a{99}   --> a99   len = 3
a{100}  --> a100  len = 4

--> *encoding length only change when same char combo is
     1->2, 9->10, 99->100)
    *encoding always have len <= original len, can't make it longer


Observation 2: an intuition of dfs:

traverse the whole string and make decision whether to remove a char and
do a k--. When k is 0, nothing else can be changed. The result is decided.
So currentIdx, k(Left) is something needed in a state.

Observation 3: you need to know what's the current string you are working on

            idx   012345
For example, s = "aabbaa", k = 2.

Imagine, you are deleting 2 chars from the first 4 chars aabb, you can get:
1. remove aa, get bb, which makes s' = "bbaa", encode = "b2a2"
2. remove ab, get ab, which makes s' = "abaa", encode = "aba2"
2. remove bb, get aa, which makes s' = "aaaa", encode = "a4"

So if you are doing dfs for the state search of index 4 of s, e.g. 'a'
you need to know what is the last char of previous result.
E.g. if last char of previous result is also 'a', we can concatenate and make
a not bigger encoded len! So the state also need the information of lastChar.
Also, you need to know the combo count of lastChar.


Conclusion:

The state we need to do dfs:
- index where we are searching at the moment
- kLeft, how many chars can we further delete
- lastChar, last char of previous state
- lastCombo, running len/combo count of last char of previous state

Terminate: kLeft = 0

Recursion:

dp[index][kLeft][lastChar][lastCombo]
  = if (s[index] == lastChar):
      carry + dp[index + 1][kLeft][lastChar][lastCombo + 1]
      where carry = (lastCombo == 1 | lastCombo == 9 || lastCombo == 99)
    else:
      min(
        dp[index + 1][kLeft - 1][lastChar][lastCombo], // you remove s[i]
        1 + dp[index + 1][kLeft][s[index]][1], // you keep s[i], checking new
                                               // combo for s[i] which starts a
                                               // new char with len 1
      )

This method would have got a TLE (if you use 4D vector) or memory exceed stack
overflow (if you use 4D array and memset), though.

So how do you do better? Here comes the tricky part: instead of trying to keep
track of what is latest characters and its combo - you dfs in a different way.

say dp[i][k] := min len to encode s[i:] with at most k deletion


Say you search string from index i, then with s[i], you try:

(1) delete the s[i]: then dp[i+1][k-1] = dp[i][k]
(2) keep the s[i] through assuming s[i] is the character to keep - and
    everything else should be removed. (e.g. to achieve what the question asked,
    for a specific string, we should always try to make the char with max
    frequency to stay around, which could have give a better compression.)

    So it's searching through finding an index j, where you make s[i, j]
    (inclusive) to be all equal to s[i]. E.g. you will have to consume
    count(s[x] != s[i] for x for index from i to j).

    e.g. dp[i][k] = encodeLen(sum(s[x] == s[i] for x from i to j)) +
                    dp[j+1][k - i_to_j_neq_si]

*/

class Solution {
  static constexpr int invalid = INT_MAX / 2;
  int dp[101][101];
  int n = 0;

 public:
  int getLengthOfOptimalCompression(string s, int k) {
    n = s.size();
    memset(dp, -1, sizeof(dp));
    return dfs(s, 0, k);
  }

  int dfs(std::string_view s, int index, int kLeft) {
    if (kLeft < 0) return invalid;
    if (n - index <= kLeft) return 0;  // kLeft large enough to delete all
    auto& res = dp[index][kLeft];
    if (res != -1) return res;
    res = dfs(s, index + 1, kLeft - 1);  // remove s[i]
    int len = 0;
    int same = 0;
    int diff = 0;
    for (int x = index; x < n && diff <= kLeft; ++x) { // keep s[i]
      // how to keep? by assuming s[i] being what shouldn't be deleted
      if (s[x] == s[index]) {
        ++same;
        if (same <= 2 || same == 10 || same == 100) ++len;
      } else {
        ++diff;
      }
      res = std::min(res, len + dfs(s, x + 1, kLeft - diff));
    }
    return dp[index][kLeft] = res;
  }
};

/* TLE 4D vector implementation..

class Solution {
  static constexpr int invalid = INT_MAX / 2;
  static constexpr int WontMatchChar = 26;  // 0 - 25 are valid char
  using D1Vec = std::vector<int>;
  using D2Vec = std::vector<D1Vec>;
  using D3Vec = std::vector<D2Vec>;
  using D4Vec = std::vector<D3Vec>;
  D4Vec dp;

 public:
  int getLengthOfOptimalCompression(string s, int k) {
    dp = D4Vec(s.size(), D3Vec(k + 1, D2Vec(27, D1Vec(101, -1))));
    return dfs(s, 0, k, WontMatchChar, 0);
  }

  int dfs(std::string_view s, int index, int kLeft, int lastChar,
          int lastCombo) {
    if (kLeft < 0) return invalid;
    if (index + kLeft >= s.size())
      return 0;  // you can delete all the remaining
    int& ans = dp[index][kLeft][lastChar][lastCombo];
    if (ans != -1) return ans;

    if (s[index] - 'a' == lastChar) {
      ans = (lastCombo == 1 || lastCombo == 9 || lastCombo == 99) +
            dfs(s, index + 1, kLeft, lastChar,
                lastCombo + 1);  // concatenate s[index]
    } else {
      ans = std::min(
          dfs(s, index + 1, kLeft - 1, lastChar, lastCombo),  // remove s[index]
          1 + dfs(s, index + 1, kLeft, s[index] - 'a', 1)     // keep s[index]
      );
    }
    return ans;
  }
};
*/