/*
Idea from: https://leetcode.com/problems/number-of-closed-islands/solutions/425150/java-c-with-picture-number-of-enclaves/?orderBy=most_votes

basically flood all land connected to the edges.
then flood the remaining lands
*/
class Solution {
 public:
  int m = 0;
  int n = 0;
  std::array<int, 5> dir = {1, 0, -1, 0, 1};
  int closedIsland(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid.front().size();
    auto checkFlood = [&](int r, int c) {
      if (!grid[r][c]) {
        flood(grid, r, c);
      }
    };
    // flood the boarder!
    for (int i = 0; i < m; ++i) {
      checkFlood(i, 0);
      checkFlood(i, n - 1);
    }
    for (int j = 0; j < n; ++j) {
      checkFlood(0, j);
      checkFlood(m - 1, j);
    }
    // flood the island!
    int cnt = 0;
    for (int i = 1; i < m - 1; ++i) {
      for (int j = 1; j < n - 1; ++j) {
        cnt += !grid[i][j];
        checkFlood(i, j);
      }
    }
    return cnt;
  }

  void flood(vector<vector<int>>& grid, int i, int j) {
    grid[i][j] = 1;
    for (int d = 0; d < 4; ++d) {
      int ni = i + dir[d];
      int nj = j + dir[d + 1];
      if (ni < 0 || ni >= m || nj < 0 || nj >= n || grid[ni][nj]) {
        continue;
      }
      flood(grid, ni, nj);
    }
  }
};