/*
Idea: it's basically like 0/1 knapsack problem, m and n are the capacity of
the knapsack for 1s and 0s respectively. Each string is like the weight of an
item to put into the knapsack.

Because we now have 2 dimensions of capacity, the question basically becomes a
3-D dp question. And one axis for considering the new item can be taken away.

Overall dp[m][n][i] is the max of ...
- dp[m][n][i - 1]   ...  don't take item[i]
- dp[m - zero(item[i])][n - one(item[i])][i - 1])  ... take item[i] if doable
*/
class Solution {
 public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    using Vec2D = std::vector<std::vector<int>>;
    std::vector<int> ones(strs.size(), 0);
    for (int i = 0; i < strs.size(); ++i) {
      ones[i] = std::count(strs[i].begin(), strs[i].end(), '1');
    }
    auto zeros = [&](int i) { return strs[i].size() - ones[i]; };

    Vec2D dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 0; i < strs.size(); ++i) {
      Vec2D nxtDp(m + 1, std::vector<int>(n + 1, 0));
      int oneCnt = ones[i];
      int zeroCnt = zeros(i);

      for (int zeroCap = 0; zeroCap <= m; ++zeroCap) {
        for (int oneCap = 0; oneCap <= n; ++oneCap) {
          // don't take item i, always doable
          nxtDp[zeroCap][oneCap] = dp[zeroCap][oneCap];
          // try to take item i, if doable.
          if (zeroCnt <= zeroCap && oneCnt <= oneCap) {
            nxtDp[zeroCap][oneCap] =
                std::max(nxtDp[zeroCap][oneCap],
                         1 + dp[zeroCap - zeroCnt][oneCap - oneCnt]);
          }
        }
      }
      std::swap(nxtDp, dp);
    }
    return dp[m][n];
  }
};

/*
// A even quicker implementation that got a better result in leetcode OJ:
// likely because you don't need to keep constructing new vector

class Solution {
 public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    const auto sz = strs.size();
    std::vector<int> dp;
    dp = std::vector<int>((sz + 1) * (m + 1) * (n + 1));
    auto idx = [&](int i, int j, int k) {
      return i * (m + 1) * (n + 1) + j * (n + 1) + k;
    };
    for (int i = 1; i <= sz; ++i) {
      auto& s = strs[i - 1];
      const auto zeros = std::count(s.begin(), s.end(), '0');
      const auto ones = s.size() - zeros;
      for (int j = 0; j <= m; ++j) {
        for (int k = 0; k <= n; ++k) {
          if (j >= zeros && k >= ones) {
            dp[idx(i, j, k)] = std::max(
                dp[idx(i - 1, j, k)],                    // don't use strs[i]
                dp[idx(i - 1, j - zeros, k - ones)] + 1  // must use strs[i]
            );
          } else {
            // can't use strs[i] given zeros <= i && ones <= j
            dp[idx(i, j, k)] = dp[idx(i - 1, j, k)];
          }
        }
      }
    }
    return dp[idx(sz, m, n)];
  }
*/