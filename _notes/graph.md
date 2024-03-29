# Graph

## Shortest path high-level comparison

- from [WilliamFiset](https://youtu.be/4NQ3HnhyNfQ)

|     | BFS | Dijkstra | Bellmon-Ford | Floyd-Warshall |
|---  |--- |--- |--- |--- |
|Complexity| O(V+E) | O((V + E)logV) | O(VE) | O(V^3) |
|Recommend graph size | large | large/medium | medium/small | small |
|can do ASAP? | only on unweighted graphs | O | Bad | Yes!|
|can detect negative cycle? | X | X | O | O |
|SP on graph with weighted edges | Can't derive answer | Best | Works | Bad in general |
|SP on graph with unweighted edges | Best | Ok | Bad | Bad in general |

## [Single Source Shortest Path](graph_sssp.md)

## [All Pairs Shortest Path](graph_apsp.md)

## [Topological Sort](graph_topological_sort.md)

## [Tarjan's Strongly Connected Component](graph_tarjan_scc.md)

## [Max flow / Ford-Fulker Method](graph_max_flow.md)

## [Bipartite](graph_bipartite.md)



TODOs concept
```
- Vertex cover
- Independent set

Vertex cover: set of vertices that includes at least one endpoint of every edge of the graph
Independent set: set of vertices in a graph, no two of which are adjacent
Matching: in an undirected graph, is a set of edges without common vertices

The complement of a vertex cover in any graph is an independent set, so a minimum vertex cover is complementary to a maximum independent set.

In any bipartite graph, the number of edges in a maximum matching equals the number of vertices in a minimum vertex cover. (Kőnig's theorem)

Finally, in any bipartite graph (V=A u B, E \in A x B), the number of edges in a maximum matching equals the maximum flow in a network (V'=V u {s,t}, E', c(e)=1 for e \in E'), with source s, sink t and E' containing:
s->a for a \in A
a->b for a \in A, b \in B
b->t for b \in B

In the 1349. Maximum Students Taking Exam problem, if we construct undirected graph G with tiles in the mxn grid as vertices and edges for all pairs of conflicting chairs, then G is bipartite: there is no edge between two tiles with even column numbers and no edge between tiles with odd column numbers. The answer we seek is the size of the maximum independent set.
```