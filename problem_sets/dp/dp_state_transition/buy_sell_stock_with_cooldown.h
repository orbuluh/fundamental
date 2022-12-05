/*
b, s, c: profit of last operation being buy/sell/cool down respectively
The trick is including buy price p as -p into the profit, then you don't
need to keep track of the buy price for each state, you just need to
focus on maximize the profit.

b[i] = max(c[i - 1] - p,              # previously chill, and buy now
           b[i - 1])                  # do nothing, same as last buy
s[i] = max(b[i - 1] + p,              # sell at i, from last buy
          s[i - 1])                   # do nothing, same as last sell
c[i] = max(s[i - 1], c[i - 1])        # sell previously and chill or just chill
*/
class Solution {
 public:
  enum State { B, S, C };
  int maxProfit(vector<int>& prices) {
    std::array<int, 3> bsc = {INT_MIN, INT_MIN, 0};
    auto nxtBsc = bsc;
    for (auto p : prices) {
      nxtBsc[B] = std::max(bsc[B], bsc[C] - p);
      nxtBsc[S] = std::max(bsc[S], bsc[B] + p);
      nxtBsc[C] = std::max(bsc[C], bsc[S]);
      std::swap(bsc, nxtBsc);
    }
    return std::max(bsc[1], bsc[2]);
  }


/* The other way that will also work:

dp[i] = max profit when doing X at i

buy at i can either from previous buy (no buy at i) or
previous cooldown - price(buy at i)
- B[i] = std::max(C[i - 1] - prices[i], B[i - 1])

sell at i can only from buy at i - 1
- S[i] = B[i - 1] + prices[i]

cooldown at i can either be from sell at i - 1
or cooldown at i - 1
- C[i] = std::max(S[i - 1], C[i - 1])

initially:
B[0] = -prices[0]
S[0] = 0
C[0] = 0

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      const auto sz = prices.size();
      // 0: B, 1: S, 2: Cooldown
      std::array<int, 3> bsc = { -prices[0], 0, 0 };
      std::array<int, 3> nxtBsc = {};
      for (int i = 1; i < sz; ++i) {
        nxtBsc[0] = std::max(bsc[2] - prices[i], bsc[0]);
        nxtBsc[1] = bsc[0] + prices[i];
        nxtBsc[2] = std::max(bsc[1], bsc[2]);
        std::swap(bsc, nxtBsc);
      }
      return std::max(bsc[1], bsc[2]);
    }
};

*/