/*
You could have use map as well, making key being start of interval, value is end
of interval ...etc.
*/

class SummaryRanges {
  std::vector<std::vector<int>> intervals;

 public:
  SummaryRanges() = default;
  void addNum(int value) {
    // first interval with end >= value
    auto it = std::lower_bound(
        intervals.begin(), intervals.end(), std::vector<int>{value, value},
        [](const auto& a, const auto& b) { return a[1] < b[1]; });
    if (it == intervals.end()) {
      if (intervals.empty() || (*std::prev(it))[1] != value - 1) {
        // all existing intervals are smaller than new value and largest
        // interval can't be merged with new value
        intervals.insert(it, {value, value});
      } else {
        (*std::prev(it))[1] = value;
      }
    } else {
      // there is an existing interval with end >= value. The value could either
      // extend the interval because it's smaller than start of the interval. Or
      // it's simply being included already.
      int& start = (*it)[0];
      if (start > value) {
        if (start == value + 1) {
          start = value;  // we can extend the existing one
        } else {
          // existing range is disjoint with new value
          it = intervals.insert(it, {value, value});
        }
        // we need to see if we need to further merge front
        // [3, 3] [5, 5], insert 4, => [3, 3][4, 5] => [3, 5]
        // or
        // [3, 4] [6, 6], insert 4, => [3, 3][4, 4][6, 6] => [3, 4][6, 6]
        //
        // it can only further merge front once as we only insert single number
        // in each addNum, so no while loop is needed
        if (it != intervals.begin() && (*std::prev(it))[1] == value - 1) {
          (*std::prev(it))[1] = (*it)[1];
          intervals.erase(it);
        }
      }
    }
  }

  vector<vector<int>> getIntervals() const { return intervals; }
};
