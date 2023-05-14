/*

Basically a smarter way to do brute force + memorization

when nums[i] and nums[j] is considered, we set the i-th and j-th bit in an int

then dp index is basically such int.

we can pre-compute all pairs of gcd. Then we iterate all possible cases though
brute-force all integers <= (1 << n).

When integer has odd number of set bits, it can't be a valid case as each time
we are using 2 numbers. So we can skip.

Then for an integer, say it has x set bits, then we know it has gone through
y = x / 2 of iterations. Then now, we are trying to find in y + 1 iteration,
what's the max possible value.

And the max possible value can be found through iterating all possible gcds that
we've pre-computed. Say for a gcd, if the pair's key & the case's key is
non-zero, then it means they have shared some set bits, then it's not a valid
case to consider (e.g. say we've taken nums[0], nums[1], we won't want to see
nums[1], nums[2]'s gcd as nums[1] has been considered.)

Eventually, we update the result accordingly. And last element of DP is
basically the place where we've considered all number.

*/
class Solution {
  static constexpr int maxMastInt = 1 << 14;

 public:
  std::unordered_map<int, int> preComputeGcds(const vector<int>& nums) {
    std::unordered_map<int, int> gcds;
    const int sz = nums.size();
    for (int i = 0; i < sz; ++i) {
      for (int j = i + 1; j < sz; ++j) {
        gcds[(1 << i) ^ (1 << j)] = std::gcd(nums[i], nums[j]);
      }
    }
    return gcds;
  }

  int maxScore(vector<int>& nums) {
    const auto gcds = preComputeGcds(nums);
    const int sz = 1 << nums.size();
    std::vector<int> dp(sz);
    for (int caseKey = 0; caseKey < sz; caseKey++) {
      const int bitsUsed = std::bitset<14>(caseKey).count();
      if (bitsUsed % 2 != 0) {
        continue;
      }
      const int iteration = bitsUsed / 2;
      for (const auto& [gcdKey, gcdVal] : gcds) {
        if (gcdKey & caseKey) {
          continue;
        }
        const auto afterCombineCaseKey = gcdKey ^ caseKey;
        dp[afterCombineCaseKey] = std::max(
            dp[afterCombineCaseKey], dp[caseKey] + (iteration + 1) * gcdVal);
      }
    }
    return dp.back();
  }
};
