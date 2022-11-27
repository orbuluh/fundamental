# Subarray (contiguous, Kadane's Algorithm)

> "rule of thumb" is that we should search for O(n) solution if we are dealing
with consecutive sequences, and O(n ^ 2) if we are dealing with subsequences" - @votrubac

## [:ok_hand: 53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) [:dart:](max_subarray.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an integer array nums,
find the contiguous subarray (containing at least one number)
which has the largest sum and return its sum.

A subarray is a **contiguous** part of an array.
Input: nums = [5,4,-1,7,8]
Output: 23
```

</details>

------------------------------------------------------------------------------

## [:bulb: 363. Max Sum of Rectangle No Larger Than K](https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/) [:dart:](max_sum_of_rectangle_le_k.h)

- if you forget Kadane's algorithm ... check [Maximum Subarray](#ok_hand-53-maximum-subarray-dart)
- Easier preliminary question of this one: [560. Subarray Sum Equals K](../range_query/README.md#okhand-560-subarray-sum-equals-khttpsleetcodecomproblemssubarray-sum-equals-k-dartrangesumequaltokh)

<details><summary markdown="span">Question</summary>

```markdown
Given an integer array nums,
find the contiguous subarray (containing at least one number)
which has the largest sum and return its sum.

A subarray is a **contiguous** part of an array.
Input: nums = [5,4,-1,7,8]
Output: 23
```

</details>

------------------------------------------------------------------------------

## [:exploding_head: 2272. Substring With Largest Variance](https://leetcode.com/problems/substring-with-largest-variance/) [:dart:](substring_w_largest_variance.h)

- if you forget Kadane's algorithm ... check [Maximum Subarray](#ok_hand-53-maximum-subarray-dart)

<details><summary markdown="span">Question</summary>

```markdown
The variance of a string is defined as
- the largest difference between the number of occurrences of any 2 characters present in the string.
- Note the two characters may or may not be the same.
- Given a string s consisting of lowercase English letters only,
  return the largest variance possible among all substrings of s.
- A substring is a contiguous sequence of characters within a string.

Input: s = "aababbb"
Output: 3
Explanation: "babbb"

Input: s = "abcde"
Output: 0
Explanation:
No letter occurs more than once in s, so the variance of every substring is 0
```

</details>

------------------------------------------------------------------------------