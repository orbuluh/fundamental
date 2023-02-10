/*
Idea is that you can do a BFS from all the land "simultaneously", how?

Maintain a queue of toTravel for grid in a particular step. At the beginning,
the queue have all the lands.

0 1 0 0 0
0 0 0 1 0
1 0 0 0 0
0 0 0 0 0

step 1 distance would look like

1 - 1 1 *       -:      island
1 1 1 - 1   ==> X:      haven't stepped on
- 1 * 1 *       *:      next iteration cell
1 * X * X       number: distance away

step 2 distance would look like

1 - 1 1 2
1 1 1 - 1
- 1 2 1 2
1 2 * 2 *

step 3 distance would look like

1 - 1 1 2
1 1 1 - 1
- 1 2 1 2
1 2 3 2 3

As in each step, you are pop'ing all the candidate cell in the step, it's
basically like you are BFS from each lands at the same time.

Overall, this has the same complexity as those DP solution, as you basically
travel the whole grid twice. (First time finding island, second time BFS, and
each cell only traversed once in the second times.)

Note that making queue to have one index (i * m + j) is just much faster than
storing pair (i, j)

further speedup using a vector to mimic the queue
*/

class Solution {
  static constexpr std::array<int, 5> dir = {1, 0, -1, 0, 1};

 public:
  int maxDistance(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid.front().size();
    std::vector<int> toTravel, nxtStepTravel;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j]) {
          toTravel.emplace_back(i * m + j);
        }
      }
    }
    if (toTravel.size() == m * n || toTravel.size() == 0) {
      return -1;
    }
    int step = 0;
    while (!toTravel.empty()) {
      nxtStepTravel.clear();
      for (int idx : toTravel) {
        const int i = idx / m;
        const int j = idx % m;
        for (int d = 0; d < 4; ++d) {
          const int ni = i + dir[d];
          const int nj = j + dir[d + 1];
          if (ni < 0 || ni >= m || nj < 0 || nj >= n || grid[ni][nj]) {
            continue;
          }
          grid[ni][nj] = 1;  // basically make it non-zero to flag as seen
          nxtStepTravel.emplace_back(ni * m + nj);
        }
      }
      std::swap(toTravel, nxtStepTravel);
      step++;
    }
    // your step++ is at the end of the iteration, so there will be extra loop
    // and just break so the return value is step - 1
    return step - 1;
  }
};