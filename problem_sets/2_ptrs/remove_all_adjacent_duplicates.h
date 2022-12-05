class Solution {
 public:
  string removeDuplicates(string s) {
    int endOfS = -1;
    int sz = s.size();
    for (int i = 0; i < sz; ++i) {
      if (endOfS >= 0 && s[endOfS] == s[i]) {
        endOfS--;
      } else {
        s[++endOfS] = s[i];
      }
    }
    return s.substr(0, endOfS + 1);
  }
};