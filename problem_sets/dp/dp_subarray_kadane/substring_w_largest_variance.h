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

  Then you basically convert this subproblem to the Kadane maxsum question!
  */
 public:
  std::vector<int> lastPos;
  int largestVariance(string s) {
    lastPos = std::vector<int> (26, -1);
    for (int i = 0; i < s.size(); ++i) {
      // so we know where is the last position of a char, check function later.
      lastPos[s[i] - 'a'] = i;
    }
    int maxVar = 0;
    for (char hfChar = 'a'; hfChar <= 'z'; ++hfChar) { // hf == high frequency
      for (char lfChar = 'a'; lfChar <= 'z'; ++lfChar) { // lf == low frequency
        if (hfChar == lfChar) continue;
        if (lastPos[hfChar - 'a'] == -1 || lastPos[lfChar - 'a'] == -1) {
          continue;
        }
        maxVar = std::max(maxVar, getMaxVarWithKadane(s, hfChar, lfChar));
      }
    }
    return maxVar;
  }

  int getMaxVarWithKadane(std::string_view s, char hfChar, char lfChar) {
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
      if (lowFreq > highFreq && i < lastPos[c - 'a']) {
        // abaabbb, say hfChar = b, lfChar = a, max var will be the abbb,
        // but how to see this?
        // When we do first 'a' and realize there is still 'a' afterwards, we
        // are good to just reset. (Basically like we see the sum becomes
        // negative in Kadances, so it can't be a better choice with what
        // currently choose.)
        // This is the same for the second 'a', we just reset when we see the
        // third 'a'. But for the third 'a', we must include it, otherwise the
        // remaining bbb just won't be a candidate to calculate variance
        lowFreq = 0;
        highFreq = 0;
      }
    }
    return var;
  }
};