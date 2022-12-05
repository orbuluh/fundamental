class Solution {
 public:
  double maxProbability(int n, vector<vector<int>>& edges,
                        vector<double>& succProb, int start, int end) {
    // return solveWithDijkstra(n, edges, succProb, start, end);
    return solveWithBellmonFord(n, edges, succProb, start, end);
  }

  double solveWithDijkstra(int n, vector<vector<int>>& edges,
                           vector<double>& succProb, int start, int end) {
    std::unordered_map<int, std::unordered_map<int, double>> graph;
    for (int i = 0; i < edges.size(); ++i) {
      graph[edges[i][0]][edges[i][1]] = succProb[i];
      graph[edges[i][1]][edges[i][0]] = succProb[i];
    }
    std::vector<double> nodeProbs(n, 0.0);
    std::priority_queue<std::pair<double, int>> toVisit;
    toVisit.push({1.0, start});
    nodeProbs[start] = 1.0;
    while (!toVisit.empty()) {
      auto [prob, idx] = toVisit.top();
      if (idx == end) {
        return prob;
      }
      nodeProbs[idx] = prob;
      toVisit.pop();
      for (const auto& [neighborIdx, probOnEdge] : graph[idx]) {
        const auto probToNeighbor = prob * probOnEdge;
        // note: this ensures you are not walking back to a point!
        // the variation of relax for Dijkstra
        if (probToNeighbor > nodeProbs[neighborIdx]) {
          toVisit.push({probToNeighbor, neighborIdx});
        }
      }
    }
    return 0.0;
  }

  double solveWithBellmonFord(int n, vector<vector<int>>& edges,
                              vector<double>& succProb, int start, int end) {
    std::vector<double> nodeProbs(n, 0.0);
    nodeProbs[start] = 1;
    const int edgeSz = edges.size();
    for (int iter = 0; iter < n - 1; ++iter) {
      bool haveRelax = false;
      for (int i = 0; i < edgeSz; ++i) {
        const auto w = succProb[i];
        auto relax = [&](int u, int v) {
          const auto p = nodeProbs[u] * w;
          // When a vertex is not reachable before, nodeProbs[v] = initial value
          // which is 0, and is always smaller than a value when it becomes
          // reachable
          if (nodeProbs[v] < p) {
            nodeProbs[v] = p;
            haveRelax = true;
          }
        };
        relax(edges[i][0], edges[i][1]);
        relax(edges[i][1], edges[i][0]);
      }
      if (!haveRelax) {
        break;
      }
    }
    return nodeProbs[end];
  }
};