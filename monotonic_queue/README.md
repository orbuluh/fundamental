# Monotonic Queue [:notebook:](../notes/README.md#monotonic-queue)
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

## [:bulb: 1696. Jump Game VI](https://leetcode.com/problems/jump-game-vi/) [:dart:](jump_game_vi.h)
- a dp problem but the core is actually monotonic Queue.
- core is the same as [239. Sliding Window Maximum](#bulb-239-sliding-window-maximum-dart)
<details><summary markdown="span">Question</summary>

```markdown
You are given a 0-indexed integer array nums and an integer k.
    - You are initially standing at index 0.
    - In one move, you can jump at most k steps forward (inclusive)
      without going outside the boundaries of the array.
You want to reach the last index of the array (index n - 1).
Your score is the sum of all nums[j] for each index j you visited in the array.

Return the maximum score you can get.

Example:
Input: nums = [1,-1,-2,4,-7,3], k = 2
               ^  ^    ^    ^
Output: 7
Explanation: You can choose your jumps with [1,-1,4,3] (^ above). The sum is 7.
```
</details>
