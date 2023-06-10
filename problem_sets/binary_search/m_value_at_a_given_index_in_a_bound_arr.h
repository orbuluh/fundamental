/*
Overall the idea is using binary search to find the max value at index that can
satisfy...

The harder part is the math portion. And the critical idea so you don't need to
think about where is the value starts from 1 or so, which complicates how to
find the sum, is subtract n from maxSum first.

By doing so, each of the element already have min value 1, and we can imagine
now the array can have value 0. Then you are basically distributing the
remaining value from the peak at index. The optimal case is basically peak looks
like a mountain shape:


What's the good for value 0?


Say index 5, val = 3, then at best it will be like
idx 0 1 2 3 4 5 6 7 8 9
    0 0 0 1 2 3 2 1 0 0

since 0 + 0 + 0 + 1 + 2 + 3 is equal to 1 + 2 + 3, we can easily just find the
left side bound, and do the arithmetic series summation


or say index is 5, val = 9, n = 10, then at best it will be like
idx 0 1 2 3 4 5 6 7 8 9
    4 5 6 7 8 9 8 7 6 5

e.g. left side will start from val - index in this case
     right side will still have (n - 1 - index) numbers,
     so right most value will be x - (n - 1 - index)

Overall generalize as:

left side min val: val[0] = max(x - index, 0)
right side min val: val[n-1] = max(x - (n - 1 - index), 0)

The sum of arithmetic sequence [m, m+1, ....n],
equals to (n + m) * (n - m + 1) / 2.

So the full array sum = leftVal +...+ val +...+ rightVal
= ari(leftVal, val) + ari(rightVal, val) - val
*/

class Solution {
  long ariSum(long sml, long lge) const {
    return ((sml + lge) * (lge - sml + 1)) / 2;
  }
  bool cantFormAnswer(int index, int n, int maxSum, int val) {
    const int leftVal = std::max(val - index, 0);
    const int rightVal = std::max(val - (n - 1 - index), 0);
    return (ariSum(leftVal, val) + ariSum(rightVal, val)) - val > maxSum;
  }

 public:
  int maxValue(int n, int index, int maxSum) {
    maxSum -= n;
    int l = 0;
    int r = maxSum;
    while (l < r) {
      // need to find the last valid value ... so need
      // to do right bias binary search
      int mid = l + (r - l + 1) / 2;
      if (cantFormAnswer(index, n, maxSum, mid)) {
        r = mid - 1;
      } else {
        l = mid;
      }
    }
    // we've subtracted n at the beginning, need to add back
    return r + 1;
  }
};
