class Solution {
    /*
    Bipartite:
    - "every edge in the graph connects a node in set A and a node in set B."

    This implies:
    - "no edges between nodes in the same set in a bipartite graph"

    Hence we can do this in a greedy way.

    E.g. if a node hasn't been assigned a set, we can just randomly assign one.
    Then we use DFS to make sure all the neighbors can be assigned with the
    other set. If it's not the case, then we violate the bipartite already,
    hence we can early exit.

    Put in another way, since you are doing a dfs validation for an unvisited
    node i. It implies that all the node before i has no edge to connect to
    node i. So you can basically paint it with any of the color and exam it.
    After you've dfs through i, you can be sure that is any node that is going
    to put constraint to a later node j where j > i, then node j must have
    assigned a set already. If not, there must be no constraint, so you can
    assign j with any color follow the same rationale.
    */
  public:
    enum class Set {
        None, // not yet assign
        A,
        B,
    };
    Set alternate(Set s) {
        return s == Set::None ? s : (s == Set::A ? Set::B : Set::A);
    }
    std::vector<Set> sets;
    bool isBipartite(vector<vector<int>>& graph) {
        sets = std::vector<Set>(graph.size(), Set::None);
        for (int i = 0; i < graph.size(); ++i) {
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
        const auto otherSet = alternate(assignSet);
        sets[idx] = assignSet;
        for (auto neighbor : edges) {
            if (!dfsValidate(graph, neighbor, otherSet)) {
                return false;
            }
        }
        return true;
    }
};