/*
Idea from https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/solutions/978450/c-dsu-two-pointers/?orderBy=most_votes

"whether there is a path between any two nodes with the max weight < limit" can
change to the other problem:

1. we iterate all edges with weight less than limit and do the disjoin set join
   operation along the way.

2. if for all edge weight < limit, we can find that node i and node j are in the
   same set, then it means there must exists a path where max weight < limit

So the ideal is sorting the query with limit so we build the disjoin set with
sorted limit. And along the way, we know if such query can be achieved.
*/
class Solution {
  class DisjoinSet {
    std::vector<int> parent;
   public:
    DisjoinSet(int n) {
      parent.resize(n);
      std::iota(parent.begin(), parent.end(), 0);
    }
    int unionFind(int i) {
      if (parent[i] == i) {
        return i;
      }
      return parent[i] = unionFind(parent[i]);
    }

    void join(int i, int j) {
      int x = unionFind(i);
      int y = unionFind(j);
      if (x != y) {
        parent[x] = y;
      }
    }
  };

 public:
  vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList,
                                         vector<vector<int>>& queries) {
    ios_base::sync_with_stdio(0); // main reason to be up in distribution...
    DisjoinSet ds(n);
    const int qSz = queries.size();
    for (int i = 0; i < qSz; ++i) {
      // append query's index so we know where to put in the result
      queries[i].push_back(i);
    }
    std::sort(queries.begin(), queries.end(),
              [](const auto& q1, const auto& q2) {
                return q1[2] < q2[2];  // sort query with limit
              });
    std::sort(edgeList.begin(), edgeList.end(),
              [](const auto& e1, const auto& e2) {
                return e1[2] < e2[2];  // sort edge with weight
              });
    const int wSz = edgeList.size();
    std::vector<bool> res(qSz, false);
    int i = 0;
    for (int q = 0; q < qSz; ++q) {
      // join all edges with weight less than limit
      while (i < wSz && edgeList[i][2] < queries[q][2]) {
        ds.join(edgeList[i][0], edgeList[i++][1]);
      }
      // if to nodes are in same set, the query must be okay
      res[queries[q][3]] =
          ds.unionFind(queries[q][0]) == ds.unionFind(queries[q][1]);
    }
    return res;
  }
};