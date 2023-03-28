/*
dp[i] being the min cost to travel on date i

The key thing is when date i is not in the input days - the cost should equal
to the latest day in input days. This can be captured by setting it with the
same value as previous day - hence the hashset and find.

By setting every date accordingly, you can get the clean state transition
from day - 1, day - 7, and day - 30
*/

class Solution {
 public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    std::unordered_set<int> daysSet(days.begin(), days.end());
    int dp[30] = {};
    auto mod = [](int d) { return d > 0 ? d % 30 : 0; };
    for (int day = days.front(); day <= days.back(); ++day) {
      if (daysSet.find(day) == daysSet.end()) {
        dp[mod(day)] = dp[mod(day - 1)];
      } else {
        dp[mod(day)] =
            std::min({dp[mod(day - 1)] + costs[0],
                      dp[mod(day - 7)] + costs[1],
                      dp[mod(day - 30)] + costs[2]});
      }
    }
    return dp[mod(days.back())];
  }
};