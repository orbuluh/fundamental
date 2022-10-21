# Graph [:notebook:](../notes/algorithms.md#dynamic-programming)

# Bipartite

## [:bulb: 785. Is Graph Bipartite](https://leetcode.com/problems/is-graph-bipartite/) [:dart:](is_graph_bipartite.h)
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

# Dijkstra
- [778. Swim in Rising Water](../backtracking/README.md#bulb-778-swim-in-rising-waterhttpsleetcodecomproblemsswim-in-rising-water-dartmatchstickstosquareh)


# Model as graph

## [:bulb: 2115. Find All Possible Recipes from Given Supplies](https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/) [:dart:](find_all_possible_recipes.h)
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

## [:exploding_head: 1153. String Transforms Into Another String](https://leetcode.com/problems/string-transforms-into-another-string/) [:dart:](string_to_another_string.h)
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