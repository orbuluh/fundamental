/*
Don't over-complicate ...
Just much clean if you do it in the straightforward way actually.
Easy problem but food for thought!
*/

class Solution {
 public:
  int findKthPositive(vector<int>& arr, int k) {
    const int maxV = arr.back();
    int idx = 0;
    for (int i = 1; i <= maxV; ++i) {
      if (arr[idx] == i) {
        idx++;
      } else {
        if (--k == 0) {
          return i;
        }
      }
    }
    return maxV + k;
  }
};