/*

You tried a lot on using upper_bound and lower_bound as you thought you
should find the insertion point then try the merge... But in reality it's
really hard ...

Particularly upper_bound/lower_bound doesn't seem to work well if you try
to find value.end v.s. element.start and vise versa. Just hard to get it right.

And in reality ... the "brute force" solution is actually the most clean way to
do.

so you don't need to try to do this in-place. You create a new vector.
Then you just move over the content till you hit the insertion point.

Then merge newInterval with all the later element till you shouldn't
- e.g. till newInterval.end is smaller than a interval.start.
and then just insert the newInterval

Finally, copy the remaining.
*/

class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    const auto oriSz = intervals.size();
    std::vector<std::vector<int>> res;
    res.reserve(oriSz + 1);
    int idx = 0;
    // just move over the value before insertion point
    for (; idx < oriSz && intervals[idx][1] < newInterval[0]; ++idx) {
      res.emplace_back(std::move(intervals[idx]));
    }
    // merge all the later element till you shouldn't
    for (; idx < oriSz && newInterval[1] >= intervals[idx][0]; ++idx) {
      newInterval[0] = std::min(newInterval[0], intervals[idx][0]);
      newInterval[1] = std::max(newInterval[1], intervals[idx][1]);
    }
    res.emplace_back(std::move(newInterval));
    // finally, copy the remaining
    res.insert(res.end(), intervals.begin() + idx, intervals.end());
    return res;
  }
};