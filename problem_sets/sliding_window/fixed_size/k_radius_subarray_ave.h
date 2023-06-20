static const int io_trick = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
}();

class Solution {
 public:
  vector<int> getAverages(vector<int>& nums, int k) {
    const int n = nums.size();
    int wSz = 2 * k + 1;
    std::vector<int> res(n, -1);
    long sum = 0;
    for (int i = 0, mid = k, l = 0; i < n; ++i) {
      sum += nums[i];
      if (i >= wSz) {
        sum -= nums[l++];
      }
      if (i >= wSz - 1) {
        res[mid++] = sum / wSz;
      }
    }
    return res;
  }
};