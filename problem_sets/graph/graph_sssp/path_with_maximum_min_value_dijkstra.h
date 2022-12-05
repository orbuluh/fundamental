/*

"Dijkstra's algorithm is BFS with a priority queue"

The idea is that using Dijkstra to relax an edge in a way that you just try to
find the maximum value to walk on. Then at the end, the path must be the one
with maximum score, where the score is the value along the path.

*/
class Solution {
  std::array<int, 5> dir{1, 0, -1, 0, 1};

 public:
  int maximumMinimumPath(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid.front().size();
    std::priority_queue<std::tuple<int, int, int>> toTravel;
    int pathScore = grid[0][0];
    toTravel.emplace(grid[0][0], 0, 0);
    while (!toTravel.empty()) {
      auto [val, i, j] = toTravel.top();
      toTravel.pop();
      pathScore = std::min(pathScore, val);
      if (i == m - 1 && j == n - 1) {
        break;
      }
      for (int d = 0; d < 4; ++d) {
        int ni = i + dir[d];
        int nj = j + dir[d + 1];
        if (ni < 0 || ni >= m || nj < 0 || nj >= n || grid[ni][nj] < 0) {
          continue;
        }
        toTravel.emplace(grid[ni][nj], ni, nj);
        grid[ni][nj] = -1;
      }
    }
    return pathScore;
  }
};