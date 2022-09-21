// The point for top down to not get a TLE is that
// 1. you have to understand that eIdx depends on sIdx and mIdx, so you don't
//    need to make an extra dimension for it.
// 2. since you can take only m numbers out of nums, the whole dp matrix only
//    requires m * m size, not n * m size.
// 3. how you decide a state hasn't traversed. There is test case that
//    (deliberately) makes you TLE when you use `if (dp[i][j] != 0)` as criteria

class Solution {
public:
    std::vector<std::vector<int>> dp;
    int maximumScore(vector<int>& nums, vector<int>& mlt) {
      dp = std::vector(mlt.size() + 1, std::vector(mlt.size() + 1, INT_MIN));
      return dfs(nums, mlt, 0, 0);
    }

    int dfs(const vector<int>& nums, const vector<int>& mlt, int sIdx, int mIdx) {
      if (mIdx >= mlt.size()) return 0;
      if (dp[sIdx][mIdx] != INT_MIN) return dp[sIdx][mIdx];
      /*
      start = 3 means we use 3 elements from begin,
      if mIdx = 4, means we've consumed 4 elements in total
      so we must have consumed mIdx - sIdx == 1 from the back
      so the valid eIdx will be nums.size() - 1 - (mIdx - sIdx) */
      const auto eIdx = nums.size() - 1 - mIdx + sIdx;
      if (sIdx == eIdx) return nums[sIdx] * mlt[mIdx];
      const int takeS = nums[sIdx] * mlt[mIdx] + dfs(nums, mlt, sIdx + 1, mIdx + 1);
      const int takeE = nums[eIdx] * mlt[mIdx] + dfs(nums, mlt, sIdx, mIdx + 1);
      return dp[sIdx][mIdx] = std::max(takeS, takeE);
    }
