# Backtracking

- [:notebook:](../../_notes/backtracking.md)

```markdown
- One important thing while dfs backtracking is that how to NOT go to the same state.
  - It's basically like when you dfs a graph, you want to keep a visited node set.
- So make sure while you construct the recursion, you can somehow avoid the duplicated states.
  - For example, parameter of recursion could be how the state is defined.
  - For some DFS problem where state with smaller parameter is related to state with larger one, it's likely dp'able. Check [here](../dp/dp_dfs_memorization/README.md)
```

## State walking

## [:ok_hand: 39. Combination Sum](https://leetcode.com/problems/combination-sum/) / [:man_technologist:](combinational_sum.h)

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

## [:ok_hand: 131. Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning) / [:man_technologist:](palindrome_partitioning.h)

<details><summary markdown="span">Question</summary>

```markdown
Given a string s, partition s such that every substring of the partition is a
palindrome. Return all possible palindrome partitioning of s.

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Input: s = "a"
Output: [["a"]]
```

</details>

------------------------------------------------------------------------------

## [:bulb: 93. Restore IP Addresses](https://leetcode.com/problems/restore-ip-addresses) / [:man_technologist:](restore_ip_addresses.h)

<details><summary markdown="span">Question</summary>

```markdown
A valid IP address consists of exactly four integers separated by single dots.

Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but
"0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.

Given a string s containing only digits, return all possible valid IP addresses
that can be formed by inserting dots into s.

You are not allowed to reorder or remove any digits in s. You may return the
valid IP addresses in any order.


Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]

Input: s = "0000"
Output: ["0.0.0.0"]

Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]

```

</details>

------------------------------------------------------------------------------

## [:bulb: 31. Next Permutation](https://leetcode.com/problems/next-permutation/) / [:man_technologist:](next_permutation.h)

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

## [:bulb: 491. Non-decreasing Subsequences](https://leetcode.com/problems/non-decreasing-subsequences) / [:man_technologist:](non_decreasing_subseq.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an integer array nums, return all the different possible non-decreasing
subsequences of the given array with at least two elements.

You may return the answer in any order.

Input: nums = [4,6,7,7]
Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]

Input: nums = [4,4,3,2,1]
Output: [[4,4]]
```

</details>

------------------------------------------------------------------------------

## [:bulb: 473. Matchsticks to Square](https://leetcode.com/problems/matchsticks-to-square/) / [:man_technologist:](matchsticks_to_square.h)

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

## [:bulb: 410. Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/) / [:man_technologist:](split_arr_largest_sum_bt.h)

- Problem description, optimal solution check -> [here](../binary_search/README.md#bulbbulb-410-split-array-largest-sumhttpsleetcodecomproblemssplit-array-largest-sum-dartsplitarrlargestsumbsh)
- Would be nice to practice backtrack on this problem...

------------------------------------------------------------------------------

## [:bulb: 465. Optimal Account Balancing](https://leetcode.com/problems/optimal-account-balancing/) / [:man_technologist:](optimal_acct_balancing.h)

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

## [:bulb: 2477. Minimum Fuel Cost to Report to the Capital](https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital) / [:man_technologist:](min_fuel_cost_to_capital.h)

<details><summary markdown="span">Question</summary>

```markdown
There is a tree (i.e., a connected, undirected graph with no cycles) structure
country network
- consisting of n cities numbered from 0 to n - 1 and
- exactly n - 1 roads.

The capital city is city 0.

You are given a 2D integer array roads where roads[i] = [ai, bi] denotes that
there exists a bidirectional road connecting cities ai and bi.

- There is a meeting for the representatives of each city.
- The meeting is in the capital city.
- There is a car in each city.

You are given an integer seats that indicates the number of seats in each car.

A representative can use the car in their city to travel or change the car and
ride with another representative.

The cost of traveling between two cities is one liter of fuel.
Return the minimum number of liters of fuel to reach the capital city.


Input: roads = [[0,1],[0,2],[0,3]], seats = 5

              2
              |
            1-0-3

Output: 3

Explanation:
- Representative1 goes directly to the capital with 1 liter of fuel.
- Representative2 goes directly to the capital with 1 liter of fuel.
- Representative3 goes directly to the capital with 1 liter of fuel.
It costs 3 liters of fuel at minimum.
It can be proven that 3 is the minimum number of liters of fuel needed.

Input: roads = [[3,1],[3,2],[1,0],[0,4],[0,5],[4,6]], seats = 2

          1-3-2
          |
      6-4-0-5

Output: 7

Explanation:
- Representative2 goes directly to city 3 with 1 liter of fuel.
- Representative2 and representative3 go together to city 1 with 1 liter of fuel.
- Representative2 and representative3 go together to the capital with 1 liter of fuel.
- Representative1 goes directly to the capital with 1 liter of fuel.
- Representative5 goes directly to the capital with 1 liter of fuel.
- Representative6 goes directly to city 4 with 1 liter of fuel.
- Representative4 and representative6 go together to the capital with 1 liter of fuel.
It costs 7 liters of fuel at minimum.
It can be proven that 7 is the minimum number of liters of fuel needed.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 1088. Confusing Number II](https://leetcode.com/problems/confusing-number-ii/) / [:man_technologist:](confusing_number_ii.h)

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

## [:ok_hand: 490. The Maze](https://leetcode.com/problems/the-maze/) / [:man_technologist:](the_maze.h)

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

## [:bulb: 1254. Number of Closed Islands](https://leetcode.com/problems/number-of-closed-islands) / [:man_technologist:](number_of_closed_island.h)

<details><summary markdown="span">Question</summary>

```markdown
Given a 2D grid consists of 0s (land) and 1s (water).

An island is a maximal 4-directionally connected group of 0s and a closed island
is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.


Input: grid = [
       [1,1,1,1,1,1,1,0],
       [1,0,0,0,0,1,1,0],
       [1,0,1,0,1,1,1,0],
       [1,0,0,0,0,1,0,1],
       [1,1,1,1,1,1,1,0]]
Output: 2
Explanation: the ^ are closed island as defined

       [1,1,1,1,1,1,1,0],
       [1,^,^,^,^,1,1,0],
       [1,^,1,^,1,1,1,0],
       [1,^,^,^,^,1,^,1],
       [1,1,1,1,1,1,1,0]

```

</details>

------------------------------------------------------------------------------

## [:bulb: 489. Robot Room Cleaner](https://leetcode.com/problems/robot-room-cleaner) / [:man_technologist:](robot_room_cleaner.h)

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

## [:bulb: 417. Pacific Atlantic Water Flow](https://leetcode.com/problems/pacific-atlantic-water-flow/) / [:man_technologist:](pac_atl_water_flow.h)

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

## [:persevere: 1293. Shortest Path in a Grid with Obstacles Elimination](https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/) / [:man_technologist:](shortest_path_with_obstacle_elimination.h)

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
------------------------------------------------------------------------------

## [:ok_hand: 841. Keys and Rooms](https://leetcode.com/problems/keys-and-rooms) / [:man_technologist:](keys_and_rooms.h)

- check out [1971. Find if Path Exists in Grap](../union_find/README.md#👌-1971-find-if-path-exists-in-graph-🎯), similar, but can solve with union find because it's undirected graph

<details><summary markdown="span">Question</summary>

```markdown
There are n rooms labeled from 0 to n - 1
- all the rooms are locked except for room 0.
- Your goal is to visit all the rooms.
- However, you cannot enter a locked room without having its key.

When you visit a room, you may find a set of distinct keys in it.
- Each key has a number on it, denoting which room it unlocks, and
- you can take all of them with you to unlock the other rooms.

Given an array rooms where rooms[i] is the set of keys that you can obtain if
you visited room i, return true if you can visit all the rooms, or false otherwise.

Input: rooms = [[1],[2],[3],[]]
Output: true

Input: rooms = [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can not enter room number 2 since the only key that unlocks it is in that room.
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 1345. Jump Game IV](https://leetcode.com/problems/jump-game-iv) / [:man_technologist:](jump_game_iv.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an array of integers arr, you are initially positioned at the first index
of the array.

In one step you can jump from index i to index:

- i + 1 where: i + 1 < arr.length.
- i - 1 where: i - 1 >= 0.
- j where: arr[i] == arr[j] and i != j.

Return the minimum number of steps to reach the last index of the array.
Notice that you can not jump outside of the array at any time.

Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
Output: 3
Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9.
Note that index 9 is the last index of the array.
```

</details>

------------------------------------------------------------------------------


## [:bulb: 1926. Nearest Exit from Entrance in Maze](https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/) / [:man_technologist:](nearest_exit_from_entrance.h)

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

## [:bulb: 1129. Shortest Path with Alternating Colors](https://leetcode.com/problems/shortest-path-with-alternating-colors) / [:man_technologist:](shortest_path_with_alternating_colors.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given an integer n, the number of nodes in a directed graph
- where the nodes are labeled from 0 to n - 1.

Each edge is red or blue in this graph,
and there could be self-edges and parallel edges.

You are given two arrays redEdges and blueEdges where:

redEdges[i] = [ai, bi] indicates that
- there is a directed red edge from node ai to node bi in the graph, and
blueEdges[j] = [uj, vj] indicates that
- there is a directed blue edge from node uj to node vj in the graph.

Return an array answer of length n, where
- each answer[x] is the length of the shortest path from node 0 to node x
  such that the edge colors alternate along the path,
- or -1 if such a path does not exist.

Input: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
Output: [0,1,-1]
```

</details>

------------------------------------------------------------------------------

## BFS from multiple points

## [:bulb: 1162. As Far from Land as Possible](https://leetcode.com/problems/as-far-from-land-as-possible) / [:man_technologist:](as_far_from_land_as_possible.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an n x n grid containing only values 0 and 1, where
- 0 represents water and
- 1 represents land,

find a water cell such that its distance to the nearest land cell is maximized,
and return the distance. If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance:

the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

Input: grid = [[1,0,1],
               [0,0,0],
               [1,0,1]]
Output: 2
Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.


Input: grid = [[1,0,0],
               [0,0,0],
               [0,0,0]]
Output: 4
Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.
```

</details>

------------------------------------------------------------------------------

## Backtracking the BFS path

## [:persevere: 126. Word Ladder II](https://leetcode.com/problems/word-ladder-ii/) / [:man_technologist:](word_ladder_ii.h)

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