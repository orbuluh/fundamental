class Solution {
  /*
  Idea: for the same group of adjacent colors, just poke all of the ballon
  except for the highest cost! Then the remaining must not having adjacent same
  color

  Check below implementation, there is an amazing way to loop and detect the
  max cost within the group.

            b  a  a     a
  cost      2  1 1000  100
  max_cost  2  0  1    1000
  delta    +0 +0  +1   +100

  --> cost[i - 1] only take effect till iteration i, and in the i iteration,
      the delta is the min of maxCost so far and cost[i], so if cost[i - 1] is
      the bigger one, it won't affect the result, and if it's the smaller one,
      it is added into the delta as expected.

  Also side note, why the original dp intuition with two variable (burst, keep)
  failed? because when you do that, situation like aaa - when you burst the
  second a while keeping the first one, the third also can't be a! So you can't
  just make some recursion like:
    b(t) = min(k(t - 1), b(t-1)) + cost[t]
    k(t) = if color different: min(k(t - 1), b(t-1))
           else b(t-1)
  */
 public:
  int minCost(string colors, vector<int>& cost) {
    int maxCostOfGroup = cost[0];
    int totalCost = 0;
    for (int i = 1; i < colors.size(); ++i) {
      if (colors[i] != colors[i - 1]) {
        maxCostOfGroup = 0;
      }
      // maxCostOfGroup is updated when the color just
      // changed, the logic here only triggers when
      // you hit the first adjacent same color. So given
      // the std::min - the maximum of maxCostOfGroup will
      // never be added.
      totalCost += std::min(maxCostOfGroup, cost[i]);
      maxCostOfGroup = std::max(maxCostOfGroup, cost[i]);
    }
    return totalCost;
  }
};