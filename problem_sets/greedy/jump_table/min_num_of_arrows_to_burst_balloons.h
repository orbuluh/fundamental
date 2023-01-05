/*
[1  6][7 ...   12]
  [2    8] [10 ...  16]

sort with begin and (if begin same, smaller end in front)

every iteration, pop the first one and record its end as curEnd

Because begin is sorted, this one that just got pop'ed out should be one that
can't be covered by the previous arrow. And the goal is to find an arrow that
must cover this one and greedily covered as most later balloons as possible.

Can we simply do it with:

- for every next balloon that has start <= curEnd, we pop?

No, say [1 10] [3 6] [7 11]

- we need to cover [1 10] in this iteration, and [3 6] is something we can
  burst together in this round. But once we burst it, can we still burst [7 9]?
  We can't. Because [3 6] effectively shrink the curEnd to 6.

- Then the question will be, what if we take [1 10][7 11] together, and [3 6]
  later, we still use 2 arrows. But then we realize sorted with start might not
  give us a good greedy way to derive the answer.

- (We could shrink the curEnd accordingly, and will pass OJ, which is your
  original solution. But there is actually other way to think...)

So the observation here is that, we would actually want to burst as right as
possible, as doing this gives us the best chance to cover most balloons.

So we can actually sort with end instead.

[3 6][1 10][7 11]

==> then the one with smallest end at the moment must be consumed by an arrow.
For later balloons, as long as its start <= currentEnd, we are good to burst!

Then we can greedily burst at 6, and we know it covers [1 10] as well.
Then [7 11] has to be covered by other arrow!
*/
class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& points) {
    std::sort(points.begin(), points.end(),
              [](const auto& pt1, const auto& pt2) { return pt1[1] < pt2[1]; });
    const int n = points.size();
    int idx = 0;
    int arrow = 0;
    int curEnd = -1;
    while (idx < n) {
      arrow += 1;
      curEnd = points[idx++][1];
      while (idx < n && points[idx][0] <= curEnd) {
        idx++;
      }
    }
    return arrow;
  }
};