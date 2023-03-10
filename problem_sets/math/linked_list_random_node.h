/**
Reservoir sampling is used more in the context of the list
could be changed by other operation, while each time you
want to make sure all elements has equal probability to be
selected.


In the context of list just being a fixed number. You could
have do it this way:

- In constructor, just find out the size n
- In getRandom, just create random idx with r = rand() % n
  and use O(n) to traverse to the r-th node and return the
  value.
- Complexity is basically the same as reservoir, but likely
  to be quicker as you won't need to traverse all n nodes
  every time
**/

class Solution {
  ListNode* head_ = nullptr;
  int n = 0; // not for reservoir sampling

 public:
  Solution(ListNode* head) : head_(head) {
    while (head) { // not for reservoir sampling
      n++;
      head = head->next;
    }
  }

  int reservoir_sampling_with_size_1() {
    auto node = head_;
    auto res = head_->val;
    auto i = 1;
    while (node) {
      // reservoir sampling with size k = 1
      // at timing i, k/i = 1/i prob to replace
      // new value into reservoir. We could select
      // any number in the equation, the point is
      // to make the probability 1/i
      if (rand() % i++ == 0) {
        res = node->val;
      }
      node = node->next;
    }
    // after traversing the whole list, each node
    // has equal probability of 1/n to be selected,
    // as what reservoir sampling guarantee
    return res;
  }

  int getRandom() {
    // return reservoir_sampling_with_size_1();
    int r = rand() % n;
    auto node = head_;
    while (r) {
      node = node->next;
      r--;
    }
    return node->val;
  }
};
