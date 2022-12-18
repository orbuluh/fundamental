# Divide and Conquer

## [:ok_hand: 823. Binary Trees With Factors](https://leetcode.com/problems/binary-trees-with-factors) [:dart:](btree_with_factors.h)

- easier version (but same concept) with [894](#bulbbulb-894-all-possible-full-binary-trees-dart)

<details><summary markdown="span">Question</summary>

```markdown
Given an array of unique integers, `arr`,
where each integer `arr[i]` is strictly greater than 1.

- We make a binary tree using these integers,
and each number may be used for **any number of times.**

- Each non-leaf node's value should be equal to the product of the values of its children.

- Return the number of binary trees we can make.
- The answer may be too large so return the answer modulo 10^9 + 7.

Input: arr = [2,4,5,10]
Output: 7

Explanation:
- We can make these trees:
- [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].
```

</details>

------------------------------------------------------------------------------

## [:bulb: 23. Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/) [:dart:](merge_k_sorted_lists.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given an array of k linked-lists lists,
each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 889. Construct Binary Tree from Preorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/) [:dart:](btree_from_pre_post.h)

- for a genius recursive solution from lee215 ... check [here](../recursion/btree_from_pre_post_recursion.h)

<details><summary markdown="span">Question</summary>

```markdown
Given two integer arrays, preorder and postorder where
- preorder is the preorder traversal of a binary tree of distinct values and
- postorder is the postorder traversal of the same tree,

reconstruct and return the binary tree.
If there exist multiple answers, you can return any of them.

Input: preorder = [1,2,4,5,3,6,7],
       postorder = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]

           1
         2    3
        4 5  6 7
```

</details>

------------------------------------------------------------------------------

## [:persevere: 894. All Possible Full Binary Trees](https://leetcode.com/problems/all-possible-full-binary-trees/) [:dart:](all_full_btree.h)

- Check [823](#ok_hand-823-binary-trees-with-factors-dart) as well for an easier but similar question
- Beautiful!

<details><summary markdown="span">Question</summary>

```markdown
Given an integer n, return a list of all possible full binary trees with n nodes.
- Each node of each tree in the answer must have Node.val == 0.
- Each element of the answer is the root node of one possible tree.
- You may return the final list of trees in any order.

- A full binary tree is a binary tree where each node has exactly 0 or 2 children.
```

</details>

------------------------------------------------------------------------------
