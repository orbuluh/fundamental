/*

Idea - sort the array and loop on first number, and use 2 ptrs for the second
and third numbers. For a fixed first number, if 3 sum is larger than target, it
means we have to shrink the third number. if 3 sum is smaller than target, we
have to increase the second number. And when second bypass third - we need to
change the first number and do the same search!
*/

class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());
    int closest = nums[0] + nums[1] + nums[2];
    for (int first = 0; first < nums.size() - 2; ++first) {
      // optional speedup
      if (first > 0 && nums[first] == nums[first - 1]) continue;
      int second = first + 1;
      int third = nums.size() - 1;
      while (second < third) {
        const int sum = nums[first] + nums[second] + nums[third];
        if (sum == target) return target;
        if (std::abs(sum - target) < std::abs(closest - target)) {
          closest = sum;
        }

        if (sum > target) {
          third--;
        } else {
          second++;
        }
      }
    }
    return closest;
  }
};