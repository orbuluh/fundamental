/**

several ways to implement, really need to think is what to put in the while
loop and its corresponding invariant in the loop. From other's solution, a key
point to make the code clean here is that you need to realize:

if there is even node, then odd node must be non-null.
Hence you can simply check on even in while.

Also, when do we keep pointing next node? only if even->next exists.
So that we will point odd->next to even->next accordingly, and move odd forward.

And when we move odd forward, if there is nothing afterwards, even will be
pointing to the end, and the while loop can break correctly.

At the end, need to be careful that we can't just make odd->next to head->next
As head->next has already pointed to next odd nodes, and you will get a infinite
loop if you do so. So you need to record the evenHead, and point odd->next to
evenHead!

 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        auto odd = head;
        auto even = head->next;
        auto evenHead = even;
        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};