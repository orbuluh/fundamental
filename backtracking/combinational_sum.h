class Solution {
  vector<vector<int>> result;

 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    std::vector<int> solution;
    dfs(candidates, target, solution);
    return result;
  }

  void dfs(const vector<int>& candidates, int target, vector<int>& solution) {
    if (target == 0) {
      result.emplace_back(solution);
      return;
    }
    for (auto n : candidates) {
      if (n > target) {
        break;
      }
      if (!solution.empty() && n < solution.back()) {
        // make sure the solution is unique.
        // e.g. only [2 2 3] is selected, [2 3 2] won't be
        continue;
      }
      solution.push_back(n);
      dfs(candidates, target - n, solution);
      solution.pop_back();
    }
  }
};