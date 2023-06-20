# Fixed size sliding window

## [:ok_hand: 2090. K Radius Subarray Averages](https://leetcode.com/problems/k-radius-subarray-averages) / [:man_technologist:](k_radius_subarray_ave.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given a 0-indexed array nums of n integers, and an integer k.

The k-radius average for a subarray of nums centered at some index i with the
radius k is the average of all elements in nums between the indices i - k and
i + k (inclusive). If there are less than k elements before or after the index i
, then the k-radius average is -1.

Build and return an array avgs of length n where avgs[i] is the k-radius average
for the subarray centered at index i.

The average of x elements is the sum of the x elements divided by x, using
integer division. The integer division truncates toward zero, which means losing
its fractional part.

Input: nums = [7,4,3,9,1,8,5,2,6], k = 3
Output: [-1,-1,-1,5,4,4,-1,-1,-1]
Explanation:
- avg[0], avg[1], and avg[2] are -1 because there are less than k elements
  before each index.
- The sum of the subarray centered at index 3 with radius 3 is:
  7 + 4 + 3 + 9 + 1 + 8 + 5 = 37.
  Using integer division, avg[3] = 37 / 7 = 5.
- For the subarray centered at index 4,
  avg[4] = (4 + 3 + 9 + 1 + 8 + 5 + 2) / 7 = 4.
- For the subarray centered at index 5,
  avg[5] = (3 + 9 + 1 + 8 + 5 + 2 + 6) / 7 = 4.
- avg[6], avg[7], and avg[8] are -1 because there are less than k elements after
  each index.
```

</details>

------------------------------------------------------------------------------

- highly related to [:point_right: Monotonic Queue](../monotonic/README.md)

## [:bulb: 1423. Maximum Points You Can Obtain from Cards](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/) / [:man_technologist:](max_pts_from_cards.h)

<details><summary markdown="span">Question</summary>

```markdown
There are several cards arranged in a row, and each card has an associated number of points.
The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row.
You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.
Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

Example
Input: cardPoints = [1,2,3,4,5,6,1], k = 3

Output: 12
Explanation:
- After the first step, your score will always be 1.
- However, choosing the rightmost card first will maximize your total score.
- The optimal strategy is to take the three cards on the right,
  giving a final score of 1 + 6 + 5 = 12.
```

</details>

------------------------------------------------------------------------------

## [:persevere: 30. Substring with Concatenation of All Words](https://leetcode.com/problems/substring-with-concatenation-of-all-words/) / [:man_technologist:](substr_with_concat_of_all.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given a string s and an array of strings words of the same length.
Return all starting indices of substring(s) in s that is a concatenation of each
word in words exactly once, in any order, and without any intervening characters.

You can return the answer in any order.
Input: s = "barfoothefoobarman", words = ["foo","bar"]
            0  3  6  9
Output: [0,9]

Input: s = "aaaaa", words = ["a","a"]
            0123
Output: [0,1,2,3]
```

</details>

------------------------------------------------------------------------------
