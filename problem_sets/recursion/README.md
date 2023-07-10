# Recursion

- Note: When thinking about the complexity ... recursion can be thought of as n nested loops where in each loop the number of iterations decreases by one.
- See also [really tricky recursion DP questions](../dp/README.md#really-tricky-dp-recursion)

## [:ok_hand: 38. Count and Say](https://leetcode.com/problems/count-and-say/) / [:man_technologist:](count_and_say.h)

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

## [:ok_hand: 1026. Maximum Difference Between Node and Ancestor](https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/) / [:man_technologist:](max_diff_between_node_and_ancestor.h)

<details><summary markdown="span">Question</summary>

```markdown
Given the root of a binary tree, find the maximum value v for which there exist
different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.

A node a is an ancestor of b if either: any child of a is equal to b or any
child of a is an ancestor of b.


Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 669. Trim a Binary Search Tree](https://leetcode.com/problems/trim-a-binary-search-tree/) / [:man_technologist:](trim_a_bst.h)

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

## [:ok_hand: 783. Minimum Distance Between BST Nodes](https://leetcode.com/problems/minimum-distance-between-bst-nodes) / [:man_technologist:](min_distance_between_bst_nodes.h)

<details><summary markdown="span">Question</summary>

```markdown
Given the root of a Binary Search Tree (BST), return the minimum difference
between the values of any two different nodes in the tree.

Input: root = [1,0,48,null,null,12,49]
    1
0       48
      12   49

Output: 1
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 226. Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree) / [:man_technologist:](invert_binary_tree.h)

<details><summary markdown="span">Question</summary>

```markdown
Given the root of a binary tree, invert the tree, and return its root.

       4                 4
   2      7           7      2
 1   3  6   9       9   6  3   1
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 101. Symmetric Tree](https://leetcode.com/problems/symmetric-tree) / [:man_technologist:](symmetric_tree.h)

<details><summary markdown="span">Question</summary>

```markdown
Given the root of a binary tree, check whether it is a mirror of itself
(i.e., symmetric around its center).

Input: root = [1,2,2,3,4,4,3]
Output: true
      1
   2      2
 3   4  4   3

Input: root = [1,2,2,null,3,null,3]
Output: false
      1
   2      2
     3      3
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 814. Binary Tree Pruning](https://leetcode.com/problems/binary-tree-pruning/) / [:man_technologist:](bt_prunning.h)

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

## [:ok_hand: 129. Sum Root to Leaf Numbers](https://leetcode.com/problems/sum-root-to-leaf-numbers) / [:man_technologist:](sum_root_to_leaf_numbers.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers.
Test cases are generated so that the answer will fit in a 32-bit integer.

Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 111. Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree) / [:man_technologist:](min_depth_of_btree.h)

<details><summary markdown="span">Question</summary>

```markdown
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Input: root = [3,9,20,null,null,15,7]
Output: 2
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 1443. Minimum Time to Collect All Apples in a Tree](https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree) / [:man_technologist:](min_time_to_collect_all_apples_in_a_tree.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an undirected tree consisting of n vertices numbered from 0 to n-1,
which has some apples in their vertices.

You spend 1 second to walk over one edge of the tree.

Return the minimum time in seconds you have to spend to collect all apples in
the tree,

starting at vertex 0 and coming back to this vertex.

The edges of the undirected tree are given in the array edges, where
edges[i] = [ai, bi] means that exists an edge connecting the vertices ai and bi.

Additionally, there is a boolean array hasApple,
where hasApple[i] = true means that vertex i has an apple;
otherwise, it does not have any apple.

Input: n = 7,

edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]],
hasApple = [false,false,true,false,true,true,false]
Output: 8

              0__
            /     \
          1        2(a)
        / \       / \
    4(a)  5(a)    3  6

8 seconds to traverse node with order:
0 -> 1 -> 4 -> 1 -> 5 -> 1 -> 0 -> 2 -> 0
   1   2    3    4    5    6    7    8
```

</details>

------------------------------------------------------------------------------

## [:bulb: 236. Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) / [:man_technologist:](lca_of_btree.h)

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

## [:bulb: 105. Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) / [:man_technologist:](btree_from_pre_and_in.h)

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

## [:bulb: 106. Construct Binary Tree from Inorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal) / [:man_technologist:](btree_from_in_and_post.h)

<details><summary markdown="span">Question</summary>

```markdown
Given two integer arrays inorder and postorder where inorder is the inorder
traversal of a binary tree and postorder is the postorder traversal of the same
tree, construct and return the binary tree.

Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
     3
  9      20
       15  7
```

</details>

------------------------------------------------------------------------------

## [:bulb: 889. Construct Binary Tree from Preorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/) / [:man_technologist:](btree_from_pre_post_recursion.h)

- for more intuitive (?) divide and conquer approach and problem statement, check [here](../divide_and_conquer/README.md#💡-889-construct-binary-tree-from-preorder-and-postorder-traversal-🎯)

------------------------------------------------------------------------------

## [:bulb: 230. Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/) / [:man_technologist:](kth_smallest_element_in_bst.h)

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

## [:bulb: 222. Count Complete Tree Nodes](https://leetcode.com/problems/count-complete-tree-nodes/) / [:man_technologist:](count_complete_tree_nodes.h)

<details><summary markdown="span">Question</summary>

```markdown
Given the root of a complete binary tree, return the number of the nodes in the tree.

complete binary tree:
- every level, except possibly the last, is completely filled in a complete
  binary tree
- all nodes in the last level are as far left as possible. It can have between
  1 and 2^h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.
```

</details>


------------------------------------------------------------------------------

## [:bulb: 958. Check Completeness of a Binary Tree](https://leetcode.com/problems/check-completeness-of-a-binary-tree) / [:man_technologist:](check_complete_tree.h)

<details><summary markdown="span">Question</summary>

```markdown
Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely
filled, and all nodes in the last level are as far left as possible.

It can have between 1 and 2^h nodes inclusive at the last level h.

return true for:
     3
  9      20
8  6    15


return false for:
     3
  9      20
8      15
```

</details>

------------------------------------------------------------------------------

## [:bulb: 124. Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/) / [:man_technologist:](binary_tree_max_path_sum.h)

<details><summary markdown="span">Question</summary>

```markdown
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes
in the sequence has an edge connecting them.

A node can only appear in the sequence at most once.

Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.


      -10
    9      20
         15   7

Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7
             with a path sum of 15 + 20 + 7 = 42.

```

</details>

------------------------------------------------------------------------------

## [:bulb: 2246. Longest Path With Different Adjacent Characters](https://leetcode.com/problems/longest-path-with-different-adjacent-characters) / [:man_technologist:](longest_path_with_different_adjacent_characters.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given a tree (i.e. a connected, undirected graph that has no cycles)
- rooted at node 0
- consisting of n nodes numbered from 0 to n - 1.

The tree is represented by a 0-indexed array parent of size n,
where parent[i] is the parent of node i.
Since node 0 is the root, parent[0] == -1.

You are also given a string s of length n,
where s[i] is the character assigned to node i.

Return the length of the longest path in the tree

such that no pair of adjacent nodes on the path
have the same character assigned to them.

Input: parent = [-1,0,0,1,1,2], s = "abacbe"
Output: 3

            0(a)
      2(a)        1(b)
    5(e)        3(c)  4(b)


Explanation: The longest path 0 -> 1 -> 3.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 1372. Longest ZigZag Path in a Binary Tree](https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree) / [:man_technologist:](longest_zigzag_path_in_a_btree.h)

<details><summary markdown="span">Question</summary>

```markdown

You are given the root of a binary tree.

A ZigZag path for a binary tree is defined as follow:

Choose any node in the binary tree and a direction (right or left).

- If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
- Change the direction from right to left or from left to right.
- Repeat the second and third steps until you can't move in the tree.
- Zigzag length is defined as the number of nodes visited - 1.
- (A single node has a length of 0).

- Return the longest ZigZag path contained in that tree.

      1
        1*
      1    1*
        1*    1
           1*
             1

Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]
Output: 3
```

</details>

------------------------------------------------------------------------------

## [:bulb: 394. Decode String](https://leetcode.com/problems/decode-string/) / [:man_technologist:](decode_string.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an encoded string, return its decoded string.

The encoding rule is:`k[encoded_string]`, where
- the `encoded_string` inside the square brackets is being repeated exactly k times.
- Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid;
there are no extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits
and that digits are only for those repeat numbers, k.

For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 10^5.

Input: s = "3[a2[c]]"
Output: "accaccacc"
```

</details>

------------------------------------------------------------------------------

## [:bulb: 427. Construct Quad Tree](https://leetcode.com/problems/construct-quad-tree) / [:man_technologist:](construct_quad_tree.h)

<details><summary markdown="span">Question</summary>

```markdown
Given a n * n matrix grid of 0's and 1's only.
We want to represent the grid with a Quad-Tree.

A Quad-Tree is a tree data structure in which each internal node has exactly
four children. Besides, each node has two attributes:

- val: True if the node represents a grid of 1's or
       False if the node represents a grid of 0's.
- isLeaf: True if the node is leaf node on the tree or
          False if the node has the four children.
- Notice that you can assign the value of a node to True or False when isLeaf
is False, and both are accepted in the answer.

Return the root of the Quad-Tree representing the grid.
- check Leetcode for pictures of example
```

</details>

------------------------------------------------------------------------------

## [:persevere: 897. Increasing Order Search Tree](https://leetcode.com/problems/increasing-order-search-tree/) / [:man_technologist:](increasing_order_bst.h)

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

## [:persevere: 426. Convert Binary Search Tree to Sorted Doubly Linked List](https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/) / [:man_technologist:](convert_bst_to_dll.h)

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

## [:dizzy_face: 114. Flatten Binary Tree to Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/) / [:man_technologist:](flattern_btree_to_ll.h)

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
