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

## [:bulb: 1130. Minimum Cost Tree From Leaf Values](https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/) / [:man_technologist:](min_cost_tree_from_leaf_values_dp.h)

- DP solution is actually almost pure brute force solution... the actual O(n) sol and problem statement is [here](../../monotonic/README.md#🤯-1130-minimum-cost-tree-from-leaf-values-🎯)

------------------------------------------------------------------------------