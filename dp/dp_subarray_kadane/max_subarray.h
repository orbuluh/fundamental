class Solution {
  /* Kadane's algorithm

  Basically a DP to find the max subarray sum including i
  when adding nums[i], and if the sum becomes negative, because subarray is
  contiguous, number before and including i just can't be part of the max
  subarry so we can basically the sum seen so far and see if can find a bigger
  sum later
  */

 public:
  int maxSubArray(vector<int>& nums) {
    int sum = nums[0];
    int maxSum = sum;
    for (int i = 1; i < nums.size(); ++i) {
      if (sum < 0) sum = 0;
      sum += nums[i];
      maxSum = std::max(maxSum, sum);
    }
    return maxSum;
  }
};