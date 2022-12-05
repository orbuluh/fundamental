/*

k: stopping points
n: target points

Observation:

when the game stops, the minimum point is k
and the maximal point is k - 1 + maxPts, as you can imagine that you get a
maxPts in the last draw and before then, you can only get k - 1 points at max,
otherwise the game has stopped already.

Say p[x] is the probability of getting score x at the end.

The problem is asking for p[k] + ... + p[k - 1 + maxPts] then.

For positions x <= k,

p[x] = (p[x - 1] + p[x - 2] + ..... + p[x - maxPts]) * (1/maxPts);

- draw a card with y value with prob (1/maxPts),
  plus the fact that previously the points drawn was x - y

So this will be like a sliding window for index [x - maxPts, x - 1] inclusive
Every time we kicks p[x - maxPts - 1] out,and add p[x - 1] in

for x > k, as the game stops while reaching k, we shouldn't reach x from P[y]
where y >= k. So:

p[x] = (p[k - 1] + ... p[k - 2] + ... + p[x - maxPts]) * 1/maxPts

So overall it's like a fibonacci recursion ... but with dynamic relation with
result calculate previously........ HOLLY MOLLY
*/

class Solution {
 public:
  double new21Game(int n, int k, int maxPts) {
    int maxStopPt = k - 1 + maxPts;
    if (n >= maxStopPt || k == 0) {
      // the probability of getting score <= maxStopPt is just 1.0
      return 1.0;
    }
    double anyPtProb = 1.0 / maxPts;
    std::vector<double> p(maxStopPt + 1, 0);
    p[0] = 1.0;

    double prevProbSum = 0;
    double ans = 0.0;
    for (int tgtRes = 1; tgtRes <= n; ++tgtRes) {
      int preHeadIdx = tgtRes - maxPts - 1;
      if (preHeadIdx >= 0) {
        prevProbSum -= p[preHeadIdx];
      }
      if (tgtRes <= k) {
        // when tgtRes > k, we no longer need to consider p[tgtRes - 1] into
        // the interested window, as the game should have stopped
        prevProbSum += p[tgtRes - 1];
      }
      p[tgtRes] = prevProbSum * anyPtProb;
      if (tgtRes >= k) {
        // goal is summing p[k] to p[n], loops ends at n
        ans += p[tgtRes];
      }
    }
    return ans;
  }
};