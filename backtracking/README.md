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

## [:bulb: 410. Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/) [:dart:](split_arr_largest_sum_bt.h)
- Problem description, optimal solution check -> [here](../binary_search/README.md#bulbbulb-410-split-array-largest-sumhttpsleetcodecomproblemssplit-array-largest-sum-dartsplitarrlargestsumbsh)
- Would be nice to practice backtrack on this problem...

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