/*

Things to understand is that

1. operations could happen like this:
   [3 2 1]
--> you only need 1 op to make it a 3 (e.g. 3 eat 2 and 2 eat 1 in one op)

2. there could be case like:

  10 1 2 3 9 2 5 6 8 1 2 3 4 5 6 7
   |-------|-------|--------------
  eventually: 10 is the only one left, but with how many steps?

  you can imagine in 3 ops:
  - 10 eats 1, 2, 3, while
  - 9 eats 2, 5, 6, while
  - 8 eats 1, 2, 3

  then, it becomes

  [10 9 8 4 5 6 7], in 1 op:
    - 10 eats 9
    - 8 eats 4

  [10 8 5 6 7], in 1 op:
    - 10 eat 8
    - 8 eat 5

  [10 6 7], in 2 op and left 10

  so overall 3 + 1 + 1 + 2 = 7 ops


So how do we capture this kind of operations?

Reference:
https://leetcode.com/problems/steps-to-make-array-non-decreasing/discuss/2085967/Python-Explanation-with-pictures-stack


  10 1 2 3 9 2 5 6 8 1 2 3 4 5 6 7
   |-------|-------|-------------|


You can imagine ... in between 10 1 2 3 9
                                |-------|
9 can't be removed till 1 2 3 is removed, same for 9 2 5 6 8
                                                   |-------|
8 can't be remove before 2 5 6 is removed


For a number A[i], assume the first larger number on its left is A[lft].
A[i] can only be removed after all the numbers within (lft, i) are removed,
and its step equals the largest step within (lft, i) plus 1.

--> for example: 1 take 1 step to be removed, 2 takes 1 + 1 step
    3 takes 1 + 2 steps, and 9 takes 1 + 3 steps


Thus we can maintain a monotonic decreasing stack, and traverse the array
from left to right. For each newly added number A[i]...

- remove the top number from stack that is no larger than A[i], and
- record the maximum step number from these popped numbers.
- the ops to remove A[i] will be the max popped number's step + 1

Until we find the first number that is larger than A[i], meaning A[i] will
be removed by this larger number in some step, and this step number equals the
maximum step number we removed plus 1.


  10 1 2 3 9 2 5 6 8 1 2 3 4 5 6 7
   |-------|-------|--------------

   (10, 0)
-> (10, 0)(1, 1)
-> (10, 0)(2, 2)
-> (10, 0)(3, 3)
-> (10, 0)(9, 4)
-> (10, 0)(9, 4)(2, 1)
-> (10, 0)(9, 4)(5, 2)
-> (10, 0)(9, 4)(6, 3)
-> (10, 0)(9, 4)(8, 4)
-> (10, 0)(9, 3)(8, 4)(1, 1)
-> (10, 0)(9, 3)(8, 4)(2, 2)
...
-> (10, 0)(9, 3)(8, 4)(7, 7)

At the end, because eat number can happen on the same time for each of the
element in the final stack

-> to make everything to 0 while knowing it can happen at the same time
   it's like:

(10, 0)(9, 3)(8, 4)(7, 7)  --> -3 for all > 0 (total op = 3)

(10, 0)(9, 0)(8, 1)(7, 3)  --> -1 for all > 0 (total op = 3 + 1)

(10, 0)(9, 0)(8, 0)(7, 2)  --> -1 for all > 0 (total op = 4 + 1)

(10, 0)(9, 0)(8, 0)(7, 0)  --> -2 for all > 0 (total op = 5 + 2)

the 3 / 1 / 1 / 2 ops are basically like how we analyze before


So, the whole step needed should be the maximum step on the stack!
*/

class Solution {
  struct Data {
    int val = -1;
    int count = 0;
  };

 public:
  int totalSteps(vector<int>& nums) {
    int maxOps = 0;
    std::stack<Data> monoDec;
    monoDec.push({nums[0], 0});
    for (int i = 1; i < nums.size(); ++i) {
      int popCnt = 0;
      while (!monoDec.empty() && monoDec.top().val <= nums[i]) {
        popCnt = std::max(popCnt, monoDec.top().count);
        monoDec.pop();
      }
      if (!monoDec.empty()) {
        popCnt += 1;
      } else {
        popCnt = 0;
      }
      maxOps = std::max(maxOps, popCnt);
      monoDec.push({nums[i], popCnt});
    }
    return maxOps;
  }
};