/*
 Important to think about all kind of solutions and the complexity. Got asked
 during interview and failed to explain well ...


Solution_1_priority_queue

- Priority queue always has k ListNode*, so space will be O(k) space here.
  (If you calculate the new resulting LinkList*, it took O(n) space.
- And in each iteration, pop one node out with O(logk),
  then insert another one in, also with O(logk)
- As each time pop/insert one node, at the end, you are going to do this for n
  times, so overall time complexity is O(nlogk)


Solution_2_merge2

- Overall there are (k-1) times merge.
- On average, in the i-th iteration, the first list has i * n / k elements
  the second list has n / k elements
- So overall time complexity is sum_i (i*n/k + n/k), for i in 1 to k - 1
  = (n/k) * (i + 1), for i in  i to k - 1
  ~= O(n/k) * O(k^2) = O(nk)
- Space complexity is like O(1), don't really need extra space.


Solution_3_divide_and_conquer

- Similar to solution 2, but you don't do the merge with (k-1) times.
  Rather, you do this O(logk) times through:
  first iteration, merge lists  [0, 1] [2, 3] [4, 5] [6, 7]
  second iteration, merge lists [0, 2][4, 6]
  third iteration, merge lists  [0, 4]
- Each iteration, you are iterate all the nodes with O(n) to form the result
  Overall time complexity is therefore O(nlogk)
- Space complexity is like O(1), don't really need extra space.
 */

class Solution_1_priority_queue {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto comp = [](ListNode* n1, ListNode* n2) { return n1->val > n2->val; };
    std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(comp)> pq(
        comp);
    auto pushNonNull = [&](auto n) {
      if (!n) return;
      pq.push(n);
    };
    for (auto n : lists) {
      pushNonNull(n);
    }
    ListNode dummy;
    auto cur = &dummy;
    while (!pq.empty()) {
      auto nxt = pq.top()->next;
      cur->next = pq.top();
      pq.pop();
      pushNonNull(nxt);
      cur = cur->next;
    }
    return dummy.next;
  }
};

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

class Solution_2_merge2 {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    auto head = lists.front();
    for (int i = 1; i < lists.size(); ++i) {
      head = merge2Lists(head, lists[i]);
    }
    return head;
  }
};

class Solution_3_divide_and_conquer {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    const int sz = lists.size();
    int interval = 1;
    while (interval < sz) {
      // merge [0, 1] to 0, [2, 3] to 2 [4, 5] to 4
      // merge [0, 2] to 0, [4] the same
      // merge [0, 4] to 0.  6 lists are now fully merged
      for (int i = 0; i < sz - interval; i += 2 * interval) {
        lists[i] = merge2Lists(lists[i], lists[i + interval]);
      }
      interval *= 2;
    }
    return lists.front();
  }
};

using Solution = Solution_3_divide_and_conquer;