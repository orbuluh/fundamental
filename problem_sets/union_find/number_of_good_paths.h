/*
My understand from [@lee215's
post](https://leetcode.com/problems/number-of-good-paths/solutions/2620680/python-union-find-solution/?orderBy=most_votes)

# Good path requirements
* The starting node and the ending node have the same value.
* the starting node's value should be the maximum value along the path
* a path and its reverse are counted as the same path.

Hint: Don't think about tree/graph structure and DFS/BFS traversing....

# How can a path forms?
From edges. A unique path must comes from a
unique edge that we haven't seen so far.

Say whenever we see a new edge, we combine nodes as a group.
say nodes: a, b
`g1 = {a}`, `g2 = {b}`, then `edge(a, b)` forms a new big group `g'={a, b}`

# How can a good path forms?
An edge(u, v) appears such that `group(u)` and `group(v)` having the same max
value.

Say we have node group 1 with values: `g1 = {1, 2, 3}`, `max(g1) = 3`
            node group 2 with values: `g2 = {1, 3, 3}`, `max(g2) = 3`

And we have an edge to connect these 2 groups.

What would be the good path count added?
It will be `count[g1][3] * count[g2][3] = 1 * 2 = 2`

# How do we search in a way that we can build up all the unique good path?

A path comes from an edge. A good path must have start/end with a max value in
the path. So the goal is searching **in an order of max value seen so far.**

But how? Say an `edge(u, v)` has weight `max(val(u), val(v))`
- e.g. larger node value is the weight of the edge weight

Then if we check edges in a way that has sorted weight of edge, then we are sure
the max value seen so far.

And when we combine 2 groups on the edge, as long as both group has nodes with
`value == edgeWeight`, then they must be able to combine and form new good path.
And those good paths must be something that we haven't seen yet.

# Could we ever double count while combine edges?

Noted that it's a tree without cycle. So each group must have no cycle itself.
Say we already find: `group1 = {a, b}`, `group2 {c, d}`, then if next, we see
`edge(b, c)`, we now have a structure like `a-b-c-d`.

And there can't be other intra edges like `edge(a, c)`, `edge(a, d)`, or
`edge(b, d)`, because either case will create a cycle. So we are sure that we
are always good to combine 2 groups when counting the good path.

So there can't be double counting when we merge 2 groups.



*/
class Solution {
 public:
  std::vector<int> ufParent;
  std::vector<std::unordered_map<int, int>> count;
  struct EdgeWeight {
    int weight = 0;
    int node1 = 0;
    int node2 = 0;
  };
  std::vector<EdgeWeight> edgeWeights;

  int ufFind(int i) {
    return ufParent[i] == i ? i : (ufParent[i] = ufFind(ufParent[i]));
  }

  void init(const vector<int>& vals, const vector<vector<int>>& edges) {
    const int n = vals.size();
    ufParent.resize(n);
    count.resize(n);
    for (int i = 0; i < n; ++i) {
      ufParent[i] = i;
      count[i][vals[i]]++;
    }
    edgeWeights.reserve(n);
    for (const auto& e : edges) {
      edgeWeights.push_back({std::max(vals[e[0]], vals[e[1]]), e[0], e[1]});
    }
    std::sort(
        edgeWeights.begin(), edgeWeights.end(),
        [](const auto& w1, const auto& w2) { return w1.weight < w2.weight; });
  }
  int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
    init(vals, edges);
    int res = vals.size();  // single node is itself a good path
    for (const auto& ew : edgeWeights) {
      auto g1 = ufFind(ew.node1);
      auto g2 = ufFind(ew.node2);
      auto c1 = count[g1][ew.weight];
      auto c2 = count[g2][ew.weight];
      res += c1 * c2;
      // union g1 and g2
      ufParent[g1] = g2;
      // we only care about the count of max value seen so far, as the new big
      // group of g2 could be used to combine with other group in later
      // iteration. So we add count of max value in g1 to g2.
      count[g2][ew.weight] += c1;
    }

    return res;
  }
};