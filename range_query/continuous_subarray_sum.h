/*
This is a twist of prefix sum question, the twist is not that easy to discover,
though.

Idea: say we keep a running sum from the beginning of array - if we can find 2
running sum where they are having the same mod k value, say,
- X = running_sum[i: k] (say, inclusive of both index)
- Y = running_sum[i: j], where k < j, and
- And X % k == Y % k then,
- ((Y - X) % k) = 0 = (running_sum[k + 1: j] % k)

So as long as j - k >= 2, there must be continuous range of numbers summing to
the multiply of k


[23 2 4 6 7], k = 6

i   sum[0:i] mod k
0   23       5
1   25       1
2   29       5

--> when we see that running sum having the same mod k result it must mean that
    in between these 2 result, there must be a subrange summing up to multiply
    of k e.g. between (0, 2] range, the sum must be the multiply of k

so overall the idea is keeping a map:
- "running sum mod k" value -> "the end index of the running sum"

Base case:
- when we run into running sum that % k is 0 and it's not the first element -
  we've already find our answer. (E.g. running_sum[0:i] is valid.)

Edge case 1: single element that is multiply of k

[23 6 6], k = 6
i   sum mod k
0   23  5
1   29  5

--> The first single 6 isn't what we are looking. In this case, we have to keep
    checking. How, we just ignore this one and do nothing. Why do nothing,
    because we will prefer the earlier index for the same mod k value. E.g. keep
    the original map[5] = 0 instead of updating to map[1] = 1, as when the next
    time we hit another mod k == 5, we would want to check the distance between
    2 indices again. And our goal is just making sure 2 indicies >= 2

[23 6 6], k = 6
i   sum mod k
0   23  5  ... hash[5] = 0
1   29  5  ... 1 - hash[5] < 2, do nothing
2   35  5  ... 2 - hash[5] == 2, we find the result!

This should cover the case that single 0 is presented.
(If there are 2 0's, it's good anyway.)

[23 0 0], k = 6
i   sum mod k
0   23  5  ... hash[5] = 0
1   23  5  ... 1 - hash[5] < 2, do nothing
2   23  5  ... 2 - hash[5] == 2, we find the result!


Edge case 2: 2 consecutive multiple values with mod k == 0?
[6 6], k = 6

i   sum mod k
0   6   0  ... hash[0] = 0
1   12  0  ... 1 - hash[0] < 2, ... but it's actually answer already

Here, we can either do a branching here...
if k-mod-val has seen
  if k-mod-val is 0, index diff should >= 1
  else index diff should >= 2

Or the trick is inserting hash[0] = -1 into the map

i   sum mod k
0   6   0  ... hash[0] = -1, 0 - hash[0] < 2, do nothing
1   12  0  ... hash[0] = -1, 1 - hash[0] == 2, we find the result!
*/

class Solution {
 public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    const int sz = nums.size();
    std::unordered_map<int, int> sumModKToIdx = {{0, -1}};
    int sum = 0;
    for (int i = 0; i < sz; ++i) {
      sum += nums[i];
      const int modK = sum % k;
      if (modK == 0 && i != 0) {
        return true;
      }
      auto it = sumModKToIdx.find(modK);
      if (it == sumModKToIdx.end()) {
        sumModKToIdx[modK] = i;
      } else {
        if (i - it->second >= 2) return true;
      }
    }
    return false;
  }
};