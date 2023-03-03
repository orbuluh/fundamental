/*
With KMP,
- lps is pre-computed with O(size(needle)).
- in each iteration, i either keep moving forward or keep the same value
- worst case, i keeps the same for O(size(needle)) time
- So overall complexity should be O(size(haystack) + size(needle))
*/
class Solution {
  std::vector<int> lps;
  void buildLps(std::string_view needle) {
    const int sz = needle.size();
    lps = std::vector<int>(sz, 0);
    int j = 0;
    for (int i = 1; i < sz; ++i) {
      while (j > 0 && needle[i] != needle[j]) {
        j = lps[j - 1];
      }
      if (needle[i] == needle[j]) {
        lps[i] = ++j;
      }
    }
  }

 public:
  int strStr(string haystack, string needle) {
    buildLps(needle);
    const int hSz = haystack.size();
    const int nSz = needle.size();
    int i = 0;
    int j = 0;
    while (i < hSz) {
      int start = i;
      while (i < hSz && j < nSz && haystack[i] == needle[j]) {
        i++;
        j++;
      }
      // invariance: when break, either exhaust i/j or haystack[i] != needle[j]
      if (j == nSz) {
        //  for compare abcd and bcd, when loop break, i = 4, j = 3
        //  we find a match, and the match start at i - j = 1
        return i - j;
      }
      if (j != 0) {
        // kmp reset index and avoid redundant comparison though the lps
        j = lps[j - 1];
      } else {
        i++;
      }
    }
    return -1;
  }
};