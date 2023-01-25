/*
Idea: for each index, you decide to include or not include and then backtracking

The beautiful part is for case with same number like [2, 2, 3, 2]
the consecutive subsequence of same number is just [2], [2, 2], [2, 2, 2]

So when you meet such case, you just don't skip if nums[i] == cur.back
then you are sure to get all the combinations eventually
*/

class Solution {
 public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<vector<int>> ans;
    std::vector<int> cur;
    backTrack(nums, 0, cur, ans);
    return ans;
  }

  void backTrack(const vector<int>& nums, int i, std::vector<int>& cur,
                 vector<vector<int>>& ans) {
    if (i >= nums.size()) {
      if (cur.size() >= 2) {
        ans.emplace_back(cur);
      }
      return;
    }
    // skip nums[i] only if nums[i] != cur.back
    if (cur.empty() || (!cur.empty() && nums[i] != cur.back())) {
      backTrack(nums, i + 1, cur, ans);
    }
    // include nums[i]
    if (cur.empty() || cur.back() <= nums[i]) {
      cur.push_back(nums[i]);
      backTrack(nums, i + 1, cur, ans);
      cur.pop_back();
    }
  }
};