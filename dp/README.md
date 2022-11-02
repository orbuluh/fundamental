# Dynamic programming [:notebook:](../notes/algorithms.md#dynamic-programming)

# [DP: 0/1 knapsack like recursion structure](dp_01_knapsack/README.md)

# [DP: Unbounded knapsack like recursion structure](dp_unbounded_knapsack/README.md)

# [DP: state transition](dp_state_transition/README.md)

# [DP: DFS + memorization](dp_dfs_memorization/README.md)

# [DP: subarray (contiguous, Kadane's Algorithm)](dp_subarray_kadane/README.md)

# [DP: subsequence](dp_subseq/README.md)

# [DP: string match](dp_string_match/README.md)

# DP: The really tricky recursion ...

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
```

</details>

------------------------------------------------------------------------------

## [:exploding_head: 837. New 21 Game](https://leetcode.com/problems/new-21-game/) [:dart:](new_21_pts.h)

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

------------------------------------------------------------------------------

## [:exploding_head: :exploding_head: 465. Optimal Account Balancing](https://leetcode.com/problems/optimal-account-balancing/) [:dart:](optimal_acct_balancing_dp.h)

- The brute-force backtracking solution and problem statement, some initial idea
  check [backtracking section](../backtracking/README.md#💡-465-optimal-account-balancing-🎯).
- The DP plus bitmask costs me so many hours to understand ... leave it here for future reference