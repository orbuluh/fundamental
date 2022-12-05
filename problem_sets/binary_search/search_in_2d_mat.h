class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix.front().size();
    int totalSize = m * n;
    int l = 0, r = totalSize - 1;
    auto val = [&](int idx) {
      const int i = idx / n;
      const int j = idx % n;
      return matrix[i][j];
    };
    while (l < r) {
      const auto mid = l + (r - l) / 2;
      const auto midVal = val(mid);
      if (midVal == target)
        return true;
      else if (midVal < target) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return val(l) == target;
  }
};