/*

> "rule of thumb" is that we should search for O(n) solution if we are dealing
with consecutive sequences, and O(n ^ 2) if we are dealing with subsequences" -
@votrubac

The O(n^2) intuition is that if we record the number of elements ending up at
nums[i] with an arithmetic diff=d, and then when we encounter a new number
also having a d diff, then this new number basically has 1 more element:

say: [2,4,6,8,10]

we record

idx val  dp[idx] stores {diff: count of prev numbers in this subseq}
0    2   dp[0] = {}
1    4   dp[1] = {2: 1}                    e.g. [2,4]
2    6   dp[2] = {2: 2, 4: 1}              e.g. [2,4,6], [2,6]
3    8   dp[3] = {2: 3, 4: 1, 6: 1}        e.g. [2,4,6,8], [4,8], [2,8]
4   10   dp[4] = {2: 4, 4: 2, 6: 1, 8: 1}  e.g. [2,4,6,8,10], [2,6,10], [4, 10],
                                                                        [2, 10]

say when we check idx=4, val=10, and we turn back and check idx=3, val=8,
the diff is 10 - 2 = 8. We check dp[idx=3][diff=2] = 3
so we know dp[idx=4][diff=2] will add 4 (e.g. one extra number)

How many new valid subsequence is introduced? it will happen to be the
dp[idx=3][diff=2] = 3, specifically:

- [6,8,10]
- [4,6,8,10]
- [2,4,6,8,10]

which is like there are 3 numbers beforehand ending at idx=3 with diff = 2, and
there are also 3 combinations of new subsequence that will be newly formed

There are some other optimization ... might need more thoughts
https://leetcode.com/problems/arithmetic-slices-ii-subsequence/discuss/849944/C%2B%2B-with-picture%3A-base-%2B-optimizations

*/

class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& A, int res = 0) {
    std::vector<std::unordered_map<long, int>> dp(
        std::max(1ul, A.size()), std::unordered_map<long, int>{});
    auto cntDiff = [&](int i1, int i2) {
      return static_cast<long>(A[i1]) - A[i2];
    };
    for (int i = 0; i < A.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        auto diff = cntDiff(i, j);
        // don't do cnt = dp[j][diff] which will add lots of unnecessary len 2
        // subsequence in the end and it's 2x slower. Overall the map will be
        // huge in OA, so you want to reduce the time to access dp[][] as much
        // as possible to be quick!
        auto it = dp[j].find(diff);
        int cnt = it == dp[j].end() ? 0 : it->second;
        // why +=? note that A is not sorted. And there could have multiple j
        // having the same value. Each of them have different number if
        // subsequence and each of them, plus the new number, will create that
        // amount of new subsequence
        dp[i][diff] += cnt + 1;
        res += cnt;
      }
    }
    return res;
  }
};