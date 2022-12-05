/*
The idea is, you are basically doing a *horizontal* line scanning on each x that
is an edge of a building. Why horizontal? Because you are trying to find the
skyline, which means the highest remaining building matters.

The key point will only exist at x where x is an edge of a building.

So the core idea is that we maintain a max PQ like structure, where the PQ.top()
is the current max height. Say PQ.top() = h1
- When we see a building's end edge with height h, we will have to remove that
  height from the PQ (so eventually this isn't an PQ, otherwise it is hard to
  remove a height that is not at top.).
- And if after the removal, there is no other height left in the "PQ", it means
  there is a key point with height 0 to mark the skyline.
- Otherwise, if there is other height left, say height h2 ...
  - if h2 < h1, (e.g. what get popped is the same as original top, h1 == h),
then this h2 will surface (create a key point)
  - if h2 == h1, it means there is other building with same height that is not
    ended yet, so not key point created
  - if h2 > h1, this can't happen. As if h2 > h1, h1 can't be the PQ.top() value

- On the other hand, when we see a building's left edge with height h, we just
  insert the height into the PQ. As it's a PQ like structure, what matters is
  still PQ.top()

The edge cases happens when there are multiple building edges at a point x.
- If both edges are left, we process the higher height first. (So we can always
  append the highest height to the keyPts)
- If both edges are right, we process the smaller height first. (So we won't
  "surface" the wrong height, as both of them eventually will be removed.)

- If one edge is left and the other is left? We always process the left edge
  first. As that new left edge could be "surfaced" after remove the right edge.
  So it has to be in the PQ like structure to be surfaced.

So what we are going to do is breaking down the input to "(skyline) event"s,
where each event has
- x (position)
- isLeft (event type, either left or right)
- h (height)

And we sort the events by the above logic.
- event at smaller x should be processed first.
- if x are the same, event that isLeft should be processed first.
- otherwise,
  - if both events are isLeft: we processed higher height first.
  - if both events are !isLeft: we processed smaller height first.

Finally - the PQ like stucture with quick removal can actually be done through
multiset - because multiset is ordered, multiset.rbegin() will always be the max
value. And we can insert into multiset through bisect, and remove a height with
lg(n) complexity.
*/

class Solution {
  struct Event {
    int x = 0;
    int h = 0;
    bool isLeft = false;
  };

 public:
  std::vector<Event> events;
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    for (const auto& bld : buildings) {
      events.emplace_back(Event{bld[0], bld[2], true});
      events.emplace_back(Event{bld[1], bld[2], false});
    }
    std::sort(events.begin(), events.end(), [](const auto& e1, const auto& e2) {
      // process smaller x first
      if (e1.x != e2.x) return e1.x < e2.x;
      // x is the same, process open edge first
      if (e1.isLeft ^ e2.isLeft) return e1.isLeft;
      // x is the same, and both are either left or open
      if (e1.isLeft) {
        return e1.h > e2.h; // if it's open, process higher one first
      } else {
        return e1.h < e2.h; // if it's close, process lower one first
      }
    });
    std::vector<std::vector<int>> keyPts;
    std::multiset<int> heightBst; //the PQ-like book keeping of horizontal level
    for (const auto& e : events) {
      if (e.isLeft) {
        // left edge with new max height - key point!
        if (heightBst.empty() || *heightBst.rbegin() < e.h) {
          keyPts.emplace_back(std::vector<int>{e.x, e.h});
        }
        auto it = heightBst.lower_bound(e.h);
        heightBst.insert(it, e.h);
      } else {
        auto it = heightBst.lower_bound(e.h);
        if (it != heightBst.end()) heightBst.erase(it);
        // no other building remaining - key point with 0 height!
        if (heightBst.empty()) {
          keyPts.emplace_back(std::vector<int>{e.x, 0});
        } else if (*heightBst.rbegin() < e.h) {
          // some other building remaining, which has a lower height than the
          // one just got removed - such height will be "surfaced" as key point
          keyPts.emplace_back(std::vector<int>{e.x, *heightBst.rbegin()});
        }
      }
    }
    return keyPts;
  }
};