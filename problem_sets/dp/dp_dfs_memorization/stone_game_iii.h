/*
The key observation is that for Alice and Bob, their strategy are the same.


The brilliant part is making:

- dp[x] = "max difference" a player start from x (and the other player take
whatever follows this player's decision)


Then from index x, you can took (((stone[x]), stone[x+1]), stone[x+2])
and each of the case, the next player start from x+1, x+2, x+3 respectively

So the diff will be calculated through:

=> sum_{x -> x + i} - dfs(x + i + 1), where i = [0, 3)
=> and dp[x] is the max value of above possible ways

*/

class Solution_TopDown {
  std::vector<int> dp;

  int dfs(vector<int>& stoneValue, size_t startFrom) {
    if (startFrom >= stoneValue.size()) {
      return 0;
    }
    if (dp[startFrom] != INT_MIN) {
      return dp[startFrom];
    }
    int maxTo = std::min(stoneValue.size(), startFrom + 3);
    int sum = 0;
    for (auto i = startFrom; i < maxTo; ++i) {
      sum += stoneValue[i];
      dp[startFrom] = std::max(dp[startFrom], sum - dfs(stoneValue, i + 1));
    }
    return dp[startFrom];
  }

 public:
  string stoneGameIII(vector<int>& stoneValue) {
    dp = std::vector<int>(stoneValue.size(), INT_MIN);
    const auto maxDiff = dfs(stoneValue, 0);
    return maxDiff == 0 ? "Tie" : maxDiff > 0 ? "Alice" : "Bob";
  }
};

class Solution_BottomUp {
 public:
  string stoneGameIII(vector<int>& stoneValue) {
    int n = stoneValue.size();
    vector<int> dp(n + 1, INT_MIN);
    dp.back() = 0;
    for (int startFrom = n - 1; startFrom >= 0; --startFrom) {
      int sum = 0;
      for (int i = 0; i < 3 && startFrom + i + 1 <= n; ++i) {
        sum += stoneValue[startFrom + i];
        dp[startFrom] = std::max(dp[startFrom], sum - dp[startFrom + i + 1]);
      }
    }
    return dp[0] == 0 ? "Tie" : dp[0] > 0 ? "Alice" : "Bob";
  }
};

using Solution = Solution_BottomUp;
