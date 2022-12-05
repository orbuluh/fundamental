/*

The "jump line" solution from
https://leetcode.com/problems/amount-of-new-area-painted-each-day/discuss/1751389/Jump-Line


So the idea is making the same size bucket-like concept array (as start-end is
constrained) with the end value - which means from the array index to the end
index is painted.

At index i ...

1. if the array has an "unpainted" value, say, -1, then it's going to be
painted:
- we add 1 to the going-to-paint-counter, and then mark array[i] = end - 1
  (noted that as the problem defined, index at end won't be covered.)

2. if the array has a value that is >= end, it means the whole range has been
covered before, nothing else need to do here.

3. if the array has a value x that is smaller than end (say, end has value y)
That means i to x (inclusive) has been painted - it should also imply that array
for i to x has a value that is x. What do we do here? We simply mark array from
x to end - 1 to y, which implies the fact that x to end - 1 (inclusive) will be
painted.

Say next time, a new (start, end) comes in with start = x - 1, and end - 1 = z,
where z > y.  What would happen? array[x - 1] will still have value x, so we do
nothing here, then it tries to check array[x], find the value is y, which is
smaller than z. So then it tries to mark array[y] = z, which implies y to z has
been painted as well!
*/

class Solution {
 public:
  std::array<int, 50'001> painted;

  vector<int> amountPainted(vector<vector<int>>& paint) {
    std::vector<int> res;
    std::memset(&painted, -1, sizeof(painted));
    for (const auto& p : paint) {
      int start = p[0];
      int end = p[1];
      int paintCnt = 0;
      for (int i = start; i < end; ++i) {
        if (painted[i] == -1) {
          painted[i] = end - 1;
          paintCnt++;
        } else {
          if (painted[i] < end) {
            i = painted[i];
            painted[i] = std::max(end - 1, painted[i]);
          } else {
            break;
          }
        }
      }
      res.push_back(paintCnt);
    }
    return res;
  }
};