/*
Since split numbers must be unique, the best strategy is to use the smallest
possible numbers first, by the time that you exceed the finalSum - just
basically put the remaining in one.
*/
class Solution {
 public:
  vector<long long> maximumEvenSplit(long long finalSum) {
    vector<long long> sol;
    for (int i = 2; i <= finalSum && finalSum % 2 == 0; i += 2) {
      if (finalSum - i >= i + 2) {
        sol.push_back(i);
      } else {
        // if after adding i, the remaining is not enough to put the next number
        // i + 2, we won't push i, we just push all the remaining as last number
        // there cannot be a solution with more number, as we've already used
        // all the smaller number
        sol.push_back(finalSum);
      }
      finalSum -= sol.back();
    }
    return sol;
  }
};