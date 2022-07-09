# Monotonic Queue [:notebook:](../basics/README.md#monotonic-queue)
- Subtopic of [Sliding window](../sliding_window/README.md)

## [:bulb: 239. Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum) [:dart:](sliding_window_maximum.h)
<details><summary markdown="span">Question</summary>

```markdown
You are given an array of integers nums,
- there is a sliding window of size k which is
- moving from the very left of the array to the very right.
- e.g. You can only see the k numbers in the window.
- Each time the sliding window moves right by one position.

Return the max value in the window in from left to right.

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

```
</details>

