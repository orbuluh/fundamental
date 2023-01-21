/*
recursion ...
every time might try to take 1 - 3 digits
*/
class Solution {
 public:
  vector<string> restoreIpAddresses(string s) {
    if (s.size() > 12) {
      return {};
    }
    std::vector<std::string> ans;
    backtrack(ans, s, 0, 3);
    return ans;
  }

  void backtrack(std::vector<std::string>& ans, std::string s, int idx,
                 int dotLeft) {
    if (idx >= s.size()) {
      return;
    }
    if (dotLeft == 0) {
      if (s[idx] == '0') {
        if (idx == s.size() - 1) {
          ans.emplace_back(std::move(s));
        }
      } else if (s.size() - idx <= 3) {
        if (std::stoi(s.substr(idx)) <= 255) {
          ans.emplace_back(std::move(s));
        }
      }
      return;
    }

    for (int len = 1; len <= 3; ++len) {
      if (s[idx] == '0' && len > 1) {
        return;
      }
      if (idx + len >= s.size()) {
        return;
      }
      // after taking extra len size and consume one more dot, the remaining
      // chars need to at least needs dotLeft chars (1 dot left, 2 chars least)
      int charLeft = int(s.size()) - idx - len;
      if (charLeft < dotLeft) {
        return;
      }
      // also one dot left, maximally 6 chars left. If more than the limit, we
      // are consuming too less char here.
      if (charLeft > dotLeft * 3) {
        continue;
      }
      if (std::stoi(s.substr(idx, len)) <= 255) {
        // "123456" --> idx == 0, len == 3
        // "123.456" ==> next idx should be 4 after insertion
        auto newS = s.substr(0, idx + len) + '.' + s.substr(idx + len);
        backtrack(ans, std::move(newS), idx + len + 1, dotLeft - 1);
      }
    }
  }
};