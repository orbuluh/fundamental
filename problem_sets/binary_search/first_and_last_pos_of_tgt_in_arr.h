// Check notes/binary_search.md for reasoning.

class Solution {
  int firstOccur(const vector<int>& nums, int l, int r, int target) {
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] >= target) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return l;
  }
  int lastOccur(const vector<int>& nums, int l, int r, int target) {
    while (l < r) {
      int mid = l + (r - l + 1) / 2;
      if (nums[mid] <= target) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    return r;
  }

 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.empty()) return {-1, -1};
    const int lastIdx = nums.size() - 1;
    int l = 0;
    int r = lastIdx;
    int firstIdx = firstOccur(nums, l, r, target);
    if (nums[firstIdx] != target) {
      return {-1, -1};
    }
    return {firstIdx, lastOccur(nums, firstIdx, lastIdx, target)};
  }
};