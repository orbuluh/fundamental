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

------------------------------------------------------------------------------

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

------------------------------------------------------------------------------

## [:bulb: 853. Car Fleet](https://leetcode.com/problems/car-fleet/) [:dart:](car_fleet.h)

```markdown
There are n cars going to the same destination along a one-lane road.
The destination is target miles away.

You are given two integer array position and speed, both of length n, where
- position[i] is the position of the ith car and
- speed[i] is the speed of the ith car (in miles per hour).

A car can never pass another car ahead of it,
but it can catch up to it and drive bumper to bumper at the same speed.

The faster car will slow down to match the slower car's speed.
The distance between these two cars is ignored
(i.e., they are assumed to have the same position).

A **car fleet** is
some non-empty set of cars driving at the same position and same speed.
- Note that a single car is also a car fleet.

If a car catches up to a car fleet right at the destination point, it will still
be considered as one car fleet.

Return the number of car fleets that will arrive at the destination.

Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
Output: 3
Explanation:
The cars starting at 10 (speed 2) and 8 (speed 4) become a fleet, meeting each other at 12.
The car starting at 0 does not catch up to any other car, so it is a fleet by itself.
The cars starting at 5 (speed 1) and 3 (speed 3) become a fleet, meeting each other at 6.
The fleet moves at speed 1 until it reaches target.
Note that no other cars meet these fleets before the destination, so the answer is 3.
```
</details>

------------------------------------------------------------------------------

