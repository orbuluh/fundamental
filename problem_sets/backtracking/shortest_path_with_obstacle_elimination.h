/*
BFS plus a constraint on the cost of path is the core idea - but it's not enough
To not get a TLE, you need a correct heuristic to do the BFS.

E.g. you favor the one with a smaller path length (cause it's BFS),
then you want to find the one with a smaller cost (gives you higher chance to
break some later critical obstacles),
then (optionally, as I randomly try. But conceptually makes sense.)
favor the point that is closer to bottom right.
*/
class Solution {
 public:
  static constexpr std::array<int, 5> dir = {1, 0, -1, 0, 1};
  static constexpr int unvisited = 10'000;
  int m = 0;
  int n = 0;
  std::vector<int> costSeen;
  int idx(int row, int col) { return row * 40 + col; };

  struct State {
    int r = 0;
    int c = 0;
    int cost = 0;
    int pathLen = 0;
  };

  int shortestPath(vector<vector<int>>& grid, int k) {
    m = grid.size();
    n = grid[0].size();
    costSeen = std::vector<int>(1600, unvisited);

    auto stateComp = [](const State& s1, const State& s2) {
      // PQ favors state with smaller pathLen
      if (s1.pathLen > s2.pathLen) return true;
      if (s1.pathLen < s2.pathLen) return false;
      // Otherwise PQ favors state with smaller cost
      if (s1.cost > s2.cost) return true;
      if (s1.cost < s2.cost) return false;
      // Otherwise PQ favors point closer to bottom right
      if (s1.r < s2.r && s1.c < s2.c) return true;
      if (s1.r < s2.r) return true;
      if (s1.c < s2.c) return true;
      return false;
    };

    std::priority_queue<State, std::vector<State>, decltype(stateComp)>
        toTravel(stateComp);
    toTravel.emplace(State{0, 0, 0, 0});

    while (!toTravel.empty()) {
      auto [r, c, cost, pathLen] = toTravel.top();
      toTravel.pop();
      if (r == m - 1 && c == n - 1) {
        if (cost <= k) {
          return pathLen;
        }
        continue;
      }
      for (int d = 0; d < 4; ++d) {
        int nR = r + dir[d];
        int nC = c + dir[d + 1];
        int nIdx = idx(nR, nC);
        if (nR < 0 || nR >= m || nC < 0 || nC >= n || cost > k) {
          continue;
        }
        const int nCost = cost + grid[nR][nC];
        if (costSeen[nIdx] > nCost) {
          costSeen[nIdx] = nCost;
          toTravel.emplace(State{nR, nC, nCost, pathLen + 1});
        }
      }
    }
    return -1;
  }
};