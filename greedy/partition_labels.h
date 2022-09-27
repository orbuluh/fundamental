/*
Idea: you don't really need to know the initial position of a char, you just
need to know the end of it, as the end would have decide the least close
position for the group.

Consider: a b a b c
a's end is at pos 2, but before hitting 2, we find that b's end pos is 3, so
we know eventually the group has the end at 3
*/
class Solution {
 public:
  vector<int> partitionLabels(string s) {
    auto idx = [&](int idx) { return s[idx] - 'a'; };
    std::vector<int> lastIdx(26, 0);
    for (int i = 0; i < s.size(); ++i) {
      lastIdx[idx(i)] = i;
    }
    std::vector<int> res;
    int start = 0, end = -1;
    for (int i = 0; i < s.size(); ++i) {
      auto charLastIdx = lastIdx[idx(i)];
      end = std::max(charLastIdx, end);
      if (i == end) {
        res.push_back(end - start + 1);
        start = i + 1;
      }
    }
    return res;
  }
};