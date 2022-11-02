# String match with DP

```markdown
- A common trait is building a 2-D DP matrix and think from the back of 2 strings.
- e.g. DP represents subproblem to handle `s1[i:]` v.s. `s2[j:]`
- The base case is often time when (either one/both) string is empty.
```

------------------------------------------------------------------------------

## [:bulb: 72. Edit Distance](https://leetcode.com/problems/edit-distance/) [:dart:](edit_distance.h)

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

