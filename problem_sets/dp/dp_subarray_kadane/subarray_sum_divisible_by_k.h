/*
Clever part if utilizing prefix sum to achieve the O(n) search

say prefixSum[i] = nums[0] + ... nums[i]

then if (prefixSum[j] - prefixSum[i]) % k == 0, it means
nums[i + 1] + ... nums[j] must bee divisible by k

So we can basically keep a counter of remainder value we've seen.
Once we see more than once, it basically make a pair.

The edge case is that for prefixSum[i] equal to 0, itself is already a range
that is divisible by k.

So the first time we are seeing such value, we don't need other pair. So we
can set remainderCnt[0] = 1.

The other details is how to deal with negative value.

(n % k) + k should make sure to flip it around to a positive value for C++
so we update it with (prefixSum + n % k + k) % k;

*/
class Solution {
 public:
  int subarraysDivByK(vector<int>& nums, int k) {
    std::vector<int> remainderCnt(k, 0);
    remainderCnt[0] = 1;
    int res = 0;
    int prefixSum = 0;
    for (int n : nums) {
      prefixSum = (prefixSum + n % k + k) % k;
      res += remainderCnt[prefixSum]++;
    }
    return res;
  }
};