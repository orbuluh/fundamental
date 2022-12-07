/*
@lee215 idea to make it O(1 memory space).
The idea is to use 4 numbers to record the process.

right[0] stores evenIdx sum that is in the right of idx we've tried
right[1] stores oddIdx sum that is in the right of idx we've tried

Before remove anything, everything is on the right of what we've tried,
so using example [6 1 7 4 1]

right[0] = 6+7+1 = 14 (e.g. from [6   7   1])
right[1] = 1+4 = 5    (e.g. from [  1   4  ])

The key point is, every time we try to remove a number, we are also seeing a
number that is considered to be a "left of index" in the next round.

So originally nothing is on the left of index 0, we have

left[0] = 0
left[1] = 0

where

left[0] stores evenIdx sum that is in the left of idx we've tried
left[1] stores oddIdx sum that is in the left of idx we've tried


after remove idx[0], it's like we are removing nums[0] == 6 out from
right[0 % 2] -= nums[i]

And in the next round, this 6 becomes part of the evenIdx sum that is in the
left of what we've tried, so we can do:

left[0 % 2] += nums[i]

But before we update left (for the next round), what is being checked in this
round?

right[1] + left[0] == right[0] + left[1]

So we just need constant memory to do this!!
*/

class Solution {
 public:
  int waysToMakeFair(vector<int>& nums) {
    const auto n = nums.size();
    int rightOfIdxSum[2] = {};
    int leftOfIdxSum[2] = {};
    for (int i = 0; i < n; ++i) {
      rightOfIdxSum[i % 2] += nums[i];
    }
    int fairCnt = 0;
    for (int i = 0; i < n; ++i) {
      rightOfIdxSum[i % 2] -= nums[i];
      fairCnt += (rightOfIdxSum[0] + leftOfIdxSum[1] ==
                  rightOfIdxSum[1] + leftOfIdxSum[0]);
      leftOfIdxSum[i % 2] += nums[i];
    }
    return fairCnt;
  }
};

/* you original O(n) space solution ....

v   v   v
6 1 7 4 1

O(n) scan odd/even sum
idx even: 6 + 7 + 1 = 14
idx odd: 1 + 4 = 5

loop:
idx = 0, remove 6 from even sum 14 - 6, odd sum afterwards and even sum
afterwards need to swap

how to get "sum afterwards"? use range sum.

             6 1  7  4  1
oddSum cdf   6 6 13 13  14
evenSum cdf  0 1   1 5  5

also we can see, before the removed idx, index relation is still the same.
but after the removed idx, index relation is swapped (oddIdx <-> evenIdx)

remove idx 0: osa = odd sum afterwards = os[n-1] - os[0] = 8
              esa = even sum afterwards = es[n-1] - es[0] = 5
              osb = odd sum before = 0
              esb = even sum before = 0
              osb + esa = 5 != esa + osb = 8

remove idx 1: osa = odd sum afterwards = os[n-1] - os[1] = 8
              esa = even sum afterwards = es[n-1] - es[1] = 4
              osb = odd sum before = os[0] = 6
              esb = even sum before = es[0] = 0
              osa + esb = 8  != esa + osb = 4 + 6 = 10
...
*/

/*class Solution {
 public:
  int waysToMakeFair(vector<int>& nums) {
    const auto n = nums.size();
    std::vector<int> oddSum(n, 0);
    std::vector<int> evenSum(n, 0);
    evenSum[0] = nums[0];

    for (int i = 1; i < n; ++i) {
      if (i % 2) {
        oddSum[i] = oddSum[i - 1] + nums[i];
        evenSum[i] = evenSum[i - 1];
      } else {
        oddSum[i] = oddSum[i - 1];
        evenSum[i] = evenSum[i - 1] + nums[i];
      }
    }
    int fair = (oddSum[n - 1] - oddSum[0] == evenSum[n - 1] - evenSum[0]);
    for (int i = 1; i < n; ++i) {
      int oddSumBeforei = oddSum[i - 1];
      int evenSumBeforei = evenSum[i - 1];
      int oddSumAfteri = oddSum[n - 1] - oddSum[i];
      int evenSumAfteri = evenSum[n - 1] - evenSum[i];
      fair +=
          (oddSumBeforei + evenSumAfteri) == (evenSumBeforei + oddSumAfteri);
    }
    return fair;
  }
};
*/