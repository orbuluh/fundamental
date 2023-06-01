class Solution {
 public:
  static std::vector<std::pair<int, int>> dir;
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    if (grid[0][0] != 0) {
      return -1;
    }
    const int n = grid.size();
    if (n == 1) {
      return 1;
    }
    grid[0][0] = 1;
    std::queue<std::pair<int, int>> toTravel;
    toTravel.emplace(0, 0);
    while (!toTravel.empty()) {
      const int sz = toTravel.size();
      for (int i = 0; i < sz; ++i) {
        auto [r, c] = toTravel.front();
        toTravel.pop();
        for (auto [dr, dc] : dir) {
          const int nr = r + dr;
          const int nc = c + dc;
          if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 0) {
            if (nr == n - 1 && nc == n - 1) {
              return grid[r][c] + 1;
            }
            grid[nr][nc] = grid[r][c] + 1;
            toTravel.emplace(nr, nc);
          }
        }
      }
    }
    return -1;
  }
};
std::vector<std::pair<int, int>> Solution::dir = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, 1}, {-1, -1}, {1, -1}};