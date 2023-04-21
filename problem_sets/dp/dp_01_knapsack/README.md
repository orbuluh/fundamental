# DP: 0/1 knapsack like recursion structure

```markdown
- "to use or not to use" and the relation to previous state
- basically of backtracking like dp should be able to modeled as this - as
  making current state the same as previous is like "not to use" current item.
  and making current state = delta + previous state of (not use current item) is
  like the effect of "use" current item.
```

## [:bulb: 474. Ones and Zeroes](https://leetcode.com/problems/ones-and-zeroes/) / [:man_technologist:](ones_and_zeros.h)

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

## [:bulb: 416. Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/) / [:man_technologist:](partition_equal_subset_sum.h)

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

## [:bulb: 115. Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/) / [:man_technologist:](distinct_subsequences.h)

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

## [:bulb: 1235. Maximum Profit in Job Scheduling](https://leetcode.com/problems/maximum-profit-in-job-scheduling/) / [:man_technologist:](maximum_profit_in_job_scheduling.h)

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

## [:bulb: 2218. Maximum Value of K Coins From Piles](https://leetcode.com/problems/maximum-value-of-k-coins-from-piles) / [:man_technologist:](max_val_of_k_coins_from_piles.h)

<details><summary markdown="span">Question</summary>

```markdown
There are n piles of coins on a table.

Each pile consists of a positive number of coins of assorted denominations.

In one move, you can choose any coin on top of any pile, remove it, and add it
to your wallet.

Given a list piles, where piles[i] is a list of integers denoting the
composition of the ith pile from top to bottom, and a positive integer k, return
the maximum total value of coins you can have in your wallet if you choose
exactly k coins optimally.

Input: piles = [[1,100,3],[7,8,9]], k = 2
Output: 101

Input: piles = [[100],[100],[100],[100],[100],[100],[1,1,1,1,1,1,700]], k = 7
Output: 706
```

</details>

------------------------------------------------------------------------------

## [:bulb: 1639. Number of Ways to Form a Target String Given a Dictionary](https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary) / [:man_technologist:](number_of_ways_to_form_a_tgt_string_give_dictionary.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given a list of strings of the same length words and a string target.

Your task is to form target using the given words under the following rules:

target should be formed from left to right.

To form the ith character (0-indexed) of target, you can choose the kth
character of the jth string in words if target[i] = words[j][k].

Once you use the kth character of the jth string of words, you can no longer use
the xth character of any string in words where x <= k.

In other words, all characters to the left of or at index k become unusuable for
every string.

Repeat the process until you form the string target.

Notice that you can use multiple characters from the same string in words
provided the conditions above are met.

Return the number of ways to form target from words.
Since the answer may be too large, return it modulo 10^9 + 7.

Input: words = ["acca","bbbb","caca"], target = "aba"
Output: 6
Explanation: There are 6 ways to form target.
"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("caca")
"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("caca")
"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("acca")
"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("acca")
"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("acca")
"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("caca")
```

</details>

------------------------------------------------------------------------------

## [:persevere: 879. Profitable Schemes](https://leetcode.com/problems/profitable-schemes) / [:man_technologist:](profitable_schemes.h)

<details><summary markdown="span">Question</summary>

```markdown
There is a group of n members, and a list of various crimes they could commit.

- The ith crime generates a profit[i] and
- requires group[i] members to participate in it.

- If a member participates in one crime, that member can't participate in another crime.

- Let's call a profitable scheme any subset of these crimes that generates
  at least minProfit profit, and the total number of members participating in
  that subset of crimes is at most n.

Return the number of schemes that can be chosen.
Since the answer may be very large, return it modulo 10^9 + 7.

Input: n = 10, minProfit = 5, group = [2,3,5], profit = [6,7,8]
Output: 7
Explanation: To make a profit of at least 5 with total member <= 10,
There are 7 possible schemes: (0), (1), (2), (0,1), (0,2), (1,2), and (0,1,2).
(basically all combination is fine)

```

</details>

------------------------------------------------------------------------------

## [:persevere: 494. Target Sum](https://leetcode.com/problems/target-sum/) / [:man_technologist:](target_sum_bottom_up.h)

- check [below for full description](#bulb-494-target-sum-dart) ... overall dfs solution is much more straightforward
- bottom up solution is much faster and is basically a 0/1 knapsack, but need a conversion for the problem

------------------------------------------------------------------------------
