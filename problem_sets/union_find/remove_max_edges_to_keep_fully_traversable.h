/*

Supposed there is only one person to consider, you simply need to gradually add
each edge into disjoin set - as long as it't an edge that can reduce the group
count. At the end, a fully traversable graph must have n - 1 edges out of n
vertices. The ordering of edges doesn't matter, it just needs to have that many
edges.

For 2 disjoin set, it's pretty much the same. The key is to handle edges for
both first. Then you can consider each one separately.
*/
class Solution {
  class DisjoinSet {
    std::vector<int> parent;
    int groupCnt;

   public:
    DisjoinSet(int n) : parent(n), groupCnt(n - 1) {
      std::iota(parent.begin(), parent.end(), 0);
    }
    int unionFind(int x) {
      if (parent[x] == x) {
        return x;
      }
      return parent[x] = unionFind(parent[x]);
    }
    bool join(int x, int y) {
      int xp = unionFind(x);
      int yp = unionFind(y);
      if (xp == yp) {
        return false;
      }
      parent[xp] = yp;
      groupCnt--;
      return true;
    }
    bool isUnited() const { return groupCnt == 1; }
  };

 public:
  int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    DisjoinSet alice(n + 1);
    int noNeed = 0;
    std::for_each(edges.begin(), edges.end(), [&](const auto& e) {
      if (e[0] != 3) {
        return;
      }
      if (!alice.join(e[1], e[2])) {
        noNeed++;
      }
    });
    // as we handle type 3 edges first, at this point, both 2 ds are the same
    DisjoinSet bob = alice;
    // then we check edges specific for alice or bob
    std::for_each(edges.begin(), edges.end(), [&](const auto& e) {
      if (e[0] == 3) {
        return;
      }
      noNeed += e[0] == 1 ? !alice.join(e[1], e[2]) : !bob.join(e[1], e[2]);
    });
    return alice.isUnited() && bob.isUnited() ? noNeed : -1;
  }
};