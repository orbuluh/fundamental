/*
The critical thing is don't do a erase on intervals while merging, it's just
slow and you will get a TLE
*/
class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end());
    std::vector<std::vector<int>> result({{intervals.front()}});
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] <= result.back()[1]) {
        result.back()[1] = std::max(result.back()[1], intervals[i][1]);
      } else {
        result.emplace_back(std::move(intervals[i]));
      }
    }
    return result;
  }
};