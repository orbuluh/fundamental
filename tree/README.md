# Tree
- more focus on insight of tree.
- For question that is more about beautiful recursion - check [notes :notebook:](../recursion/README.md)
- For segment tree - check [notes :notebook:](../range_query/segment_tree/README.md)


## [:ok_hand: 235. Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) [:dart:](lca_of_bst.h)

<details><summary markdown="span">Question</summary>

```markdown
Given a binary search tree (BST),
find the lowest common ancestor (LCA) node of two given nodes in the BST.
```
</details>


## [:ok_hand: 297. Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/) [:dart:](de_serialize_binary_tree.h)

<details><summary markdown="span">Question</summary>

```markdown
Serialize and deserialize a binary tree.
```
</details>

## [:ok_hand: 987. Vertical Order Traversal of a Binary Tree](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree//) [:dart:](vertical_order_traversal.h)
- tips: [Tree like DS are sorted by keys!](../basics/data_structures.md#tree-like-ds-are-sorted-by-keys-map-set-multimap-multiset)

<details><summary markdown="span">Question</summary>

```markdown
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
- If two nodes are in the same row and column, the order should be from left to right.
       3
    1     4     --> 2, 3' are actually at the same column as root 3.
  0   2  3'  7
  --> Output should be: [[0],[1],[3,2,3],[4],[7]]
```
</details>