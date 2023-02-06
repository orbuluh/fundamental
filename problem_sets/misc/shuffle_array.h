/*

As requirement suggests, nums[i] <= 10^3
So each number only requires 10 bits
We can store second half in left 10 bits of first half number

    1      2     3   4 5 6
-> [4 1] [5 2] [6 3] 4 5 6

for i in [0, n - 1]
nums[i] now stores value for 2 * i + 1, 2 * i

idx -> stores idx for
2   -> 5, 4
1   -> 3, 2
0   -> 1, 0

so we can unpack the info out and fill in the data

[4 1] [5 2] [6 3] 4 5 6
              v     * * (extract i = 2 for idx 5 and  4)
[4 1] [5 2] [6 3] 4 3 6
        v   * *         (extract i = 1 for idx 3 and  2)
[4 1] [5 2] 2 5 3 6
v* *                    (extract i = 0 for idx 1 and  0)
 1 4 2 5 3 6
*/
class Solution {
 public:
  vector<int> shuffle(vector<int>& nums, int n) {
    for (int i = 0; i < n; ++i) {
      // store second half in left 10 bits of first half number
      nums[i] |= (nums[n + i] << 10);
    }
    for (int i = n - 1; i >= 0; --i) {
      // unpack i for 2 * i + 1 and 2 * i
      // nums[2 * i + 1]'s value is stored in the [10, 20) bits of nums[i]
      nums[2 * i + 1] = (nums[i] & (~1023)) >> 10;
      // nums[2 * i]'s value is stored in the [0, 10) bits of nums[i]
      nums[2 * i] = nums[i] & 1023;
    }
    return nums;
  }
};