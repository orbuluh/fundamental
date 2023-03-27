/*

The question only wants "subarrays filled with 0"
and subarray needs to be contiguous non-empty seuqence

consider if you hit

[0] -> [0] * 1 -> 1
[0, 0] -> [0] * 2, [0, 0] * 1 -> 2 + 1
[0, 0, 0] -> [0] * 3, [0, 0] * 2, [0, 0, 0] * 1 -> 3 + 2 + 1

So for non-0 number it's just as if spliting the 0-filled
subarray, and for each of 0-filled subarray of length n, it's
basically adding 1 + 2 + .. + n to the result

*/

class Solution {
 public:
  long long zeroFilledSubarray(vector<int>& nums) {
    long long res = 0;
    int combo0 = 0;
    for (auto n : nums) {
      if (n != 0) {
        combo0 = 0;
        continue;
      }
      res += ++combo0;
    }
    return res;
  }
};