# DP: Subsequence

```markdown
- (Might need more observations, but) a common trait seem to be that longer
  subsequence can be built up from shorter subsequence.
- So the subproblem is actually trying to deal with a shorter one, then try to
  find the recurrence relation
- check 647. Palindromic Substrings below - this could be the basic idea of all
  these problems
```

> "rule of thumb" is that we should search for O(n) solution if we are dealing
with consecutive sequences, and O(n ^ 2) if we are dealing with subsequences" - @votrubac

------------------------------------------------------------------------------

## [:bulb: 1143. Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/) / [:man_technologist:](longest_common_subseq.h)

<details><summary markdown="span">Question</summary>

```markdown
Given two strings s1 and s2,
return the length of their longest common subsequence.

If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string
with some characters (can be none) deleted without changing the relative order
of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Input: s1 = "abcde", s2 = "ace"
Output: 3
Explanation: The longest common subsequence is "ace" and its length is 3.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 1964. Find the Longest Valid Obstacle Course at Each Position](https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position) / [:man_technologist:](find_longest_valid_obstacle_at_each_pos.h)

<details><summary markdown="span">Question</summary>

```markdown
You want to build some obstacle courses.

- You are given a 0-indexed integer array obstacles of length n, where
  obstacles[i] describes the height of the ith obstacle.

- For every index i between 0 and n - 1 (inclusive), find the length of the
  longest obstacle course in obstacles such that:

  - You choose any number of obstacles between 0 and i inclusive.
  - You must include the ith obstacle in the course.
  - You must put the chosen obstacles in the same order as they appear in
    obstacles.
  - Every obstacle (except the first) is taller than or the same height as the obstacle immediately before it.

Return an array ans of length n, where ans[i] is the length of the longest
obstacle course for index i as described above.

Input: obstacles = [1,2,3,2]
Output: [1,2,3,3]
Explanation: The longest valid obstacle course at each position is:
- i = 0: [1], [1] has length 1.
- i = 1: [1,2], [1,2] has length 2.
- i = 2: [1,2,3], [1,2,3] has length 3.
- i = 3: [1,2,3,2], [1,2,2] has length 3.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 647. Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/) / [:man_technologist:](palindromic_substring.h)

- check out [516. Longest Palindromic Subsequence](#bulb-516-longest-palindromic-subsequence-dart), a really nice variation upon this one.

<details><summary markdown="span">Question</summary>

```markdown
Given a string s, return the number of palindromic substrings in it.
- A string is a palindrome when it reads the same backward as forward.
- A substring is a contiguous sequence of characters within the string.

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
```

</details>

------------------------------------------------------------------------------

## [:bulb: 516. Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/) / [:man_technologist:](longest_palindromic_subseq.h)

- beautiful extension from [647. Palindromic Substrings](#bulb-647-palindromic-substrings-dart)

<details><summary markdown="span">Question</summary>

```markdown
Given a string s, find the longest palindromic subsequence's length in s.

- A subsequence is a sequence that can be derived from another sequence by
  deleting some or no elements without changing the order of the remaining
  elements.

Input: s = "bbbab"
Output: 4

Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2

Explanation: One possible longest palindromic subsequence is "bb".
```

</details>

------------------------------------------------------------------------------

## [:bulb: 300. Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/) / [:man_technologist:](longest_increasing_subseq.h)

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

------------------------------------------------------------------------------

## [:bulb: 1626. Best Team With No Conflicts](https://leetcode.com/problems/best-team-with-no-conflicts) / [:man_technologist:](best_team_with_no_conflict.h)

- Really nice variation of LIS problem!

<details><summary markdown="span">Question</summary>

```markdown
You are the manager of a basketball team.

For the upcoming tournament, you want to choose the team with the highest overall score.
The score of the team is the sum of scores of all the players in the team.

However, the basketball team is not allowed to have conflicts.

A conflict exists if
- a younger player has a strictly higher score than an older player.
A conflict does not occur between players of the same age.

Given two lists, scores and ages, where each scores[i] and ages[i] represents
the score and age of the ith player, respectively, return the highest overall
score of all possible basketball teams.

Input: scores = [4,5,6,5], ages = [2,1,2,1]
Output: 16
Explanation: It is best to choose the last 3 players.
Notice that you are allowed to choose multiple people of the same age.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 1130. Minimum Cost Tree From Leaf Values](https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/) / [:man_technologist:](min_cost_tree_from_leaf_values_dp.h)

- DP solution is actually almost pure brute force solution... the actual O(n) sol and problem statement is [here](../../monotonic/README.md#🤯-1130-minimum-cost-tree-from-leaf-values-🎯)

------------------------------------------------------------------------------