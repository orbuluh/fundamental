/*
b, s, c: profit of last operation being buy/sell/cool down respectively
The trick is including buy price p as -p into the profit, then you don't
need to keep track of the buy price for each state, you just need to
focus on maximize the profit.

b[i] = max(c[i - 1] - p, b[i - 1])    # buy can either from cool down, or prev
                                      # buy, which means you do nothing with
                                      # prices[i]

s[i] = max(b[i - 1] + p, s[i - 1])    # same rationale, either do nothing or
                                      # from a last operations buy

c[i] = max(s[i - 1]    , c[i - 1])    # just chill
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
