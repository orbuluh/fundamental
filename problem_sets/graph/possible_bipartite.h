/*

The brilliant way to use union find to solve ...

Say there is a dislike edge [a, b], in normal union find, an edge
should represent a grouping, but now, what we want to do is make
sure a nd b are not in the same group. How do we do that?

We can create pseudo node for each node, where we want pseudo node
to be in a different set than its corresponding node.

Because we are looking for bipartite
- for dislike edge [a, b]: a, b are not in the same group
- and we want:
    - a and a' to be not in the same group
    - b and b' are not in the same group
-> So [a, b'] and [a', b] should be in the same group.

At the end, we just check: for all node v, group(v) != group(v')

How to create pseudo node? we can just make v' = v + n
*/
class Solution {
 public:
  bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    UnionFind uf(2 * n + 1);
    for (const auto& d : dislikes) {
      uf.join(d[0], d[1] + n);
      uf.join(d[1], d[0] + n);
    }
    for (int i = 1; i <= n; ++i) {
      if (uf.find(i) == uf.find(i + n)) {
        return false;
      }
    }
    return true;
  }

 private:
  class UnionFind {
   public:
    UnionFind(int n) : parent(n) {
      for (int i = 0; i < n; ++i) {
        parent[i] = i;
      }
    }
    int find(int x) {
      if (x == parent[x]) return x;
      return parent[x] = find(parent[x]);
    }
    void join(int x, int y) {
      int xP = find(x);
      int yP = find(y);
      if (xP != yP) {
        parent[xP] = yP;
      }
    }

   private:
    std::vector<int> parent;
  };
};