/*
Your original idea is that for each index, you decide to whether append it to
the back of the string, or make it a new element. And if you want to make it a
new element, the previous back of the string must be a palindrome. This way
actually create much more temporary string along the way.

Below is from others, the thinking is more like from each index, you exhaust the
way to find a palindrome! This way you can use index on s to check the candidate
, and it's also a clean way to think!
*/

class Solution {
 public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> cur;
    backtrack(ans, s, 0, cur);
    return ans;
  }

  bool isPalindrome(std::string_view s, int l, int r) {
    while (l < r) {
      if (s[l++] != s[r--]) {
        return false;
      }
    }
    return true;
  }

  void backtrack(vector<vector<string>>& ans, std::string_view s, int start,
                 vector<string>& cur) {
    if (start == s.size()) {
      ans.push_back(cur);
      return;
    }
    const int n = s.size();
    for (int end = start; end < n; ++end) {
      if (isPalindrome(s, start, end)) {
        cur.emplace_back(s.substr(start, end - start + 1));
        backtrack(ans, s, end + 1, cur);
        cur.pop_back();
      }
    }
  }
};