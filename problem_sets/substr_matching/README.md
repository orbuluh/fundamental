# Substring matching algorithm

- LMP notes [:point_right: here](https://js-notes.vercel.app/software_engineering/ds_and_algos/kmp)
- Rolling hash notes [:point_right: here](https://js-notes.vercel.app/software_engineering/ds_and_algos/rolling_hash)

## [:bulb: 28. Find the Index of the First Occurrence in a String](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string) / [:man_technologist:](find_first_occurrence_in_string.h)

<details><summary markdown="span">Question</summary>

```markdown
Given two strings needle and haystack, return the index of the first occurrence
of needle in haystack, or -1 if needle is not part of haystack.

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 718. Maximum Length of Repeated Subarray](https://leetcode.com/problems/maximum-length-of-repeated-subarray/) / [:man_technologist:](max_len_of_repeated_subarray.h)

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

## Sliding window of Substring

- check [here](../2_ptrs/README.md#substring-window-algorithm)
