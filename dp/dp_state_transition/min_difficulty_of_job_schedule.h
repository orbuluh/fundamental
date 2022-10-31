/*

dp[i][d] --> start with i-th job with d days left

dp[i][0] = -1
dp[i][1] = max(job[i:])
dp[i][2] = find j, s.t. max(job[i: j)) + dp[j][1] is minimized.
                    --> note, dp[j][1] == max(job[j:]) with d == 1
...
dp[i][d] = find j, s.t. max(job[i: j)) + dp[j][d-1] is minimized.
                    --> e.g. dp[j][d-1] == max(job[j:]) with d == d - 1
*/

class Solution {
 public:
  static constexpr int invalid = INT_MAX;
  int minDifficulty(vector<int>& jobDifficulty, int d) {
    const int n = jobDifficulty.size();
    std::vector<int> dp(n, -1);
    int maxD = jobDifficulty.back();
    for (int i = dp.size() - 1; i >= 0; --i) {
      dp[i] = maxD = std::max(maxD, jobDifficulty[i]);
    }

    for (int day = 2; day <= d; ++day) {
      std::vector<int> nxtDp(n, -1);
      for (int i = 0; i < jobDifficulty.size(); ++i) {
        int maxDFromI2J = jobDifficulty[i];
        int minSumFromI2J = invalid;
        for (int j = i + 1; j < jobDifficulty.size(); ++j) {
          maxDFromI2J = std::max(maxDFromI2J, jobDifficulty[j - 1]);
          if (dp[j] != invalid) {
            minSumFromI2J = std::min(minSumFromI2J, maxDFromI2J + dp[j]);
          }
        }
        nxtDp[i] = minSumFromI2J;
      }
      std::swap(dp, nxtDp);
    }

    return dp[0] == invalid ? -1 : dp[0];
  }
};