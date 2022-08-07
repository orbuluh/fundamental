# Backtracking [:notebook:](../basics/algorithms.md#backtracking)

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