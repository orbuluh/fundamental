/*
Idea, put linked lists to stacks then just add and carry the shorter portion up
and passing along the carry!
*/
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    auto toStk = [&](ListNode* node) {
      std::stack<ListNode*> stk;
      while (node) {
        stk.push(node);
        node = node->next;
      }
      return stk;
    };
    auto stk1 = toStk(l1);
    auto stk2 = toStk(l2);
    if (stk1.size() < stk2.size()) {
      std::swap(l1, l2);
      std::swap(stk1, stk2);
    }
    //-----------------------------------
    int carry = 0;
    auto updateVal = [](ListNode* node, int valToAdd) {
      int newVal = node->val + valToAdd;
      node->val = newVal % 10;
      return newVal / 10;
    };
    while (!stk2.empty()) {
      carry = updateVal(stk1.top(), stk2.top()->val + carry);
      stk1.pop();
      stk2.pop();
    }
    while (carry && !stk1.empty()) {
      carry = updateVal(stk1.top(), carry);
      stk1.pop();
    }
    if (carry) {
      auto newHead = new ListNode(carry);
      newHead->next = l1;
      return newHead;
    } else {
      return l1;
    }
  }
};