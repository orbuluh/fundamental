/*
When you encounter a stack like problem, consider 2-pointers to make the memory
complexity O(1)
*/
class Solution {
 public:
  string removeStars(string s) {
    int i = 0;
    int nxtWrite = 0;
    const int sz = s.size();
    while (i < sz) {
      if (s[i] == '*') {
        nxtWrite--;
      } else {
        std::swap(s[nxtWrite++], s[i]);
      }
      i++;
    }
    return s.substr(0, nxtWrite);
  }
};