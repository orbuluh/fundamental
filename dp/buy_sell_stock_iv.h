/*

State transition DP ...
Buy can be from
- a buy state (where you basically ignore price[i]) or
- from a sell state (as previously it ends with a buy)

Sell can be from
- a sell state (where you basically ignore price[i]) or
- from a buy state (as previously it ends with a sell)

Embedded the buy price/sell price into the resulting profit
will make sure you don't even need to track it. You just need
to focus on maximizing the profit in each state

So we can define

dpB[k][i] = max profit with at most k transactions
                            ending with last operation being buy
                            using array index [0, i]
dpS[k][i] = max profit with at most k transactions
                            ending with last operation being sell
                            using array index [0, i]

And the recursion will be like

dpB[k][i] = max(
  dpB[k][i - 1]           ... e.g. prices[i] don't affect at all)
, dpS[k - 1][i - 1] - p)  ... e.g. eventually buy at i, which use one more
                                   transaction

dpS[k][i] = max(
  dpS[k][i - 1])          ... e.g. prices[i] don't affect at all
, dpB[k][i - 1] + p)      ... e.g. you sell at i, where transaction counter has
                                   included while calculating buy, so it's also
                                   using k

when there is no transaction, e.g. k == 0, a.k.a initial state ...
it's basically similar to a sell with eventually 0 profit before.

dpS[0][i] = 0

you can't buy before seeing anything, use INT_MIN to represent an invalid state
dpB[0][i] = INT_MIN

*/
class Solution {
 public:
  int maxProfit(int k, vector<int>& prices) {
    const int m = prices.size();
    auto dpB = std::vector<int>(k + 1, INT_MIN);
    auto dpS = std::vector<int>(k + 1, 0);
    for (auto p : prices) {
      for (int txn = 1; txn <= k; ++txn) {
        dpB[txn] = std::max(dpB[txn], dpS[txn - 1] - p);
        dpS[txn] = std::max(dpS[txn], dpB[txn] + p);
      }
    }
    return dpS.back();
  }
