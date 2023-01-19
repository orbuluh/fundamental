# DP: Subarray (contiguous, Kadane's Algorithm)

> "rule of thumb" is that we should search for O(n) solution if we are dealing
with consecutive sequences, and O(n ^ 2) if we are dealing with subsequences" - @votrubac

## [:ok_hand: 53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) / [:man_technologist:](max_subarray.h)

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

## [:bulb: 918. Maximum Sum Circular Subarray](https://leetcode.com/problems/maximum-sum-circular-subarray) / [:man_technologist:](max_circle_subarray.h)

<details><summary markdown="span">Question</summary>

```markdown
Given a circular integer array nums of length n,
return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the
array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the
previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once.

Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not
exist i <= k1, k2 <= j with k1 % n == k2 % n.

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.

Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 363. Max Sum of Rectangle No Larger Than K](https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/) / [:man_technologist:](max_sum_of_rectangle_le_k.h)

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

## [:bulb: 974. Subarray Sums Divisible by K](https://leetcode.com/problems/subarray-sums-divisible-by-k) / [:man_technologist:](subarray_sum_divisible_by_k.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an integer array nums and an integer k, return the number of non-empty
subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
```

</details>

------------------------------------------------------------------------------

## [:dizzy_face: 2272. Substring With Largest Variance](https://leetcode.com/problems/substring-with-largest-variance/) / [:man_technologist:](substring_w_largest_variance.h)

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