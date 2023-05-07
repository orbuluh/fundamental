/*
Note, you can't simply do a monoIncQ directly

Consider: [5,1,5,5,1,3,4,5,1,4]

monoQ -> [5], [1], [1, 5], [1, 5, 5], [1, 1]
         [1, 1, 3], [1, 1, 3], [1, 1, 3, 4]
         [1, 1, 3, 4, 5], [1, 1, 1], [1, 1, 1, 4]

      --> but for 4, longest is
         [1, 1, 3, 4, 4] isntead, e.g. the 3
         were mistakenly took out too early

It's a LIS problem, the core is maintain a dp where for dp[i], it stores
the smallest value that can form a subsequence of length i.

nums = [2, 6, 8, 3, 4, 5, 1],

2: [2] forms the smallest value on len 1 subsequence, dp[1] = 2
6: [2, 6] forms the smallest value on len 2 subsequence, dp[2] = 6
8: [2, 6, 8] forms the smallest value on len 3 subsequence, dp[3] = 8
3: checking current dp [X, 2, 6, 8], which is a LIS itself. We find
   that 3 will form the LIS with smallest value on len 2 subarray
   dp[2] = 3, dp = [X, 2, 3, 8]
4: checking current dp [X, 2, 3, 8], 4 will replace 8 to form the smallest
   value on len 3, so dp[3] = 5, dp = [X, 2, 3, 4]
5: 5 can form the smallest value on len 5, dp[4] = 5, dp = [X, 2, 3, 4, 5]
1: 1 can only update the len 1, dp[1] = 1, dp = [X, 1, 3, 4, 5]


check out the implementation below that avoids the if/else when binary search
is at the end or not. Basically the trick is operating on index instead of on
the iterator, so you don't need to worry dereference end()!
*/

class Solution {
 public:
  vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
    const auto sz = obstacles.size();
    std::vector<int> res(sz, 0);
    std::vector<int> dp(sz, INT_MAX);
    int curLen = 0;
    dp.reserve(obstacles.size());
    for (int i = 0; i < sz; ++i) {
      const auto obs = obstacles[i];
      const int idx =
          std::upper_bound(dp.begin(), dp.begin() + curLen, obs) - dp.begin();
      dp[idx] = obs;
      curLen = std::max(curLen, res[i] = idx + 1);
    }
    return res;
  }
};