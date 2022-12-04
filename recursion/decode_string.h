/*

[ always after a number. Assume recursion always deal with something inside a []

Every time encounter [, you should go one step deeper. And when the recursion
return, you should start from the next of inner layer's corresponding ]

So overall, the first time the loop inside one layer actually hits a ] is the
time to leave this layer of iteration.

*/
class Solution {
 public:
  string decodeString(string s) {
    auto res = recur(s, 0);
    return res.first;
  }

  std::pair<std::string, int> recur(std::string_view s, int idx) {
    int i = idx;
    std::string resStr;
    int numBuf = 0;
    for (; i < s.size(); ++i) {
      if (std::isdigit(s[i])) {
        numBuf = 10 * numBuf + (s[i] - '0');
      } else if (s[i] == '[') {
        auto recurRes = recur(s, i + 1);
        std::string tmp;
        tmp.reserve(numBuf * recurRes.first.size());
        while (numBuf > 0) {
          tmp += recurRes.first;
          numBuf--;
        }
        resStr += tmp;
        i = recurRes.second; // i should point to the inner recur's ]
      } else if (s[i] == ']') { // first time hitting ], time to leave
        return std::make_pair(std::move(resStr), i);
      } else {
        resStr += s[i];
      }
    }
    return std::make_pair(std::move(resStr), i);
  }
};