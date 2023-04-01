/*
You could do a Dijkstra like path update to derive -
or you could do it another way: the answer is basically looking
the connected nodes from node 1 (and it's guaranteed to connect to node n)

So if you do a DFS from node 1 to find all the connected nodes of node 1
then at the end, you just need to check the min weight.

The fastest solution will be using union find to record the connected component
to node 1. You can try it but just skip that implementation here.
*/
class Solution {
 public:
  int minScore(int n, vector<vector<int>>& roads) {
    std::unordered_map<int, std::vector<int>> adjMap;
    for (const auto& ew : roads) {
      adjMap[ew[0]].push_back(ew[1]);
      adjMap[ew[1]].push_back(ew[0]);
    }
    // DFS finding the connected nodes to node 1
    std::unordered_set<int> connectedNodes = {1};
    auto isConnected = [&](int node) {
      return connectedNodes.find(node) != connectedNodes.end();
    };
    std::queue<int> toTravel;
    toTravel.push(1);
    while (!toTravel.empty()) {
      int node = toTravel.front();
      toTravel.pop();
      for (auto nxtNode : adjMap[node]) {
        if (!isConnected(nxtNode)) {
          connectedNodes.insert(nxtNode);
          toTravel.push(nxtNode);
        }
      }
    }
    int score = INT_MAX;
    for (const auto& ew : roads) {
      if (isConnected(ew[0])) {
        score = std::min(score, ew[2]);
      }
    }
    return score;
  }
  int minScoreDijkstra(int n, vector<vector<int>>& roads) {
    std::unordered_map<int, std::unordered_map<int, int>> adjMap;
    for (const auto& ew : roads) {
      adjMap[ew[0]][ew[1]] = ew[2];
      adjMap[ew[1]][ew[0]] = ew[2];
    }
    std::vector<int> scores(n + 1, INT_MAX);
    std::vector<int> toTravel = {1};
    std::vector<int> nxtTravel;
    while (!toTravel.empty()) {
      nxtTravel.clear();
      for (auto node : toTravel) {
        for (const auto& [nxtNode, d] : adjMap[node]) {
          const auto score = std::min(scores[node], d);
          if (score < scores[nxtNode]) {
            scores[nxtNode] = std::min(score, d);
            nxtTravel.push_back(nxtNode);
          }
        }
      }
      std::swap(toTravel, nxtTravel);
    }
    return scores[n];
  }
};