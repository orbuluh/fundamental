# Union find

- [:notebook:](../../_notes/union_find.md)

------------------------------------------------------------------------------

## [:ok_hand: 1971. Find if Path Exists in Graph](https://leetcode.com/problems/find-if-path-exists-in-graph/) / [:man_technologist:](find_if_path_exists_in_graph.h)

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

## [:ok_hand: 990. Satisfiability of Equality Equations](https://leetcode.com/problems/satisfiability-of-equality-equations/) / [:man_technologist:](satisfiability_of_eqs.h)

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

## [:ok_hand: 839. Similar String Groups](https://leetcode.com/problems/similar-string-groups) / [:man_technologist:](similar_string_groups.h)

<details><summary markdown="span">Question</summary>

```markdown
Two strings X and Y are similar if we can swap two letters (in different
positions) of X, so that it equals Y. Also two strings X and Y are similar if
they are equal. For example,
- "tars" and "rats" are similar (swapping at positions 0 and 2), and
- "rats" and "arts" are similar,
- but "star" is not similar to "tars", "rats", or "arts".

Each group is such that a word is in the group if and only if it is similar to
at least one other word in the group.


These form two connected groups by similarity:
- {"tars", "rats", "arts"} and {"star"}.

- Notice that "tars" and "arts" are in the same group even though they are not
  similar.

We are given a list strs of strings where every string in strs is an anagram of
every other string in strs. How many groups are there?

Input: strs = ["tars","rats","arts","star"]
Output: 2

Input: strs = ["omv","ovm"]
Output: 1
```

</details>

------------------------------------------------------------------------------

## [:bulb: 1579. Remove Max Number of Edges to Keep Graph Fully Traversable](https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable) / [:man_technologist:](remove_max_edges_to_keep_fully_traversable.h)

<details><summary markdown="span">Question</summary>

```markdown
Alice and Bob have an undirected graph of n nodes and three types of edges:

- Type 1: Can be traversed by Alice only.
- Type 2: Can be traversed by Bob only.
- Type 3: Can be traversed by both Alice and Bob.

Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional
edge of type typei between nodes ui and vi, find the maximum number of edges you
can remove so that after removing the edges, the graph can still be fully
traversed by both Alice and Bob.

The graph is fully traversed by Alice and Bob if starting from any node, they
can reach all other nodes.

Return the maximum number of edges you can remove, or return -1 if Alice and Bob
cannot fully traverse the graph.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 947. Most Stones Removed with Same Row or Column](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/) / [:man_technologist:](most_stones_removed_with_same_row_or_col_uf.h)

- check problem statement and dfs solution in [here](../graph/README.md#💡-947-most-stones-removed-with-same-row-or-column-🎯)

------------------------------------------------------------------------------

## [:persevere: 1697. Checking Existence of Edge Length Limited Paths](https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths) / [:man_technologist:](existence_of_edge_lenth_limited_path.h)

<details><summary markdown="span">Question</summary>

```markdown
An undirected graph of n nodes is defined by edgeList, where
- edgeList[i] = [ui, vi, disi] denotes an edge between nodes ui and vi with
  distance disi.
- Note that there may be multiple edges between two nodes.

Given an array queries, where queries[j] = [pj, qj, limitj], your task is to
determine for each queries[j] whether there is a path between pj and qj such
that each edge on the path has a distance strictly less than limitj .

Return a boolean array answer, where answer.length == queries.length and
the jth value of answer is true if there is a path for queries[j] is true, and
false otherwise.

Input: n = 3, edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]],
              queries = [[0,1,2],[0,2,5]]
Output: [false,true]

- between 0 and 1 there is no path where each distance is less than 2
- there is a path (0 -> 1 -> 2) of two edges with distances less than 5
```

</details>

------------------------------------------------------------------------------

## [:dizzy_face: 2421. Number of Good Paths](https://leetcode.com/problems/number-of-good-paths/) / [:man_technologist:](number_of_good_paths.h)

<details><summary markdown="span">Question</summary>

```markdown
There is a tree (i.e. a connected, undirected graph with no cycles) consisting
of n nodes numbered from `0` to `n - 1` and exactly `n - 1` edges.

You are given a 0-indexed integer array vals of length n where vals[i] denotes
the value of the ith node.

You are also given a 2D integer array edges where `edges[i] = [ai, bi]` denotes
that there exists an undirected edge connecting nodes ai and bi.

A good path is a simple path that satisfies the following conditions:

- The starting node and the ending node have the same value.
- All nodes between the starting node and the ending node have values less than
  or equal to the starting node (i.e. the starting node's value should be the
  maximum value along the path).

Return the number of distinct good paths.

Note that a path and its reverse are counted as the same path.
For example, 0 -> 1 is considered to be the same as 1 -> 0.
A single node is also considered as a valid path.

Input: vals = [1,3,2,1,3], edges = [[0,1],[0,2],[2,3],[2,4]]
Output: 6

nodeIdx(val) below:

        0(1)
    1(3)     2(2)
           3(1) 4(3)

Explanation: There are 5 good paths consisting of a single node.
There is 1 additional good path: nodeIdx: 1 -> 0 -> 2 -> 4.

(The reverse path 4 -> 2 -> 0 -> 1 is treated as the same as 1 -> 0 -> 2 -> 4.)
Note that 0 -> 2 -> 3 is not a good path because vals[2] > vals[0].

```

</details>

------------------------------------------------------------------------------


## [Use union-find to solve Bipartition](../graph/README.md#solve-bipartition-with-union-find)
