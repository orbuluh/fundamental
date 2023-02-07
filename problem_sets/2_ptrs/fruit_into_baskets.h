/*
Your first intuition was dfs backtracking (to pick or not to pick), got TLE,
then you were trying to see if there is a DP solution.

But in the end, it's actually a 2 pointer sliding window problem ...


@lee215 translation:

"Start from any index, we can collect at most two types of fruits. What is the
maximum amount"

is the same as

"Find out the longest length of subarray with at most 2 different numbers"

So it's like all the other similar problem, you keep a window with 2 pointers.
You maintain the invariance in the window (e.g. only 2 different numbers in the
subarray). You assume to include the new number in each iteration, and when such
inclusion breaks the invariant, you shrink the window till the window is valid
again.

*/
class Solution {
 public:
  int totalFruit(vector<int>& fruits) {
    const int sz = fruits.size();
    std::vector<int> typeCnt(sz, 0);
    int pickedCnt = 0;
    int maxCnt = 0;
    for (int l = 0, r = 0; r < sz; ++r) {
      if (++typeCnt[fruits[r]] == 1) {
        pickedCnt++;
      }
      while (pickedCnt > 2) {
        if (--typeCnt[fruits[l++]] == 0) {
          pickedCnt--;
        }
      }
      maxCnt = std::max(maxCnt, r - l + 1);
    }
    return maxCnt;
  }
};
