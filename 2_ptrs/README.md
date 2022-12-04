# 2 pointers

## [:ok_hand: 1047. Remove All Adjacent Duplicates In String](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/) [:dart:](remove_all_adjacent_duplicates.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given a string s consisting of lowercase English letters.
A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made.
It can be proven that the answer is unique.

Input: s = "abbaca"
Output: "ca"

Input: s = "azxxxzy"
Output: "azxzy"
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 151. Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/) [:dart:](reverse_words_in_a_string.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters.
The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
```

</details>

------------------------------------------------------------------------------


## [:bulb: 16. 3Sum Closest](https://leetcode.com/problems/3sum-closest/) [:dart:](3sum_closest.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an integer array nums of length n and an integer target,
find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.
You may assume that each input would have exactly one solution.

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
```

</details>

------------------------------------------------------------------------------

## [:bulb: 11. Container With Most Water](https://leetcode.com/problems/container-with-most-water/) [:dart:](container_with_most_water.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given an integer array height of length n.
Find two lines that together with the x-axis form a container,
such that the container contains the most water.

Return the maximum amount of water a container can store.
Notice that you may not slant the container.

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49

[1,8,6,2,5,4,8,3,7]
   ^_____________^  yields 7 * 7 = 49, which is the maxArea
```

</details>

------------------------------------------------------------------------------

## [:bulb::bulb: 777. Swap Adjacent in LR String](https://leetcode.com/problems/swap-adjacent-in-lr-string/) [:dart:](swap_adj_in_lr_string.h)

<details><summary markdown="span">Question</summary>

```markdown
In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL"

a move consists of either
- replacing one occurrence of "XL" with "LX", or
- replacing one occurrence of "RX" with "XR".

Given the starting string start and the ending string end,
return True if and only if there exists a sequence of moves to
transform start to end.

(Note: LX in start can't transform to XL in end, only XL in start can
 transform to LX in end!)


Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
Output: true
Explanation: We can transform start to end following these steps:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX

```

</details>
------------------------------------------------------------------------------

## [:bulb::bulb: 838. Push Dominoes](https://leetcode.com/problems/push-dominoes/) [:dart:](push_dominoes.h)

<details><summary markdown="span">Question</summary>

```markdown
There are n dominoes in a line
- dominoes[i] = 'L', if the ith domino has fallen to the left,
- dominoes[i] = 'R', if the ith domino has fallen to the right, and
- dominoes[i] = '.', if the ith domino has not been pushed.

- After each second, each domino that is falling to the left pushes the adjacent domino on the left.
- Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.
- When a non-fallen domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.
- For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

Return a string representing the final state.

Input: dominoes = ".L.R...LR..L.."
Output:           "LL.RR.LLRRLL.."

```

</details>

------------------------------------------------------------------------------

# Circular sort

- check [here](../sorting/README.md#circular-sort)

------------------------------------------------------------------------------

# Quick select

- check [here](../sorting/README.md#quick-select)

------------------------------------------------------------------------------

# Substring window algorithm

- All the below questions using the same "template" of substring window
- The idea is that you keep a window containing valid substring with 2 ptrs
  - you keep expand the right pointer till you find the first window
  - then you try to make the window invalid again through shrinking the left pointer
- TODOs: 3. Longest Substring Without Repeating Characters
- TODOs: 30. Substring with Concatenation of All Words

## [:bulb: 76. Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/) [:dart:](min_window_substr.h)

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

## [:bulb: 159. Longest Substring with At Most Two Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/) [:dart:](longest_substr_with_at_most_2_uniq.h)

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

## [:bulb: 438. Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/) [:dart:](find_all_anagram.h)

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

## [:bulb: 1295. Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/) [:dart:](median_from_stream.h)

<details><summary markdown="span">Question</summary>

```markdown
The median is the middle value in an ordered integer list.

If the size of the list is even, there is no middle value,
and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num)
- adds the integer num from the data stream to the data structure.
double findMedian()
- returns the median of all elements so far.

Answers within 10-5 of the actual answer will be accepted.
```

</details>

------------------------------------------------------------------------------