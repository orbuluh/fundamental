class Solution {
 public:
  static constexpr auto notYet = INT_MAX;

  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    // return withBellmonFord(times, n, k);
    return withDijkstra(times, n, k);
  }

  int withBellmonFord(vector<vector<int>>& times, int n, int k) {
    std::vector<int> timeToNode(n + 1, notYet);
    timeToNode[k] = 0;
    for (int i = 1; i <= n; ++i) {
      for (auto& edgeW : times) {
        const auto u = edgeW[0];
        const auto v = edgeW[1];
        const auto w = edgeW[2];
        if (timeToNode[u] != notYet && timeToNode[u] + w < timeToNode[v]) {
          timeToNode[v] = timeToNode[u] + w;
        }
      }
    }
    int timeNeed = 0;
    for (int i = 1; i <= n; ++i) {
      if (timeToNode[i] == notYet) {
        return -1;
      }
      timeNeed = std::max(timeNeed, timeToNode[i]);
    }
    return timeNeed;
  }

  int withDijkstra(vector<vector<int>>& times, int n, int k) {
    std::vector<std::vector<int>> nodeEdgeIdx(n + 1);
    for (int i = 0; i < times.size(); ++i) {
      nodeEdgeIdx[times[i][0]].push_back(i);
    }
    std::vector<int> timeToNode(n + 1, notYet);
    timeToNode[k] = 0;
    std::priority_queue<std::pair<int, int>> pq;
    pq.emplace(0, k);
    while (!pq.empty()) {
      auto [w, node] = pq.top();
      pq.pop();
      for (int i = 0; i < nodeEdgeIdx[node].size(); ++i) {
        const auto& edge = times[nodeEdgeIdx[node][i]];
        const auto u = edge[0];
        const auto v = edge[1];
        const auto w = edge[2];
        if (timeToNode[u] + w < timeToNode[v]) {
          timeToNode[v] = timeToNode[u] + w;
          pq.emplace(timeToNode[v], v);
        }
      }
    }
    int timeNeed = 0;
    for (int i = 1; i <= n; ++i) {
      if (timeToNode[i] == notYet) {
        return -1;
      }
      timeNeed = std::max(timeNeed, timeToNode[i]);
    }
    return timeNeed;
  }
};