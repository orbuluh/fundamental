class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::vector<std::vector<int>> res;
        std::sort(intervals.begin(), intervals.end(),
                  [](const auto& a, const auto& b) {
                      return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
                  });
        res.emplace_back(std::move(intervals.front()));
        for (int i = 1; i < intervals.size(); ++i) {
            if (res.back()[1] >= intervals[i][0]) {
                res.back()[1] = std::max(res.back()[1], intervals[i][1]);
            } else {
                res.emplace_back(std::move(intervals[i]));
            }
        }
        return res;
    }
};
