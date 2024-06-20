/*

The Aha moment from seeing lee215's solution...
Subarray needs to be continuous elements
so it can only be 2 cases:

1. something in the middle of array
2. partially from front + partially from back

For 1. => it's the normal max subarray problem (Kadane)

How about 2? It's basically equal to

full array sum - min array sum in the middle!

Just consider: [10 -20 -30 10]

then the case 2 is equal to -30 - (-50)! E.g. because it's partial sum from
begin and partial sum from end, we subtract the middle part. And the portion we
subtract should have been the min portion to make the result max!
*/

class Solution {
 public:
  int maxSubarraySumCircular(vector<int>& nums) {
    const int n = nums.size();
    int maxSum = nums.front();
    int totalMaxSum = maxSum;
    int totalSum = nums.front();
    int minSum = nums.front();
    int totalMinSum = minSum;
    for (int i = 1; i < n; ++i) {
      totalSum += nums[i];
      maxSum = std::max(nums[i], maxSum + nums[i]);  // Kadane
      totalMaxSum = std::max(totalMaxSum, maxSum);
      minSum = std::min(nums[i], minSum + nums[i]);  // Kadane
      totalMinSum = std::min(totalMinSum, minSum);
    }
    // edge case: full array are negative, then totalSum == totalMinSum
    return totalSum == totalMinSum
               ? totalMaxSum
               : std::max(totalMaxSum, totalSum - totalMinSum);
  }
};