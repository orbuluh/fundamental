/*
There is an optimal math solution ...check ../math/min_of_max_of_array_math.h

Binary search idea ... we feed the array an maxVal such that all the value
in the array after operations must be <= maxVal.

And because we can only move larger value to the left, it will be like the

If nums[i] < maxVal:
- the difference can be "borrowed" to value afterwards
  e.g. credit += maxVal - nums[i]

If nums[i] > max:
- It must borrow value from previous result
  e.g. credit -= (nums[i] - maxVal)

And if credit is ever < 0, it means that we don't have enough number to flow to
the left. So we need to feed it with a larger maxVal. Overall, binary search
on the maxVal accordingly
*/

class Solution {
 public:
  bool canBeLE(const vector<int>& nums, long maxVal) {
    long credit = 0;
    for (auto n : nums) {
      credit += (maxVal - n);
      if (credit < 0) {
        return false;
      }
    }
    return true;
  }
  int minimizeArrayValue(vector<int>& nums) {
    long l = 0;
    long r = 1'000'000'000;
    // want to find the first value evaluates to true
    while (l < r) {
      long mid = l + (r - l) / 2;
      if (canBeLE(nums, mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return r;
  }
};