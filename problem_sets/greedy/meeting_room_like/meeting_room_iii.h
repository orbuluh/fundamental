/*

One key thing is to understand the problem:  ... for case like

2, [[2,15], [3,12], [16,17]]

The answer is 0, not 1
So even though at time 12, room 1 is freed up, at time 16, room 0 is freed as
well. So [16,17] will be using room 0, not room 1. And room 0 holds 2 meeting.

So in addition to the fact that we need to record the latest available time of
each room and pops those valid one out, we also need another queue to find out:
for all the available room, what are the one with smallest idx

So overall the idea is that we can keep 2 pqs. One to represent when a busy
room is freed up, and the other one represent the current available time.


We sorted the input with start time. Then whenever we see a new starting time,
we pop the busy room out if it's already available at this time point. Then we
find the available room with min index.

If there is no available room at this time point, then the earliest room that
is released will be used - but the release time have to be shifted. Otherwise,
we can just use the meeting room's endtime as its release time.

As we've sorted the start time, whatever that we've put into available room set
should be available in the next run.

*/
class Solution {
 public:
  int mostBooked(int n, vector<vector<int>>& meetings) {
    std::sort(meetings.begin(), meetings.end());
    using State = std::pair<unsigned long, int>;  // start time, room index
    std::priority_queue<State, std::vector<State>, std::greater<State>>
        roomBusyTill;
    std::priority_queue<int, std::vector<int>, std::greater<int>> availRoom;
    std::vector<int> meetingHold(n, 0);
    for (int i = 0; i < n; ++i) {
      availRoom.push(i);
    }
    auto topAndPop = [&](auto& q) -> auto{
      auto res = q.top();
      q.pop();
      return res;
    };
    int maxMeetingSeen = 0;
    for (const auto& meeting : meetings) {
      const auto s = meeting[0];
      const auto e = meeting[1];
      while (!roomBusyTill.empty() && roomBusyTill.top().first <= s) {
        auto [_, idx] = topAndPop(roomBusyTill);
        availRoom.push(idx);
      }
      if (availRoom.empty()) {
        // none of the room is available at this time
        // the first busy room that is released will be used
        auto [releasedT, idx] = topAndPop(roomBusyTill);
        // new job can only be start from releasedT as
        // at s, no room is available
        roomBusyTill.emplace(releasedT + e - s, idx);
        maxMeetingSeen = std::max(maxMeetingSeen, ++meetingHold[idx]);
      } else {
        auto idx = topAndPop(availRoom);
        roomBusyTill.emplace(e, idx);
        // note that we don't need to clean up the availRoom
        // as if it's available at t, it must be available later as well
        maxMeetingSeen = std::max(maxMeetingSeen, ++meetingHold[idx]);
      }
    }

    for (int i = 0; i < n; ++i) {
      if (meetingHold[i] == maxMeetingSeen) {
        return i;
      }
    }
    return -1;  // can't happen
  }
};