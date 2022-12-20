# Union find

- [:notebook:](../../_notes/union_find.md)

------------------------------------------------------------------------------

## [:ok_hand: 1971. Find if Path Exists in Graph](https://leetcode.com/problems/find-if-path-exists-in-graph/) [:dart:](find_if_path_exists_in_graph.h)

- Can also do it in a dfs way, but union find is much faster.
- Nice basic problem to practice union find!
- Check out [841. Keys and Rooms](../backtracking/README.md#👌-841-keys-and-rooms-🎯) -> very similar to this one but can't do union find, Why? because it's directed!

<details><summary markdown="span">Question</summary>

```markdown
There is a bi-directional graph with n vertices, where
- each vertex is labeled from 0 to n - 1 (inclusive).

The edges in the graph are represented as a 2D integer array edges, where
- each edges[i] = [ui, vi] denotes a bi-directional edge between ui and  vi.
- Every vertex pair is connected by at most one edge, and
- no vertex has an edge to itself.

You want to determine
- if there is a valid path that exists from source to destination.

Given edges and the integers n, source, and destination,
return true if there is a valid path from source to destination,
or false otherwise.


Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
Output: true
Explanation:

There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 990. Satisfiability of Equality Equations](https://leetcode.com/problems/satisfiability-of-equality-equations/) [:dart:](satisfiability_of_eqs.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given an array of strings equations that represent relationships between variables where
- each string equations[i] is of length 4
- takes one of two different forms: "x==y" or "x!=y".
- x and y are lowercase letters (not necessarily different) that represent one-letter variable names.

Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.

Input: equations = ["a==b","b!=a"]
Output: false
```

</details>

------------------------------------------------------------------------------

## [:bulb: 947. Most Stones Removed with Same Row or Column](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/) [:dart:](most_stones_removed_with_same_row_or_col_uf.h)

- check problem statement and dfs solution in [here](../graph/README.md#💡-947-most-stones-removed-with-same-row-or-column-🎯)

------------------------------------------------------------------------------