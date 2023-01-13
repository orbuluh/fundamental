/*
Note that the question is asking "no pair of adjacent having same""
So you can have a path of a - b - a

The implication is, as long as child node is different from parent
then 2 child node must be able to combine to form a path

while on each node, we update max with
1. a path combine 2 longest child path + the node
2. a path only including the longest child path + the node

And we only return 2's result in recursion
(as if 1 is selected, it can't be a path with parent no more)

Also the other note ... a path doesn't need to go through root.
so case like

[-1,0,1]
"aab"

0(a)
  1(a)
     2(b)

The answer is 2, path of 1(a)-2(b)
*/

class Solution {
 public:
  int longestPath(vector<int>& parent, string s) {
    const int n = parent.size();
    std::vector<std::vector<int>> adjMat(n);
    for (int i = 1; i < n; ++i) {
      adjMat[parent[i]].push_back(i);
    }
    std::vector<bool> seenNode(s.size());
    int maxDis = 0;
    dfs(adjMat, s, 0, seenNode, maxDis);
    return maxDis;
  }

  int dfs(const std::vector<std::vector<int>>& adjMat, std::string_view s,
          int nodeIdx, std::vector<bool>& seenNode, int& maxDis) {
    seenNode[nodeIdx] = true;
    int maxSubPath = 0;
    int nxtMaxSubPath = 0;
    for (auto n : adjMat[nodeIdx]) {
      if (seenNode[n]) {
        continue;
      }
      const auto subPath = dfs(adjMat, s, n, seenNode, maxDis);
      if (s[nodeIdx] != s[n]) {
        if (subPath > maxSubPath) {
          nxtMaxSubPath = std::exchange(maxSubPath, subPath);
        } else if (subPath > nxtMaxSubPath) {
          nxtMaxSubPath = subPath;
        }
      }
    }
    maxDis = std::max(maxDis, maxSubPath + nxtMaxSubPath + 1);
    return 1 + maxSubPath;
  }
};