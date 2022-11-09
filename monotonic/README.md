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

# Monotonic stack

------------------------------------------------------------------------------

## [:bulb: 901. Online Stock Span](https://leetcode.com/problems/online-stock-span/) [:dart:](online_stock_span.h)

<details><summary markdown="span">Question</summary>

```markdown
Design an algorithm that collects daily price quotes for some stock and returns
the span of that stock's price for the current day.

The span of the stock's price today is defined as the maximum number of
consecutive days (starting from today and going backward)
for which the stock price was less than or equal to today's price.

For example, if the price of a stock over the next 7 days were
[100,80,60,70,60,75,85], then the stock spans would be [1,1,1,2,1,4,6].

Implement the StockSpanner class:
- StockSpanner() Initializes the object of the class.
- int next(int price) Returns the span of the stock's price given that today's price is price.

Input
["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]
Output
[null, 1, 1, 1, 2, 1, 4, 6]

Explanation
StockSpanner stockSpanner = new StockSpanner();
stockSpanner.next(100); // return 1 (as nothing consecutive < 100)
stockSpanner.next(80);  // return 1 (as nothing consecutive < 80)
stockSpanner.next(60);  // return 1 (as nothing consecutive < 60)
stockSpanner.next(70);  // return 2 (as 60 < 70)
stockSpanner.next(60);  // return 1 (as nothing consecutive < 60)
stockSpanner.next(75);  // return 4, (the last 4 prices (including today's price
                        // of 75) were less than or equal to today's price.
stockSpanner.next(85);  // return 6 ... same reasoning

```

</details>

------------------------------------------------------------------------------

## [:bulb: 853. Car Fleet](https://leetcode.com/problems/car-fleet/) [:dart:](car_fleet.h)

<details><summary markdown="span">Question</summary>

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

## [:exploding_head: 1776. Car Fleet II](https://leetcode.com/problems/car-fleet/) [:dart:](car_fleet2.h)

<details><summary markdown="span">Question</summary>

```markdown
There are n cars traveling at different speeds in the same direction along a
one-lane road. You are given an array cars of length n, where

cars[i] = [positioni, speedi] represents:

positioni is the distance between the ith car and the beginning of the road in
meters. It is guaranteed that positioni < positioni+1.

speedi is the initial speed of the ith car in meters per second.

For simplicity, cars can be considered as points moving along the number line.
Two cars collide when they occupy the same position.
Once a car collides with another car, they unite and form a single car fleet.
The cars in the formed fleet will have the same position and the same speed,
which is the initial speed of the slowest car in the fleet.

Return an array answer, where answer[i] is the time, in seconds, at which the
ith car collides with the next car, or -1 if the car does not collide with the
next car. Answers within 10-5 of the actual answers are accepted.
```

</details>

------------------------------------------------------------------------------

## [:exploding_head: 1130. Minimum Cost Tree From Leaf Values](https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/) [:dart:](min_cost_tree_from_leaf_values.h)

- The "you thought good enough DP solution" is [here](../dp/dp_subseq/README.md#💡-1130-minimum-cost-tree-from-leaf-values-🎯)

<details><summary markdown="span">Question</summary>

```markdown
Given an array arr of positive integers, consider all binary trees such that:
- Each node has either 0 or 2 children;
- A node is a leaf if and only if it has zero children.
- The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
- The value of each non-leaf node is equal to
  the product of the largest leaf value in its left and right subtree, respectively.
- Among all possible binary trees considered, return the smallest possible sum
  of the values of each non-leaf node.

It is guaranteed this sum fits into a 32-bit integer.

Input: arr = [6,2,4]
Output: 32
Explanation: There are two possible trees:

    24                 24
  12  4       or      6  8
 6  2                   2  4

The first has a non-leaf node sum 12 + 24 = 36, and the second has non-leaf node
sum 8 + 24 = 32.
```

</details>

------------------------------------------------------------------------------
