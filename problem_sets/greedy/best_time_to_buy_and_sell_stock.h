/*
keep a minPrice seen so far, say, 3, If you later see a even smaller price, say
2, then a larger price, say, 5 then the even smaller price must create a larger
profit

[3 2 5] => so whenever we see a smaller number, we update the minPrice.
Otherwise, we just calculate the profit and see if it's the largest we've seen

On the contrary, if it's [1 3 2 5], 3 and 2 will just be ignored as minSeen is 1
along the way. Then the maxProfit is 4
*/
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int minSeen = INT_MAX;
    int maxProfit = 0;
    for (auto p : prices) {
      if (p < minSeen) {
        minSeen = p;
      } else if (p > minSeen) {
        maxProfit = std::max(maxProfit, p - minSeen);
      }
    }
    return maxProfit;
  }
};