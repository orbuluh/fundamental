/*
You were thinking about O(n^2) DP but it's actually a greedy question...

The way to be greedy is that you only make extra step when needed.

In each step, you will gain a range that this step can further reach, say it's
[curStepReachBegin, curStepReachEnd]

When should be the next necessary step happens? It should be at the furthest
indicies that this step's range [curStepReachBegin, curStepReachEnd] brings you.
*/

class Solution {
 public:
  int jump(vector<int>& nums) {
    const auto sz = nums.size();
    int step = 0;
    int furthest = 0;
    int curIdx = 0;
    while (furthest < sz - 1) { // once you can jump to the next index, break
      int nxtStepFurthest = furthest;
      // each step would cover a range, within this range, find the max next
      // step can jump to
      while (curIdx <= furthest) {
        nxtStepFurthest = std::max(curIdx + nums[curIdx], nxtStepFurthest);
        curIdx++;
      }
      furthest = nxtStepFurthest;
      step++;
    }
    return step;
  }
};