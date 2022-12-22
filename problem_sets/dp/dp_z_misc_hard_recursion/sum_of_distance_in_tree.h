/*

From post:
https://leetcode.com/problems/sum-of-distances-in-tree/solutions/130583/c-java-python-pre-order-and-post-order-dfs-o-n/?orderBy=most_votes
https://leetcode.com/problems/sum-of-distances-in-tree/solutions/1308366/c-solution-using-dfs-with-explanation-o-n-time-complexity/?orderBy=most_votes

               0
            1     2
          5      3  4

Say you've find the result of using 0 as root.

[0, 1] = 1
[0, 5] = 2
[0, 2] = 1
[0, 3] = 2
[0, 4] = 2

Can this tell you anything if you change 1 as root? Yes

From @lee215: "Re-root" intuition:

"When we move our root from one node to its connected node,
one part of nodes get closer, one the other part get further."

[1, 5] = [0, 5] - 1 = 1  ---> one part get closer
[1, 0] = [0, 1] = 1
[1, 2] = [0, 2] + 1 = 2  \
[1, 3] = [0, 3] + 1 = 3   } the other part get further
[1, 4] = [0, 4] + 1 = 3  /


The observation is that, there are 3 nodes under the subtree of
root 0's right, and each of them get 1 dis further, so the delta
from these 3 nodes is equal to the count of nodes, e.g. 3.


So we will be collecting the info of number of nodes under
a node (inclusive), with function subCnt[node]:

Say 0 as root:

There are subCnt[1] = 2, 2 nodes in subtree(1), and
          subCnt[2] = 3, 3 nodes in subtree(2)
          and we know subCnt[2] = n - (subCnt[1] + 1)
          as subCnt(right) = fullTreeCnt - subCnt(left) - 1(root))


when we move root to 1:
There will be delta of sum coming from:
    1. subCnt[1] - 1 nodes get 1 dis closer
    2. subCnt[2] nodes get 1 dis further
    3. (and 1 edge has no change between root 0 and new root 1, 0 delta)

Or generalize:

sumWithRoot[newRoot]
    = sumWithRoot[root]
      - (subCnt[newRoot] - 1)        // item 1 above, 1 dis closer
      + (n - subCnt[newRoot] - 1)   // item 2 above, 1 dis further

    = sumWithRoot[root] - 2 * subCnt[newRoot] + n

So overall we basically can use 2 dfs pass to solve
1. the first pass is basically assuming a node as root, and calculate
   the result and collecting the subCnt table lookup
2. the second pass is trying to "re-root", dfs from the root we selected
   from pass 1, and apply the above recurrence.
*/

class Solution {
 public:
  using AdjGraph = std::vector<std::vector<int>>;
  AdjGraph graph;
  std::vector<int> sumWithRoot;
  std::vector<int> subCnt;
  int n;
  vector<int> sumOfDistancesInTree(int nIn, vector<vector<int>>& edges) {
    n = nIn;
    graph = AdjGraph(n);
    sumWithRoot = std::vector<int>(n);
    subCnt = std::vector<int>(n);
    for (const auto& edge : edges) {
      graph[edge[0]].emplace_back(edge[1]);
      graph[edge[1]].emplace_back(edge[0]);
    }
    // randomly pick 0 as root in pass 1, build
    // the result of using 0 as root, plus the subCnt
    dfsFirstPass(0, 0, -1);
    dfsReRoot(0, -1);
    return sumWithRoot;
  }

  int dfsFirstPass(int node, int len, int prevInDfs) {
    // prevInDfs to prevent traversing back in undirected graph
    int count = 1;
    sumWithRoot[0] += len;
    for (auto neighbor : graph[node]) {
      if (neighbor == prevInDfs) {
        continue;
      }
      count += dfsFirstPass(neighbor, len + 1, node);
    }
    return subCnt[node] = count;
  }

  void dfsReRoot(int prevRoot, int prevInDfs) {
    // prevInDfs to prevent traversing back in undirected graph
    for (auto newRoot : graph[prevRoot]) {
      if (newRoot == prevInDfs) {
        continue;
      }
      sumWithRoot[newRoot] = sumWithRoot[prevRoot] - 2 * subCnt[newRoot] + n;
      dfsReRoot(newRoot, prevRoot);
    }
  }
};