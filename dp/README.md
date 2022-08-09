# Dynamic programming [:notebook:](../basics/algorithms.md#dynamic-programming)

# DFS + memorization
- DP but likely with a more sparse access needed to whole dp matrix

## [:ok_hand: 377. Combination Sum IV](https://leetcode.com/problems/combination-sum-iv/) [:dart:](combination_sum_iv.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an array of distinct integers nums and a target integer target,
return the number of possible permutations that add up to target.

Input: nums = [1,2,3], target = 4
Output: 7

Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
# Note that different sequences are counted as different combinations.
```
</details>

## [:ok_hand: 576. Out of Boundary Paths](https://leetcode.com/problems/out-of-boundary-paths/) [:dart:](out_of_bound_path_sol1.h)
- DF + memorization is straight forward (and faster), the food for thought is doing in the [other way](out_of_bound_path_sol2.h).
<details><summary markdown="span">Question</summary>

```markdown
There is an m x n grid with a ball.
- The ball is initially at the position [`startRow`, `startColumn`].
- You are allowed to move the ball to one of the four adjacent cells in the grid
  - (possibly out of the grid crossing the grid boundary).
- You can apply at most `maxMove` moves to the ball.

Given the five integers `m`, `n`, `maxMove`, `startRow`, `startColumn`
return the number of paths to move the ball out of the grid boundary.

Since the answer can be very large, return it modulo 10^9 + 7.
```
</details>

## [:bulb: 1473. Paint House III](https://leetcode.com/problems/paint-house-iii/) [:dart:](paint_house_iii.h)

<details><summary markdown="span">Question</summary>

```markdown
- There is a row of m houses in a small city
    - each house must be painted with one of the n colors (labeled from 1 to n)
    - some houses that have been painted (non-zero color) not be painted again.

- A neighborhood is a maximal group of continuous houses with the same color.
    - For example: houses = [1,2,2,3,3,2,1,1] contains 5 neighborhoods
      `[{1}, {2,2}, {3,3}, {2}, {1,1}].`
- Given an array houses, an m x n matrix cost and an integer `target` where:
    - houses[i]: is the color of the house i, 0 if the house is not painted yet.
    - cost[i][j]: is the cost of paint the house i with the color j + 1.
- Return the minimum cost of painting all the remaining houses in such a way
  that there are exactly `target` neighborhoods.
  - If it is not possible, return -1.

Input: houses = [0,0,0,0,0],
       cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3

Output: 9
Explanation: Paint houses of this way [1,2,2,1,1]
- This array contains target = 3 neighborhoods, [{1}, {2,2}, {1,1}].
- Cost of paint all houses (1 + 1 + 1 + 1 + 5) = 9.
```
</details>

# Common sequence

## [:bulb: 300. Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/) [:dart:](longest_common_subseq.h)
<details><summary markdown="span">Question</summary>

```markdown
Given an integer array `nums`,
return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array
by deleting some or no elements without changing the order of the remaining elements.

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
```
</details>



# Situation analyze

## [:ok_hand: 1220. Count Vowels Permutation](https://leetcode.com/problems/count-vowels-permutation/) [:dart:](count_vowels_permutation.h)
<details><summary markdown="span">Question</summary>

```markdown
Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a' or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a 'u'.
Each vowel 'u' may only be followed by an 'a'.
Since the answer may be too large, return it modulo 10^9 + 7.

Input: n = 2
Output: 10
Explanation: All possible strings are:
"ea", "ia", "ua",
"ae", "ie",
"ei", "oi",
"io",
"iu", "ou"
```
</details>

# Really tricky dp recursion

## [:exploding_head: 629. K Inverse Pairs Array](https://leetcode.com/problems/k-inverse-pairs-array/) [:dart:](k_inverse_pairs_arr.h)
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
</details>


## [:exploding_head: :exploding_head: 376. Wiggle Subsequence](https://leetcode.com/problems/wiggle-subsequence/) [:dart:](wiggle_subseq.h)
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