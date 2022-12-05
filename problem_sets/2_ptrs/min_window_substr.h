/*
The post to discuss the template is here:
https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems

Idea is making a counter for the tgt string to match
Loop through the src string and checking the state of counter:
- for src[i], if counter[src[i]] > 0, it means tgt contains the char

we use 2 pointers to expand the window till we match all chars in tgt
- note that after we find a right ptr of the valid window, the left ptr won't
  necessarily contain any char of tgt. Hence we can start to shrink it.
- while doing shrinking, we are basically adding counter[src[left]] back
- for src[left], if counter[src[left]] is 0, it means tgt contains the char, and
  you are going to pop it out from your valid window - which means you are
  invalid you current window!
- once you invalid your current window, you can try again to move right till you
  find the next valid window ...etc
*/
class Solution {
 public:
  string minWindow(string s, string t) {
    std::array<int, 52> counter = {};
    auto idx = [](char c) { return (c <= 'Z') ? c - 'A' : 26 + (c - 'a'); };
    for (char c : t) {
      counter[idx(c)]++;
    }
    int unmatched = t.size();
    int l = 0;
    int r = 0;
    int windowBegin = 0;
    int minLen = INT_MAX;
    while (r < s.size()) {
      if (counter[idx(s[r++])]-- > 0) unmatched--;
      while (unmatched == 0) {
        if (r - l < minLen) {
          windowBegin = l;
          minLen = r - windowBegin;
        }
        if (counter[idx(s[l++])]++ == 0) {
          unmatched++;
        }
      }
    }
    return minLen != INT_MAX ? s.substr(windowBegin, minLen) : "";
  }
};