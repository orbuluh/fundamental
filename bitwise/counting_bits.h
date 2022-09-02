/*
say X = 2 * Y and X is even number
Then X is left shift 1 bit of Y,
which means X and Y has the same set bit

Say X = 2 * Y + 1, then X will be left shift 1 of Y
plus making the lsb 1.

*/

class Solution {
 public:
  vector<int> countBits(int n) {
    std::vector<int> res(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      res[i] = res[i / 2] + (i % 2);
    }
    return res;
  }
};