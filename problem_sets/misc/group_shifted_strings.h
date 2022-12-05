class Solution {
 public:
  std::string countShift(std::string_view s) {
    std::string pattern;
    for (int i = 1; i < s.size(); ++i) {
      auto offset = s[i] - s[i - 1];
      if (offset < 0) offset += 26;
      // you don't need to to_string ... (much slower), just convert it to other
      // char for hashing's sake. Also you need to add the separator, otherwise
      // one offset could have value 11, which could be the same as 2 offsets
      // with value 1 each.
      pattern += ('a' + offset) + '_';
    }
    return pattern;
  }
  vector<vector<string>> groupStrings(vector<string>& strings) {
    vector<vector<string>> res;
    std::unordered_map<std::string, int> stringToResIdx;

    for (std::string_view sv : strings) {
      auto pattern = countShift(sv);
      auto it = stringToResIdx.find(pattern);
      if (it == stringToResIdx.end()) {
        stringToResIdx[pattern] = res.size();
        res.emplace_back();
      }
      res[stringToResIdx[pattern]].emplace_back(std::string(sv));
    }
    return res;
  }
};