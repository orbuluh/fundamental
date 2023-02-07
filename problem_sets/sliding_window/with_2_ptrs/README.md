# Sliding window with 2 pointers

- All the below questions using the same "template" of substring window
- The idea is that you keep a window containing valid substring with 2 ptrs
  - you keep expand the right pointer till you find the first window
  - then you try to make the window invalid again through shrinking the left pointer
- TODOs: 3. Longest Substring Without Repeating Characters
- TODOs: 30. Substring with Concatenation of All Words

## [:bulb: 76. Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/) / [:man_technologist:](min_window_substr.h)

<details><summary markdown="span">Question</summary>

```markdown
Given two strings s and t of lengths m and n respectively,
return the minimum window substring of s such that every character in t
(including duplicates) is included in the window.

If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

Note: A substring is a contiguous sequence of characters within the string.

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 567. Permutation in String](https://leetcode.com/problems/permutation-in-string) / [:man_technologist:](permutation_in_string.h)

<details><summary markdown="span">Question</summary>

```markdown
Given two strings s1 and s2,
return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

                           vv
Input: s1 = "ab", s2 = "eidbaooo"
Output: true

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
```

</details>

------------------------------------------------------------------------------

## [:bulb: 904. Fruit Into Baskets](https://leetcode.com/problems/fruit-into-baskets) / [:man_technologist:](fruit_into_baskets.h)

<details><summary markdown="span">Question</summary>

```markdown
You are visiting a farm that has a single row of fruit trees arranged from
left to right. The trees are represented by an integer array fruits where
fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some
strict rules that you must follow:

- You only have two baskets, and
- each basket can only hold a single type of fruit.
- There is no limit on the amount of fruit each basket can hold.
- Starting from any tree of your choice, you must pick exactly one fruit from
  every tree (including the start tree) while moving to the right.
- The picked fruits must fit in one of your baskets.
- Once you reach a tree with fruit that cannot fit in your baskets, you must stop.

Given the integer array fruits, return the maximum number of fruits you can pick.

Input: fruits = [1,1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,1,2].
```

</details>

------------------------------------------------------------------------------

## [:bulb: 159. Longest Substring with At Most Two Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/) / [:man_technologist:](longest_substr_with_at_most_2_uniq.h)

<details><summary markdown="span">Question</summary>

```markdown
Given a string s, return the length of the longest substring that contains at most two distinct characters.

Input: s = "eceba"
Output: 3
Explanation: The substring is "ece" which its length is 3.

Input: s = "ccaabbb"
Output: 5
Explanation: The substring is "aabbb" which its length is 5.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 438. Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/) / [:man_technologist:](find_all_anagram.h)

<details><summary markdown="span">Question</summary>

```markdown
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]

Explanation:
- The substring with start index = 0 is "cba", which is an anagram of "abc".
- The substring with start index = 6 is "bac", which is an anagram of "abc".

Input: s = "abab", p = "ab"
Output: [0,1,2]
- The substring with start index = 0 is "ab", which is an anagram of "ab".
- The substring with start index = 1 is "ba", which is an anagram of "ab".
- The substring with start index = 2 is "ab", which is an anagram of "ab".
```

</details>

------------------------------------------------------------------------------