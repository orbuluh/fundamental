/*

say a b c d e >= target

we should always be okay to move the left pointer

as if b c d e also >= target, then it must be a shorter result

than b c d e f ...

and if b c d e < target, we are going to do the next check that is starting
from the new left pointer b. So we are not losing any potential candidates.

*/
class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int l = 0, r = 0, n = nums.size(), sum = 0, minLen = INT_MAX;
    while (r < n) {
      sum += nums[r++];
      while (sum >= target) {
        minLen = std::min(minLen, r - l);
        sum -= nums[l++];
      }
    }
    return minLen != INT_MAX ? minLen : 0;
  }
};