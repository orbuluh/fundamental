# Monotonic Stack/Queue

- [:notebook:](../../_notes/README.md#monotonic-queue)

------------------------------------------------------------------------------

## [:bulb: 739. Daily Temperatures](https://leetcode.com/problems/path-with-maximum-minimum-value) [:dart:](daily_temperatures_monostk.h)

- check problem description and better greedy solution [here](../greedy/README.md#🤔-739-daily-temperatures-🎯)

------------------------------------------------------------------------------

## [:bulb: 496. Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/) [:dart:](next_greater_element_i.h)

<details><summary markdown="span">Question</summary>

```markdown
The next greater element of some element x in an array is
- the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where
nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j]
and determine the next greater element of nums2[j] in nums2.

If there is no next greater element, then the answer for this query is -1.
Return an array ans of length nums1.length such that ans[i] is the next greater
element as described above.

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

```

</details>

------------------------------------------------------------------------------

## [:bulb: 503. Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii/) [:dart:](next_greater_element_ii.h)

<details><summary markdown="span">Question</summary>

```markdown
Given a circular integer array nums
- (i.e., the next element of nums[nums.length - 1] is nums[0]),
return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its
traversing-order next in the array, which means you could search circularly to
find its next greater number. If it doesn't exist, return -1 for this number.

Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2;
The number 2 can't find next greater number.
The second 1's next greater number needs to search circularly, which is also 2.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 556. Next Greater Element III](https://leetcode.com/problems/next-greater-element-iii/) [:dart:](next_greater_element_iii.h)

<details><summary markdown="span">Question</summary>

```markdown
Given a positive integer n, find the smallest integer which has exactly the
same digits existing in the integer n and is greater in value than n.

If no such positive integer exists, return -1.

Note that the returned integer should fit in 32-bit integer,
if there is a valid answer but it does not fit in 32-bit integer, return -1.

Input: n = 12
Output: 21

Input: n = 21
Output: -1

Input: n = 11
Output: -1
```

</details>

------------------------------------------------------------------------------

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

- a dp problem but the core is actually monotonic stack.
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

## [:bulb: 84. Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/) [:dart:](largest_retangle_in_histogram.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an array of integers heights representing the histogram's bar height where
the width of each bar is 1, return the area of the largest rectangle in the histogram.

Input: heights = [2,1,5,6,2,3]

Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is 5 * 2 = 10
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

## [:persevere: 2454. Next Greater Element IV](https://leetcode.com/problems/next-greater-element-iv/) [:dart:](next_greater_element_iv.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given a 0-indexed array of non-negative integers nums.

For each integer in nums, you must find its respective second greater integer.

The second greater integer of nums[i] is nums[j] such that:
- j > i
- nums[j] > nums[i]
- There exists exactly one index k such that nums[k] > nums[i] and i < k < j.

- If there is no such nums[j], the second greater integer is considered to be -1.

For example, in the array [1, 2, 4, 3], the second greater integer of
- 1 is 4,
- 2 is 3,
- and that of 3 and 4 is -1.

Return an integer array answer, where answer[i] is the second greater integer of
nums[i].

Input: nums = [2,4,0,9,6]
Output: [9,6,6,-1,-1]

--> note: second largest of 2 is 9 not 4, as both 4 and 9 are larger than 2, but
    9 is on the right of 4.
```

</details>

------------------------------------------------------------------------------

## [:persevere: 2289. Steps to Make Array Non-decreasing](https://leetcode.com/problems/steps-to-make-array-non-decreasing/) [:dart:](steps_to_make_arr_non_dec.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given a 0-indexed integer array nums.

In one step, remove all elements nums[i] where
- nums[i - 1] > nums[i] for all 0 < i < nums.length.

Return the number of steps performed until nums becomes a non-decreasing array.

Input: nums = [5,3,4,4,7,3,6,11,8,5,11]
Output: 3
Explanation: The following are the steps performed:
- Step 1: [5,3,4,4,7,3,6,11,8,5,11] becomes [5,4,4,7,6,11,11]
             ^       ^      ^ ^
- Step 2: [5,4,4,7,6,11,11] becomes [5,4,7,11,11]
             ^     ^
- Step 3: [5,4,7,11,11] becomes [5,7,11,11]
             ^
--> [5,7,11,11] is a non-decreasing array. Therefore, we return 3.
```

</details>

------------------------------------------------------------------------------

## [:persevere: 907. Sum of Subarray Minimums](https://leetcode.com/problems/sum-of-subarray-minimums/) [:dart:](sum_of_subarray_mininums.h)

- the most difficult part is the dp recursion, so check [here](../dp/dp_z_misc_hard_recursion/README.md#💡💡-907-sum-of-subarray-minimums-🎯)

------------------------------------------------------------------------------

## [:dizzy_face: 1776. Car Fleet II](https://leetcode.com/problems/car-fleet/) [:dart:](car_fleet2.h)

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

## [:dizzy_face: 1130. Minimum Cost Tree From Leaf Values](https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/) [:dart:](min_cost_tree_from_leaf_values.h)

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
