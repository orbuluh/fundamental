/*
Shortest path you should either think of those graph algorithm, or simplest form
--> BFS.

This is a variant of BFS where, if you want to prevent infinite loop, you need
to know if a node has been reached from a red edge or not. And next edge should
only be considered if the color has alternated.
*/
class Solution {
 public:
  struct EdgeInfo {
    EdgeInfo(bool r, int n) : isRed(r), dstNode(n){};
    bool isRed = false;
    int dstNode = 0;
  };
  struct TravelInfo {
    TravelInfo(int n, int d, bool r) : node(n), distance(d), fromRedEdge(r){};
    int node = 0;
    int distance = 0;
    bool fromRedEdge = false;
  };
  using AdjMat = std::unordered_map<int, std::vector<EdgeInfo>>;
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                       vector<vector<int>>& blueEdges) {
    AdjMat adjMat;
    for (const auto& e : redEdges) {
      adjMat[e[0]].emplace_back(true, e[1]);
    }
    for (const auto& e : blueEdges) {
      adjMat[e[0]].emplace_back(false, e[1]);
    }
    std::vector<int> res(n, -1);
    std::vector<std::vector<bool>> seen(
        n, {false, false});  // seen from redEdge or not
    res[0] = 0;
    std::queue<TravelInfo> toTravel;
    // src node not from red nor blue, so either way is good
    toTravel.emplace(0, 0, false);
    toTravel.emplace(0, 0, true);
    while (!toTravel.empty()) {
      auto [node, dis, fromRedEdge] = toTravel.front();
      toTravel.pop();
      seen[node][fromRedEdge] = true;
      if (res[node] == -1) {
        res[node] = dis;
      }
      for (const auto& [isRed, dstNode] : adjMat[node]) {
        if (isRed != fromRedEdge && !seen[dstNode][isRed]) {
          toTravel.emplace(dstNode, dis + 1, isRed);
        }
      }
    }
    return res;
  }
};