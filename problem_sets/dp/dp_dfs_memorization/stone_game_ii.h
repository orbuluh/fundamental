
/*
The thing to understand is that both Alice and Bob basically have the same
strategy. Say we use dp[i][m] to record the max stone we can get, starting from
index i, with M = m, then it shouldn't matter who the person is, they all using
the same method to optimize their move.

With this being said, when you do DFS, you don't really need to know which
person are making the move. Rather, the state is about what's the start index
and what's the M at this point.

And you can get a recursion to search the possible move:

dp[i][m] = std::max(stoneLeft - dp[j][max(m, j - i + 1)]),
  for j in [i, std::min(n, i + 2 * m))

So overall stoneLeft - what DFS return is basically what you can get.

*/

static int _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();

class Solution {
  std::vector<std::vector<int>> dp;

 public:
  int findMaxWithState(const vector<int>& piles, int i, int m, int leftStones) {
    const int n = piles.size();
    if (i >= n) {
      return 0;
    }
    int& res = dp[i][m];
    if (res != -1) {
      return res;
    }

    res = 0;
    int taken = 0;

    const int moveBound = min(n, i + 2 * m);
    for (int j = i; j < moveBound; ++j) {
      taken += piles[j];
      int newM = max(m, j - i + 1);
      res = max(res, leftStones - findMaxWithState(piles, j + 1, newM,
                                                   leftStones - taken));
    }
    return res;
  }

  int stoneGameII(vector<int>& piles) {
    int n = piles.size();
    dp = std::vector<std::vector<int>>(n, std::vector<int>(50, -1));
    int stoneLeft = accumulate(piles.begin(), piles.end(), 0);
    return findMaxWithState(piles, 0, 1, stoneLeft);
  }
};