# Range Query

## Prefix sum

## [:ok_hand: 560. Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) / [:man_technologist:](range_sum_equal_to_k.h)

- The basic question, but has certain details...
- Check [363. Max Sum of Rectangle No Larger Than K](../dp/README.md#bulb-363-max-sum-of-rectangle-no-larger-than-khttpsleetcodecomproblemsmax-sum-of-rectangle-no-larger-than-k-dartmaxsumofrectanglelekh)


<details><summary markdown="span">Question</summary>

```markdown
Given an array of integers nums and an integer k,
return the total number of subarrays whose sum equals to k.

Input: nums = [1,2,3], k = 3
Output: 2
- e.g. [1, 2], [3]
```
</details>

------------------------------------------------------------------------------

## [:bulb: 523. Continuous Subarray Sum](https://leetcode.com/problems/continuous-subarray-sum/) / [:man_technologist:](continuous_subarray_sum.h)
- Actually a twist of prefix sum ... quite clever..

<details><summary markdown="span">Question</summary>

```markdown
Given an integer array nums and an integer k, return true if nums has a
continuous subarray of size at least two whose elements sum up to a multiple of
k, or false otherwise.


Input: nums = [23,2,6,4,7], k = 6
Output: true

Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
```
</details>

------------------------------------------------------------------------------

## [:bulb: 1664. Ways to Make a Fair Array](https://leetcode.com/problems/ways-to-make-a-fair-array) / [:man_technologist:](ways_to_make_fair_array.h)

- @lee215's way to make it O(1) space is :exploding_head:

<details><summary markdown="span">Question</summary>

```markdown
ou are given an integer array nums. You can choose exactly one index (0-indexed) and remove the element. Notice that the index of the elements may change after the removal.

For example, if nums = [6,1,7,4,1]:

Choosing to remove index 1 results in nums = [6,7,4,1].
Choosing to remove index 2 results in nums = [6,1,4,1].
Choosing to remove index 4 results in nums = [6,1,7,4].
An array is fair if the sum of the odd-indexed values equals the sum of the even-indexed values.

Return the number of indices that you could choose such that after the removal, nums is fair.

Input: nums = [2,1,6,4]
Output: 1
Explanation:
Remove index 0: [1,6,4] -> Even sum: 1 + 4 = 5. Odd sum: 6. Not fair.
Remove index 1: [2,6,4] -> Even sum: 2 + 4 = 6. Odd sum: 6. Fair.
Remove index 2: [2,1,4] -> Even sum: 2 + 4 = 6. Odd sum: 1. Not fair.
Remove index 3: [2,1,6] -> Even sum: 2 + 6 = 8. Odd sum: 1. Not fair.
There is 1 index that you can remove to make nums fair.
```
</details>

------------------------------------------------------------------------------

## The jump line method
- Suitable when the range is constrained!

## [:bulb: 2158. Amount of New Area Painted Each Day](https://leetcode.com/problems/amount-of-new-area-painted-each-day/) / [:man_technologist:](amt_of_new_area_painted.h)
- the segment tree implementation check [here](segment_tree//amt_of_new_area_painted_segment_tree.h)

<details><summary markdown="span">Question</summary>

```markdown
There is a long and thin painting that can be represented by a number line.
You are given a 0-indexed 2D integer array paint of length n, where paint[i] = [starti, endi].
- This means that on the ith day you need to paint the area between starti and endi.

- Painting the same area multiple times will create an uneven painting so you only
  want to paint each area of the painting at most once.

Return an integer array worklog of length n, where worklog[i] is the amount of
new area that you painted on the ith day.

Input: paint = [[1,4],[4,7],[5,8]]
Output: [3,3,1]
Explanation:
- On day 0, paint everything between 1 and 4. The amount of new area painted on day 0 is 4 - 1 = 3.
- On day 1, paint everything between 4 and 7. The amount of new area painted on day 1 is 7 - 4 = 3.
- On day 2, paint everything between 7 and 8. Everything between 5 and 7 was already painted on day 1.
  The amount of new area painted on day 2 is 8 - 7 = 1.
```
</details>

------------------------------------------------------------------------------

- [Segment tree](segment_tree/README.md)

- [Binary indexed tree](binary_indexed_tree/README.md)