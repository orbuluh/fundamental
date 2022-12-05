/*
check out KMP notes, but the idea is gradually reduce pattern len and do KMP
till the pattern contains nothing.

say M = source len, N = pattern len
genLps took O(N), kmp took O(M)
and we are looping the len of pattern, hence overall it took
O(N * (M + N))

- hence we do a swap if nums1 is shorter than nums2

Space complexity is O(N) to store the lps
*/
class Solution {
 public:
  std::vector<int> genLps(const std::vector<int>& pattern) {
    std::vector<int> lps(pattern.size(), 0);
    int j = 0;
    for (int i = 1; i < pattern.size(); ++i) {
      while (j > 0 && pattern[j] != pattern[i]) {
        j = lps[j - 1];
      }
      if (pattern[i] == pattern[j]) {
        lps[i] = ++j;
      }
    }
    return lps;
  }

  int kmp(const vector<int>& nums1, const vector<int>& pattern) {
    int pIdx = 0;  // pattern index
    int maxLen = 0;
    const auto lps = genLps(pattern);
    for (int i = 0; i < nums1.size() && pIdx < pattern.size(); ++i) {
      while (pIdx > 0 && nums1[i] != pattern[pIdx]) {
        pIdx = lps[pIdx - 1];
      }
      if (nums1[i] == pattern[pIdx]) {
        pIdx++;
      }
      maxLen = std::max(maxLen, pIdx);
    }
    return maxLen;
  }

  int findLength(vector<int>& nums1, vector<int>& pattern) {
    if (nums1.size() < pattern.size()) {
      std::swap(nums1, pattern);
    }
    int maxLen = 0;
    while (pattern.size() > 0 && maxLen < pattern.size()) {
      maxLen = std::max(kmp(nums1, pattern), maxLen);
      pattern.erase(pattern.begin());
    }
    return maxLen;
  }
};