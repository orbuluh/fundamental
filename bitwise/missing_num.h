class Solution {
  // xor: a ^ a = 0
  // a ^ a ^ b = 0 ^ b = b

  // imagine you are xor values in nums with 1 -> n

  // for [3, 0, 1] you are actually xor'ing..
  // (3 ^ 0 ^ 1) ^ (0 ^ 1 ^ 2 ^ 3)
  // which would give you the result 2 at the end

 public:
  int missingNumber(vector<int>& nums) {
    auto missingNum = nums.size();
    for (int i = 0; i < nums.size(); ++i) {
      missingNum ^= (i ^ nums[i]);
    }
    return missingNum;
  }
};