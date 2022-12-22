# DP: Misc hard recursion

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