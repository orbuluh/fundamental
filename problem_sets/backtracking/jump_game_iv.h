/*
Build a map about val -> indicies
BFS should solve it, where neighbor[i] = i-1, i+1, other indicies in map[val]

Performance tip: when removing entry from your map, don't need to remove the
whole key, just clear the indices vector will be much faster!!!

(using vector or queue for toVisited isn't that important)
*/

class Solution {
 public:
  std::unordered_map<int, std::vector<int>> sameVal;
  int minJumps(vector<int>& arr) {
    const int sz = arr.size();
    for (int i = 0; i < sz; ++i) {
      sameVal[arr[i]].push_back(i);
    }
    std::vector<bool> visited(sz, 0);
    visited[0] = true;
    std::vector<int> toVisited = {0};
    std::vector<int> nxtVisit;
    auto tryWalk = [&](int nxtIdx, bool canWalk = true) {
      if (!canWalk || visited[nxtIdx]) {
        return;
      }
      visited[nxtIdx] = true;
      nxtVisit.push_back(nxtIdx);
    };
    int step = 0;
    while (!toVisited.empty()) {
      nxtVisit.clear();
      for (auto idx : toVisited) {
        if (idx == sz - 1) {
          return step;
        }
        tryWalk(idx - 1, idx - 1 >= 0);
        if (idx + 1 == sz - 1) {
          return step + 1;
        }
        tryWalk(idx + 1, idx + 1 < sz);
        for (auto sameValIdx : sameVal[arr[idx]]) {
          if (sameValIdx == sz - 1) {
            return step + 1;
          }
          tryWalk(sameValIdx);
        }
        // sameVal.erase(arr[idx]); // much slower to do this!!!
        sameVal[arr[idx]].clear();
      }
      std::swap(nxtVisit, toVisited);
      step++;
    }
    return sz - 1;
  }
};