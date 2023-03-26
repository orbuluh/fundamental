/*
Using the low-link value idea from Trojan's SCC algorithm. The low-link
structure helps you to keep track the node you've visited. As when you hit a
visited node, it should indicate that you've found a cycle.

Overall, the key observation for this problem is that each node has at most one
outgoing edge. This implies that the node is either in a cycle, or it's not in
a cycle.
*/

class Solution {
 public:
  int longestCycle(vector<int>& edges) {
    const int n = edges.size();
    // by default 0 so you can use 0 as non visited node
    std::vector<int> nodeIndices(n, 0);
    int maxLen = -1;
    for (int i = 0, idx = 1; i < n; ++i) {
      int node = i;
      int cycleStartIdx = idx;
      while (node != -1 && !nodeIndices[node]) {
        // assign a unique index for a node to indicate visited - plus give you
        // the index to calculate cycle length when you hit one. When do you hit
        // one? When you see another visited node!
        nodeIndices[node] = idx++;
        node = edges[node];
      }
      // when the above loop break, you either find a cycle (with non-0 index)
      // or there is no cycle (as edge[node] assign a -1). When it's hitting a
      // cycle, that nodeIndices[node] will be the unique id you assigned to the
      // cycle starting node. So its difference to idx will be the length of the
      // cycle.
      if (node != -1 && nodeIndices[node] >= cycleStartIdx) {
        maxLen = std::max(maxLen, idx - nodeIndices[node]);
      }
    }
    return maxLen;
  }
};