class Solution {
 public:
  int c1 = INT_MAX;  // candidate 1
  int c2 = INT_MAX;  // candidate 2
  bool increasingTriplet(vector<int>& nums) {
    for (auto n : nums) {
      if (n <= c1) {
        c1 = n;
      } else if (n <= c2) {
        c2 = n;
      } else {
        return true;
      }
    }
    return false;
  }
};