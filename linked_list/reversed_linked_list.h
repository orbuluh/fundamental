/*
Think about what you need to reversed a linked list
    A -> B -> C

1. you need to break the link
2. you need to update for the next step

To do 1. you get 2 pointers: pre and cur, each iteration, cur->next = pre
But when you do this, you lose the original cur->next
hence you have to store it, say, to tmp
The to do 2, you just need to do ...
-    pre = cur
then cur = tmp

iter   0    1   2   3
pre   null  A   B   C
cur    A    B   C   X
tmp     B    C   X

At the end, cur is null and break
pre is the original tail, or the final head.
*/

class Solution {
  public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* tmp = nullptr; // head might be null
        while (cur) {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};