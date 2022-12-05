class Solution {
    /*
    Idea: We know how to reverse the whole linked list. So why don't we just
    identify the L-R list, reverse them, and reconnect back to the original
    list?

    L = 2, R = 4

    we want to reverse L to R

         L         R
    A -> B -> C -> D -> E
         2         4

    say cur=A, need to advance L - 1 = 1 time to make cur equal to L

    When we reach L, the pre is the "fixed head", and its next is supposed to
    concatenate to the head of reverse array (R), we need to store it.
    - fixedHead = A = pre
    Also at this point, the final reversed tail is the cur, also store it.
    - reverseTail = B = cur

    The reverse is doing cur -> pre reversing.
    So we move once s.t. cur is at L + 1 (C), as we want to start from
    C -> B reverse, and overall we we want to do reverse for R - L = 2 time
    to reverse the whole L->R partial list.

    After reversing twice, we will be:

         L         R
    A -> B -> C -> D -> E
        pre<-Cur            |
             pre<-cur       | reverse R - L times
                  pre  cur  | then after the R-L loop, pre at D, cur at E

    e.g. cur is now the "fixedTail"
    - fixedTail = E = cur
    and pre is basically the reversedHead

    So reconnect back the partial list back
    reverseTail->next = fixedTail = cur  (B -> E)
    fixedHead->next = A->next = reversedHead = pre  (A -> D)
    */
  public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy;
        auto pre = &dummy;
        dummy.next = head;
        for (int i = 0; i < left - 1; ++i) {
            pre = pre->next;
        }
        auto fixedHead = pre;
        pre = pre->next; // move once in preparation to reverse cur->pre
        auto cur = pre->next;
        auto reversedTail = pre;
        ListNode* tmp = nullptr;
        for (int i = 0; i < right - left; ++i) {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        reversedTail->next = cur;
        fixedHead->next = pre;
        return dummy.next;
    }
};