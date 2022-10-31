/*
Say dp[i] is number of ways to decode while ending at index i

... s[i - 2] s[i - 1] s[i]

so to end at s[i], it could be

case 1. s[i-1] and s[i] form a num within [10, 26]
case 2. s[i] itself is not 0 and form a single digit.

When case 1 is valid, because there is single way to transform
s[i-1] and s[i] to the 2 digits number, the number of ways
to be able to do so will be equal to dp[i - 2]

When case 2 is valid, number of ways will be equal to dp[i - 1]
(because the same, you can only decode s[i] to 1 result)
*/

class Solution {
 public:
  int numDecodings(string s) {
    std::vector<int> dp(s.size(), 0);
    if (s[0] == '0') return 0;
    if (s.size() == 1) return 1;

    auto canBe2digit = [&s](int i) {
      if (i >= s.size()) return 0;
      int num = (s[i - 1] - '0') * 10 + (s[i]) - '0';
      return (num >= 10 && num <= 26) ? 1 : 0;
    };

    dp[0] = 1;
    dp[1] = (s[1] != '0') + canBe2digit(1);

    for (int i = 2; i < s.size(); ++i) {
      // 2 digit ending at i
      dp[i] += canBe2digit(i)? dp[i - 2]: 0;
      // one digit ending at i
      dp[i] += (s[i] != '0')? dp[i - 1]: 0;
    }
    return dp.back();
  }
};