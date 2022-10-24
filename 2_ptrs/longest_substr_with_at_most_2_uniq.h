/*
Idea: keep a window that contains 2 distinct characters

Grow the window with right pointer till we are seeing the 3 distinct chars
Shrink the left till only one unique char left in the window

eceba
l r   --> maxLen: 3
eceba
  lr    --> move l till it's invalid, then move r till it's valid
eceba
   lr   --> move l till it's invalid, then move r till it's valid

ccaabbb
l  r
ccaabbb
  l   r --> move l till it's invalid, then move r till it's valid
*/
class Solution {
 public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    std::vector<int> seen(52, 0);
    int l = 0;
    int r = 0;
    int maxLen = 0;
    int curUniq = 0;
    auto idx = [](char c) { return c <= 'Z' ? c - 'A' : 26 + c - 'a'; };

    while (r < s.size()) {
      // the invariant is that every time entering the loop, curUniq < 2
      if (seen[idx(s[r++])]++ == 0) {
        curUniq++;
      }
      while (r < s.size() && seen[idx(s[r])] > 0) { //window can be longer
        seen[idx(s[r++])]++;
      }
      maxLen = std::max(maxLen, r - l); // input can be only "a" or so
      while (curUniq == 2 && l < r) { // try to make curUniq < 2 again
        if (--seen[idx(s[l++])] == 0) {
          curUniq--;
          break;
        }
      }
    }
    return maxLen;
  }
};