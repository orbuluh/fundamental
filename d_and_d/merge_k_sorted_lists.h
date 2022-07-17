/*
 Originally you were thinking about using minQ to push the small head in, till
 nothing to push. Doing this makes complexity O(nlogn), and with much more
 complicated code to handle the whole thing! Give the lists has been sorted on
 its own, you just need to merge! It's basically like merge sort!!
 */
class Solution {
  public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        auto head = lists.front();
        for (int i = 1; i < lists.size(); ++i) {
            head = merge2Lists(head, lists[i]);
        }
        return head;
    }

    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val) {
            l1->next = merge2Lists(l1->next, l2);
            return l1;
        } else {
            l2->next = merge2Lists(l1, l2->next);
            return l2;
        }
    }
};