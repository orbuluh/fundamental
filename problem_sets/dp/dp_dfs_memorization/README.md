# DP: DFS + memorization

```markdown
- DP but likely with a more sparse access needed to whole dp matrix
- or problem that likely you can convert to some bottom-up ... but just hard to think of
```

## [:ok_hand: 931. Minimum Falling Path Sum](https://leetcode.com/problems/minimum-falling-path-sum/description/) / [:man_technologist:](minimum_falling_path_sum.h)

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

## [:ok_hand: 576. Out of Boundary Paths](https://leetcode.com/problems/out-of-boundary-paths/) / [:man_technologist:](out_of_bound_path_sol1.h)

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

## [:ok_hand: 2328. Number of Increasing Paths in a Grid](https://leetcode.com/problems/number-of-increasing-paths-in-a-grid) / [:man_technologist:](number_of_increasing_paths_in_a_grid.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given an m x n integer matrix grid, where you can move from a cell to
any adjacent cell in all 4 directions.

Return the number of strictly increasing paths in the grid such that you can
start from any cell and end at any cell.

Since the answer can be very large, return it modulo 10^9 + 7.

Input: grid = [[1,1],[3,4]]
Output: 8
Explanation: The strictly increasing paths are:
- Paths with length 1: [1], [1], [3], [4].
- Paths with length 2: [1 -> 3], [1 -> 4], [3 -> 4].
- Paths with length 3: [1 -> 3 -> 4].
The total number of paths is 4 + 3 + 1 = 8.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 1770. Maximum Score from Performing Multiplication Operations](https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/) / [:man_technologist:](max_score_from_mul_ops.h)

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

## [:bulb: 494. Target Sum](https://leetcode.com/problems/target-sum/) / [:man_technologist:](target_sum_dfs.h)

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

## [:bulb: 871. Minimum Number of Refueling Stops](https://leetcode.com/problems/minimum-number-of-refueling-stops/) / [:man_technologist:](min_of_refueling_stops.h)

- The better greedy solution -> / [:man_technologist:](../greedy/min_of_refueling_stops_greedy.h)

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

## [:bulb: 1473. Paint House III](https://leetcode.com/problems/paint-house-iii/) / [:man_technologist:](paint_house_iii.h)

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

## [:bulb: 1187. Make Array Strictly Increasing](https://leetcode.com/problems/make-array-strictly-increasing) / [:man_technologist:](make_arr_strictly_increasing.h)

<details><summary markdown="span">Question</summary>

```markdown
Given two integer arrays arr1 and arr2, return the minimum number of operations
(possibly zero) needed to make arr1 strictly increasing.

In one operation, you can choose two indices 0 <= i < arr1.length and
0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].

If there is no way to make arr1 strictly increasing, return -1.

Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
Output: 2
Explanation: Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6, 7].

Input: arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
Output: -1
Explanation: You can't make arr1 strictly increasing.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 1575. Count All Possible Routes](https://leetcode.com/problems/count-all-possible-routes) / [:man_technologist:](count_all_possible_routes.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given an array of distinct positive integers locations where locations[i] represents the position of city i. You are also given integers start, finish and fuel representing the starting city, ending city, and the initial amount of fuel you have, respectively.

At each step, if you are at city i, you can pick any city j such that j != i and 0 <= j < locations.length and move to city j. Moving from city i to city j reduces the amount of fuel you have by |locations[i] - locations[j]|. Please notice that |x| denotes the absolute value of x.

Notice that fuel cannot become negative at any point in time, and that you are allowed to visit any city more than once (including start and finish).

Return the count of all possible routes from start to finish. Since the answer may be too large, return it modulo 10^9 + 7.

Input: locations = [2,3,6,8,4], start = 1, finish = 3, fuel = 5
Output: 4
Explanation: The following are all possible routes, each uses 5 units of fuel:
1(@3) -> 3(@8)
1(@3) -> 2(@6) -> 3(@8)
1(@3) -> 4(@4) -> 3(@8)
1(@3) -> 4(@4) -> 2(@6) -> 3(@8)
```

</details>

------------------------------------------------------------------------------


## [:persevere: 1547. Minimum Cost to Cut a Stick
](https://leetcode.com/problems/minimum-cost-to-cut-a-stick) / [:man_technologist:](min_cost_to_cut_a_stick.h)

<details><summary markdown="span">Question</summary>

```markdown
Given a wooden stick of length n units.

The stick is labelled from 0 to n.

Given an integer array cuts where cuts[i] denotes a position you should perform
a cut at.

You should perform the cuts in order, you can change the order of the cuts as
you wish.

The cost of one cut is the length of the stick to be cut, the total cost is the
sum of costs of all cuts.

When you cut a stick, it will be split into two smaller sticks (i.e. the sum of
their lengths is the length of the stick before the cut).


Return the minimum total cost of the cuts.


Input: n = 7, cuts = [1,3,4,5]
Output: 16

say (x, y) is stick's starting and endpoint

(0, 7) -> cut 3 (cost 7 - 0 = 7) => (0, 3) (3, 7)
       -> cut 5 (cost 7 - 3 = 4) => (0, 3) (3, 5) (5, 7)
       -> cut 1 (cost 3 - 0 = 3) => (0, 1) (1, 3) (3, 5) (5, 7)
       -> cut 4 (cost 5 - 3 = 2) => (0, 1) (1, 3) (3, 4) (4, 5) (5, 7)
       -> total: 7 + 4 + 3 + 2 = 16

(0, 7) -> cut 1 (cost 7 - 0 = 7) => (0, 1) (1, 7)
       -> cut 3 (cost 7 - 1 = 6) => (0, 1) (1, 3) (3, 7)
       -> cut 4 (cost 5 - 3 = 2) => (0, 1) (1, 3) (3, 4) (4, 7)
       -> cut 5 (cost 7 - 4 = 3) => (0, 1) (1, 3) (3, 4) (4, 5) (5, 7)
       -> total: 7 + 6 + 2 + 3 = 18

```

</details>

------------------------------------------------------------------------------

## [:persevere: 1140. Stone Game II](https://leetcode.com/problems/stone-game-ii) / [:man_technologist:](stone_game_ii.h)

<details><summary markdown="span">Question</summary>

```markdown
Alice and Bob continue their games with piles of stones.

There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones.

Alice and Bob take turns, with Alice starting first.  Initially, M = 1.

On each player's turn, that player can
- take all the stones in the first X remaining piles, where 1 <= X <= 2M.
- Then, we set M = max(M, X).

- The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

Input: piles = [2,7,9,4,4]
Output: 10

Explanation:  If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 piles in total. If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 piles in total. So we return 10 since it's larger. 

```

</details>

------------------------------------------------------------------------------

## [:persevere: 1406. Stone Game III](https://leetcode.com/problems/stone-game-iii) / [:man_technologist:](stone_game_iii.h)

<details><summary markdown="span">Question</summary>

```markdown
Alice and Bob continue their games with piles of stones.

There are several stones arranged in a row, and each stone has an associated
value which is an integer given in the array stoneValue.

Alice and Bob take turns, with Alice starting first.

On each player's turn, that player can take 1, 2, or 3 stones from the first
remaining stones in the row.

The score of each player is the sum of the values of the stones taken.
The score of each player is 0 initially.

The objective of the game is to end with the highest score,
and the winner is the player with the highest score and there could be a tie.

The game continues until all the stones have been taken.

Assume Alice and Bob play optimally.

Return "Alice" if Alice will win, "Bob" if Bob will win, or
"Tie" if they will end the game with the same score.

Input: values = [1,2,3,7]
Output: "Bob"
Explanation: Alice will always lose. Her best move will be to take three piles and the score become 6. Now the score of Bob is 7 and Bob wins.

Input: values = [1,2,3,6]
Output: "Tie"
Explanation: Alice cannot win this game. She can end the game in a draw if she decided to choose all the first three piles, otherwise she will lose.

```

</details>

------------------------------------------------------------------------------

## [:persevere: 1444. Number of Ways of Cutting a Pizza](https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza) / [:man_technologist:](number_of_ways_of_cutting_pizza.h)

<details><summary markdown="span">Question</summary>

```markdown
Given a rectangular pizza represented as a rows x cols matrix containing the
following characters: 'A' (an apple) and '.' (empty cell) and given the integer
k. You have to cut the pizza into k pieces using k-1 cuts.

For each cut you choose the direction: vertical or horizontal, then you choose a
cut position at the cell boundary and cut the pizza into two pieces.

If you cut the pizza vertically, give the left part of the pizza to a person.
If you cut the pizza horizontally, give the upper part of the pizza to a person.
Give the last piece of pizza to the last person.

Return the number of ways of cutting the pizza such that each piece contains at
least one apple.

Since the answer can be a huge number, return this modulo 10^9 + 7.


Input: pizza = ["A..",
                "AAA",
                "..."], k = 3
Output: 3

After cut, mark as ~.

H_0 = cut row-0 horizontally
V_3 = cut col-3 vertically

"A.."  H_0   "~~~"   V_0   "~~~"
"AAA"   =>   "AAA"    =>   "~AA"
"..."        "..."         "~.."

"A.."  H_0   "~~~"   V_2   "~~~"
"AAA"   =>   "AAA"    =>   "AA~"
"..."        "..."         "..~"

"A.."  V_0   "~.."   V_1   "~~."
"AAA"   =>   "~AA"    =>   "~~A"
"..."        "~.."         "~~."

```

</details>

------------------------------------------------------------------------------

## [:exploding_head: 1531. String Compression II](https://leetcode.com/problems/string-compression-ii/) / [:man_technologist:](string_compression_ii.h)

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
