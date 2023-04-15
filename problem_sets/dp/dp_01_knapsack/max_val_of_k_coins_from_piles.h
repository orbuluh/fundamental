/*
As the really big value could be under some pile, generally we need an exhaust
search. We can imagine that there are overlapped subproblems that we can
dp/memorize.

                    pop(0, 0)          pop(1,0)
[[1,100,3],[7,8,9]] -> [[100,3],[7,8,9]] -> [[100,3],[8,9]]

                    pop(1, 0)          pop(0,0)
[[1,100,3],[7,8,9]] -> [[1,100,3],[8,9]] -> [[100,3],[8,9]]

These 2 orderings both eventually hit the same case [[100,3],[8,9]].

Taking further look, one critical thing to realize is that ordering
doesn't change the result. For [[1,100,3],[7,8,9]], you pick 1 then 7,
or you pick  7 then 1, the result are the same.

Because ordering doesn't matter, when we do DFS, we could simply make sure our
DFS iteration is a unique case through iterating each pile. For each iteration,
the variant is how many coins we've taken on that specific pile.
- (the amount we can take is min(size of pile, k).

When we dfs down, we will no longer exam previous pile. It's fine because, again
, ordering doesn't matter. And we've ensured to check the case of including
previous pile in previous DFS.

Essentially, it's a 0/1 knapsack problem. To take or not to take from a pile.
*/
class Solution {
 public:
  int n = 0;
  std::vector<std::vector<int>> dp;
  int maxValueOfCoins(vector<vector<int>>& piles, int k) {
    n = piles.size();
    dp = std::vector<std::vector<int>>(n, std::vector<int>(k + 1, -1));
    return dfs(piles, 0, k);
  }

  int dfs(vector<vector<int>>& piles, int pileIdx, int k) {
    if (pileIdx >= n || k <= 0) {
      return 0;
    }
    if (dp[pileIdx][k] != -1) {
      return dp[pileIdx][k];
    }
    // not picking any value from piles[pileIdx]
    int maxVal = dfs(piles, pileIdx + 1, k);
    // picking 1 -> maxCoinCnt of coins from piles[pileIdx]
    const int pileSz = piles[pileIdx].size();
    const int maxCoinCnt = std::min(k, pileSz);
    int value = 0;
    for (int i = 0, kLeft = k; i < maxCoinCnt; ++i) {
      value += piles[pileIdx][i];
      maxVal = std::max(maxVal, value + dfs(piles, pileIdx + 1, --kLeft));
    }
    return dp[pileIdx][k] = maxVal;
  }
};
