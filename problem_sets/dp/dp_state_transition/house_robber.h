class Solution {
 public:
  int rob(vector<int>& nums) {
    int take = 0;
    int noTake = 0;
    for (auto n : nums) {
      auto preNoTake = std::exchange(noTake, std::max(take, noTake));
      take = std::max(take, preNoTake + n);
    }
    return std::max(take, noTake);
  }
};