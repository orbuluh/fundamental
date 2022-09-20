# Dynamic programming [:notebook:](../notes/algorithms.md#dynamic-programming)

# State transition

## [:ok_hand: 309. Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/) [:dart:](buy_sell_stock_with_cooldown.h)

<details><summary markdown="span">Question</summary>

```markdown
- You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve.

You may complete as many transactions as you like (i.e., buy one and sell one
share of the stock multiple times) with the following restrictions:
- After you sell your stock, you cannot buy stock on the next day
  (i.e., cool-down one day).
- You may not engage in multiple transactions simultaneously
  (i.e., you must sell the stock before you buy again).
- Different sequences are counted as different combinations.

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cool-down, buy, sell]
```
</details>

------------------------------------------------------------------------------
## [:thinking: 188. Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/) [:dart:](buy_sell_stock_iv.h)
- although understand the solution, looping in k still feel unintuitive...

<details><summary markdown="span">Question</summary>

```markdown
- You are given an integer array prices where prices[i] is the price of a given
  stock on the ith day, and an integer k.
- Find the maximum profit you can achieve. You may complete at most k transactions.
- Note: You may not engage in multiple transactions simultaneously
  (i.e., you must sell the stock before you buy again).

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
             Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
```
</details>

------------------------------------------------------------------------------

# DFS + memorization
- DP but likely with a more sparse access needed to whole dp matrix

## [:ok_hand: 377. Combination Sum IV](https://leetcode.com/problems/combination-sum-iv/) [:dart:](combination_sum_iv.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an array of distinct integers nums and a target integer target,
return the number of possible permutations that add up to target.

Input: nums = [1,2,3], target = 4
Output: 7

Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

- Note that different sequences are counted as different combinations.
```
</details>

------------------------------------------------------------------------------

## [:bulb: 1770. Maximum Score from Performing Multiplication Operations](https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/) [:dart:](max_score_from_mul_ops.h)
- bottom up solution is much faster, but hard to wrap up my head... -> check [here](max_score_from_mul_ops_bottom_up.h)
<details><summary markdown="span">Question</summary>

```markdown
You are given two integer arrays
- nums of size n
- multipliers of size m
- where n >= m.

You begin with a score of 0.
You want to perform exactly m operations.

On the ith operation (1-indexed), you will:
- Choose one integer x from either the start or the end of the array nums.
- Add multipliers[i] * x to your score.
- Remove x from the array nums.
- Return the maximum score after performing m operations.

Input: nums = [1,2,3], multipliers = [3,2,1]
Output: 14
Explanation: An optimal solution is as follows:
- Choose from the end, [1,2,3], adding 3 * 3 = 9 to the score.
- Choose from the end, [1,2], adding 2 * 2 = 4 to the score.
- Choose from the end, [1], adding 1 * 1 = 1 to the score.
The total score is 9 + 4 + 1 = 14.
```
</details>

------------------------------------------------------------------------------

## [:ok_hand: 576. Out of Boundary Paths](https://leetcode.com/problems/out-of-boundary-paths/) [:dart:](out_of_bound_path_sol1.h)
- DF + memorization is straight forward (and faster), the food for thought is doing in the [other way](out_of_bound_path_sol2.h).
<details><summary markdown="span">Question</summary>

```markdown
There is an m x n grid with a ball.
- The ball is initially at the position [`startRow`, `startColumn`].
- You are allowed to move the ball to one of the four adjacent cells in the grid
  - (possibly out of the grid crossing the grid boundary).
- You can apply at most `maxMove` moves to the ball.

Given the five integers `m`, `n`, `maxMove`, `startRow`, `startColumn`
return the number of paths to move the ball out of the grid boundary.

Since the answer can be very large, return it modulo 10^9 + 7.
```
</details>

------------------------------------------------------------------------------

## [:bulb: 871. Minimum Number of Refueling Stops](https://leetcode.com/problems/minimum-number-of-refueling-stops/) [:dart:](min_of_refueling_stops.h)
- The better greedy solution -> [:dart:](../greedy/min_of_refueling_stops_greedy.h)

<details><summary markdown="span">Question</summary>

```markdown
- A car travels from a starting position to a destination `target`

- There are gas stations along the way.
- The gas stations are represented as an array stations where
  - stations[i] = [position_i, fuel_i]
  - indicates that the ith gas station is position_i miles east of the starting
    position and has fuel_i liters of gas.

- The car has infinite tank of gas, which initially has `startFuel` in it.
- It uses one unit of gas per one mile that it drives.
- When the car reaches a gas station, it may stop and refuel, transferring all
  the gas from the station into the car.

- Return the minimum number of refueling stops the car must make in order to
 reach its destination. If it cannot reach the destination, return -1.
- Note that if the car reaches a gas station with 0 fuel left, the car can still
  refuel there.
- If the car reaches the destination with 0 fuel left, it is still considered to
  have arrived.

Input: target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
Output: 2
start with 10
drive to position 10, expending 10, refuel 60
drive from position 10 to position 60, 10 gas remains, then add the fuel 40
then we can arrive the target 100. We made 2 stops in total.

```
</details>

------------------------------------------------------------------------------

## [:bulb: 1473. Paint House III](https://leetcode.com/problems/paint-house-iii/) [:dart:](paint_house_iii.h)

<details><summary markdown="span">Question</summary>

```markdown
- There is a row of m houses in a small city
    - each house must be painted with one of the n colors (labeled from 1 to n)
    - some houses that have been painted (non-zero color) not be painted again.

- A neighborhood is a maximal group of continuous houses with the same color.
    - For example: houses = [1,2,2,3,3,2,1,1] contains 5 neighborhoods
      `[{1}, {2,2}, {3,3}, {2}, {1,1}].`
- Given an array houses, an m x n matrix cost and an integer `target` where:
    - houses[i]: is the color of the house i, 0 if the house is not painted yet.
    - cost[i][j]: is the cost of paint the house i with the color j + 1.
- Return the minimum cost of painting all the remaining houses in such a way
  that there are exactly `target` neighborhoods.
  - If it is not possible, return -1.

Input: houses = [0,0,0,0,0],
       cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3

Output: 9
Explanation: Paint houses of this way [1,2,2,1,1]
- This array contains target = 3 neighborhoods, [{1}, {2,2}, {1,1}].
- Cost of paint all houses (1 + 1 + 1 + 1 + 5) = 9.
```
</details>

------------------------------------------------------------------------------

# Sub-array (contiguous, Kadane's Algorithm)

## [:ok_hand: 53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) [:dart:](max_subarray.h)
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

## [:bulb: 363. Max Sum of Rectangle No Larger Than K](https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/) [:dart:](max_sum_of_rectangle_le_k.h)
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

# Common sequence

## [:bulb: 300. Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/) [:dart:](longest_common_subseq.h)
<details><summary markdown="span">Question</summary>

```markdown
Given an integer array `nums`,
return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array
by deleting some or no elements without changing the order of the remaining elements.

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
```
</details>

------------------------------------------------------------------------------

# KMP
- check [KMP notes :point_right: here](../notes/kmp.md)

## [:bulb: 718. Maximum Length of Repeated Subarray](https://leetcode.com/problems/maximum-length-of-repeated-subarray/) [:dart:](max_len_of_repeated_subarray.h)
- dp solution with worse complexity than KMP [:point_right: here](max.)

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

# Situation analyze

## [:ok_hand: 1220. Count Vowels Permutation](https://leetcode.com/problems/count-vowels-permutation/) [:dart:](count_vowels_permutation.h)
<details><summary markdown="span">Question</summary>

```markdown
Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a' or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a 'u'.
Each vowel 'u' may only be followed by an 'a'.
Since the answer may be too large, return it modulo 10^9 + 7.

Input: n = 2
Output: 10
Explanation: All possible strings are:
"ea", "ia", "ua",
"ae", "ie",
"ei", "oi",
"io",
"iu", "ou"
```
</details>

------------------------------------------------------------------------------

## [:exploding_head::exploding_head: 818. Race Car](https://leetcode.com/problems/race-car/) [:dart:](race_car.h)
<details><summary markdown="span">Question</summary>

```markdown
Your car starts at position 0 and speed +1 on an infinite number line.
Your car can go into negative positions.
Your car drives automatically according to a sequence of instructions
- 'A' (accelerate):
  - `position += speed`
  - `speed *= 2`
- 'R' (reverse):
  - Your position stays the same, but ...
  - If your speed is positive then `speed = -1`
  - else: `speed = 1`

Given a target position target, return the length of the shortest sequence of instructions to get there.

Input: target = 6
Output: 5
Explanation:
- The shortest instruction sequence is "AAARA".
- Your position goes from 0 --> 1 --> 3 --> 7 -->  7 -->  6
- Your speed goes from    1 --> 1 --> 2 --> 4 --> -1 --> -2
```
</details>

------------------------------------------------------------------------------

# Really tricky dp recursion

## [:exploding_head: 629. K Inverse Pairs Array](https://leetcode.com/problems/k-inverse-pairs-array/) [:dart:](k_inverse_pairs_arr.h)
<details><summary markdown="span">Question</summary>

```markdown
- For an integer array nums
- an inverse pair is
  - a pair of integers [i, j]
  - where 0 <= i < j < nums.length
  - and nums[i] > nums[j].

- Given two integers n and k, return
  - the number of different arrays
    consist of numbers from 1 to n
    such that there are exactly k inverse pairs.

- Since the answer can be huge, return it modulo 10^9 + 7.
```
</details>

------------------------------------------------------------------------------

## [:exploding_head: :exploding_head: 376. Wiggle Subsequence](https://leetcode.com/problems/wiggle-subsequence/) [:dart:](wiggle_subseq.h)
<details><summary markdown="span">Question</summary>

```markdown
- A wiggle sequence is a sequence where the differences between successive numbers
  **strictly alternate between positive and negative**.
    - The first difference (if one exists) may be either positive or negative.
    - A sequence with one element and a sequence with two non-equal elements are
      trivially wiggle sequences.
- For example, `[1, 7, 4, 9, 2, 5]` is a wiggle sequence because the differences
  `(6, -3, 5, -7, 3)` alternate between positive and negative.
- In contrast, `[1, 4, 7, 2, 5]` and `[1, 7, 4, 5, 5]` are not wiggle sequences.
    - The first is not because its first two differences are positive, and
    - the second is not because its last difference is zero.
- A subsequence is obtained by deleting some elements (possibly zero) from the original
  sequence, leaving the remaining elements in their **original order**.
- Given an integer array nums
- Return the length of the **longest** wiggle subsequence of nums.
```
</details>

------------------------------------------------------------------------------