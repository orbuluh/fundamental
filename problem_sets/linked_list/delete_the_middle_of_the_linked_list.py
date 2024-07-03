"""
1 2 3 4 5
s s
  f   f     --> delete s.next

1 2 3 4
s s         --> delete s.next
  f   f

1 2
s
  f
"""


class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow = head
        if not head.next:
            return None
        fast = head.next
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        slow.next = slow.next.next
        return head
