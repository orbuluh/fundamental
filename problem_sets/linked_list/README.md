# Linked list

## Basic operations on linked list

## [:ok_hand: 141. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/) / [:man_technologist:](linked_list_cycle.h)

<details><summary markdown="span">Question</summary>

```markdown
Given head, the head of a linked list, determine if the linked list has a cycle.
Return true if there is a cycle in the linked list. Otherwise, return false.
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 142. Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/) / [:man_technologist:](linked_list_cycle_ii.h)

<details><summary markdown="span">Question</summary>

```markdown
Given the head of a linked list, return the node where the cycle begins.
If there is no cycle, return null.
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 206. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/) / [:man_technologist:](reversed_linked_list.h)

<details><summary markdown="span">Question</summary>

```markdown
Given the head of a singly linked list, reverse the list, and return the reversed list.
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 876. Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/) / [:man_technologist:](middle_of_the_linked_list.h)

<details><summary markdown="span">Question</summary>

```markdown
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 328. Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list/) / [:man_technologist:](odd_even_linked_list.h)

<details><summary markdown="span">Question</summary>

```markdown
Given the head of a singly linked list, group all the nodes with odd indices
together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain
as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.


Input:  [1,2,3,4,5]
         ^   ^   ^
Output: [1,3,5,2,4]
              |

Input:  [2,1,3,5,6,4,7]
         ^   ^   ^   ^
Output: [2,3,6,7,1,5,4]
                |
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 1721. Swapping Nodes in a Linked List](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/) / [:man_technologist:](swapping_nodes_in_a_ll.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node
from the beginning and the kth node from the end (the list is 1-indexed).


                 v   v
Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
                     v     v
Input: head = [7,9,6,6,7,8,3,0,9,5], k = 4
Output: [7,9,6,3,7,8,6,0,9,5]
```

</details>

------------------------------------------------------------------------------

## [:bulb: 382. Linked List Random Node](https://leetcode.com/problems/linked-list-random-node)

- Need to use reservoir sampling ... check [here](../math/README.md#💡-382-linked-list-random-node--👨‍💻)


## Composite operations on linked list

## [:bulb: 61. Rotate List](https://leetcode.com/problems/rotate-list/) / [:man_technologist:](rotate_list.h)

<details><summary markdown="span">Question</summary>

```markdown
Given the head of a linked list, rotate the list to the right by k places.

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
```

</details>

------------------------------------------------------------------------------

## [:bulb: 19. Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) / [:man_technologist:](remove_n_th_node_from_end.h)

<details><summary markdown="span">Question</summary>

```markdown
Given the head of a linked list, remove the nth node from the end of the list and return its head.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 92. Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/) / [:man_technologist:](reversed_linked_list_ii.h)

- partial reverse basically ...

<details><summary markdown="span">Question</summary>

```markdown
Given the head of a singly linked list and two integers left and right
  - where left <= right

reverse the nodes of the list from **position** left to **position** right
and return the reversed list.

1 -> 2 -> 3 -> 4 -> 5   LEFT = 2, RIGHT = 4
return:
1 -> 4 -> 3 -> 2 -> 5
```

</details>

------------------------------------------------------------------------------

## [:bulb: 234. Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/) / [:man_technologist:](palindrome_linked_list.h)

<details><summary markdown="span">Question</summary>

```markdown
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Input: head = [1,2,2,1]
Output: true
```

</details>

------------------------------------------------------------------------------

## [:bulb: 445. Add Two Numbers II](https://leetcode.com/problems/add-two-numbers-ii/) / [:man_technologist:](add_2_nums_ii.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given two non-empty linked lists representing two non-negative integers.
The most significant digit comes first and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Please do it without reversing the linked list

Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]

Input: l1 = [9], l2 = [1]
Output: [1,0]

```

</details>

------------------------------------------------------------------------------
