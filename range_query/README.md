# Range Sum

## [:ok_hand: 560. Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) [:dart:](range_sum_equal_to_k.h)
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

# The jump line method
- Suitable when the range is constrained!

## [:bulb: 2158. Amount of New Area Painted Each Day](https://leetcode.com/problems/amount-of-new-area-painted-each-day/) [:dart:](amt_of_new_area_painted.h)

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


# Segment tree related
- check [:notebook:](segment_tree/README.md)

# Binary indexed tree related
- check [:notebook:](binary_indexed_tree/README.md)