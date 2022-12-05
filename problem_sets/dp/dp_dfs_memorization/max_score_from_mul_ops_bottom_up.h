class Solution {
  // sIdx == startIdx for nums
  // eIdx == endIdx for nums
  // mIdx == index for mlt
  //
  // dp(sIdx, eIdx, mIdx) means
  // mlt[mIdx] is multiplied with either nums[sIdx] or nums[eIdx]
  //
  // the recursion will be like
  // dp(sIdx, eIdx, mIdx) = max(
  //    mlt[mIdx] * nums[sIdx] + dp(sIdx + 1, eIdx, mIdx + 1),
  //    mlt[mIdx] * nums[eIdx] + dp(sIdx, eIdx - 1, mIdx + 1)
  // )
  //
  // [observation 1]:
  // eIdx is always a function of sIdx and mIdx:
  // e.g. sIdx = 3 means we use 3 elements from begin,
  // if mIdx = 4, means we've consumed 4 elements in total
  // so we must have consumed mIdx - sIdx == 1 from the back
  // so the valid eIdx will be nums.size() - 1 - (mIdx - sIdx)
  //
  // we conclude:
  // dp(sIdx, mIdx) = max(
  //    mlt[mIdx] * nums[sIdx] + dp(sIdx + 1, mIdx + 1),
  //    mlt[mIdx] * nums[eIdx] + dp(sIdx,     mIdx + 1)
  // )
  //
  // [observation 2]:
  // When we are using mIdx = X, it means we've used X elements at this
  // point, the valid sIdx is either ...
  // (a) sIdx is 0, which means ...
  //   we've always used the end of nums for the previous X operations
  // (b) sIdx is X, which means
  //   we've always used the start of nums for the previous X operations
  //
  // [observation 3]:
  // the result of mIdx depends on mIdx + 1, so we are filling the dp
  // from larger mIdx, which means the base case should be when mIdx == m - 1
  // when mIdx is m - 1, it means we are at the end of mIdx
  // we don't need to check the recursion from mIdx == m, so:
  //
  // dp(sIdx, m - 1) = max(
  //    mlt[m - 1] * nums[sIdx],
  //    mlt[m - 1] * nums[eIdx]
  // )
  // where from observation 2, we know the valid sIdx is [0, m - 1] inclusive

 public:
  std::vector<std::vector<int>> dp;
  int maximumScore(vector<int>& nums, vector<int>& mlt) {
    const auto n = nums.size();
    const auto m = mlt.size();
    dp = std::vector(m, std::vector(m, 0));
    for (int mIdx = m - 1; mIdx >= 0; --mIdx) {
      // we are using mIdx means we've used mIdx number/operations
      const int operationCnt = mIdx;  // just for clarity
      for (int sIdx = 0; sIdx <= operationCnt; ++sIdx) {
        const auto eIdx = n - 1 - mIdx + sIdx;
        if (sIdx > eIdx) continue;
        int takeS = 0, takeE = 0;
        if (mIdx != m - 1) {
          takeS = nums[sIdx] * mlt[mIdx] + dp[sIdx + 1][mIdx + 1];
          takeE = nums[eIdx] * mlt[mIdx] + dp[sIdx][mIdx + 1];
        } else {
          takeS = nums[sIdx] * mlt[mIdx];
          takeE = nums[eIdx] * mlt[mIdx];
        }
        dp[sIdx][mIdx] = std::max(takeS, takeE);
      }
    }
    return dp[0][0];
  }
};
