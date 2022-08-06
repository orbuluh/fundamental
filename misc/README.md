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

# Brainteaser

## [:bulb: 458. Poor Pigs](https://leetcode.com/problems/poor-pigs) [:dart:](pool_pigs.h)
<details><summary markdown="span">Question</summary>

```markdown
There are buckets buckets of liquid, where exactly one of the buckets is poisonous.
To figure out which one is poisonous,
you feed some number of (poor) pigs the liquid to see whether they will die or not.

Unfortunately, you only have minutesToTest minutes to determine which bucket is poisonous.

You can feed the pigs according to these steps:

- Choose some live pigs to feed.
- One pig can drink several buckets in each test round simultaneously and will take no time.
- Several pigs can drink the same buckets in each test round.
- Wait for minutesToDie minutes. You may not feed any other pigs during this time.
- After minutesToDie minutes have passed, any pigs that have been fed the poisonous bucket will die, and all others will survive.
- Repeat this process until you run out of time.

Given buckets, minutesToDie, and minutesToTest,
return the minimum number of pigs needed to figure out which bucket is poisonous within the allotted time.

Input: buckets = 4, minutesToDie = 15, minutesToTest = 15
Output: 2

Input: buckets = 4, minutesToDie = 15, minutesToTest = 30
Output: 2
```
