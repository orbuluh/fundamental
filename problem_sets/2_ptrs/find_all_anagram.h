/*
Idea: same as 567. The key thing is keeping a valid window of (sub)anagram of p
in s.

Use 2 pointers to maintain such invariance in the window. How? The counter of p
can't be reduced with a value less than 0. When it happens, then we need to
shrink the left (e.g. pop'ing out value in the window) till the invariant holds
again. The left pointer is basically the start of the current window.
*/
class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    std::vector<int> counter(26, 0);
    for (char c : p) {
      counter[c - 'a']++;
    }
    const int sz = s.size();
    std::vector<int> result;
    for (int l = 0, r = 0; r < sz; ++r) {
      if (--counter[s[r] - 'a'] < 0) {// invariant breaks
        while (counter[s[r] - 'a'] < 0) { // recover the invariant
          counter[s[l++] - 'a']++; // through shrinking left
        }
      }
      // window is always valid. And if size is  equal to p.size(), it must
      // be a full match!
      if (r - l + 1 == p.size()) {
        result.push_back(l);
      }
    }
    return result;
  }
};