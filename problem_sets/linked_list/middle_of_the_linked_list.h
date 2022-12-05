/*
No need a dummy node, pattern:
- break when !fast || !fast->next
- when break:
    - if fast --> odd nodes, slow is middle
    - if !fast --> even nodes, slow is the second middle
- So slow is always the result you want.

s
f
a X


  s
    f
a b X


  s f
a b c X


    s   f
a b c d X

*/

class Solution {
 public:
  ListNode* middleNode(ListNode* head) {
    auto slow = head;
    auto fast = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    return slow;
  }
};