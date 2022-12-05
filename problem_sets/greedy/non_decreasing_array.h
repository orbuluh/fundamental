class Solution {
  public:
    bool checkPossibility(vector<int>& nums) {
        int decreasingCnt = 0;
        for (int i = 1; i < nums.size() && decreasingCnt <= 1; ++i) {
            if (nums[i] >= nums[i - 1])
                continue;
            // in order to remove one element, need to consider remove nums[i]
            // or nums[i-1]

            // As we keep the array non-increasing below,
            // if i - 2 >= 0, nums[i-2] must be the second largest.
            // so ...
            // [3, 4, 2, ...] --> the case that need to remove nums[i]
            //        ^           because if remove nums[i-1], nums[i-2] >
            //        nums[i]
            // [1, 4, 2 ...]  --> for these 2 cases, remove nums[i-2] must be
            // better [4, 2, ...]
            //
            // Also to maintain the fact that nums is increasing, we use replace
            // value to represent removing the element
            decreasingCnt++;
            if (i - 2 < 0 || nums[i - 2] <= nums[i]) {
                nums[i - 1] = nums[i]; // e.g. remove nums[i-1]
            } else {
                nums[i] = nums[i - 1]; // e.g. remove nums[i]
            }
        }
        return decreasingCnt <= 1;
    }
};