/*
    Idea is ... find mid, then reverse everything after mid
    then compare the reverse head and head.

    (If you are thinking to find mid while reverse the first
     half ... it would be much difficult to do right...)

    A B C D E
    mid = C, reverse: E->D->X, compare E->D->X with A->B(->C)

    A B C D
    mid = B, reverse D->C->X, compare D->C->X with A->B->X

    so when doing comparision, you just need to check on
    while (reverseHead), then ...
    - original even nodes it will compare the same amount of nodes
    - original odd nodes will just skip the middle node

    -------------------------------

    About finding mid using slow and fast ptrs.
    if you start from dummy, breaks when !fast || !fast->next

    D -> A  -> X
   s/f
         s     f  (1 node A, when break, s is the middle)

    D -> A  -> B  -> X
   s/f
         s     f  (2 nodes A, B, when break, s is middle)

    D -> A  -> B  -> C -> X
   s/f
         s     f   (3 nodes A, B, C, when break, s is middle)
               s          f
    D -> A  -> B  -> C -> D ->X
   s/f
         s     f   (3 nodes A, B, C, D, when break, s is middle)
               s          f
    ...

 */
class Solution {
 public:
  ListNode* findMid(ListNode* head) {
    ListNode dummy{};
    dummy.next = head;
    auto slow = &dummy;
    auto fast = &dummy;
    ListNode* tmp = nullptr;
    while (fast) {
      if (!fast || !fast->next) {
        return slow;
      }
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
  ListNode* reversed(ListNode* head) {
    ListNode* tmp = nullptr;
    ListNode* prev = nullptr;
    while (head) {
      tmp = head->next;
      head->next = prev;
      prev = head;
      head = tmp;
    }
    return prev;  // reversed head
  }

  bool isPalindrome(ListNode* head) {
    auto mid = findMid(head);
    auto reversedHead = reversed(mid->next); // will break the mid to mid->next

    while (reversedHead) {
      if (!head || head->val != reversedHead->val) {
        return false;
      }
      head = head->next;
      reversedHead = reversedHead->next;
    }
    return true;
  }
};