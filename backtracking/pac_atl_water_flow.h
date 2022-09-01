/*
If you keep trying to only traverse once ... it would be hard to think...
It turns out all the best answer are basically doing one thing ...
traverse from pacific border, then traverse again from atlantic border
Then just gather the result...
*/
class Solution {
 public:
  static constexpr std::array<int, 5> dir = {-1, 0, 1, 0, -1};
  int m = 0;
  int n = 0;
  inline int idx(int r, int c) { return r * n + c; }

  using Flag = std::bitset<40000>;
  using TravelQ = std::queue<std::pair<int, int>>;

  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    m = heights.size();
    n = heights[0].size();
    TravelQ pQ; // pacificQ
    TravelQ aQ; // atlanticQ
    Flag pSeen; // flag for visited
    Flag aSeen; // flag for visited

    for (int i = 0; i < m; ++i) {
      pQ.emplace(i, 0);
      pSeen.set(idx(i, 0));
      aQ.emplace(i, n - 1);
      aSeen.set(idx(i, n - 1));
    }
    for (int j = 0; j < n; ++j) {
      pQ.emplace(0, j);
      pSeen.set(idx(0, j));
      aQ.emplace(m - 1, j);
      aSeen.set(idx(m - 1, j));
    }

    Flag pacific;  // flag for reachable
    bfs(heights, pQ, pSeen, pacific);

    Flag atlantic;  // flag for reachable
    bfs(heights, aQ, aSeen, atlantic);

    vector<vector<int>> res;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int index = idx(i, j);
        if (pacific.test(index) && atlantic.test(index)) {
          res.emplace_back(vector<int>{i, j});
        }
      }
    }
    return res;
  }

  void bfs(vector<vector<int>>& heights, TravelQ& queue, Flag& seen,
           Flag& flag) {
    while (!queue.empty()) {
      auto [r, c] = queue.front();
      queue.pop();
      int index = idx(r, c);
      flag.set(index);

      for (int d = 0; d < 4; ++d) {
        int nr = r + dir[d];
        int nc = c + dir[d + 1];
        const auto nextIdx = idx(nr, nc);
        if (nr < 0 || nr >= m || nc < 0 || nc >= n || seen.test(nextIdx) ||
            heights[nr][nc] < heights[r][c]) {
          continue;
        }

        seen.set(nextIdx);
        queue.emplace(nr, nc);
      }
    }
  }
};