class Solution {
 public:
  string reverseWords(string s) {
    int start = 0;
    int end = -1;
    std::string res;

    while (start < s.size()) {
      if (s[start] == ' ') {
        start++;
        continue;
      }
      end = s.find(' ', start);
      auto rev = s.substr(start, end - start);
      std::reverse(rev.begin(), rev.end());
      res += rev + ' ';
      start = end;
    }
    res.pop_back();  // extra space at the end
    std::reverse(res.begin(), res.end());
    return res;
  }
};