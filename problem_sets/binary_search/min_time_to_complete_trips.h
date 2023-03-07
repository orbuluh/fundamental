/*
Idea: find the minimumTime that meets the criteria => binary search
As it's finding minimumTime, so basically apply the "finding firstOccur"
binary search structure.

Performance tip: no need to sort the time beforehand (if you do, it's just
slower in OG's result ...)
*/

class Solution {
 public:
  using LL = long long;
  long long minimumTime(vector<int>& time, int totalTrips) {
    // std::sort(time.begin(), time.end());
    LL minT = 1;
    LL maxT = static_cast<LL>(totalTrips) * time.back();
    while (minT < maxT) {
      const auto timeAt = minT + (maxT - minT) / 2;
      if (needMoreTime(time, timeAt, totalTrips)) {
        minT = timeAt + 1;
      } else {
        maxT = timeAt;
      }
    }
    return minT;
  }

  bool needMoreTime(const vector<int>& time, LL timeAt, int totalTrips) {
    LL tripCnt = 0;
    for (auto t : time) {
      // if (timeAt / t == 0 || tripCnt >= totalTrips) {
      if (tripCnt >= totalTrips) {
        return false;
      }
      tripCnt += timeAt / t;
    }
    return tripCnt < totalTrips;
  }
};