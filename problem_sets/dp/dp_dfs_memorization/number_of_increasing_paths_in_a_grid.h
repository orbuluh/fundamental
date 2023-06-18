/*
Since it requires to be a strictly increasing path, you basically don't need to
worry the case that you step on a seen cell. So when you do dfs, you don't need
extra space to keep track of it. Also, the simple memorization will be just let
dp[i][j] to be the length starting from it.
*/

static const int io_trick = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
}();

class Solution {
  static constexpr int mod = 1e9 + 7;
  static constexpr std::array<int, 5> dir = {0, 1, 0, -1, 0};
  int dp[1000][1000] = {};
  int dfs(vector<vector<int>>& grid, int i, int j, int v) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() ||
        grid[i][j] <= v) {
      return 0;
    }
    if (dp[i][j]) {
      return dp[i][j];
    }
    int res = 1;
    for (int d = 0; d < 4; ++d) {
      res = (res + dfs(grid, i + dir[d], j + dir[d + 1], grid[i][j])) % mod;
    }
    return dp[i][j] = res;
  }

 public:
  int countPaths(vector<vector<int>>& grid) {
    int res = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[i].size(); ++j) {
        res = (res + dfs(grid, i, j, 0)) % mod;
      }
    }
    return res;
  }
};