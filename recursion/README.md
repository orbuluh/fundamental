# Recursion
- See also [really tricky recursion DP questions](../dp/README.md#really-tricky-dp-recursion)

## [:ok_hand: 669. Trim a Binary Search Tree](https://leetcode.com/problems/trim-a-binary-search-tree/) [:dart:](trim_a_bst.h)

<details><summary markdown="span">Question</summary>

```markdown
Given the root of a binary search tree and the lowest and highest boundaries as low and high,
trim the tree so that all its elements lies in [low, high]

     3               3
   0   4    ==>     2
      2            1
     1
```
</details>

------------------------------------------------------------------------------

## [:bulb: 236. Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) [:dart:](lca_of_btree.h)

<details><summary markdown="span">Question</summary>

```markdown
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

         3
       5       1
    6    2   0   8
        7 4

- LCA of 5 and 1 is 3
- LCA of 5 and 4 is 5
...
```
</details>

------------------------------------------------------------------------------

## [:bulb: 105. Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) [:dart:](btree_from_pre_and_in.h)

<details><summary markdown="span">Question</summary>

```markdown
Given two integer arrays preorder and inorder where
- preorder is the preorder traversal of a binary tree and
- inorder is the inorder traversal of the same tree,
construct and return the binary tree.

Input: preorder = [3,9,8,6,20,15,7], inorder = [8,9,6,3,15,20,7]
Output: [3,9,20,8,6,15,7]

     3
  9      20
8  6    15  7
```
</details>

------------------------------------------------------------------------------

## [:bulb::bulb: 897. Increasing Order Search Tree](https://leetcode.com/problems/increasing-order-search-tree/) [:dart:](increasing_order_bst.h)
- related: [426. Convert Binary Search Tree to Sorted Doubly Linked List](#bulbbulb-426-convert-binary-search-tree-to-sorted-doubly-linked-list-dart)
<details><summary markdown="span">Question</summary>

```markdown
Given the root of a binary search tree, rearrange the tree in in-order to a linked list.

        5                1
    3       6      --->   2
  2  4       8             3
1           7  9            4
                             5
                              6
                               7
                                8
                                 9
```
</details>

------------------------------------------------------------------------------

## [:bulb::bulb: 426. Convert Binary Search Tree to Sorted Doubly Linked List](https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/) [:dart:](convert_bst_to_dll.h)
- concept similar to [897. Increasing Order Search Tree](#bulbbulb-426-convert-binary-search-tree-to-sorted-doubly-linked-list-dart)

<details><summary markdown="span">Question</summary>

```markdown
Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in place.

    4
   2  5   -->     1 <-> 2 <-> 3 <-> 4 <-> 5
  1 3             ^_______________________^
```
</details>

------------------------------------------------------------------------------

## [:exploding_head: 114. Flatten Binary Tree to Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/) [:dart:](flattern_btree_to_ll.h)
- Doable by many ways but best voted sol is :exploding_head: recursive idea
<details><summary markdown="span">Question</summary>

```markdown
Given the root of a binary tree, flatten the tree into a "linked list" like below
               1
    1            2
  2   5     -->    3
3  4    6            4
                       5
                         6
```
</details>

------------------------------------------------------------------------------