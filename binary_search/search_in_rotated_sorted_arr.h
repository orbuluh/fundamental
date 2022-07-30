/*
Idea: Rotation makes array to two ascending parts.
if we find nums[i] < nums[j], we must know that between
i and j are on the same part. And if target is in such
part, then nums[i] < target < nums[j] must meet.
We can then behave accordingly.

Those duplicated test case really fail you several times...
Consider case like this:

[1 1 2 1 1 1 1 1]
[1 1 1 1 1 1 2 1]
*/
class Solution {
  public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[mid] > nums[l]) { // ascending [l:mid+1] part
                if (nums[l] <= target && target < nums[mid]) {
                    // if target is in the ascending part
                    r = mid - 1;
                } else { // otherwise, target in the right part
                    l = mid + 1;
                }
            } else if (nums[mid] < nums[l]) { // ascending [mid r+1] part
                // note, if mid < l, rotation must happen <= mid, so mid to
                // r (inclusive) must be ascending.
                if (nums[mid] < target && target <= nums[r]) {
                    // if target is in the ascending part
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else { // not sure rotation point nor target
                // but as nums[mid] == nums[l] and not equal to target
                // we can always move left
                l++;
            }
        }
        // mid is bias to l, so eventually we converge to l
        return nums[l] == target;
    }
};