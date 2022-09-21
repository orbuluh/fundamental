# Substring matching algorithm
- [KMP :point_right: here](../notes/kmp.md)
- [Rolling hash :point_right: here](../notes/rolling_hash.md)

## [:bulb: 718. Maximum Length of Repeated Subarray](https://leetcode.com/problems/maximum-length-of-repeated-subarray/) [:dart:](max_len_of_repeated_subarray.h)
- dp solution with worse complexity than KMP [:point_right: here](../dp/max_len_of_repeated_subarray_dp.h)
- rolling hash solution [:point_right: here](max_len_of_repeated_subarray_rollinghash.h)

<details><summary markdown="span">Question</summary>

```markdown
Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

Example 1:
Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].

Example 2:
Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5
```
</details>

------------------------------------------------------------------------------