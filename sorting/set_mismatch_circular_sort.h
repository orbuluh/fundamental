class Solution {
  // using while loop is afar more easy than trying to make for loop work
  // what you are swapping and what to return actually might easily get wrong
 public:
  vector<int> findErrorNums(vector<int>& nums) {
    int i = 0;
    while (i < nums.size()) {
      // n should be stored at index n - 1
      // say we are now swapping the duplicated value
      // and the correctPos already contains the correct
      // duplicated value, we will just do i++ as well
      int correctPos = nums[i] - 1;
      if (nums[correctPos] != nums[i]) {
        std::swap(nums[correctPos], nums[i]);
      } else {
        i++;
      }
    }
    for (int n = 1; n <= nums.size(); ++n) {
      // a number is missing if it doesn't appear at index n - 1
      // when this happens, what is stored at index n - 1 is the dup
      if (n != nums[n - 1]) {
        return {nums[n - 1], n};
      }
    }
    return {};  // can't be
  }
};