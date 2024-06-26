# DP: Subarray (contiguous, Kadane's Algorithm)

> "rule of thumb" is that we should search for O(n) solution if we are dealing
with consecutive sequences, and O(n ^ 2) if we are dealing with subsequences" - @votrubac

## [:ok_hand: 53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) / [:man_technologist:](max_subarray.h) [:snake:](max_subarray.py)

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

## [:bulb: 918. Maximum Sum Circular Subarray](https://leetcode.com/problems/maximum-sum-circular-subarray) / [:man_technologist:](max_circle_subarray.h) [:snake:](max_circle_subarray.py)

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

## [:bulb: 1186. Maximum Subarray Sum with One Deletion](https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion) / [:snake:](max_subarray_sum_with_one_deletion.py)

<details><summary markdown="span">Question</summary>

```markdown
Given an array of integers,
return the maximum sum for a non-empty subarray (contiguous elements) with at most one element deletion.

In other words, you want to choose a subarray and optionally delete one element from it so that there is still at least one element left and the sum of the remaining elements is maximum possible.

Note that the subarray needs to be non-empty after deleting one element.


Example 1:

Input: arr = [1,-2,0,3]

- Output: 4
- Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the subarray [1, 0, 3] becomes the maximum value.

Example 2:

Input: arr = [1,-2,-2,3]

- Output: 3
- Explanation: We just choose [3] and it's the maximum sum.

Example 3:

Input: arr = [-1,-1,-1,-1]

- Output: -1
- Explanation: The final subarray needs to be non-empty. You can't choose [-1] and delete -1 from it, then get an empty subarray to make the sum equals to 0.
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

## [:bulb: 1048. Longest String Chain](https://leetcode.com/problems/longest-string-chain) / [:snake:](longest_string_chain.py)

<details><summary markdown="span">Question</summary>

```markdown
You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".

A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]

- Output: 4
- Explanation: One of the longest word chains is ["a","ba","bda","bdca"].

Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]

- Output: 5
- Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].

Example 3:

Input: words = ["abcd","dbqca"]

- Output: 1
- Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
- ["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
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
