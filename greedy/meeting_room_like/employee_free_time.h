/*
Idea, minPQ to store interval by start time.

Then we keep pop'ing the value. As start time is sorted, we know later popped
has larger start time.

for 2 intervals where later one has larger start time, when can they merge?
Only when previous one's end >= later one's start. So we can merge accordingly.

And when there is no merge, we basically find a free time from prev.end to
cur.start

*/
class Solution {
 public:
  vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
    using SlotPtr = Interval*;
    auto comp = [](SlotPtr a, SlotPtr b) { return a->start > b->start; };
    std::priority_queue<SlotPtr, std::vector<SlotPtr>, decltype(comp)> minPq(
        comp);
    for (auto& employeeSlots : schedule) {
      for (auto& slot : employeeSlots) {
        minPq.push(&slot);
      }
    }
    std::vector<Interval> res;
    SlotPtr prev = minPq.top();
    while (!minPq.empty()) {
      SlotPtr cur = minPq.top();
      if (prev->end >= cur->start) {
        // can merge, set end to the larger one
        prev->end = std::max(prev->end, cur->end);
      } else {
        res.push_back({prev->end, cur->start});
        prev = cur;
      }
      minPq.pop();
    }
    return res;
  }
};