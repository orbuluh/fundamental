/*

You are way-over thinking when encounter this questions...

The top submissions were basically brute force...

Make a graph for the bombs that can trigger each other, and then do DFS from
each node...

Time complexity is O(n^3), because we start from n bombs and we can have upto
O(n^2) edges.

*/

class Solution {
  std::unordered_map<int, std::vector<int>> adjGraph;

 public:
  int dfs(int i, bitset<100>& seen) {
    if (!seen[i]) {
      seen.set(i);
      auto& neighbors = adjGraph[i];
      for (int j : neighbors) {
        dfs(j, seen);
      }
    }
    return seen.count();
  }
  int maximumDetonation(vector<vector<int>>& bombs) {
    const int n = bombs.size();
    for (int i = 0; i < n; ++i) {
      const int64_t x = bombs[i][0];
      const int64_t y = bombs[i][1];
      const int64_t r = bombs[i][2];
      const int64_t r2 = r * r;
      for (int j = 0; j < n; ++j) {
        if (i == j) {
          continue;
        }
        const int64_t x2 = bombs[j][0];
        const int64_t y2 = bombs[j][1];
        if (pow(x - x2, 2) + pow(y - y2, 2) <= r2) {
          adjGraph[i].push_back(j);
        }
      }
    }
    int res = 0;
    for (int i = 0; i < n && res < n; ++i) {
      bitset<100> seen;
      res = std::max(dfs(i, seen), res);
    }
    return res;
  }
};