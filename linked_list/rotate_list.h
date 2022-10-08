/*
The idea is simple:

concatenate the tail to the head while calculating the full size the actual k
needed should %= size. Then - as you've concatented tail to head, the new head
is actually the size - k node from the original head.

[1,2,3,4,5], k = 2

How do we concat tail back to head? We want to traverse the LL in a way that it
stops at the tail node so we can do the operation. So basically we init len to 1
, then we `while (ptr->next)` ==> this will make sure when ptr is pointing to
tail, the loop will break, at the same time the size counter is 5 already.

1 -> 2 -> 3 -X-> 4 -> 5
^_____________________|

Then after this, we would want to make sure the link between 3 and 4 will break
and 4 is what we are going to return.

How to do this? We need to make sure the loop break when pointer is on 3

                     1 -> 2 -> 3 -> 4 -> 5
k doing loop check   2    1    0

--> so basically we use `while (--cnt > 0) ==> then when ptr is on 3, the loop
break. This kind of operation is what you need to think through!
 */
class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !k) return head;

    int cnt = 1;
    auto ptr = head;
    while (ptr->next) {
      ptr = ptr->next;
      cnt++;
    }
    ptr->next = head;  // chain tail back to head
    k %= cnt;
    k = cnt - k; // new head will be k' = sz - k away
    ptr = head;
    while (--k > 0) {
      ptr = ptr->next;
    }
    head = ptr->next;
    ptr->next = nullptr; // break the link and return the next as new head
    return head;
  }
};