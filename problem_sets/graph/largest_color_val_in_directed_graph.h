/*
The idea is using iterative topological sort (Khan's algorithm, check your note)

The idea of Khan's algorithm is that we processed node without incoming node one
at a time:
  Whenever we visit an edge, we remove that incoming nodes for the node.
  If the node has no incoming nodes, it becomes next in the topological ordering

The magic is the opposite - when the algorithm broke while there are still edges
there must exist a cycle. (As when there is a cycle, there is no topological
ordering, and all the node can ever be updated to the "0-indegrees" nodes list.
Consider: a -> b -> c -> a. You just can't process any node)

So the idea here is, we just do the algorithm while keeping track of the max
color path coming into a node. E.g. say a node can be reached through aab
and bba, then the node will record colorPathCnt["a"] = colorPathCnt["b"] = 2
*/

class Solution {
  struct NodeInfo {
    std::array<int, 26> colorPathCnt = {};
    int inDegrees = 0;
    std::vector<int> neighbors;
  };
  std::vector<NodeInfo> nodesInfo;

 public:
  int largestPathValue(string colors, vector<vector<int>>& edges) {
    const int sz = colors.size();
    nodesInfo = std::vector<NodeInfo>(sz);
    for (const auto& e : edges) {
      nodesInfo[e[0]].neighbors.push_back(e[1]);
      nodesInfo[e[1]].inDegrees++;
    }
    std::queue<int> toTravel;
    for (int i = 0; i < sz; ++i) {
      // nodes without inbound edge is the source node
      // in topological ordering
      if (nodesInfo[i].inDegrees == 0) {
        toTravel.push(i);
        nodesInfo[i].colorPathCnt[colors[i] - 'a'] = 1;
      }
    }
    int maxColorPathCnt = 0;
    int nodeProcessed = 0;
    while (!toTravel.empty()) {
      int nodeIdx = toTravel.front();
      toTravel.pop();
      auto& nodeInfo = nodesInfo[nodeIdx];
      auto& nodeCPC = nodeInfo.colorPathCnt;
      nodeProcessed++;
      maxColorPathCnt = std::max(
          maxColorPathCnt, *std::max_element(nodeCPC.begin(), nodeCPC.end()));
      for (const auto& n : nodeInfo.neighbors) {
        // update neighbor's colorPathCnt accordingly
        auto& neighborCPC = nodesInfo[n].colorPathCnt;
        int neighborColor = colors[n] - 'a';
        for (int i = 0; i < 26; ++i) {
          neighborCPC[i] =
              std::max(neighborCPC[i], nodeCPC[i] + (i == neighborColor));
        }
        // see if neighbor is now ok to be processed
        if (--nodesInfo[n].inDegrees == 0) {
          toTravel.push(n);
        }
      }
    }
    return nodeProcessed == colors.size() ? maxColorPathCnt : -1;
  }
};