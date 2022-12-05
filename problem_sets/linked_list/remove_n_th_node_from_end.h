/*
 say we create dummy node
 (need dummy to handle the case to delete the last node)

 let fast walk n step first , then move slow and fast together
 till fast is going to hit null, then slow will be at the
 node before what we want to delete!

 D(0) 1 2 3 4 5
   f  ->f  1. fast walk n step first
   s       2. then point slow to dummy then walk together with f)

--> when f is right before end, (e.g. at val=5),
    it takes 3 more steps, so does slow, so slow will
    be at 3, the node before what we want to delete!
 D(0) 1 2 3 4 5
        f---->f
   s----->s

 The usage of dummy will be case like head = [1] and n = 1:
 D(0) 1
   f->f
   s
 after walking n = 1 step, f is right in front of end already.
 we don't need further step, and we can still point
 slow->next to slow->next->next, as slow is now point to dummy

 finally we return dummy.next like other cases, which gives us the correct []
 */
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy;
    dummy.next = head;
    auto fast = &dummy;
    for (int i = 0; i < n; ++i) {
      fast = fast->next;
    }
    auto slow = &dummy;
    while (fast->next) {
      slow = slow->next;
      fast = fast->next;
    }
    slow->next = slow->next->next;
    return dummy.next;
  }
};