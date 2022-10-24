# 2 pointers

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

- The below question are all using the same "template" of substring window
- The idea is that you keep a window containing valid substring with 2 ptrs
  - you keep expand the right pointer till you find the first window
  - then you try to make the window invalid again through shrinking the left pointer

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
