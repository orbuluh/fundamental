# Recursion

- Note: When thinking about the complexity ... recursion can be thought of as n nested loops where in each loop the number of iterations decreases by one.
- See also [really tricky recursion DP questions](../dp/README.md#really-tricky-dp-recursion)

## [:ok_hand: 38. Count and Say](https://leetcode.com/problems/count-and-say/) [:dart:](count_and_say.h)

- not hard but think about how to implement it cleanly

<details><summary markdown="span">Question</summary>

```markdown
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would
- "say" the digit string from countAndSay(n-1), which is then converted into a
  different digit string.
- To determine how you "say" a digit string, split it into the minimal number of
  substrings such that each substring contains exactly one unique digit.
- Then for each substring, say the number of digits, then say the digit.
- Finally, concatenate every said digit.

Input: n = 4
Output: "1211"

Explanation:
- countAndSay(1) = "1"
- countAndSay(2) = say "1" = one 1 = "11"
- countAndSay(3) = say "11" = two 1's = "21"
- countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
```

</details>

------------------------------------------------------------------------------

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

## [:ok_hand: 814. Binary Tree Pruning](https://leetcode.com/problems/binary-tree-pruning/) [:dart:](bt_prunning.h)

<details><summary markdown="span">Question</summary>

```markdown
Given the root of a binary tree with node value either 0 or 1,
return the same tree where every subtree (of the given tree) not containing a 1
has been removed.


     1               1
       0    ==>        0
      0  1               1
     0
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

## [:bulb: 889. Construct Binary Tree from Preorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/) [:dart:](btree_from_pre_post_recursion.h)

- for more intuitive (?) divide and conquer approach and problem statement, check [here](../divide_and_conquer/README.md#💡-889-construct-binary-tree-from-preorder-and-postorder-traversal-🎯)

------------------------------------------------------------------------------

## [:bulb: 230. Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/) [:dart:](kth_smallest_element_in_bst.h)

<details><summary markdown="span">Question</summary>

```markdown
Given the root of a binary search tree, and an integer k,

return the kth smallest value (1-indexed) of all the values of the nodes
in the tree.

Input: root = [3,1,4,null,2], k = 1
   3
 1   4
  2

output = 1
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
