class Solution {
 public:
  // idea: xor with [1, n] (inclusive)
  // for example
  // toXor: 1 2 3 4
  // nums:  1 2 3 2
  // result = 4 ^ 2
  // then we xor dups with result, and we can get the missing one
  // (4 ^ 2) ^ 2 = 4

  vector<int> findErrorNums(vector<int>& nums) {
    int xorRes = 0;
    int dups = -1;
    std::bitset<10'001> seen;
    for (int i = 0; i < nums.size(); ++i) {
      xorRes ^= (i + 1) ^ (nums[i]);
      if (seen.test(nums[i])) {
        dups = nums[i];
      } else {
        seen.set(nums[i]);
      }
    }
    return {dups, xorRes ^ dups};
  }
};