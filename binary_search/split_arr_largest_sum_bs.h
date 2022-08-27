/*
Compared to the backtrack way O(m * N^2), doing this is O(N * log(sum(nums)))
Run time it's 2800 ms -> 0 ms !!...

Binary search greately improve the complexity, but quite unintuitive
say given nums, as all the number in the array are positive, no matter
how you split, the min of the largest sum of a group must at least
equal to the value of the element, e.g. say [1, 1, 100] - you can't
expect the fact that there must be a group that at least contains [100].

Also, the max of largest sum of a group must be <= sum(nums), (e.g. when
there is only one group needed. Then the max value is the sum of full
array. When there are more groups needed, the max is smaller, but we don't
really need it to be precise. We just need a upper bound and a lower bound)

Then - you can actually do a binary search, where the question becomes ...
"can you find a split way, s.t. the max of each group's sum is <= target value"

But how to answer such question? As subarry is contiguous, you can actually
do this in a greedy way - as long as you leave enough elements for the remaing
groups ... check details for the implementaion


[7, 2, 5, 10, 8] -> L = max(nums) = 10, R = sum(nums) = 32
mid = (10 + 32) / 2 = 21.
Can you find a split way s.t. all group <= 21?
[7, 2, 5] ... adding 10 exceed 21, must split
-> [10, 8] ... no more group needed, and last group <= 21 as well
-> So, yes, greedily find a split way s.t. all group <= 21?

As mid = 21 works, and we want to find minimum value, we move R = mid = 21
mid = (10 + 21) / 2 = 15.
Can you find a split way s.t. all group <= 15?
[7, 2, 5] ... adding 10 exceed 15, must split
-> [10] ... adding 8 exceed 15, must split, but we have no group left
-> So, no, we can't. Binary search, we move L = mid + 1 = 16

mid = (16 + 21) / 2 = 18
Can you find a split way s.t. all group <= 18?
[7, 2, 5] ... adding 10 exceed 18, must split
[10, 8] ... good! we move R = mid = 18

mid = (16 + 18) / 2 = 17
Can you find a split way s.t. all group <= 17?
[7, 2, 5] ... adding 10 exceed 17, must split
[10] ... adding 8 exceed 17, must split, but we have no group left
-> So, no, we can't. Binary search, we move L = mid + 1 = 18
-> And we converge. The answer is 18!!!!!!!!

*/

class Solution {
 public:
  int splitArray(vector<int>& nums, int m) {
    int minGroupSum = 0;
    int maxGroupSum = 0;
    for (int n : nums) {
      minGroupSum = max(minGroupSum, n);
      maxGroupSum += n;
    }
    while (minGroupSum < maxGroupSum) {
      int tgtGroupSum = minGroupSum + (maxGroupSum - minGroupSum) / 2;
      if (canFindSplitLeTo(nums, m, tgtGroupSum)) {
        maxGroupSum = tgtGroupSum;
      } else {
        minGroupSum = tgtGroupSum + 1;
      }
    }
    return minGroupSum;
  }

  bool canFindSplitLeTo(const vector<int>& nums, int groups, int target) {
    int i = 0;
    int groupSum = 0;
    groups--;  // minus groups at start of gathering a new group
    while (groups >= 0 && i < nums.size()) {
      if (nums[i] > target) return false;
      auto enoughElesLeft = nums.size() - 1 - i >= groups;
      if (groupSum + nums[i] > target || !enoughElesLeft) {
        groupSum = 0;
        groups--;
      } else {
        groupSum += nums[i++];
      }
    }
    return groups == 0 && i >= nums.size();
  }
};