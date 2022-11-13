/*
What happen if we don't even see a greater number yet? Then all these numbers
won't have seen a greater number.

- For example, a decreasing numbers say, [8 5 2], for all the numbers, there
  aren't greater number at all. So you can imagine you need to stored all of
  them up...

But to what point?

- Imagine it's [8 5 2 4], then it means, 2 now have a next greater. BUT, 8 and
  5 still doesn't have a next greater.

How do we deal with maintain such this info?
- we pop 2 and push 4 into the storing area. E.g. now what is stored are:
  [8 5 4]
-Note that we only want to find the "next greater", so it's completely good to
 pop 2 going forward as it already finds its next greater.

Imagine it's [8 5 2 6] instead of [8 5 2 4], then it should be similar. Now,
only 8 has no next greater, so we are pop'ing both 2 and 5, assign their next
greater to 6, and just push 6 into the storing area: [8 6]

So overall, the structure is a monotonic decreasing stack, and what is on the
stack is a number that "don't have a next greater element yet".
*/
class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    std::stack<int> noGreterElements;
    std::unordered_map<int, int> nxtGt;
    for (auto n : nums2) {
      while (!noGreterElements.empty() && noGreterElements.top() < n) {
        nxtGt[noGreterElements.top()] = n;
        noGreterElements.pop();
      }
      noGreterElements.push(n);
    }
    for (int i = 0; i < nums1.size(); ++i) {
      auto it = nxtGt.find(nums1[i]);
      if (it == nxtGt.end()) {
        nums1[i] = -1;
      } else {
        nums1[i] = it->second;
      }
    }
    return nums1;
  }
};