/*

Idea is that effort between 2 cell is like the weight between edges. We are
looking for a specific path from source to target, with minimum effort in the
path.

So you will always want to reach an node in a greedy way, so that we find the
minimum effort to reach that node.

As we put the effort in to Dijkstra's PQ structure, we know each time we relax
a node using an edge, it should just get the minimum effort it can be. And once
we reached the endpoint, we should find our answer.
*/
class Solution {
 public:
  static constexpr std::array<int, 5> dir = {1, 0, -1, 0, 1};
  int minimumEffortPath(vector<vector<int>>& heights) {
    int m = heights.size();
    int n = heights[0].size();
    std::vector<std::vector<int>> effort(m, std::vector<int>(n, INT_MAX));

    using State = std::pair<int, int>; // stores: effort, pos in 1-D
    // (Note: much faster than store 3 entries tuple <efforts, i, j>)
    std::priority_queue<State, std::vector<State>, std::greater<State>> pq;
    pq.emplace(0, 0);

    while (!pq.empty()) {
      auto [effortArrive, pos] = pq.top();
      pq.pop();
      const int i = pos / 100;
      const int j = pos % 100;
      if (i == m - 1 && j == n - 1) {
        return effortArrive;
      }
      if (effort[i][j] <= effortArrive) {
        continue;
      }
      // relax
      effort[i][j] = effortArrive;
      for (int d = 0; d < 4; ++d) {
        int ni = i + dir[d];
        int nj = j + dir[d + 1];
        if (ni < 0 || ni >= m || nj < 0 || nj >= n) {
          continue;
        }
        const int effortToGo =
            std::max(effortArrive, std::abs(heights[i][j] - heights[ni][nj]));
        pq.emplace(effortToGo, ni * 100 + nj);
      }
    }
    return effort[m - 1][n - 1]; // won't go to here
  }
};