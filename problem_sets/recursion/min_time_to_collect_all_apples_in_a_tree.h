/*
              0__
            /     \
          1        2(a)
        / \       / \
    4(a)  5(a)    3  6

Recursive idea, as long as there are any apple in the subtree of the node
then adding 2 when recursive back to the node's parent

so subtree(4) has apple, and 0 distance to apple, going back 1, cnt + 2
   subtree(5) has apple, and 0 distance to it, going back 1, cnt + 2
   -> subtree(1) getting 2 + 2 from 4 and 5. Itself has apple underneath, going
      back to parent 0, + 2 again
   -> 0 getting 6 from 1, and check what it gets from 2
   -> subtree(3) has no apple, subtree(6) has no apple
      2 getting 0 from underneath, but itself has apple with 0 distance
      so 0 getting 0 + 2 from 2
   -> overall 0 will get 6 + 2 = 8 at the end.
*/

class Solution {
 public:
  int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    std::vector<std::vector<int>> adjMat(n);
    for (const auto& e : edges) {
      adjMat[e[0]].push_back(e[1]);
      adjMat[e[1]].push_back(e[0]);
    }
    vector<bool> visited(n, false);
    auto res = dfs(0, adjMat, hasApple, visited);
    return res.first;
  }

  std::pair<int, bool> dfs(int nodeIdx, const vector<vector<int>>& adjMat,
                           const vector<bool>& hasApple,
                           vector<bool>& visited) {
    visited[nodeIdx] = true;
    int cnt = 0;
    bool containsApple = hasApple[nodeIdx];
    for (auto subNode : adjMat[nodeIdx]) {
      if (visited[subNode]) {
        continue;
      }
      auto [subCnt, subHasApple] = dfs(subNode, adjMat, hasApple, visited);
      if (subHasApple) {
        cnt += 2 + subCnt;
      }
      containsApple |= subHasApple;
    }
    return {cnt, containsApple};
  }
};