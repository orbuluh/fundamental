# Backtracking [:notebook:](../notes/algorithms.md#backtracking)

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

## [:bulb: 778. Swim in Rising Water](https://leetcode.com/problems/swim-in-rising-water/) [:dart:](matchsticks_to_square.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given an n x n integer matrix grid where each value grid[i][j]
represents the elevation at that point (i, j).

The rain starts to fall. At time t, the depth of the water everywhere is t.

You can swim from a square to another 4-directionally adjacent square
- if and only if the elevation of both squares individually are at most t.
- You can swim infinite distances in zero time.
- Of course, you must stay within the boundaries of the grid during your swim.

Return the least time until you can reach the bottom right square
(n - 1, n - 1) if you start at the top left square (0, 0).

Input: grid = [[0,3],
               [2,1]]
Output: 2
You cannot reach point (1, 0) until time 2.
Then you can reach bottom right
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

# Back tracking the BFS path

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

</details>