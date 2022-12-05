class Solution {
 public:
  /*
  More of reasoning the solution from others...

  How can we get overlapped subproblems? say dp[i] is the min operations
  required to reach i, can dp[i] always be reused? NO! why? because the speed
  at i might be different, which affect how to travel from i to other point.

  So, if we define:

  " dp[i] is the minimum number of operations required to reach i, with initial
    speed 1 "

  - Then as the operation after R will start with speed 1, which implies
    we can only apply dp[i] right after the reverse instruction.

  with this, we can continue to analyze the potential scenarios.

  Note - the goal is to minimize the steps arriving a point t. In order to
  achieve it, you always try to go forward as much as you can, this leaves 3
  scenarios:

  1. taking m step forward that just arrived t. This takes m ops.
  2. taking m step forward that just passing t, then you turn around, and step
     backward for q step and arrived t. This takes m + 1 + q ops.
  3. taking m - 1 step forward (where m would have passed t), then you turn
     around and move q step backward, (where q < m - 1), then you turn around
     and move x times again to reach t. This takes m + 1 + q + 1 + x ops.

  e.g.

  scenario 1:
   x             t
  -|-------------|--
   |->   m*A   ->|  (where m step just reach t)


  scenario 2:

   x             t           y
  -|-------------|-----------|
   |->         m*A         ->|  (where m step just exceed t)
                 |<-  q*A  <-|

  scenario 3

   x     z         y     t
  -|-----|---------|-----|
   |-> (m-1) * A ->|         (where taking m step would have exceed t)
         |<- q*A <-|         (p = (q*A operation) = 2^q - 1)
         |->    x*A    ->|

  // ------------------------------

  scenario 1 [cont]:
  If t == 2^m - 1, the minimum number of operations is m.
  e.g. dp[t] = dp[x] + m

  Other wise, say we advance m times, where 2^(m-1)-1 < t < 2^m - 1
  Then we have 2 ways to get back to i with minimal steps.

  scenario 2 [cont]:
  The car reaches y = 2^m - 1 and reverses, the reverse length = y - t, which
  can be the same as the subproblem dp[y - t] = dp[2^m -1 -t].

  scenario 3 [cont] (say x == 0):
  - a. (->) The car reaches y = 2^(m-1) - 1 and then
  b. reverse (<-), accelerates for another q times in the opposite
     direction amd reach z. Then reverse again (->).
  - In 1.b - the reverse will travel p = 2^q - 1 distance
  - Now its position is at
    y - p = (2^(m-1) - 1) - (2^q - 1) =  2^(m-1) - 2^q,
  - In 1.c - the remaining len to travel is (y - p) to t, and because we've
    reversed with speed 1, we can find the sub-solution using relation:
    dp[t - (y - p)] = dp[i - 2^(m-1) + 2^q].
  */
  inline int distance(int numOfOps) {
    return (1 << numOfOps) - 1;
  }

  std::array<int, 10001> dp = {0};
  int racecar(int t) {
    if (t == 0) return 0;
    if (dp[t] > 0) return dp[t]; // we build bottom up, dp[t] must be smallest

    // we try to find the max step needed to exceed t
    // 2^m - 1 = t,  m = log2(t + 1)
    const auto m = static_cast<int>(std::ceil(log2(t + 1)));
    const auto mOpsDis = distance(m);

    // scenario 1: if m steps just make us arrive target, m is what we need
    if (mOpsDis == t) {
      return dp[t] = m;
    }

    // scenario 2: go pass t with m step, reverse,
    // then see what it takes to go back to t. (This is a potential solution,
    // but not necessary the solution, we still need to check scenario 3)
    dp[t] = m + 1 + racecar(mOpsDis - t);

    // scenario 3: we don't go pass i (with (m - 1) * A), we revert and travel q
    // times, then we revert again and travel to t.
    // Here, q must < m - 1, otherwise we go to the original point...
    // we don't know how many q should we do, we have to check them all
    for (int q = 0; q < m - 1; ++q) {
      const auto finalTravel = t - (distance(m - 1) - distance(q));
      const auto opsTook = (m - 1) + (1 + q) + 1 + racecar(finalTravel);
      dp[t] = std::min(dp[t], opsTook);
    }
    return dp[t];
  }
};