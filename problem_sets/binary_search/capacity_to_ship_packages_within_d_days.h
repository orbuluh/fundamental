/*
capacity is at least the same weight as max weight (when infinite day is fine)
and at most the sum of weights (when only 1 day is allowed). Binary search!
*/
class Solution {
 public:
  int shipWithinDays(vector<int>& weights, int days) {
    int l = *std::max_element(weights.begin(), weights.end());
    int r = std::accumulate(weights.begin(), weights.end(), 0);

    auto capacityEnough = [&](int capacity) {
      int load = 0;
      int day = 0;
      for (auto w : weights) {
        load += w;
        if (load > capacity) {
          day++;
          load = w;
        }
        if (day >= days) {
          return false;
        }
      }
      return true;
    };

    while (l < r) {
      int mid = l + ((r - l) >> 1);
      if (capacityEnough(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return l;
  }
};