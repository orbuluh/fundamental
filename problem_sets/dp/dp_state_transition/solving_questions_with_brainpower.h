/*

It's almost like painting house/house rubber questions, but you were stuck on
the place where when you pick or not pick, there could be choices in between
allowable next move and the point. How to formulate the dp array then?


If you think about top down approach, the recursive would be like you go to i,
you try to take i and go to i + brain[i] + 1, or just try i + 1 with same score.
At the end, you arrive some point >= end of questions. And then you start to
recursively return from the bottom value. The bottom value will be the case that
you are handling the right most cases, and then going back to left.


This is how we should formulate the dp questions. Think about it, if you do this
from right to left, you know what you have put into the dp array, just won't
affect the value on its left. It must be a value that can only affect its right.

So overall, we define dp[i] to be the max points you can get using questions[i:]

And the dp recursion should be

dp[i] = max(
          dp[i + 1]    //... not taking i
          score[i] + dp[i + brainpower[i] + 1] // taking i
        )
*/

static const int io_trick = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
}();

class Solution {
 public:
  long long mostPoints(vector<vector<int>>& questions) {
    std::array<int64_t, 200'001> dp = {}; // because input constraints
    const int sz = questions.size() - 1;
    for (int i = questions.size() - 1; i >= 0; --i) {
      const int score = questions[i][0];
      const int brainPower = questions[i][1];
      dp[i] = std::max(dp[i + 1], dp[i + brainPower + 1] + score);
    }
    return dp[0];
  }
};