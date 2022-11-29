/*
The idea is that you utilize binary search to find the maximum score.

The score of a path is defined by the minimum value in the path.
You can pass in a value as the minimum score a path can be.

So when you do binary search, you will be finding the last value that the check
can pass - which means you should bias to the right.

*/
class Solution {
  int m = 0;
  int n = 0;
  std::array<int, 5> dir{1, 0, -1, 0, 1};
  // just much easier to reset if it's simple 2D bool array
  bool visited[101][101] = {};

 public:
  int maximumMinimumPath(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid.front().size();
    // the binary search's maximum value is just going to be the smaller value
    // of starting and end point.
    int l = 0;
    int r = std::min(grid[0][0], grid[m - 1][n - 1]);
    while (l < r) {
      std::memset(visited, false, sizeof(visited));
      visited[0][0] = true;
      int mid = l + (r - l + 1) / 2; // bias to right
      if (pathExist(grid, 0, 0, mid)) {
        // if path exists, we can higher our criteria to see if there exists a
        // path with all value higher than such new criteria. If it exits, it's
        // going to be a path with higher value.
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    return r;
  }

  int pathExist(vector<vector<int>>& grid, int i, int j, int criteria) {
    // goal: DFS checking if a path with a value >= criteria exists
    if (i == m - 1 && j == n - 1) {
      return true;
    }
    visited[i][j] = true;
    for (int d = 0; d < 4; ++d) {
      int ni = i + dir[d];
      int nj = j + dir[d + 1];
      if (ni < 0 || ni >= m || nj < 0 || nj >= n ||
          grid[ni][nj] < criteria || visited[ni][nj]) {
        continue;
      }
      if (pathExist(grid, ni, nj, criteria)) {
        return true;
      }
    }
    return false;
  }
};