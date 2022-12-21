/*
The idea is that you can use a jump table like concept to record "how far can
you reach", given the fact that your sort all the input with starting time first

So assume you sort the input with starting time like:

[0, 1]
[0, 3]
[0, 4]

Then you know for these 3 ranges, you can always take the furthest [0, 4]

say the next range is [5, X], what will it imply? It will imply that there must
be a hole for [4, 5], as you've sorted the start time. So you know you can end
the search and return -1.

So from the exit case, you can observe that the ranges you are going to greedily
look should be those overlapped with what was added in the previous iteration.

So say remaining few ranges are not [5, X], but below instead:

[2, 5]
[3, 6]
[4, 8]
[5, 100]

What you will greedily search are the [2, 5], [3, 6], [4, 8],
but without the [5, 100]. Why? Because the 5 isn't overlapped with last time's
end range 4. So it can not be considered in our greedy search in this iteration.

Same logic, [2, 5] can't be considered in the previous iteration, because it
doesn't overlapped with the initial 0.

So we know, in the second iteration, we greedily find our end to be 8.

Then in the 3rd iteration, we check [5, 100], and we find our final end to 100.
*/

class Solution {
 public:
  int minTaps(int n, vector<int>& ranges) {
    std::vector<std::pair<int, int>> intervals;
    for (int i = 0; i <= n; ++i) {
      intervals.emplace_back(std::max(0, i - ranges[i]),
                             std::min(n, i + ranges[i]));
    }
    std::sort(intervals.begin(), intervals.end());
    int coveredEnd = 0;
    int i = 0;
    int cnt = 0;
    while (i <= n && coveredEnd < n) {
      if (intervals[i].first > coveredEnd) {  // there must be hole
        break;
      }
      int oriEnd = coveredEnd;
      while (i <= n && intervals[i].first <= oriEnd) {  // pushing the boundary
        coveredEnd = std::max(coveredEnd, intervals[i++].second);
      }
      // maybe in this iteration, nothing has made a better result
      // consider [0, 10] | [1, 9] --> second iteration just not adding anything
      cnt += (coveredEnd != oriEnd);
    }
    return coveredEnd >= n ? cnt : -1;
  }
};