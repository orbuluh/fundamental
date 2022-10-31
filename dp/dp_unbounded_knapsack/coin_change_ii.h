/*
Classic unbounded knapsack problem

Note ... the loop ordering matters

Why? with looping coins in the outer loop, it means that each time we are adding
one new coin value to pick from. So in each iteration, you are dealing with a
specific setup/subproblem and it's sure that there won't be double counting in
the next iteration.

On the other hand, if outer loop is target amount, the dp iteration would become
...
Number of ways with all coins to form target = 1
Number of ways with all coins to form target = 2
...
However, say there is a coin value 1:
then number of ways to form target = 1 also actually imply number of ways to
form target = 2, (as just through adding one more val 1 coin.) So you will
actually not be building the correct state along the way
*/
class Solution {
 public:
  int change(int amount, vector<int>& coins) {
    std::vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int j = 0; j < coins.size(); ++j) {
      for (int tgt = 1; tgt <= amount; ++tgt) {
        if (coins[j] <= tgt) {
          dp[tgt] += dp[tgt - coins[j]];  // take 1 coin[j]
        }
      }
    }
    return dp[amount];
  }
};