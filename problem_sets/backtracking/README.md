# Backtracking

- [:notebook:](../_notes/algorithms.md#backtracking)

```markdown
- One important thing while dfs backtracking is that how to NOT go to the same state.
  - It's basically like when you dfs a graph, you want to keep a visited node set.
- So make sure while you construct the recursion, you can somehow avoid the duplicated states.
  - For example, parameter of recursion could be how the state is defined.
  - For some DFS problem where state with smaller parameter is related to state with larger one, it's likely dp'able. Check [here](../dp/dp_dfs_memorization/README.md)
```

## State walking

## [:ok_hand: 39. Combination Sum](https://leetcode.com/problems/combination-sum/) [:dart:](combinational_sum.h)

- classic backtracking - worth checking
- a variation of the problem check [377. Combination Sum IV](../dp/dp_unbounded_knapsack/README.md#👌-377-combination-sum-iv-🎯)

<details><summary markdown="span">Question</summary>

```markdown

Given an array of distinct integers candidates and a target integer target,
return a list of all unique combinations of candidates
       where the chosen numbers sum to target.

You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times.
Two combinations are unique if the frequency of at least one of the chosen
numbers is different.

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]

Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 31. Next Permutation](https://leetcode.com/problems/next-permutation/) [:dart:](next_permutation.h)

<details><summary markdown="span">Question</summary>

```markdown
Find next permutation of an array.

Input: nums = [1,2,3]
Output: [1,3,2]

Input: nums = [3,2,1]
Output: [1,2,3]

Input: nums = [1,1,5]
Output: [1,5,1]
```

</details>

------------------------------------------------------------------------------

## [:bulb: 473. Matchsticks to Square](https://leetcode.com/problems/matchsticks-to-square/) [:dart:](matchsticks_to_square.h)

- might be harder to not get TLE than you originally think!

<details><summary markdown="span">Question</summary>

```markdown
You are given an integer array matchsticks where
- matchsticks[i] is the length of the ith matchstick.

You want to use all the matchsticks to make one square.
- You should not break any stick
- but you can link them up
- and each matchstick must be used exactly one time.

Return true if you can make this square and false otherwise.

Input: matchsticks = [1,1,2,2,2]
Output: true
Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
(1+1 / 2 / 2 / 2)

Input: matchsticks = [3,3,3,3,4]
Output: false
Explanation: You cannot find a way to form a square with all the matchsticks.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 410. Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/) [:dart:](split_arr_largest_sum_bt.h)

- Problem description, optimal solution check -> [here](../binary_search/README.md#bulbbulb-410-split-array-largest-sumhttpsleetcodecomproblemssplit-array-largest-sum-dartsplitarrlargestsumbsh)
- Would be nice to practice backtrack on this problem...

------------------------------------------------------------------------------

## [:bulb: 465. Optimal Account Balancing](https://leetcode.com/problems/optimal-account-balancing/) [:dart:](optimal_acct_balancing.h)

- There is a DP solution that is much difficult to think about... check ...

<details><summary markdown="span">Question</summary>

```markdown
You are given an array of transactions transactions where

transactions[i] = [fromi, toi, amounti] indicates that
- the person with ID = fromi gave amounti $ to the person with ID = toi.

Return the minimum number of transactions required to settle the debt.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 1088. Confusing Number II](https://leetcode.com/problems/confusing-number-ii/) [:dart:](confusing_number_ii.h)

<details><summary markdown="span">Question</summary>

```markdown
A confusing number is a number that
- when rotated 180 degrees becomes a different number with each digit valid.
  - When   0, 1, 6, 8, and 9 are rotated 180 degrees, they
    become 0, 1, 9, 8, and 6 respectively.
  - When 2, 3, 4, 5, and 7 are rotated 180 degrees, they become invalid.

- We can rotate digits of a number by 180 degrees to form new digits.


Note that after rotating a number, we can ignore leading zeros.
For example, after rotating 8000, we have 0008 which is considered as just 8.

Given an integer n, return the number of confusing numbers in the
inclusive range [1, n].
```

</details>

------------------------------------------------------------------------------

## Grid walking

## [:ok_hand: 490. The Maze](https://leetcode.com/problems/the-maze/) [:dart:](the_maze.h)

- pokemon ice gym like variations of normal 2D walking!

<details><summary markdown="span">Question</summary>

```markdown
There is a ball in a maze with
- empty spaces (represented as 0) and
- walls (represented as 1).

The ball can go through the empty spaces by rolling up, down, left or right,
but it won't stop rolling until hitting a wall.

When the ball stops, it could choose the next direction.

Given the m x n maze, the ball's start position and the destination, where

- start = [startrow, startcol] and
- destination = [destinationrow, destinationcol],

return true if the ball can stop at the destination, otherwise return false.
You may assume that the borders of the maze are all walls.


Input: maze =
[[0,0,1,0,0],
 [0,0,0,0,0],
 [0,0,0,1,0],
 [1,1,0,1,1],
 [0,0,0,0,0]], start = [0,4], destination = [4,4]

Output: true
Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 489. Robot Room Cleaner](https://leetcode.com/problems/robot-room-cleaner) [:dart:](robot_room_cleaner.h)

<details><summary markdown="span">Question</summary>

```markdown
You are controlling a robot that is located somewhere in a room.
The room is modeled as an m x n binary grid where
- 0 represents a wall and 1 represents an empty slot.

The robot starts at an unknown location in the room that is guaranteed to be
empty, and you do not have access to the grid, but you can only move the robot using
the given API Robot.

You are tasked to use the robot to clean the entire room (i.e., clean every
empty cell in the room). The robot with the four given APIs can
- move forward,
- turn left
- turn right. Each turn is 90 degrees.

When the robot tries to move into a wall cell, its bumper sensor detects the
obstacle, and it stays on the current cell.

Design an algorithm to clean the entire room using the following APIs:

interface Robot {
  // returns true if next cell is open and robot moves into the cell.
  // returns false if next cell is obstacle and robot stays on the current cell.
  boolean move();

  // Robot will stay on the same cell after calling turnLeft/turnRight.
  // Each turn will be 90 degrees.
  void turnLeft();
  void turnRight();

  // Clean the current cell.
  void clean();
}


- Note that the initial direction of the robot will be facing up. You can
assume all four edges of the grid are all surrounded by a wall.

Custom testing:
- The input is only given to initialize the room and the robot's position
internally. You must solve this problem "blindfolded". In other words, you must
control the robot using only the four mentioned APIs without knowing the room
layout and the initial robot's position.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 417. Pacific Atlantic Water Flow](https://leetcode.com/problems/pacific-atlantic-water-flow/) [:dart:](pac_atl_water_flow.h)

<details><summary markdown="span">Question</summary>

```markdown
There is an m x n rectangular island
that borders both the Pacific Ocean and Atlantic Ocean.

The Pacific Ocean touches the island's left and top edges,
and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells.
You are given an m x n integer matrix heights where heights[r][c]
represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can
flow to neighboring cells directly north, south, east, and west if
the neighboring cell's height is less than or equal to the current cell's height.

Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci]
denotes that rain water can flow from cell (ri, ci)
to both the Pacific and Atlantic oceans.

Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
[0,4]: [0,4] -> Pacific Ocean
       [0,4] -> Atlantic Ocean
[1,3]: [1,3] -> [0,3] -> Pacific Ocean
       [1,3] -> [1,4] -> Atlantic Ocean
[1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean
       [1,4] -> Atlantic Ocean
[2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean
       [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
[3,0]: [3,0] -> Pacific Ocean
       [3,0] -> [4,0] -> Atlantic Ocean
[3,1]: [3,1] -> [3,0] -> Pacific Ocean
       [3,1] -> [4,1] -> Atlantic Ocean
[4,0]: [4,0] -> Pacific Ocean
       [4,0] -> Atlantic Ocean
Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.
```

</details>

------------------------------------------------------------------------------

## [:bulb::bulb: 1293. Shortest Path in a Grid with Obstacles Elimination](https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/) [:dart:](shortest_path_with_obstacle_elimination.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given an m x n integer matrix grid where each cell is either 0 (empty)
or 1 (obstacle). You can move up, down, left, or right from and to an empty cell
in one step.

Return the minimum number of steps to walk from the upper left corner (0, 0) to
the lower right corner (m - 1, n - 1) given that you can eliminate at most k
obstacles. If it is not possible to find such walk return -1.

Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
Output: 6
Explanation:

The shortest path without eliminating any obstacle is 10.
The shortest path with one obstacle elimination at position (3,2) is 6.
Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
```

</details>

------------------------------------------------------------------------------

## BFS

```markdown
- Note: when BFS, you should mark a point as visited whenever it's put into the
  priority queue, not when you pop the point out. Otherwise it's easily
  exploding the search space with repeated point.
```


## [:bulb: 1926. Nearest Exit from Entrance in Maze](https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/) [:dart:](nearest_exit_from_entrance.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given an m x n matrix maze (0-indexed) with empty cells
(represented as '.') and walls (represented as '+').

You are also given the entrance of the maze, where
- entrance = [entrance_row, entrance_col] denotes the row and column of the cell
             you are initially standing at.

In one step, you can move one cell up, down, left, or right.

You cannot step into a cell with a wall, and you cannot step outside the maze.
Your goal is to find the nearest exit from the entrance.

An exit is defined as an empty cell that is at the border of the maze.
The entrance does not count as an exit.

Return the number of steps in the shortest path from the entrance to the nearest
exit, or -1 if no such path exists.

Input: maze = [["+","+",".","+"],
               [".",".",".","+"],
               ["+","+","+","."]],
entrance = [1,2]
Output: 1

Explanation:
There are 3 exits in this maze at [1,0], [0,2], and [2,3].
Initially, you are at the entrance cell [1,2].
- You can reach [1,0] by moving 2 steps left.
- You can reach [0,2] by moving 1 step up.
It is impossible to reach [2,3] from the entrance.
Thus, the nearest exit is [0,2], which is 1 step away.
```

</details>

------------------------------------------------------------------------------

## Backtracking the BFS path

## [:bulb::bulb: 126. Word Ladder II](https://leetcode.com/problems/word-ladder-ii/) [:dart:](word_ladder_ii.h)

<details><summary markdown="span">Question</summary>

```markdown
A transformation sequence from word `beginWord` to word `endWord`
using a dictionary `wordList` is a sequence of words:
    `beginWord -> s1 -> s2 -> ... -> sk`

such that:
- Every adjacent pair of words differs by **a single letter**.
- Every `si` for `1 <= i <= k` is in wordList.
- Note that `beginWord` does not need to be in `wordList`.
- `sk == endWord`

- Given two words, `beginWord` and `endWord`, and a dictionary `wordList`,
return all the shortest transformation sequences from `beginWord` to `endWord`,
or an empty list if no such sequence exists.

- Each sequence should be returned as a list of the words `[beginWord, s1, s2, ..., sk]`.

Input: `beginWord` = "hit",
       `endWord`   = "cog",
       `wordList` = ["hot","dot","dog","lot","log","cog"]

Output: [["hit","hot","dot","dog","cog"],
         ["hit","hot","lot","log","cog"]]

Explanation: There are 2 shortest transformation sequences:
- "hit" -> "hot" -> "dot" -> "dog" -> "cog"
- "hit" -> "hot" -> "lot" -> "log" -> "cog"
```

</details>

------------------------------------------------------------------------------

## [Backtracking with binary search](../binary_search/README.md#backtracking-x-binary-search)