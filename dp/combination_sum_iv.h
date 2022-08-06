class Solution {
  public:
    std::vector<int> dp;
    int combinationSum4(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        dp = std::vector<int>(target + 1, -1);
        dp[0] = 1;
        return dfs(nums, target);
    }

    int dfs(const vector<int>& nums, int target) {
        if (dp[target] != -1)
            return dp[target];
        int res = 0;
        for (auto n : nums) {
            if (target < n) {
                break;
            }
            res += dfs(nums, target - n);
        }
        return dp[target] = res;
    }
};