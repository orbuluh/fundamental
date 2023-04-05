/*
Math solution is super non-intuitive ... consider the binary search solution
afterwords.

The operation is, for i >= 1:
- Decrease nums[i] by 1.
- Increase nums[i - 1] by 1

Which implies:
- Sum of array will be a fixed value.
- The flow of value is only to the left

Because we want to find the min of (max val in array), we want to "flow" the
value to the left "if possible". And when do we want to do so? Only when value
in the left is smaller than value in the right.
- For [1, 10], we want to do [1, 10] -> [2, 9] -> ... [6, 5].
- For [10, 1], we don't want to do anything as one operation make it [11, 0]

So what we want to do is:

- If nums[i] < nums[i + 1], then we can repeatedly do the operations,
  until nums[i] >= nums[i + 1]. By doing so, we always let the smaller number
  upfront to help to decrease the larger number in the back.

Eventually, when we can't find such operation to do, it implies for each idx i,
nums[i] >= nums[i + 1], e.g. it's a decreasing list at the end. And when it
happens, the nums[0] should be our answer.

The question now is, how do we find out the final result without simulating the
whole flow?

- The observation is, say array [1, 5, 10]

  idx 0, ceil_ave(nums[0...0]) = 1
  idx 1, ceil_ave(nums[0...1]) = 3 < nums[1], which implies that we could flow
         nums[i] = 5 to the left (till it becomes [3, 3])
  idx 2, ceil_ave(nums[0...2]) = 6 < nums[2], which implies that we could flow
         nums[i] = 10 to the left (till it becomes [6, 5, 5])

- On the contrary, say array [10, 5, 1]
  idx 0, ceil_ave(nums[0...0]) = 10
  idx 1, ceil_ave(nums[0...1]) = 6 > nums[1], which implies we can't flow
         nums[1]'s value to the left
  idx 2, ceil_ave(nums[0...2]) = 6 > nums[2], which implies we can't flow
         nums[2]'s value to the left as well


So overall, it's like:

- Say, lb(i) = ceil(avg(sum(nums[0...i])))
- Look at index i:
  - suppose 0 to i - 1 can achieve its best lower bound lb(i - 1), then as long
    as nums[i] >= lb(i - 1), we must be able to flow the value to the left so
    eventually for nums[0...i], it achieves lb(i) for the max value
  - if nums[i] < lb(i - 1), the max should have already recorded on or before
    position i - 1.

e.g. The best we can do is to reduce nums[i] to the average of array nums[0, i],
and if we can't do the best, we should have already captured it.
*/

class Solution {
 public:
  int minimizeArrayValue(vector<int>& nums) {
    double sum = 0;
    int res = 0;
    const int sz = nums.size();
    for (int i = 0; i < sz; ++i) {
      sum += nums[i];
      res = std::max(0.0 + res, std::ceil(sum / (i + 1)));
    }
    return res;
  }
};
