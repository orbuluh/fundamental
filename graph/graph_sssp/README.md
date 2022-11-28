# Single source shortest path

- notes [here](../../notes/graph_sssp.md)

## Dijkstra

## [TODO: 778. Swim in Rising Water](https://leetcode.com/problems/swim-in-rising-water/) [:dart:](matchsticks_to_square_dijkstra.h)

- Problem description and backtracking solution check [here](../../backtracking/README.md#bulb-778-swim-in-rising-waterhttpsleetcodecomproblemsswim-in-rising-water-dartmatchstickstosquareh)

------------------------------------------------------------------------------

## Bellmon-Ford

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

