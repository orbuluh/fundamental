/*
We can't just use monoQ ... as pop'ing some values from small age for a smaller
score of larger age might not worth. Consider
[age, score]: [1, 5][1, 5][2, 4][2, 6]
if monoQ, it would have build the monoQ like [5] -> [5, 5] -> [4] -> [4, 6]
But the actual answer is [5, 5, 6] (e.g. we don't need to pop 5, 5 for that 4)

We can try to use backtrack, while you decide whether or not to take
a score with an age or not. This will TLE though.

Overall, this is actually the same as longest increasing subsequence (LIS).

In LIS problem, what we do:
  dp[i] = minimum value that can form a seq with len i + 1

Here, consider the case that we sort the input with smaller age, then when we
loop, we know that for player in the front, it must have a smaller than or equal
to age compared to the back. So once after sorting with age, the score are
basically what we want to build for LIS.

And for same age, should we sort the score increasingly or decreasingly? As
"same age don't have conflict" and we are trying to build LIS, we should
actually put lower score in the front as well.

so for [age, score]: [1, 5][1, 5][2, 4][2, 6], it becomes LIS problem of [5 5 4 6]

The other variation part is that we are building the sum along the way.
So here, we store state like this:

dp[i] stores the max sum consists of
  - player i and
  - player j where j in [0, i - 1]

For a subsequence containing player[i], all previous score must <= scores[i]
we can just build it with with dp[j] where j < i and scores[j] <= scores[i]
*/
class Solution {
 public:
  struct Info {
    int age = 0;
    int score = 0;
    Info(int a, int s) : age(a), score(s) {}
  };
  int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    std::vector<Info> players;
    const int sz = scores.size();
    for (int i = 0; i < sz; ++i) {
      players.emplace_back(ages[i], scores[i]);
    }
    std::sort(
        players.begin(), players.end(), [](const Info& i1, const Info& i2) {
          return i1.age < i2.age || (i1.age == i2.age && i1.score < i2.score);
        });
    int maxSum = 0;
    std::vector<int> dp(sz, 0);
    for (int i = 0; i < sz; i++) {
      dp[i] = players[i].score;
      for (int j = 0; j < i; j++) {
        if (players[j].score <= players[i].score) {
          dp[i] = max(dp[i], dp[j] + players[i].score);
        }
      }
      maxSum = max(maxSum, dp[i]);
    }
    return maxSum;
  }
};