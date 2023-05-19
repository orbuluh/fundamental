class Solution {
/*

A graph can be broken down to several connected component.

For each of the connected component, if you do DFS on it, then each adjacent
nodes must not have same color. (As Bipartite requires.)

So we simply start from one node and DFS it, while marking a node a color.
Once DFS returned, then the connected component for the node is done.

We just find the next non-visited node, which must be on a different connected
component. Then we do the same, DFS this component and see if any node is
breaking the requirement of bipartite.

*/

 public:
  std::vector<int> nodeColor;
  bool isBipartite(vector<vector<int>>& graph) {
    const int sz = graph.size();
    nodeColor = std::vector<int>(sz, 0);
    for (int i = 0; i < sz; ++i) {
      // randomly assign a color for the new component
      if (!nodeColor[i] && !dfsValidate(graph, i, 1)) {
        return false;
      }
    }
    return true;
  }

  bool dfsValidate(vector<vector<int>>& graph, int idx, int assignedColor) {
    if (nodeColor[idx]) {  // have been assigned for a color
      return assignedColor == nodeColor[idx];
    }
    const auto adjColor = -1 * assignedColor;
    nodeColor[idx] = assignedColor;
    const auto& edges = graph[idx];
    for (auto neighbor : edges) {
      if (!dfsValidate(graph, neighbor, adjColor)) {
        return false;
      }
    }
    return true;
  }
};