// Floyd's tortoise and hare: we move slow 1 step and move fast 2 steps
// The intuition is that
// 1. If there is no cycle in the list, the fast pointer will eventually reach
//    the end and we can return false in this case.
// 2. If there is a cycle, once slow entering the cycle, it will be like both
//    slow and fast are running in the cycle. And because fast is just one step
//    quicker - eventually it must be able to catch slow.
//
// NOTE that the full algorithm is trying to find the starting point of the
// cycle, where when slow and fast hit, it moves back slow to head, fast stay
// at meeting point, then move one step for both slow and fast in each iteration
// when they meet again, they are at the beginning of cycle.
//
// more formal proof: say:
//   m: distance of head to first node of cycle
//   n: length of cycle
//   k: distance of meeting point from the first node of cycle
//
//     m      _k__v    <- v: hitting point
//  ---------O     \   <- O: beginning of cycle O to v has distance k
//           ^      |
//           \_____/
//
// x: number of complete cycle fast pointer run before meeting
// y: number of complete cycle slow pointer run before meeting
// - slow run s = m + n * y + k  ... (1)
// - fast run f = m + n * x + k  ... (2)
// --> we can get: m + k = (x - 2y) * n
//
// which means m + k is a multiple of n (cycle length)
// Thus we can write, m + k = z * n, z being some integer
//  or m = z * n - k.
//
// say now, we move slow pointer from head, and fast pointer from meeting point
// v, and making both of them only travel 1 at a time, then when slow move m,
// fast should also move m = z * n - k, as fast start from v, z cycles minus k
// will basically make fast to travel to O, the same as what slow is now at.

class Solution {
public:
    bool hasCycle(ListNode *head) {
      ListNode* slow = head;
      ListNode* fast = head;
      while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
      }
      return false;
    }
};