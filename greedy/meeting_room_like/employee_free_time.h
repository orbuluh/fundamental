/*
Idea, minPQ to store interval by start time.
Then we keep pop'ing the value. As start time is sort, we know later popped
has larger start time. We only need to check if prev end time is larger than
current start time, if so, 2 slots can be merged, through setting end time to
the larger value.
*/
class Solution {
  public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        using SlotPtr = Interval*;
        auto comp = [](SlotPtr a, SlotPtr b) { return a->start > b->start; };
        std::priority_queue<SlotPtr, std::vector<SlotPtr>, decltype(comp)>
            minPq(comp);
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