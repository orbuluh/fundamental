/*

All numbers are distinct. The rotation makes 2 ascending part, where
elements in first part > elements in second part
so should be something like the partial of:

Observation:
1. Within the same part, it's monotonically increasing
2. If nums[mid] < nums[l], we know that mid and l must be in different part
   and because there are only 2 parts, we know that mid to r must be in the
   second part.
3. If nums[mid] >= nums[l], we know that mid and l must be in same part and
   it's the first part.
4. Once we are sure what's the portion that is monotonically increasing, we
   can decide - if target is in that part?
   for 2. because [mid, r] is monotonically increasing, if target is in
   between, then target must be within the range, and we can safely move
   l to mid + 1 (as we've confirmed mid is not target)
   for 3. because [l, mid] is monotonically increasing, if target is in
   between, then target must be within the range, and we can safely move
   r to mid - 1 (as we've confirmed mid is not target)
*/

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    while (l < r) {  // mid can never equal to r, but could equal to l
      int mid = l + (r - l) / 2;

      if (nums[mid] == target) return mid;

      if (nums[mid] < nums[l]) {  // mid can't equal to r, but could equal to l
        // mid to r must be in second part, and they are ascending
        // question is, is target in the second part?
        if (target > nums[mid] &&
            target <= nums[r]) {  // target must be in second part
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      } else {
        // l to mid must be the first part, and they are ascending
        // question is, is target in the first part?
        if (target >= nums[l] &&
            target < nums[mid]) {  // target must be in first part
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
    }
    // we bias to l, mid eventually equal to l
    return nums[l] == target ? l : -1;
  }
};