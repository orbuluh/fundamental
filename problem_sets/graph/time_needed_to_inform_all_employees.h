/*
The really critical performance is that you can actually not rebuilt the adjMap
and travel from the root manager.

Instead, each employee to root manager is basically single path. So you can
do this basically from bottom employee to root manager.

And you can just utilize informTime to track the total time accordingly!!!

(If you rebuild the adjMap and go root manager to bottom employee, it's much
more slower even with the io_trick...)
*/

static const int io_trick = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
}();
class Solution {
 public:
  int numOfMinutes(int n, int headID, vector<int>& manager,
                   vector<int>& informTime) {
    const int sz = manager.size();
    int res = 0;
    for (int i = 0; i < sz; ++i) {
      res = std::max(res, dfs(i, manager, informTime));
    }
    return res;
  }

  int dfs(int i, vector<int>& manager, vector<int>& informTime) {
    if (manager[i] != -1) {
      informTime[i] += dfs(manager[i], manager, informTime);
      manager[i] = -1;
    }
    return informTime[i];
  }
};