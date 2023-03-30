# DP: String match

```markdown
- A common trait is building a 2-D DP matrix and think from the back of 2 strings.
- e.g. DP represents subproblem to handle `s1[i:]` v.s. `s2[j:]`
- The base case is often time when (either one/both) string is empty.
```

------------------------------------------------------------------------------

## [:bulb: 718. Maximum Length of Repeated Subarray](https://leetcode.com/problems/maximum-length-of-repeated-subarray/) / [:man_technologist:](max_len_of_repeated_subarray_dp.h)

- problem statement, a quicker way with rolling hash check [here](../../substr_matching/README.md#💡-718-maximum-length-of-repeated-subarray-🎯)

------------------------------------------------------------------------------

## [:bulb: 72. Edit Distance](https://leetcode.com/problems/edit-distance/) / [:man_technologist:](edit_distance.h)

<details><summary markdown="span">Question</summary>

```markdown
Given two strings word1 and word2, return the minimum number of operations
required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
```

</details>

------------------------------------------------------------------------------

## [:dizzy_face: 87. Scramble String](https://leetcode.com/problems/scramble-string) / [:man_technologist:](scramble_string.h)

<details><summary markdown="span">Question</summary>

```markdown
We can scramble a string s to get a string t using the following algorithm:

- If the length of the string is 1, stop.
- If the length of the string is > 1, do the following:
  - Split the string into two non-empty substrings at a random index,
    i.e., if the string is s, divide it to x and y where s = x + y.
  - Randomly decide to swap the two substrings or to keep them in the same order
    i.e., after this step, s may become s = x + y or s = y + x.
  - Apply step 1 recursively on each of the two substrings x and y.
- Given two strings s1 and s2 of the same length, return true if s2 is a
  scrambled string of s1, otherwise, return false.

Input: s1 = "great", s2 = "rgeat"
Output: true

Input: s1 = "abcde", s2 = "caebd"
Output: false
```

</details>

------------------------------------------------------------------------------