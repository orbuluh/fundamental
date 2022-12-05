/*
My side note upon lee215's post ...
https://leetcode.com/problems/next-greater-element-iv/discuss/2756668/JavaC%2B%2BPython-One-Pass-Stack-Solution-O(n)

noGtStk, oneGtStk are monotonic decreasing stack.

noGtStk stores the index of elements
- that have not found their first greater element.

oneGtStk stores the index of elements
- that have found their first greater element,
  have not found their second greater element.

For each newVal = nums[i] in nums

- We first compare newVal with the tail elements in oneGtStk.
- pop all element smaller than newVal, and for these elements, newVal will be
  their second greater element.

  (because all index in oneGtStk have found first greater, if it's smaller than
  a as well, then a must be the second greater element.

- Then we compare newVal with the top elements in noGtStk, move all elements
  smaller than newVal to oneGtStk, because newVal is their first greater element
  (Note, still need to maintain the monotonically decreasing relationship, so
  you can pick the correct second grater for them. which can be done through a
  tmp stack as code)

- Then add newVal to top of noGtStk, as itself can't be the
  first greater element of itself

We repeatedly do this for all nums[i] and finally return the result.

[show value in stk* for clarity, in code, store idx]
[5 1 2 3 6 7 4 8]        5   1   2   3   6   7    4   8
    oneGtStk  noGtStk    result
5 | []        [5]       [ -,  -,  -,  -,  -,  -,  -,  -]
1 | []        [5 1]     [ -,  -,  -,  -,  -,  -,  -,  -]
2 | [1]       [5 2]     [ -,  -,  -,  -,  -,  -,  -,  -]
3 | [2]       [5 3]     [ -,  3,  -,  -,  -,  -,  -,  -]
6 | [5 3]     [6]       [ -,  3,  6,  -,  -,  -,  -,  -]
7 | [6]       [7]       [ 7,  3,  6,  7,  -,  -,  -,  -]
4 | [6]       [7 4]     [ 7,  3,  6,  7,  -,  -,  -,  -]
8 | [7 4]     [8]       [ 7,  3,  6,  7,  8,  -,  -,  -]

*/
class Solution {
 public:
  vector<int> secondGreaterElement(vector<int>& nums) {
    const int sz = nums.size();
    std::vector<int> result(sz, -1);
    std::stack<int> noGtStk;
    std::stack<int> oneGtStk;
    std::stack<int> tmp; // to reverse what is moved from noGtStk to oneGtStk
    for (int i = 0; i < sz; ++i) {
      // for those in oneGtStk, they've found their first larger. Since nums[i]
      // is also larger than them, nums[i] must be its second greater value.
      while (!oneGtStk.empty() && nums[i] > nums[oneGtStk.top()]) {
        result[oneGtStk.top()] = nums[i];
        oneGtStk.pop();
      }
      // for those in noGtStk, if nums[i] is larger, they found their first
      // larger, so you can move them to oneGtStk. But since you want to
      // maintain the monotonic decreasing property - push to a tmp stk first
      // then push from tmp to oneGtStk
      while (!noGtStk.empty() && nums[i] > nums[noGtStk.top()]) {
        tmp.push(noGtStk.top());
        noGtStk.pop();
      }
      while (!tmp.empty()) {
        oneGtStk.push(tmp.top());
        tmp.pop();
      }
      // the value we encountered this iteration must haven't found greater
      noGtStk.push(i);
    }
    return result;
  }
};