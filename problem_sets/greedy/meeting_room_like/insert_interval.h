/*

upper_bound / lower_bound way listed below ... pretty hard to get right.
(Noted that when doing so, what's the element in comp that represents the new
interval? It's different in upper_bound and lower_bound...). Plus, eventually,
the erase operation is a O(n) operations... so not actually much faster.

The "brute force" solution is actually clean (and about the same speed) to do.
So you don't need to try to do this in-place. You create a new vector.
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

/*

The hard to get right lower_bound + upper_bound approach

The idea is find the "affected interval" [mergeBegin, mergeEnd)
(Note: mergeEnd is non-inclusive)

mergeBegin should start from an interval with end >= newInterval[0]
mergeEnd should start from an interval with start > newInterval[0]

The really tricky thing is the comp in lambda of the upper/lower_bound.

cppreference -> check the `comp(element, value)` v.s. `comp(value, element)`

std::lower_bound:
- Returns an iterator pointing to the first element in the range [first, last)
  that does not satisfy element < value (or comp(element, value)), (i.e. greater
  or equal to), or last if no such element is found.

std::upper_bound:
- Returns an iterator pointing to the first element in the range [first, last)
  such that value < element (or comp(value, element)) is true (i.e. strictly
  greater), or last if no such element is found.

So newInterval is second element of lower_bound's comp and
   the first element of upper_bound's comp...
*/

/*

class Solution {
 public:
  std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals,
                                       std::vector<int> newInterval) {
    // inclusive begin where existing end >= newInterval[0]
    auto mergeBegin = lower_bound(
        intervals.begin(), intervals.end(), newInterval,
        [](const auto& e, const auto& tgt) { return e[1] < tgt[0]; });
    // non-inclusive mergeEnd where the existing begin > newInterval[1]
    auto mergeEnd = upper_bound(
        intervals.begin(), intervals.end(), newInterval,
        [](const auto& tgt, const auto& e) { return tgt[1] < e[0]; });
    if (mergeBegin == mergeEnd) { // no merge needed
      intervals.insert(mergeBegin, newInterval);
    } else {
      newInterval[0] = std::min(newInterval[0], (*mergeBegin)[0]);
      // previous of non-inclusive mergeEnd is the last merged element
      newInterval[1] = std::max(newInterval[1], (*std::prev(mergeEnd))[1]);
      intervals.erase(mergeBegin, mergeEnd);
      intervals.insert(mergeBegin, newInterval);
    }
    return intervals;
  }
};


*/