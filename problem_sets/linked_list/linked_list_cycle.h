// check notes for Cycle detection using Floyd's tortoise and hare with 2 pointers

class Solution {
public:
    bool hasCycle(ListNode *head) {
      ListNode* slow = head;
      ListNode* fast = head;
      while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
      }
      return false;
    }
};