# Tree

- more focus on property of tree.
- For question that is more about beautiful recursion - check [_notes :notebook:](../recursion/README.md)
- For segment tree - check [_notes :notebook:](../range_query/segment_tree/README.md)

------------------------------------------------------------------------------

## [:ok_hand: 235. Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) [:dart:](lca_of_bst.h)

- compare to [LCA of a binary tree](#ok_hand-236-lowest-common-ancestor-of-a-binary-tree-dart)

<details><summary markdown="span">Question</summary>

```markdown
Given a binary search tree (BST),
find the lowest common ancestor (LCA) node of two given nodes in the BST.
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 236. Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) [:dart:](lca_of_bt.h)

- compare to [LCA of BST](#ok_hand-235-lowest-common-ancestor-of-a-binary-search-tree-dart)

<details><summary markdown="span">Question</summary>

```markdown
Given a binary tree,
find the lowest common ancestor (LCA) of two given nodes in the tree.
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 297. Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/) [:dart:](de_serialize_binary_tree.h)

<details><summary markdown="span">Question</summary>

```markdown
Serialize and deserialize a binary tree.
```

</details>

------------------------------------------------------------------------------

## Tree traversal

## [:ok_hand: 987. Vertical Order Traversal of a Binary Tree](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree//) [:dart:](vertical_order_traversal.h)

- tips: [Tree like DS are sorted by keys!](../_notes/data_structures.md#tree-like-ds-are-sorted-by-keys-map-set-multimap-multiset)

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

------------------------------------------------------------------------------

## [:bulb: 94. Binary Tree Inorder Traversal with Iterative](https://leetcode.com/problems/binary-tree-inorder-traversal/) [:dart:](inorder_morris.h)

- check _notes on morris: [:point_right: here](../_notes/algorithms.md#morris-traversal)

<details><summary markdown="span">Question</summary>

```markdown
Given the root of a binary tree, return the inorder traversal of its nodes' values.
```

</details>

------------------------------------------------------------------------------

## BST

- check [_notes :notebook:](../_notes/data_structures.md#bst)

## [:ok_hand: 173. Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator) [:dart:](bst_iterator.h)

- check [653 below](#💡-653-two-sum-iv---input-is-a-bst-🎯) as a variant of this one

<details><summary markdown="span">Question</summary>

```markdown
Implement the BSTIterator class that represents an iterator over the
in-order traversal of a binary search tree (BST):
- `BSTIterator(TreeNode root)`
  - Initializes an object of the BSTIterator class.
  - The root of the BST is given as part of the constructor.
  - The pointer should be initialized to a non-existent number smaller than any element in the BST.
  - Notice that by initializing the pointer to a non-existent smallest number, the first call to `next()` will return the smallest element in the BST.
- `boolean hasNext()`
  - Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
- `int next()`
  - Moves the pointer to the right, then returns the number at the pointer.


- You may assume that `next()` calls will always be valid. That is, there will be at least a next number in the in-order traversal when `next()` is called.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 653. Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/) [:dart:](two_sum_iv_with_bst.h)

- could have just used easier hashmap recursive way ... but just for fun and for a better memory complexity, there is a way to do this with bst iterator basically

<details><summary markdown="span">Question</summary>

```markdown
Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.
```

</details>

------------------------------------------------------------------------------
