# Graph

- [:notebook:](https://js-notes.vercel.app/software_engineering/ds_and_algos/graph)


## [:ok_hand: 1557. Minimum Number of Vertices to Reach All Nodes](https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes) / [:man_technologist:](min_num_of_vertices_to_all_nodes.h)

<details><summary markdown="span">Question</summary>

```markdown
Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and
an array edges where edges[i] = [from_i, to_i] represents a directed edge from
node from_i to node to_i.

Find the smallest set of vertices from which all nodes in the graph are
reachable. It's guaranteed that a unique solution exists.

Notice that you can return the vertices in any order.


Input: n = 6, edges = [[0,1],[0,2],[2,5],[3,4],[4,2]]
Output: [0,3]

0 ->１
　＼__>2 ->5
      ^
     /
3-->4

Explanation: From 0 we can reach [0,1,2,5]. From 3 we can reach [3,4,2,5].
             So we output [0,3].

```

</details>

------------------------------------------------------------------------------


## Bipartite

## Solve bipartition with union-find

## [:bulb: 886. Possible Bipartition](https://leetcode.com/problems/is-graph-bipartite/) / [:man_technologist:](possible_bipartite.h)

- Here we listed the union find way to solve bipartition. You can also do the DFS validation way like [below](#bulb-785-is-graph-bipartite--man_technologist)

<details><summary markdown="span">Question</summary>

```markdown
We want to split a group of n people (labeled from 1 to n)
into two groups of any size.

Each person may dislike some other people, and they should not go into the same group.

Given the integer n and the array dislikes where dislikes[i] = [ai, bi]
indicates that the person labeled ai does not like the person labeled bi

return true if it is possible to split everyone into two groups in this way.
```

</details>

------------------------------------------------------------------------------

## Solve bipartition with dfs validation

## [:bulb: 785. Is Graph Bipartite](https://leetcode.com/problems/is-graph-bipartite/) / [:man_technologist:](is_graph_bipartite.h)

- Here we do the DFS validation way, you can also try union find way like [above](#bulb-886-possible-bipartition--man_technologist)

<details><summary markdown="span">Question</summary>

```markdown
There is an undirected graph with n nodes
- where each node is numbered between 0 and n - 1.

You are given a 2D adjacent array graph,
- where graph[u] is an array of nodes that node u is adjacent to.

The graph has the following properties:
- There are no self-edges (graph[u] does not contain u).
- There are no parallel edges (graph[u] does not contain duplicate values).
- If v is in graph[u], then u is in graph[v] (the graph is undirected).

The graph may not be connected,
- meaning there may be two nodes u and v such that there is no path between them.

A graph is **bipartite** if
- the nodes can be partitioned into two independent sets A and B
- such that every edge in the graph connects a node in set A and a node in set B.

- Return true if and only if it is bipartite.
```

</details>

------------------------------------------------------------------------------

## Model as graph

## [:ok_hand: 1376. Time Needed to Inform All Employees](https://leetcode.com/problems/time-needed-to-inform-all-employees) / [:man_technologist:](time_needed_to_inform_all_employees.h)

<details><summary markdown="span">Question</summary>

```markdown
A company has n employees with a unique ID for each employee from 0 to n - 1.
The head of the company is the one with headID.

Each employee has one direct manager given in the manager array where manager[i]
is the direct manager of the i-th employee, manager[headID] = -1.

Also, it is guaranteed that the subordination relationships have a tree structure.

The head of the company wants to inform all the company employees of an urgent
piece of news. He will inform his direct subordinates, and they will inform
their subordinates, and so on until all employees know about the urgent news.

The i-th employee needs informTime[i] minutes to inform all of his direct
subordinates (i.e., After informTime[i] minutes, all his direct subordinates can
start spreading the news).

Return the number of minutes needed to inform all the employees about the urgent
news.

Input: n = 6, headID = 2, manager = [2,2,-1,2,2,2], informTime = [0,0,1,0,0,0]
Output: 1

    2
0 1 3 4 5
the manager 2 of all the employees needs 1 minute to inform them all.
```

</details>

------------------------------------------------------------------------------


## [:bulb: 2101. Detonate the Maximum Bombs](https://leetcode.com/problems/detonate-the-maximum-bombs) / [:man_technologist:](detonate_the_max_bombs.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given a list of bombs. The range of a bomb is defined as the area where
its effect can be felt.

This area is in the shape of a circle with the center as the location of the bomb.

The bombs are represented by a 0-indexed 2D integer array bombs where

- bombs[i] = [xi, yi, ri].
- xi and yi denote the X-coordinate and Y-coordinate of the location of the ith
  bomb, whereas ri denotes the radius of its range.

You may choose to detonate a single bomb. When a bomb is detonated, it will
detonate all bombs that lie in its range. These bombs will further detonate the
bombs that (its center)　lie in their ranges.

Given the list of bombs, return the maximum number of bombs that can be
detonated if you are allowed to detonate only one bomb.

Check example on leetcode for clarity
```

</details>

------------------------------------------------------------------------------


## [:bulb: 2115. Find All Possible Recipes from Given Supplies](https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/) / [:man_technologist:](find_all_possible_recipes.h)

<details><summary markdown="span">Question</summary>

```markdown
You have information about n different recipes.
You are given a string array recipes and a 2D string array ingredients.
The ith recipe has the name recipes[i], and you can create it if you have all
the needed ingredients from ingredients[i].

Ingredients to a recipe may need to be created from other recipes, i.e.,
ingredients[i] may contain a string that is in recipes.

You are also given a string array supplies containing all the ingredients that
you initially have, and you have an infinite supply of all of them.

Return a list of all the recipes that you can create.
You may return the answer in any order.

Note that two recipes may contain each other in their ingredients.

Input:
- recipes = ["bread","sandwich"]
- ingredients = [["yeast","flour"],["bread","meat"]]
- supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich"]

Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
```

</details>

------------------------------------------------------------------------------

## [:dizzy_face: 1153. String Transforms Into Another String](https://leetcode.com/problems/string-transforms-into-another-string/) / [:man_technologist:](string_to_another_string.h)

<details><summary markdown="span">Question</summary>

```markdown
Given two strings str1 and str2 of the same length, determine whether you can
transform str1 into str2 by doing zero or more conversions.

In one conversion you can convert **all occurrences** of one character in str1
to any other lowercase English character.

Return true if and only if you can transform str1 into str2.

Input: str1 = "aabcc", str2 = "ccdee"
Output: true
Explanation: Convert 'c' to 'e' then 'b' to 'd' then 'a' to 'c'.
Note that the order of conversions matter. Example, if you convert a to c first,
str1 will becomes ccbcc, so eventually when you do c-> conversion, it would have
gives eebee, and str1 will never equal to str2.
```

</details>

------------------------------------------------------------------------------

## Connected component


## [:ok_hand: 2492. Minimum Score of a Path Between Two Cities](https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities) / [:man_technologist:](min_score_of_a_path_between_2_cities.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given a positive integer n representing n cities numbered from 1 to n.
You are also given a 2D array roads where roads[i] = [ai, bi, distancei]
- indicates that there is a bidirectional road between cities ai and bi with a
  distance equal to distance_i.

- The cities graph is not necessarily connected.
- The score of a path between two cities is defined as the minimum distance of a
  road in this path.
- Return the minimum possible score of a path between cities 1 and n.

Note:

- A path is a sequence of roads between two cities.
- It is allowed for a path to contain the same road multiple times, and you can
  visit cities 1 and n multiple times along the path.
- The test cases are generated such that there is at least one path between 1
  and n.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 947. Most Stones Removed with Same Row or Column](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/) / [:man_technologist:](most_stones_removed_with_same_row_or_col.h)

- Can be done through [union find](../union_find/most_stones_removed_with_same_row_or_col_uf.h) as well

<details><summary markdown="span">Question</summary>

```markdown
On a 2D plane, we place n stones at some integer coordinate points.

Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as
another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the
location of the ith stone, return the largest possible number of stones that can
be removed.

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
```

</details>

------------------------------------------------------------------------------

## Use concept in Tarjan's SCC

## [:persevere: 2360. Longest Cycle in a Graph](https://leetcode.com/problems/longest-cycle-in-a-graph) / [:man_technologist:](longest_cycle_in_a_graph.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given a directed graph of n nodes numbered from 0 to n - 1, where each
node has at most one outgoing edge.

The graph is represented with a given 0-indexed array edges of size n,
indicating that there is a directed edge from node i to node edges[i].

If there is no outgoing edge from node i, then edges[i] == -1.

Return the length of the longest cycle in the graph. If no cycle exists, return -1.

A cycle is a path that starts and ends at the same node.


Input: edges = [3,3,4,2,3]
Output: 3
Explanation: The longest cycle in the graph is the cycle: 2 -> 4 -> 3 -> 2.
The length of this cycle is 3, so 3 is returned.
```

</details>

------------------------------------------------------------------------------

## [Topological sort](https://js-notes.vercel.app/software_engineering/ds_and_algos/graph_topological_sort)

## [:bulb: 269. Alien Dictionary](https://leetcode.com/problems/alien-dictionary/) / [:man_technologist:](alien_dictionary.h)

<details><summary markdown="span">Question</summary>

```markdown
There is a new alien language that uses the English alphabet.
However, the order among the letters is unknown to you.

You are given a list of strings words from the alien language's dictionary,
where the strings in words are sorted lexicographically by the rules of this new language.

Return a string of the unique letters in the new alien language sorted in lexicographically increasing order by the new language's rules.

If there is no solution, return "".
If there are multiple solutions, return any of them.

Input: words = ["wrt","wrf","er","ett","rftt"]
Output: "wertf"

Input: words = ["z","x","z"]
Output: ""

Input: words = ["abc","ab"]
Output: ""
```

</details>

------------------------------------------------------------------------------

## [:bulb: 1857. Largest Color Value in a Directed Graph](https://leetcode.com/problems/largest-color-value-in-a-directed-graph) / [:man_technologist:](largest_color_val_in_directed_graph.h)

<details><summary markdown="span">Question</summary>

```markdown
There is a directed graph of n colored nodes and m edges. The nodes are numbered
from 0 to n - 1.

You are given a string colors where colors[i] is a lowercase English letter
representing the color of the ith node in this graph (0-indexed).

You are also given a 2D array edges where edges[j] = [aj, bj] indicates that
there is a directed edge from node aj to node bj.

A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk
such that there is a directed edge from xi to xi+1 for every 1 <= i < k.

The color value of the path is the number of nodes that are colored the most
frequently occurring color along that path.

Return the largest color value of any valid path in the given graph, or -1 if
the graph contains a cycle.
```

</details>

------------------------------------------------------------------------------


- [Single source shortest path](graph_sssp/README.md)