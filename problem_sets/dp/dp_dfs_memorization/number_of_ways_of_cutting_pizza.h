/*
The more intuitive way is using a top-down dfs + memorization.
For each of the cut, we can use 2D prefix sum to make sure the cut is valid.
Eventually, you can simplify it with iterative DP and build it bottom up.


The first part is setting up 2D prefix sum so you can count the apple

Normally the 2D prefix sum needs to use set union formula. Imagine:

  a b
  c d

->  a    a+b              ->    a   a+b
    a+c  d+(a+b)+(a+c)-a  ->    a+c a+b+c+d

E.g.
-> prefix[i][j] = val[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1]

Then for each entry, prefix[i][j] should equal to sum of all the elements from
(0, 0) to (i, j)

say now I'm only interested in 1,1 cell, it will be a reversed operation like
(a+b+c+d) - (a+c) - (a+b) + a = d

E.g. say top left is (i, j), bottom right is (x, y), then the sum should be:

prefix[x][y] - prefix[i-1][j] - prefix[i][j-1] + prefix[i-1][j-1]

Here, however, we are not doing this way but a reverse way. Why, because when
we make a cut, we want to know if the remaining bottom right portion still
contains apple or not. E.g. we want the prefix sum to look like


  a b ->  a+(b+d)+(c+d)-d    b+d  ->   a+b+c+d  b+d
  c d      c+d                 d       c+d        d


So now prefix'[i][j] is the sum of rectangle from i, j to bottom right

Say we are from the beginning (0, 0), which contains the full sum from (0, 0)
to bottom right, e.g. a+b+c+d

If we make a horizontal cut at row 0, what's left is c+d = prefix'[1][0]
If we make a vertical cut at col 0, what's left is b+d = prefix'[0][1]

So, when we are at state (r, c), and we are making horizontal cut on row i-1:

- e.g. the remaining rectangle starts from (i, c), then we can use
- prefix'[i][c] to know if remaining bottom right contains enough apple for
  further cut.
- Also, we can use prefix'[r][c] - prefix'[i][c] to know if there is any
  apple in the cut itself.


Similarly, when we are at state (r, c) and we are making vertical cut on col j-1

- e.g. the remaining rectangle starts from (r, j), then we can use
- prefix'[r][j] to know if remaining bottom right contains enough apple for
  further cut.
- Also, we can use prefix'[r][c] - prefix'[r][j] to know if there is any
  apple in the cut itself.


Eventually, where there is no further cut needed, and we are at (r,c), we only
need to know if prefix'[r][c] itself is 0 or not, as it represents the remaining
sum from (r,c) to the bottom right.


Skip for bottom up approach ...I guess DFS memorization is hard enough...
*/

class Solution {
 public:
  static constexpr int mod = 1'000'000'007;
  int m = 0;
  int n = 0;
  using Vec1D = std::vector<int>;
  using Vec2D = std::vector<Vec1D>;
  using Vec3D = std::vector<Vec2D>;
  Vec2D cnt;
  Vec3D dp;
  void init(const vector<string>& pizza) {
    m = pizza.size();
    n = pizza.front().size();
    cnt = Vec2D(m + 1, Vec1D(n + 1, 0));
    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        cnt[i][j] = (pizza[i][j] == 'A') + cnt[i + 1][j] + cnt[i][j + 1] -
                    cnt[i + 1][j + 1];
      }
    }
  }

  int ways(vector<string>& pizza, int k) {
    init(pizza);
    dp = Vec3D(m + 1, Vec2D(n + 1, Vec1D(k, -1)));
    return dfs(0, 0, k - 1);
  }

  int dfs(int r, int c, int k) {
    if (k == 0) {
      return cnt[r][c] > 0;
    }
    if (dp[r][c][k] != -1) {
      return dp[r][c][k];
    }
    int64_t rowSum = 0;
    int64_t colSum = 0;
    // horizontal cut: i is top boundary after cut
    for (int i = r + 1; i < m; ++i) {
      if (cnt[i][c] >= k && cnt[r][c] - cnt[i][c] > 0) {
        rowSum = (rowSum + dfs(i, c, k - 1)) % mod;
      }
    }
    // vertical cut: j is left boundary after cut
    for (int j = c + 1; j < n; ++j) {
      if (cnt[r][j] >= k && cnt[r][c] - cnt[r][j] > 0) {
        colSum = (colSum + dfs(r, j, k - 1)) % mod;
      }
    }
    return dp[r][c][k] = (rowSum + colSum) % mod;
  }
};