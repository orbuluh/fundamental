# 2 pointers

## [:ok_hand: 946. Validate Stack Sequences](https://leetcode.com/problems/validate-stack-sequences) / [:man_technologist:](validate_stk_seq.h) [:snake:](validate_stk_seq.py)

<details><summary markdown="span">Question</summary>

```markdown
Given two integer arrays pushed and popped each with distinct values, return
true if this could have been the result of a sequence of push and pop operations
on an initially empty stack, or false otherwise.

Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true

Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 2390. Removing Stars From a String](https://leetcode.com/problems/removing-stars-from-a-string) / [:man_technologist:](remvoe_star_from_strings.h) [:snake:](remvoe_star_from_strings.py)

<details><summary markdown="span">Question</summary>

```markdown
You are given a string s, which contains stars *.

In one operation, you can:

Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.

Note:

The input will be generated such that the operation is always possible.
It can be shown that the resulting string will always be unique.

Input: s = "erase*****"
Output: ""
Explanation: The entire string is removed, so we return an empty string.
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 1047. Remove All Adjacent Duplicates In String](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/) / [:man_technologist:](remove_all_adjacent_duplicates.h) [:snake:](remove_all_adjacent_duplicates.py)

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

## [:ok_hand: 151. Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/) / [:man_technologist:](reverse_words_in_a_string.h) [:snake:](reverse_words_in_a_string.py)

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

## [:bulb: 16. 3Sum Closest](https://leetcode.com/problems/3sum-closest/) / [:man_technologist:](3sum_closest.h) [:snake:](3sum_closest.py)

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

## [:bulb: 1498. Number of Subsequences That Satisfy the Given Sum Condition](https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/) / [:man_technologist:](num_of_subseq_satisfy_sum_condition.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that the sum of the
minimum and maximum element on it is less or equal to target.

Since the answer may be too large, return it modulo 1e9 + 7

Input: nums = [3,5,6,7], target = 9
Output: 4
Explanation: There are 4 subsequences that satisfy the condition.
[3] -> Min value + max value <= target (3 + 3 <= 9)
[3,5] -> (3 + 5 <= 9)
[3,5,6] -> (3 + 6 <= 9)
[3,6] -> (3 + 6 <= 9)
```

</details>

------------------------------------------------------------------------------

## [:bulb: 11. Container With Most Water](https://leetcode.com/problems/container-with-most-water/) / [:man_technologist:](container_with_most_water.h)

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

## [:bulb: 1295. Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/) / [:man_technologist:](median_from_stream.h)

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

## [:bulb: 209. Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum) / [:man_technologist:](min_sz_subarray_sum.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
```

</details>

------------------------------------------------------------------------------

## [:persevere: 777. Swap Adjacent in LR String](https://leetcode.com/problems/swap-adjacent-in-lr-string/) / [:man_technologist:](swap_adj_in_lr_string.h)

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

## [:persevere: 838. Push Dominoes](https://leetcode.com/problems/push-dominoes/) / [:man_technologist:](push_dominoes.h)

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

## Subarray sliding window algorithm

- check [here](../sliding_window/with_2_ptrs/README.md)

------------------------------------------------------------------------------

## Circular sort

- check [here](../sorting/README.md#circular-sort)

------------------------------------------------------------------------------

## Quick select

- check [here](../sorting/README.md#quick-select)

------------------------------------------------------------------------------
