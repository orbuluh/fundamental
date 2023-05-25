/*

k: stopping points
n: target points

Observation:

Say p[x] is the probability of getting score x. Then The answer is asking for
p[k] + ... + p[k - 1 + maxPts] then. Why?

When the game stops ...
- the minimum point is k
- the maximal point is k - 1 + maxPts

As you can imagine that you get a maxPts in the last draw and before then, you
can only get k - 1 points at max, otherwise the game has stopped already.

But how do we calculate p[x]? You can imagine, to form a score of x, you can
get score x from x - 1, then pull 1; from x - 2, then pull 2; ...
            from x - maxPts, then pull maxPts

As pull 1, 2, ... maxPts all have the same probability 1/maxPts, the recursion:

p[x] = (p[x - 1] + p[x - 2] + ..... + p[x - maxPts]) * (1/maxPts);

So this will be like a sliding window for index p[x - maxPts...x - 1]
Every time we kicks p[x - maxPts - 1] out,and add p[x - 1] in


One thing to note is when x > k,  as the game stops while reaching k, we
shouldn't reach x from P[y] where y >= k. So the recursion:

p[x] = (p[k - 1] + ... p[k - 2] + ... + p[x - maxPts]) * (1/maxPts)

Therefore, it's like a fibonacci recursion ... but with dynamic relation with
result calculate previously........ HOLLY MOLLY
*/

class Solution {
 public:
  double new21Game(int n, int k, int maxPts) {
    int maxStopPt = k - 1 + maxPts;
    if (n >= maxStopPt || k == 0) {
      // the probability of getting score <= maxStopPt is just 1.0, as no
      // matter what you pull, the game is over.
      return 1.0;
    }
    double anyPtProb = 1.0 / maxPts;
    std::vector<double> p(maxStopPt + 1, 0);
    p[0] = 1.0;

    double prevProbSum = 0;
    double ans = 0.0;
    for (int score = 1; score <= n; ++score) {
      int startIdx = score - maxPts - 1;
      if (startIdx >= 0) {
        prevProbSum -= p[startIdx];
      }
      if (score <= k) {
        // when score > k, we no longer need to consider p[score - 1] into
        // the interested window, as the game should have stopped
        prevProbSum += p[score - 1];
      }
      p[score] = prevProbSum * anyPtProb;
      if (score >= k) {
        // goal is summing p[k] to p[n], loops ends at n
        ans += p[score];
      }
    }
    return ans;
  }
};