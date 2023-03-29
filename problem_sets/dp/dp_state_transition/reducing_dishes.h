/*
Say ltc = Like-time coefficient
say array [n1, n2, p1, p2, p3]
and you've got ltc = p1 * 1 + p2 * 2 + p3 * 3
now you want to pull n1, the result should be
    ltc' = n1 + p1 * 2 + p2 * 3 + p3 * 4
         = n1 + ltc + (p1 + p2 + p3)
same, if you further pull n2
    ltc'' = n2 + n1 * 2 + p1 * 3 + p2 * 4 + p3 * 5
          = n2 + ltc' + (n1 + p1 + p2 + p3)

E.g. you can keep track of sum of subarray and the current
ltc, then whenever you pull in a new number, the new ltc equals
to the previous ltc + sum of current subarray

Your original solution is finding the positive part of sorted input
then pull in the negative number one by one.

You don't really need this though. You can basically just starting
from the sorted input like you only include the largest number,
then pull in the remaining...
*/

class Solution {
 public:
  int maxSatisfaction(vector<int>& satisfaction) {
    std::sort(satisfaction.begin(), satisfaction.end(), std::greater<int>{});
    int arraySum = 0;
    int ltc = 0;
    int maxLtc = 0;
    for (int n : satisfaction) {
      arraySum += n;
      ltc += arraySum;
      maxLtc = std::max(ltc, maxLtc);
    }
    return maxLtc;
  }
};