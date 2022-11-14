/*
Check next_greater_element_i.h for rationale. A circular variant is simply
looping the array twice, otherwise the logic is the same.

Use monotonic decreasing stack to store the value that hasn't seen its next
greater element. When seeing some value larger than the top stack, it means its
next greater element is found. So you can pop it and see if the value is also
the next greater element for other number in the stack. (Note, because the stack
is monotonic decreasing, what is under the queue must have larger value.)
Consider:  [5 4 3 2 1 6]
-> before 6, the stack will be like [5 4 3 2 1]
-> it's decreasing means nothing in the upper place of queue can be the next
   greater value for previous value in the stack
-> when we see 6, we know it is the next greater of 1, and we can check whether
   it's the next greater of the remaining ...
-> After seeing 6, the stack will be [6], as 6 hasn't seen its next greater
*/

class Solution {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    int idx = 0;
    int sz = nums.size();
    std::stack<int> noGreaterIdxStk;
    std::vector<int> res(sz, -1);
    while (idx < 2 * sz) {
      int i = idx++ % sz;
      while (!noGreaterIdxStk.empty() &&
             nums[noGreaterIdxStk.top()] < nums[i]) {
        if (res[noGreaterIdxStk.top()] == -1) {
          res[noGreaterIdxStk.top()] = nums[i];
        }
        noGreaterIdxStk.pop();
      }
      noGreaterIdxStk.push(i);
    }
    return res;
  }
};