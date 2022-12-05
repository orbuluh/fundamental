# DP: 0/1 knapsack like recursion structure

```markdown
- "to use or not to use" and the relation to previous state
- basically of backtracking like dp should be able to modeled as this - as
  making current state the same as previous is like "not to use" current item.
  and making current state = delta + previous state of (not use current item) is
  like the effect of "use" current item.
```

## [:bulb: 474. Ones and Zeroes](https://leetcode.com/problems/ones-and-zeroes/) [:dart:](ones_and_zeros.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that
- there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation:

The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
- Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
- {"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
```

</details>

------------------------------------------------------------------------------

## [:bulb::bulb: 494. Target Sum](https://leetcode.com/problems/target-sum/) [:dart:](target_sum_bottom_up.h)

- check [below for full description](#bulb-494-target-sum-dart) ... overall dfs solution is much more straightforward
- bottom up solution is much faster and is basically a 0/1 knapsack, but need a conversion for the problem

------------------------------------------------------------------------------

## [:bulb: 416. Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/) [:dart:](partition_equal_subset_sum.h)

- Really nice question that can be reduced to the classic 0/1 knapsack problem!

<details><summary markdown="span">Question</summary>

```markdown

Given a non-empty array nums containing only positive integers,
find if the array can be partitioned into two subsets such that the sum of
elements in both subsets is equal.

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
```

</details>

------------------------------------------------------------------------------

## [:bulb: 115. Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/) [:dart:](distinct_subsequences.h)

<details><summary markdown="span">Question</summary>

```markdown
Given two strings s and t, return the number of distinct subsequences of s which
equals t.

A string's subsequence is a new string formed from the original string by
deleting some (can be none) of the characters without disturbing the remaining
characters' relative positions.

(i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).

The test cases are generated so that the answer fits on a 32-bit signed integer.

Input: s = "rabbbit", t = "rabbit"
Output: 3

Explanation:
rabbbit
^^^^ ^^
rabbbit
^^^ ^^^
rabbbit
^^ ^^^^
```

</details>

------------------------------------------------------------------------------

## [:bulb: 1235. Maximum Profit in Job Scheduling](https://leetcode.com/problems/maximum-profit-in-job-scheduling/) [:dart:](maximum_profit_in_job_scheduling.h)

<details><summary markdown="span">Question</summary>

```markdown
We have n jobs, where every job is scheduled to be done

from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays,
return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job
that starts at time X.

Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job.
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
```

</details>

------------------------------------------------------------------------------
