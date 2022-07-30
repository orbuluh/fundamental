# Misc, some great idea

## [:ok_hand: 916. Word Subsets](https://leetcode.com/problems/word-subsets/) [:dart:](word_subsets.h)
<details><summary markdown="span">Question</summary>

```markdown
You are given two string arrays words1 and words2.
- A string b is a **subset** of string a if
  every letter in b occurs in a including multiplicity.
- For example, "wrr" is a subset of "warrior" but is not a subset of "world".

- A string a from words1 is **universal** if
  for every string b in words2, b is a subset of a.

- Return an array of all the universal strings in words1.
  You may return the answer in any order.
```
</details>


## [:bulb: 1209. Remove All Adjacent Duplicates in String II](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/) [:dart:](remove_adj_dups_ii.h)
<details><summary markdown="span">Question</summary>

```markdown
You are given a string s and an integer k,
- a k duplicate removal
    - consists of choosing k adjacent and equal letters from s and removing them
    - causing the left and the right side of the deleted substring to concatenate together.

- We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made.
It is guaranteed that the answer is unique.

Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation:
- First delete "eee" and "ccc", get "ddbbbdaa"
- Then delete "bbb", get "dddaa"
- Finally delete "ddd", get "aa"
```
</details>