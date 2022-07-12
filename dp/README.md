# Dynamic programming [:notebook:](../basics/README.md#dynamic-programming)

# DFS + memorization
- DP but likely with a more sparse access needed to whole dp matrix
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


# Really tricky dp recursion

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