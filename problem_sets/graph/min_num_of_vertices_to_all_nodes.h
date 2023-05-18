/*
@lee215's explanation...

Just return the nodes with no in-degrees.

Necessary condition:
  All nodes with no in-degree must in the final result,
  because they can not be reached from
  All other nodes can be reached from any other nodes.

Sufficient condition:
  All other nodes can be reached from some other nodes.
*/
class Solution {
 public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    std::vector<int> indegreeCnt(n);
    for (const auto& edge : edges) {
      indegreeCnt[edge[1]]++;
    }
    std::vector<int> res;
    for (int i = 0; i < n; ++i) {
      if (!indegreeCnt[i]) res.push_back(i);
    }
    return res;
  }
};