/*
Note: this one can't use unionFind to solve. Consider the case:
[[1],[],[0,3],[1]]

All room will be group together, but you actually will stuck with 0 -> 1
Overall it's because this problem is directed graph!
*/

class Solution {
 public:
  std::bitset<1000> seen;
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    const int n = rooms.size();
    std::queue<int> toTravel;
    toTravel.push(0);
    seen.set(0);
    while (!toTravel.empty() && seen.count() < n) {
      int i = toTravel.front();
      toTravel.pop();
      for (auto nxt : rooms[i]) {
        if (seen.test(nxt)) {
          continue;
        }
        toTravel.push(nxt);
        seen.set(nxt);
      }
    }
    return seen.count() == n;
  }
};