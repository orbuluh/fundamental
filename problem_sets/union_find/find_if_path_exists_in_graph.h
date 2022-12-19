class Solution {
 public:
  struct UnionFind {
    UnionFind(int n) : parent(n) {
      for (int i = 0; i < n; ++i) {
        parent[i] = i;
      }
    };

    int find(int x) {
      if (parent[x] == x) {
        return x;
      }
      return parent[x] = find(parent[x]);
    }

    void join(int x, int y) {
      int xP = find(x);
      int yP = find(y);
      if (xP != yP) {
        parent[xP] = yP;
      }
    }

    std::vector<int> parent;
  };

  bool validPath(int n, vector<vector<int>>& edges, int source,
                 int destination) {
    UnionFind uf(n);
    for (const auto& edge : edges) {
      uf.join(edge[0], edge[1]);
    }
    return uf.find(source) == uf.find(destination);
  }
};

/*DFS solution*/
/*
class Solution {
 public:
  bool validPath(int n, vector<vector<int>>& edges, int source,
                 int destination) {
    if (source == destination) {
      return true;
    }
    std::vector<std::vector<int>> adjMat(n);
    for (const auto& edge : edges) {
      adjMat[edge[0]].push_back(edge[1]);
      adjMat[edge[1]].push_back(edge[0]);
    }
    std::vector<bool> seen(n, false);
    std::queue<int> toTravel;
    toTravel.push(source);
    seen[source] = true;
    while (!toTravel.empty()) {
      int node = toTravel.front();
      toTravel.pop();
      for (auto neighbor : adjMat[node]) {
        if (neighbor == destination) {
          return true;
        }
        if (seen[neighbor]) {
          continue;
        }
        toTravel.push(neighbor);
        seen[neighbor] = true;
      }
    }
    return false;
  }
};
*/