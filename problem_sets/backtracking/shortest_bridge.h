/*
from:
https://leetcode.com/problems/shortest-bridge/solutions/189293/c-bfs-island-expansion-uf-bonus/
(check visualization there)

Idea is finding the first island, mark it with 2.
Then start to grow from the first island - where you just mark a larger number
gradually, using BFS. Eventually, you hit the 2nd island and you should know the
distance accordingly.
*/

class Solution {
 public:
  int n = 0;
  std::vector<std::pair<int, int>> toTravel;
  std::array<int, 5> dirs = {1, 0, -1, 0, 1};
  int shortestBridge(vector<vector<int>>& grid) {
    n = grid.size();
    bool firstIslandFound = false;
    for (int i = 0; i < n && !firstIslandFound; ++i) {
      for (int j = 0; j < n && !firstIslandFound; ++j) {
        if (grid[i][j]) {
          markFirstIsland(grid, i, j);
          firstIslandFound = true;
        }
      }
    }

    std::vector<std::pair<int, int>> nxtTravel;
    while (!toTravel.empty()) {
      nxtTravel.clear();
      for (const auto& [i, j] : toTravel) {
        for (int d = 0; d < 4; ++d) {
          const int ni = i + dirs[d];
          const int nj = j + dirs[d + 1];
          if (std::min(ni, nj) < 0 || std::max(ni, nj) >= n) {
            continue;
          }
          if (grid[ni][nj] == 1) {  // hit the 2nd island
            return grid[i][j] - 2;
          }
          if (grid[ni][nj] > 1) {  // path grown from 1st island
            continue;
          }
          grid[ni][nj] = grid[i][j] + 1;  // grow the bridge
          nxtTravel.emplace_back(ni, nj);
        }
      }
      std::swap(toTravel, nxtTravel);
    }
    return -1;
  }

  void markFirstIsland(vector<vector<int>>& grid, int i, int j) {
    grid[i][j] = 2;
    toTravel.emplace_back(i, j);
    for (int d = 0; d < 4; ++d) {
      const int ni = i + dirs[d];
      const int nj = j + dirs[d + 1];
      if (std::min(ni, nj) < 0 || std::max(ni, nj) >= n || grid[ni][nj] != 1) {
        continue;
      }
      markFirstIsland(grid, ni, nj);
    }
  }
};