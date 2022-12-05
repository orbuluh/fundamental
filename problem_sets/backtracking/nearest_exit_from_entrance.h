class Solution {
 public:
  int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    std::priority_queue<std::tuple<int, int, int>> toTravel;
    toTravel.push({0, entrance[0], entrance[1]});
    // mark the point as visited whenever it's in the toTravel queue.
    // (or you got TLE if you mark it till it's popped from queue!)
    maze[entrance[0]][entrance[1]] = '-';
    const std::array<int, 5> dir = {1, 0, -1, 0, 1};
    const int m = maze.size();
    const int n = maze[0].size();
    while (!toTravel.empty()) {
      // side note ... originally you bind the value with reference and pop
      // the element out ... which make below buggy .... if you pop, you
      // need to copy the value before it's invalidate!
      const auto [dis, r, c] = toTravel.top();
      toTravel.pop();
      if (r == 0 || r == m - 1 || c == 0 || c == n - 1) {
        if (r != entrance[0] || c != entrance[1]) {
          return -1 * dis;
        }
      }
      for (int d = 0; d < 4; ++d) {
        const int nr = r + dir[d];
        const int nc = c + dir[d + 1];
        if (nr < 0 || nr >= m || nc < 0 || nc >= n || maze[nr][nc] != '.') {
          continue;
        }
        toTravel.push({dis - 1, nr, nc});
        maze[nr][nc] = '-';
      }
    }
    return -1;
  }
};