# Subsequence

```markdown
- (Might need more observations, but) a common trait seem to be that longer
  subsequence can be built up from shorter subsequence.
- So the subproblem is actually trying to deal with a shorter one, then try to
  find the recurrence relation
- check 647. Palindromic Substrings below - this could be the basic idea of all
  these problems
```

------------------------------------------------------------------------------

## [:bulb: 647. Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/) [:dart:](palindromic_substring.h)

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

------------------------------------------------------------------------------