/*

Note that the problem description actually have 2 hidden assumptions:

1. you have unlimited amount of inventory: so you can sell more than what you've
   bought
2. you have to buy before sell, which is the other aspect of the problem
   description:
   "You may not engage in multiple transactions simultaneously (i.e., you must
   sell the stock before you buy again).""

The trick is including buy price p as -p into the profit, then you don't
need to keep track of the buy price for each state, you just need to
focus on maximize the profit.

B = buy[i] means max profit before day i "for any sequence end with buy".
S = sell[i] means max profit before day i "for any sequence end with sell".
C = cd[i] means max profit before day i "for any sequence end with cooldown"

Note the state represents "any sequence end with X",
NOT that "at day i, it must be X"

So transition function is like

B' = max(C - p, B) ==> previous state C then buy, or doing nothing at i
                       and inherit the previous sequence that end with B
S' = max(B + p, S) ==> previous state C then sell, or doing nothing at i
                       and inherit the previous sequence that end with S
C' = max(S, C)     ==> previous state S then cd, or doing nothing at i
                       and inherit the previous sequence that end with C
*/
class Solution {
 public:
  enum State { B, S, C };
  int maxProfit(vector<int>& prices) {
    std::array<int, 3> bsc = {INT_MIN, INT_MIN, 0};
    auto nxtBsc = bsc;
    for (auto p : prices) {
      nxtBsc[B] = std::max(bsc[C] - p, bsc[B]);
      nxtBsc[S] = std::max(bsc[B] + p, bsc[S]);
      nxtBsc[C] = std::max(bsc[S], bsc[C]);
      std::swap(bsc, nxtBsc);
    }
    return std::max(bsc[1], bsc[2]);
  }
};