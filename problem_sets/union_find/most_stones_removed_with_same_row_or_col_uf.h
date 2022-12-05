/*

Same rationale with the other dfs implementation under graph session.
check graph/most_stones_removed_with_same_row_or_col.h
--------------------------------------------------------------

Given the fact that we want to find connected component, and we know that
answer equals to sum(size(CC_i) - 1), which equals to
size(all points) - number of CCs

We can focus on how to find the independent CC count. One way to do so is
applying union find.

The smart part here is that you don't need to union "points", you can actually
union row value and column value. (As it's how "connected" is defined in this
problem.) And to avoid same row value and column value, you simply give either
of them an offset. (lee215 use negate ~col, which equal to -(col + 1) to
represents column value. Sort of tricky but good to understand the trick)

Then the remaining is basically union join all the row value and col value from
each point having same row or col value!
*/

class Solution {
 public:
  std::unordered_map<int, int> connectedRowCol;
  int totalConnectedComponent = 0;

  int removeStones(vector<vector<int>>& stones) {
    for (const auto& stone : stones) {
      unionJoin(stone[0], stone[1]);
    }
    return stones.size() - totalConnectedComponent;
  }
  int unionFind(int x) {
    if (connectedRowCol.count(x) == 0) {
      totalConnectedComponent++;
      return connectedRowCol[x] = x;
    }
    return (connectedRowCol[x] == x)
               ? x
               : connectedRowCol[x] = unionFind(connectedRowCol[x]);
  }
  void unionJoin(int row, int col) {
    col += 10'001;  // offset col so it won't overlap
    int pOfRow = unionFind(row);
    int pOfCol = unionFind(col);
    if (pOfRow != pOfCol) {
      connectedRowCol[pOfRow] = pOfCol;
      totalConnectedComponent--;
    }
  }
};