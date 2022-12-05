/*

Fisher–Yates shuffle

5 3 1 2 4

--> each time you pick one number and swap to the last and make it fixed there.
And use the unfixed portion to generate the next number to be fixed.

So the first number has 1/n being picked.

The second number has prob of (n - 1) / n not being picked at the first run
and prob of 1 / (n - 1) being picked at the second run, so overall the second
number has ((n - 1) / n) * (1 / (n - 1)) = 1/n being picked as well.

So are the remaining numbers ...

*/

class Solution {
  vector<int> original;
  vector<int>& nums;
  int n = 0;
  std::random_device rd;
  std::mt19937 gen;
  std::vector<std::uniform_int_distribution<int>> allRangeGen;

 public:
  Solution(vector<int>& numsIn) : nums(numsIn), gen(rd()) {
    n = nums.size();
    for (int i = 0; i < n; ++i) {
      allRangeGen.emplace_back(std::uniform_int_distribution<int>(0, i));
    }
    original = nums;
  }

  vector<int> reset() { return original; }

  vector<int> shuffle() {
    for (int i = 0; i < n; ++i) {
      auto randIdx = allRangeGen[n - 1 - i](gen);
      std::swap(nums[randIdx], nums[n - 1 - i]);
    }
    return nums;
  }
};
