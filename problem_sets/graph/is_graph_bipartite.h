class Solution {
  /*
  Bipartite:
  - "every edge in the graph connects a node in set A and a node in set B."

  This implies:
  - "no edges between nodes in the same set in a bipartite graph"

  Say we always do this in a DFS way, where whenever we meet a new node, we
  mark it with one set and then do a DFS way to make sure all its neighbor
  is in another set.

  The question is - can we randomly assign it with one color?

  The answer is yes. Why? If we meet a new node that hasn't been seen before,
  it means all the nodes we've seen cannot make an edge to this node. So they
  are all unrelated to it. (Note that the graph is undirected, so it implies
  either new node has no edge to previous node and vise-versa.)

  So because we are doing DFS, all the connected nodes should have been
  checked when the recursion returns. So whenever we are meeting with a node
  without any assignment, we must be starting a new connected partial graph
  than what was previously checked. So we can always randomly assign a set to
  this new node!
  */
 public:
  enum class Set {
    None,  // not yet assign
    A,
    B,
  };
  std::vector<Set> sets;
  bool isBipartite(vector<vector<int>>& graph) {
    sets = std::vector<Set>(graph.size(), Set::None);
    for (int i = 0; i < graph.size(); ++i) {
      // if sets[i] != None, we've checked its corresponding connected
      // (partial) graph. So we will just continue.
      // Otherwise we assume the new node to be in one set, and exam
      // its parent in a DFS fashion, to make sure all nodes in the
      // connected (partial) graph with node i are valid.
      if (sets[i] == Set::None && !dfsValidate(graph, i, Set::A)) {
        return false;
      }
    }
    return true;
  }

  bool dfsValidate(vector<vector<int>>& graph, int idx, Set assignSet) {
    if (sets[idx] != Set::None) {
      return assignSet == sets[idx];
    }
    const auto& edges = graph[idx];
    const auto otherSet = assignSet == Set::A ? Set::B : Set::A;
    sets[idx] = assignSet;
    for (auto neighbor : edges) {
      if (!dfsValidate(graph, neighbor, otherSet)) {
        return false;
      }
    }
    return true;
  }
};