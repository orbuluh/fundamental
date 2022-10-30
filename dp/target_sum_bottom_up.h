/*
DFS method + memorization is much intuitive but much slower,
check target_sum_dfs.h

The conversion of bottom up is amazing...

Key: convert the problem to be that you are dividing all elements to 2 sets
- The first set is taking the positive value
- The second set is taking the negative value

Then say:
- `s1 = sum(set1)`
- `s2 = sum(set2)`

A valid answer should hold:
- `s1 + s2 = sum(nums)`
- `s1 - s2 = target`

So `2 * s1 = sum(nums) + target`
and `s1 = (sum(nums) + target) / 2`

- (If sum(nums) + target is odd, there can't be an answer)

And now, we basically convert the original problem to a 0/1 knapsack problem
where we want to find target value s1, where s1 is sum of a subset of value
in nums ....HOLY MOLLY....!!!!

Also, the question actually state that ...

0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000

so s1 can't be negative ... you can safely do the 0/1 knapsack

Also yet another edge case handling ... solving with target == x is the same as
solving target == -x, as it's just reversing all signs basically. But if target
is negative, it messed up your dp iteration. So you can simply make an absolute
value of target.
*/

class Solution {
 public:
  int solveAs01Knapsack(vector<int>& nums, int amount) {
      std::vector<int> dp(amount + 1, 0);
      dp[0] = 1;
      for (int newVal : nums) {
        std::vector<int> nxtDp(amount + 1, 0);
        for (int tgt = 0; tgt <= amount; ++tgt) {
          nxtDp[tgt] = dp[tgt];
          if (newVal <= tgt) {
            nxtDp[tgt] += dp[tgt - newVal];
          }
        }
        std::swap(nxtDp, dp);
      }
      return dp[amount];
  }

  int findTargetSumWays(vector<int>& nums, int target) {
    // avoid edge case, it's just reversing all signs anyway
    if (target < 0) target *= -1;
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    sum += target;
    if (sum % 2 || target > sum) {
      return false;
    }
    sum /= 2;
    return solveAs01Knapsack(nums, sum);
  }
};