# DP: Misc hard recursion

## [:persevere: 2448. Minimum Cost to Make Array Equal](https://leetcode.com/problems/minimum-cost-to-make-array-equal) / [:man_technologist:](min_cost_to_make_arr_equal.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given two 0-indexed arrays nums and cost consisting each of n positive integers.

You can do the following operation any number of times:

Increase or decrease any element of the array nums by 1.
The cost of doing one operation on the ith element is cost[i].

Return the minimum total cost such that all the elements of the array nums become equal.

Input: nums = [1,3,5,2], cost = [2,3,1,14]
Output: 8
Explanation: We can make all the elements equal to 2 in the following way:
- Increase the 0th element one time. The cost is 2.
- Decrease the 1st element one time. The cost is 3.
- Decrease the 2nd element three times. The cost is 1 + 1 + 1 = 3.
The total cost is 2 + 3 + 3 = 8.
It can be shown that we cannot make the array equal with a smaller cost.
Example 2:
```

</details>

------------------------------------------------------------------------------

## [:persevere: 1569. Number of Ways to Reorder Array to Get Same BST](https://leetcode.com/problemsnumber-of-ways-to-reorder-array-to-get-same-bst) / [:man_technologist:](number_of_ways_to_reorder_array_to_get_same_bst.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an array nums that represents a permutation of integers from 1 to n.
- We are going to construct a binary search tree (BST) by inserting the elements of nums in order into an initially empty BST.
- Find the number of different ways to reorder nums so that the constructed BST is identical to that formed from the original array nums.

For example, given nums = [2,1,3], we will have 2 as the root, 1 as a left child, and 3 as a right child.
- For array [2,3,1] also yields the same BST.
- For array [3,2,1] yields a different BST. (root is 3, left 1, right 2)

Return the number of ways to reorder nums such that the BST formed is identical to the original BST formed from nums.

Since the answer may be very large, return it modulo 10^9 + 7.

Input: nums = [3,4,5,1,2]
Output: 5
Explanation: The following 5 arrays will yield the same BST:
[3,1,2,4,5]
[3,1,4,2,5]
[3,1,4,5,2]
[3,4,1,2,5]
[3,4,1,5,2]
```

</details>

------------------------------------------------------------------------------

## [:persevere: 1799. Maximize Score After N Operations](https://leetcode.com/problems/maximize-score-after-n-operations) / [:man_technologist:](max_score_after_n_operations.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given nums, an array of positive integers of size 2 * n.
You must perform n operations on this array.

In the ith operation (1-indexed), you will:

Choose two elements, x and y.
Receive a score of i * gcd(x, y).
Remove x and y from nums.
Return the maximum score you can receive after performing n operations.

The function gcd(x, y) is the greatest common divisor of x and y.
```

</details>

------------------------------------------------------------------------------

## [:persevere: 907. Sum of Subarray Minimums](https://leetcode.com/problems/sum-of-subarray-minimums/) / [:man_technologist:](sum_of_subarray_mininums.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an array of integers arr, find the sum of min(b), where b is every
(contiguous) subarray of arr.

Since the answer may be large, return the answer modulo 10^9 + 7.

Input: arr = [3,1,2,4]
Output: 17

Explanation:

arr = [3,1,2,4]

Subarrays are [3], [1], [2], [4],
              [3,1], [1,2], [2,4],
              [3,1,2], [1,2,4], [3,1,2,4].
min value of each subarrays are: 3, 1, 2, 4,
                                 1, 1, 2,
                                 1, 1, 1.
Sum of all mins are 17.
```

</details>

------------------------------------------------------------------------------

## [:persevere: 956. Tallest Billboard](https://leetcode.com/problems/tallest-billboard) / [:man_technologist:](tallest_billboard.h)

<details><summary markdown="span">Question</summary>

```markdown
You are installing a billboard and want it to have the largest height.

The billboard will have two steel supports, one on each side.
Each steel support must be an equal height.

You are given a collection of rods that can be welded together.
For example, if you have rods of lengths 1, 2, and 3, you can weld them together
to make a support of length 6.

Return the largest possible height of your billboard installation.
If you cannot support the billboard, return 0.

Input: rods = [1,2,3,4,5,6]
Output: 10
Explanation: We have two disjoint subsets {2,3,5} and {4,6}, which have the same sum = 10.

Input: rods = [1,2]
Output: 0
Explanation: The billboard cannot be supported, so we return 0.
```

</details>

------------------------------------------------------------------------------

## [:dizzy_face: 446. Arithmetic Slices II - Subsequence](https://leetcode.com/problems/arithmetic-slices-ii-subsequence/) / [:man_technologist:](arithmetic_slices_ii.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an integer array nums, return the number of all the arithmetic subsequences of nums.

A sequence of numbers is called arithmetic
- if it consists of at least 3 elements and
- if the difference between any two consecutive elements is the same.

Input: nums = [2,4,6,8,10]
Output: 7
Explanation: All arithmetic subsequence slices are:
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]

Input: nums = [7,7,7,7,7]
Output: 16
Explanation: Any subsequence of this array is arithmetic.
```

</details>

------------------------------------------------------------------------------


## [:dizzy_face: 629. K Inverse Pairs Array](https://leetcode.com/problems/k-inverse-pairs-array/) / [:man_technologist:](k_inverse_pairs_arr.h)

<details><summary markdown="span">Question</summary>

```markdown
- For an integer array nums
- an inverse pair is
  - a pair of integers [i, j]
  - where 0 <= i < j < nums.length
  - and nums[i] > nums[j].

- Given two integers n and k, return
  - the number of different arrays
    consist of numbers from 1 to n
    such that there are exactly k inverse pairs.

- Since the answer can be huge, return it modulo 10^9 + 7.
```

</details>

------------------------------------------------------------------------------

## [:dizzy_face: 837. New 21 Game](https://leetcode.com/problems/new-21-game/) / [:man_technologist:](new_21_pts.h)

- ...hmmm

<details><summary markdown="span">Question</summary>

```markdown
Alice plays the following game, loosely based on the card game "21".

Alice starts with 0 points and draws numbers while she has less than k points.
During each draw, she gains an integer number of points
randomly from the range [1, maxPts],
- where maxPts is an integer.
- Each draw is independent and the outcomes have equal probabilities.

Alice stops drawing numbers when she gets k or more points.

Return the probability that Alice has n or fewer points.

Answers within 10^-5 of the actual answer are considered accepted.
```

</details>

------------------------------------------------------------------------------

## [:exploding_head: 376. Wiggle Subsequence](https://leetcode.com/problems/wiggle-subsequence/) / [:man_technologist:](wiggle_subseq.h)

<details><summary markdown="span">Question</summary>

```markdown
- A wiggle sequence is a sequence where the differences between successive numbers
  **strictly alternate between positive and negative**.
    - The first difference (if one exists) may be either positive or negative.
    - A sequence with one element and a sequence with two non-equal elements are
      trivially wiggle sequences.
- For example, `[1, 7, 4, 9, 2, 5]` is a wiggle sequence because the differences
  `(6, -3, 5, -7, 3)` alternate between positive and negative.
- In contrast, `[1, 4, 7, 2, 5]` and `[1, 7, 4, 5, 5]` are not wiggle sequences.
    - The first is not because its first two differences are positive, and
    - the second is not because its last difference is zero.
- A subsequence is obtained by deleting some elements (possibly zero) from the original
  sequence, leaving the remaining elements in their **original order**.
- Given an integer array nums
- Return the length of the **longest** wiggle subsequence of nums.
```

</details>

------------------------------------------------------------------------------

## [:exploding_head: 465. Optimal Account Balancing](https://leetcode.com/problems/optimal-account-balancing/) / [:man_technologist:](optimal_acct_balancing_dp.h)

- The brute-force backtracking solution and problem statement, some initial idea
  check [backtracking section](../backtracking/README.md#💡-465-optimal-account-balancing-🎯).
- The DP plus bitmask costs me so many hours to understand ... leave it here for future reference

------------------------------------------------------------------------------

## Reroot technique with DP

- (should this even be a category?)

## [:exploding_head: 834. Sum of Distances in Tree](https://leetcode.com/problems/sum-of-distances-in-tree) / [:man_technologist:](sum_of_distance_in_tree.h)

<details><summary markdown="span">Question</summary>

```markdown
There is an undirected connected tree with n nodes labeled from
0 to n - 1 and n - 1 edges.

You are given the integer n and the array edges where edges[i] = [ai, bi]
indicates that there is an edge between nodes ai and bi in the tree.

Return an array answer of length n where answer[i] is
the sum of the distances between the ith node in the tree and all other nodes.

Input: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
Output: [8,12,6,10,10,10]

Explanation:

      0
  1     2
      3 4 5


We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
equals 1 + 1 + 2 + 2 + 2 = 8.
Hence, answer[0] = 8, and so on.
```

</details>

------------------------------------------------------------------------------