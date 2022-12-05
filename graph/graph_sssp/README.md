# Graph: Single source shortest path

- _notes [here](../../_notes/graph_sssp.md)

## Dijkstra

## [:ok_hand: 743. Network Delay Time](https://leetcode.com/problems/network-delay-time/) [:dart:](network_delay_time.h)

- the basic forms of Dijkstra and Bellman-Ford without much variation.
- solve with both

<details><summary markdown="span">Question</summary>

```markdown
You are given a network of n nodes, labeled from 1 to n.

You are also given times, a list of travel times as directed edges

times[i] = (ui, vi, wi), where

ui is the source node, vi is the target node, and
wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k.

Return the minimum time it takes for all the n nodes to receive the signal.
If it is impossible for all the n nodes to receive the signal, return -1.
```

</details>

------------------------------------------------------------------------------

## Grid walking using Dijkstra, "Dijkstra's algorithm is BFS with a priority queue"

## [:bulb: 778. Swim in Rising Water](https://leetcode.com/problems/swim-in-rising-water/) [:dart:](swim_in_rising_water.h)

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

## [:bulb: 1102. Path With Maximum Minimum Value](https://leetcode.com/problems/path-with-maximum-minimum-value/) [:dart:](path_with_maximum_min_value_dijkstra.h)

- Check DFS with binary search solution [here](../../binary_search/README.md#💡💡-1102-path-with-maximum-minimum-value-🎯)

<details><summary markdown="span">Question</summary>

```markdown
Given an m x n integer matrix grid, return the maximum score of a path starting at (0, 0) and ending at (m - 1, n - 1) moving in the 4 cardinal directions.

The score of a path is the minimum value in that path.

For example, the score of the path 8 → 4 → 5 → 9 is 4.

Input: grid = [[5,4,5],
               [1,2,6],
               [7,4,6]]
Output: 4
Explanation: The path with the maximum score is from path 5 > 4 > 5 > 6 > 6
```

</details>

------------------------------------------------------------------------------

## [:bulb: 1514. Path with Maximum Probability](https://leetcode.com/problems/path-with-maximum-probability/) [:dart:](path_with_max_probs.h)

- solve with both Bellmon-Ford (quicker) and Dijkstra, check code.

<details><summary markdown="span">Question</summary>

```markdown
You are given an undirected weighted graph of n nodes (0-indexed), represented by
- an edge list where `edges[i] = [a, b]` is an undirected edge connecting the nodes `a` and `b` with a probability of success of traversing that edge `succProb[i]`.

Given two nodes `start` and `end`, find the path with the maximum probability of success to go from start to end and return its success probability.

If there is no path from start to end, return 0.
Your answer will be accepted if it differs from the correct answer by at most 1e-5.


Input: n = 3, start = 0, end = 2
       edges = [[0,1],[1,2],[0,2]],
       succProb = [0.5,0.5,0.2],

Output: 0.25000

Explanation: There are two paths from start to end,
one having a probability of success = 0.2 and
the other has 0.5 * 0.5 = 0.25.
```

</details>

------------------------------------------------------------------------------

## Bellmon-Ford Specific (e.g. contains negative cycle)


