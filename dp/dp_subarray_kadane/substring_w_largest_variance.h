class Solution {
  /*
  The idea is that, for all different chars pair, there is only O(26*26)
  combination. So to simplify the question, you can just focus on how to solve
  this problem with only 2 chars, then just brute force all combinations!

  And because you are trying all combination, you can separate the case for
  checking (a, b), v.s. (b, a), e.g, maybe first parameter is the higher
  frequency char and second parameter is the lower frequency char. Then variance
  should only be valid if current seen high frequency char is larger than the
  low frequency one.

  Then you basically convert this subproblem to the Kadanes!

  imagine it's a substring of high-freq-char = +1, low-freq-char = -1
  and finding variance is basically like finding maximum subarray sum!
  */
 public:
  std::unordered_map<char, int> lastPos;
  int largestVariance(string s) {
    for (int i = 0; i < s.size(); ++i) {
      lastPos[s[i]] = i;
    }
    int result = 0;
    for (int charA = 0; charA < 26; ++charA) {
      for (int charB = 0; charB < 26; ++charB) {
        if (charA == charB) continue;
        char hfChar = charA + 'a';  // hf == high frequency
        char lfChar = charB + 'a';  // lf == low frequency
        if (!lastPos.count(hfChar) || !lastPos.count(lfChar)) continue;
        result = std::max(result, getMaxVar(s, hfChar, lfChar));
      }
    }
    return result;
  }

  int getMaxVar(std::string_view s, char hfChar, char lfChar) {
    int highFreq = 0;
    int lowFreq = 0;
    int var = 0;
    for (int i = 0; i < s.size(); ++i) {
      char c = s[i];
      highFreq += (c == hfChar);
      lowFreq += (c == lfChar);
      if (highFreq > 0 && lowFreq > 0 && highFreq > lowFreq) {
        var = std::max(var, highFreq - lowFreq);
      }
      if (lowFreq > highFreq && i < lastPos[c]) {
        // abaabbb, say hfChar = b, lfChar = a,
        // max var will be the abbb, but how to see this
        // So when we do first 'a' and realize
        // there is still 'a' afterwards, we are good to just
        // "reset the Kadanes sum". As we can still form a valid
        // result later, and current string just won't make a better
        // result. This is the same for the second 'a', we just reset.
        // But for the third 'a', we must include it, otherwise the
        // remaining bbb just won't be a candidate to calculate variance
        lowFreq = 0;
        highFreq = 0;
      }
    }
    return var;
  }
};