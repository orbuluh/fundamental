/*
from @lee215 ...

define: dp[d] = the maximum sum of height we can obtain
from a pair of numbers with a difference of "d".

E.g. say we only have
- x1 + x2 + ... = a
- y1 + y2 + ... = b
- a > b
- then dp[diff = a - b] = min(a, b) = b,

Or look it in the other way, say we already have dp[d] = y, it means we must
have one group of number summing to y, and the other group of number summing
to y + d.

Supposed now we are dealing with a new rod length x, how do we update?

Case 1:

If we add a number "x" to the larger number:
-------y------|----- d -----|--- x ---|
-------y------|

We update dp[d + x] = max(dp[d + x], y), e.g. the max height we can update from
these 2 groups is still only y, but now it's for a new diff value d + x

Case 2.1:
If we add a number "x" to the smaller number and d is greater than or equal to
x:
-------y------|----- d -----|
-------y------|--- x ---|

We update dp[d-x] = max(dp[d - x], y + x).

Case 2.2:
If we add a number "x" to the smaller number and d is less than x:
-------y------|----- d -----|
-------y------|------- x -------|

We update dp[x - d] = max(dp[x - d], y + d).

Both Case 2.1 and Case 2.2 can be merged into
dp[abs(x - d)] = max(dp[abs(x - d)], y + min(d, x)).

and then, what's the initial state?

At the initial state, where we haven't checked any rod,
we have dp is dp[0] = 0.


As a result, every time we see a new rod, we update all the entry in the dp
accordingly (e.g. each diff we've seen will be one entry, and each diff has
a max height as recorded in the dp value.)

At the end, we check what's the result of dp[0], as it's the case that 2
group sums are equal!
*/
class Solution {
 public:
  int tallestBillboard(vector<int>& rods) {
    // making vector is much faster than unordered_map
    std::vector<int> dp(5001, -1);
    dp[0] = 0;
    for (auto x : rods) {
      // make a deep copy of previous dp, where we haven't
      // seen the new rod with len x. (As you can't update
      // the dp while iterating it, you need to make a copy
      // , otherwise you are not considering independent state)
      std::vector<int> prevDp(dp);
      for (int d = 0; d < 5001; ++d) {
        const auto y = prevDp[d];
        if (y < 0) continue;
        dp[d + x] = std::max(dp[d + x], y);
        dp[std::abs(x - d)] = std::max(dp[std::abs(x - d)], y + std::min(d, x));
      }
    }
    return dp[0];
  }
};