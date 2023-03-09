// check notes for Cycle detection using Floyd's tortoise and hare with 2
// pointers

class Solution {
 public:
  ListNode* detectCycle(ListNode* head) {
    auto slow = head;
    auto fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (fast == slow) {
        slow = head;
        while (slow != fast) {
          slow = slow->next;
          fast = fast->next;
        }
        return slow;
      }
    }
    return nullptr;
  }
};