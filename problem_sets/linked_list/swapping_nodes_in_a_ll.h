/*
Note: The problem description specifically asks to swap values, not nodes
      themselves.

The trick is, if you have 2 ptrs, pt1 point to head, pt2 point to the k-th node
then if you move both ptrs together, when pt2 point to the tail, pt1 should
point to the k-th node from the tail.


Hence, we mimic this thought process: say k = 4, then find the k-th node x first
record x as swap1
       x
[7,9,6,6,7,8,3,0,9,5]

Then make y point to head

 y     x
[7,9,6,6,7,8,3,0,9,5]

and move y and x together till the end

             y     x
[7,9,6,6,7,8,3,0,9,5]

then you can swap(swap1, y) to get your result
 */
class Solution {
 public:
  ListNode* swapNodes(ListNode* head, int k) {
    auto cur = head;
    while (--k > 0) {
      cur = cur->next;
    }
    auto swap1 = cur;
    auto swap2 = head;
    while (cur->next) {
      cur = cur->next;
      swap2 = swap2->next;
    }
    std::swap(swap1->val, swap2->val);
    return head;
  }
};