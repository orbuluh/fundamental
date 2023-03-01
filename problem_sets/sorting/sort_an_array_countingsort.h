/*
The question gives you the range of value - so you can just use counting sort

1 <= nums.length <= 5 * 10^4
-5 * 10^4 <= nums[i] <= 5 * 10^4
*/
static constexpr int offset = 5 * 10'000;
static constexpr int numRange = 2 * offset + 1;

class Solution {
  static std::array<int, numRange> Bucket;
public : vector<int> sortArray(vector<int>& nums) {
    Bucket = {};
    for (auto n : nums) {
      Bucket[n + offset]++;
    }
    int idx = 0;
    for (int i = 0; i < numRange; ++i) {
      while (Bucket[i] > 0) {
        nums[idx++] = i - offset;
        Bucket[i]--;
      }
    }
    return std::move(nums);
  }
};

std::array<int, numRange> Solution::Bucket = {};