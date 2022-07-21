class Solution {
public:
    /*
     left = 2
     right = 4
     P = pre, C = cur, T = tmp

        X  1  2  3  4  5
init    P  C
 i=0       P  C             (move left - 1 times to find noRevTail)
move1         P  C
 j=0           <-P  C  T
 j=1              <-P  C  T  (break right - left = 2 links, e.g. j = 0 -> 1)
    */
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy;
        dummy.next = head;
        auto pre = &dummy;
        for (int i = 0; i < left - 1; ++i) {
            pre = pre->next;
        }
        auto cur = pre->next;
        auto nonRevTail = pre; // nonRevTail point to node (1)
        auto revTail = cur; // (2) becomes the tail of reversed part
        // move once so pre point to the left node (2)
        // and cur point to the next node (3)
        // as it's the starting point we want to reverse the link
        pre = pre->next;
        cur = cur->next;
        ListNode* tmp = nullptr;
        auto reverse = [&]() {  // the algo of reverse linked list
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        };
        // then we know that we need to break right - left = 4 - 2 = 2 links
        // (by observing the question graph), so iterate right - left times
        for (int j = 0; j < right - left; ++j) {
            reverse();
        }
        // after moving twice, pre point to the last reversed node (4)
        // cur point to the nonRevHead node (5)
        nonRevTail->next = pre;
        revTail->next = cur;
        return dummy.next;
    }
};