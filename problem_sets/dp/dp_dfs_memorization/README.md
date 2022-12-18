# DP: DFS + memorization

```markdown
- DP but likely with a more sparse access needed to whole dp matrix
- or problem that likely you can convert to some bottom-up ... but just hard to think of
```

## [:ok_hand: 931. Minimum Falling Path Sum](https://leetcode.com/problems/minimum-falling-path-sum/description/) [:dart:](minimum_falling_path_sum.h)

- as grid nature, the intuition would be dfs + memorization. But you will see it's basically bottom up at the end.

<details><summary markdown="span">Question</summary>

```markdown
Given an n x n array of integers matrix, return the minimum sum of
any falling path through matrix.

A falling path starts at any element in the first row and chooses the element
in the next row that is either directly below or diagonally left/right.

Specifically, the next element from position (row, col) will be
(row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

Input: matrix = [[2,1,3],
                 [6,5,4],
                 [7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum
1->5->7  / 1->4->8
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

## [:bulb: 494. Target Sum](https://leetcode.com/problems/target-sum/) [:dart:](target_sum_dfs.h)

- bottom up solution is much faster and is basically a 0/1 knapsack, but need a [:dizzy_face: conversion of the problem... -> check here](../dp_01_knapsack/target_sum_bottom_up.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and
'-' before each integer in nums and then concatenate all the integers.

For example, if `nums = [2, 1]`, you can add a '+' before 2 and a '-' before 1
and concatenate them to build the expression "+2-1".

Return the number of different expressions that you can build, which evaluates
to target.

Input: nums = [1,1,1,1,1], target = 3
Output: 5

Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
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

## [:exploding_head: 1531. String Compression II](https://leetcode.com/problems/string-compression-ii/) [:dart:](string_compression_ii.h)

<details><summary markdown="span">Question</summary>

```markdown
Run-length encoding is a string compression method that works by
replacing consecutive identical characters (repeated 2 or more times) with the
concatenation of the character and the number marking the count of the
characters (length of the run).
- "aabccc" --> "a2bc3".
- Notice that in this problem, we are not adding '1' after single characters.

Given a string s and an integer k. You need to delete at most k characters from
s such that the run-length encoded version of s has minimum length.

Find the minimum length of the run-length encoded version of s after deleting at
most k characters.

Input: s = "aaabcccd", k = 2
Output: 4
- Explanation:
- Compressing s without deleting anything will give us "a3bc3d" of length 6.
- Deleting any of the characters 'a' or 'c' would at most decrease the length of
  the compressed string to 5, for instance delete 2 'a' then we will have
  s = "abcccd" which compressed is abc3d.
- Therefore, the optimal way is to delete 'b' and 'd', then the compressed
version of s will be "a3c3" of length 4.
```

</details>

------------------------------------------------------------------------------
