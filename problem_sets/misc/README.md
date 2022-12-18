# Misc: some great algo to do something

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

------------------------------------------------------------------------------

## [:ok_hand: 334. Increasing Triplet Subsequence](https://leetcode.com/problems/increasing-triplet-subsequence/) [:dart:](inc_triplet_subseq.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an integer array nums
return true if there exists a triple of indices (i, j, k) such that
- i < j < k and
- nums[i] < nums[j] < nums[k].

If no such indices exists, return false.
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 249. Group Shifted Strings](https://leetcode.com/problems/group-shifted-strings/) [:dart:](group_shifted_strings.h)

- asked in peer mock, how to hash the input is actually easy but you complicated it...

<details><summary markdown="span">Question</summary>

```markdown
We can shift a string by shifting each of its letters to its successive letter.
- For example, "abc" can be shifted to be "bcd" and "za" could shift to "ab"

We can keep shifting the string to form a sequence.
- For example, we can keep shifting "abc" to form the sequence: "abc" -> "bcd" -> ... -> "xyz".

Given an array of strings strings, group all strings[i] that belong to the same shifting sequence.
You may return the answer in any order.

Input: strings = ["abc","bcd","acef","xyz","az","ba","a","z"]
Output: [["acef"],["a","z"],["abc","bcd","xyz"],["az","ba"]]
```

</details>

------------------------------------------------------------------------------

## [:bulb: 189. Rotate Array](https://leetcode.com/problems/rotate-array/) [:dart:](rotate_array.h)
<details><summary markdown="span">Question</summary>

- "How to rotate 1" is actually interesting than you think ... give it a try!

```markdown
Given an array, rotate the array to the right by k steps, where k is non-negative.

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
```

</details>

------------------------------------------------------------------------------

## [:bulb: 833. Find And Replace in String](https://leetcode.com/problems/find-and-replace-in-string/) [:dart:](find_and_replace_in_string.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given a 0-indexed string s that you must perform k replacement
operations on. The replacement operations are given as three 0-indexed parallel
arrays, all of length k:
- indices
- sources
- targets

To complete the ith replacement operation:

- Check if the substring sources[i] occurs at index indices[i] in the original
string s. If it does not occur, do nothing. Otherwise if it does occur, replace
that substring with targets[i].

For example, if
- s = "abcd", indices[i] = 0, sources[i] = "ab", and targets[i] = "eee",
- then the result of this replacement will be "eeecd".

All replacement operations must occur simultaneously, meaning the replacement
operations should not affect the indexing of each other.

The testcases will be generated such that the replacements will not overlap.

For example, a test-case with s = "abc", indices = [0, 1], and
sources = ["ab","bc"] will not be generated because the "ab" and "bc"
replacements overlap. Return the resulting string after performing all
replacement operations on s.

A substring is a contiguous sequence of characters in a string.
</details>

------------------------------------------------------------------------------

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

------------------------------------------------------------------------------

## [:dizzy_face: 856. Score of Parentheses](https://leetcode.com/problems/score-of-parentheses/) [:dart:](score_of_parentheses.h)

- the more intuitive way to do this ... though also not as easy as you think ... [stack solution](score_of_parentheses_stack_sol.h)

<details><summary markdown="span">Question</summary>

```markdown
Given a balanced parentheses string s, return the score of the string.

The score of a balanced parentheses string is based on the following rule:

- "()" has score 1.
- AB has score A + B, where A and B are balanced parentheses strings.
- (A) has score 2 * A, where A is a balanced parentheses string.

Input: s = "(())"
Output: 2

Input: s = "()()"
Output: 2
```

</details>

------------------------------------------------------------------------------

## Nice implementation idea

## [:ok_hand: 12. Integer to Roman](https://leetcode.com/problems/integer-to-roman/) [:dart:](integer_to_roman.h)

<details><summary markdown="span">Question</summary>

```markdown
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example,
- 2 is written as II in Roman numeral, just two one's added together.
- 12 is written as XII, which is simply X + II.
- he number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right.
However, the numeral for four is not IIII. Instead, the number four is written as IV.
Because the one is before the five we subtract it making four.
The same principle applies to the number nine, which is written as IX.
There are six instances where subtraction is used:

- I can be placed before V (5) and X (10) to make 4 and 9.
- X can be placed before L (50) and C (100) to make 40 and 90.
- C can be placed before D (500) and M (1000) to make 400 and 900.

Given an integer, convert it to a roman numeral.
```

</details>

------------------------------------------------------------------------------

## Hard indices manipulation

## [:bulb: 48. Rotate Image](https://leetcode.com/problems/rotate-image/) [:dart:](rotate_image.h)

- TODO: dig in optimal solution [here](rotate_image_optimal.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given an n x n 2D matrix representing an image,
rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input
2D matrix directly.

DO NOT allocate another 2D matrix and do the rotation.

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
```

</details>

------------------------------------------------------------------------------

## [:persevere: 835. Image Overlap](https://leetcode.com/problems/image-overlap/) [:dart:](image_overlap.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given two images, img1 and img2,
- represented as binary, square matrices of size n x n.
- A binary matrix has only 0s and 1s as values.

We translate one image however we choose by
- sliding all the 1 bits left, right, up, and/or down any number of units.

We then place it on top of the other image.

We can then calculate the overlap by counting the number of positions that have
a 1 in both images.

Note also that a translation does not include any kind of rotation.

Any 1 bits that are translated outside of the matrix borders are erased.
Return the largest possible overlap.

Input: img1 = [[1,1,0],[0,1,0],[0,1,0]], img2 = [[0,0,0],[0,1,1],[0,0,1]]
Output: 3
Explanation: making a right shift then down shift of img1 - it becomes
[[0,0,0],[0,1,1],[0,0,1]], which has 3 overlap with img2
```

</details>

------------------------------------------------------------------------------

## Brainteaser

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

</details>

------------------------------------------------------------------------------

## [:dizzy_face: 932. Beautiful Array](https://leetcode.com/problems/beautiful-array/) [:dart:](beautiful_array.h)

- or math/divide conquer? It's ridiculous to find such solution ...

<details><summary markdown="span">Question</summary>

```markdown
An array nums of length n is beautiful if:

nums is a permutation of the integers in the range [1, n].

- For every 0 <= i < j < n, there is no index k with i < k < j
  where `2 * nums[k] == nums[i] + nums[j]`.

Given the integer n, return any beautiful array nums of length n.
There will be at least one valid answer for the given n.

Input: n = 4
Output: [2,1,4,3]

Input: n = 5
Output: [3,1,2,5,4]

Input: n = 6
Output: [1,5,3,2,6,4]
```

</details>

------------------------------------------------------------------------------
