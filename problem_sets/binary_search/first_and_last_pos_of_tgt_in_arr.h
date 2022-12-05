// When doing binary search, we want to always make the while loop condition
// to be while (l < r) so it's easier to further break down the scenarios.
//
// when loop is while (l < r), it means the invariant inside the loop is
// l < r, e.g. l's maximum is r - 1, or r's minimum is l + 1.
// with this being said ...
//
// when choosing mid = l + (r - l) / 2, as r's minimum is l + 1, right before
// loop breaks, mid = l + (l + 1 - l) / 2 = l - so basically the pointer will
// bias to l, which means inside your loop, you want to make sure l is always
// moving (as mid could == l, if l is not moving, you are getting infinite loop)
//
// E.g. we will be doing l = mid + 1 And when do we want to do so? when mid is
// smaller than target. This fits well when we want to find the first occurrence
// , as we are guaranteed to be okay to make l = mid + 1 whenever
// nums[mid] < target, as it means we will be doing r = mid whenever
// nums[mid] >= target - e.g. when nums[mid] == target, we make mid = r, where
// because mid can never equal to r (it can only equal to l), we are sure the
// pointer is still moving, and we won't hit infintie loop.
//
// Can we do the same for mid = l + (r - l) / 2 with l = mid + 1, in the case
// that we want to find last occurrence? Consider the fact that l = mid + 1 is
// only guaranteed ok to do when nums[mid] < target, and in the case that
// nums[mid] == target, we are moving r = mid, this basically means we are
// always shrinking the r when nums[mid] == target, so it's actually a condition
// to find the first occurrence, not last.
//
// How do we turn this around? we change mid condition so that it bias to the
// right instead. How? through mid = l + (r - l + 1) / 2, e.g. before loop
// breaks, l's maximum is r - 1, so mid = r - 1 + (r - r + 1 + 1) / 2 = r
// So mid could equal to r before break, so we need to make r = mid - 1 in our
// iteration to ensure no infinite loop. And when can we always move from mid?
// When nums[mid] < target, we always make r = mid - 1, e.g. the other side is
// when nums[mid] >= target, we make l = mid, which means we will try to move
// l when nums[mid] == target, and because mid can never equal to l, we are
// guaranteed to be shrinking the search space, which means by doing so, we are
// finding the last occurrence.


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