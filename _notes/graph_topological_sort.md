# [Graph: 1. Topological sort](https://en.wikipedia.org/wiki/Topological_sorting)

- a topological sort is a graph traversal in which each node v is visited only after all its dependencies are visited.
- A topological ordering is possible if and only if the graph has no directed cycles, that is, if it is a directed acyclic graph (DAG).
- **Any DAG has at least one topological ordering**, and algorithms are known for constructing **a** topological ordering of **any DAG** in **linear time in the number of nodes plus the number of edges**.
- Topological sorting is **possible even when the DAG has disconnected components**.


## Topological sort with DFS

- The high-level pseudo algorithm

```markdown
Pick an unvisited node
- begin with the selected node, DFS exploring all unvisited nodes.
- when you reach a node with no unvisited neighbor, add the current node to the
  topological ordering in reverse order, then backtrack back to see if parent
  node contains other unvisited neighbor ...
By doing above, each selection basically make sure we traverse part of the
  graph - we continue this process until all nodes are visited
```

- By doing so, each node n gets prepended to the output list L only after considering all other nodes which depend on n (all descendants of n in the graph).
- Specifically, when the algorithm adds node n, we are guaranteed that all nodes which depend on n are already in the output list L:
  - they were added to L either by the recursive call to visit() which ended
    before the call to visit n, or by a call to visit() which started even
    before the call to visit n.
- Since each edge and node is visited once, the algorithm runs in linear time.

- Here, as topological sort is for DAG, what if there is a cycle? You can utilize 2 node sets to detect the cycle. The first set `tempMark` is inserted with a node when you are just trying to dfs a node. When the node's dependencies are fully explored, you put the node from the `tempMark` to the second set `permMark` - `permMark` basically store node that is fully traversed already.
- When you visit a node that is in `tempMark` - it should mean that you cycle back to the node while doing dfs - which means there is a cycle.
- The resulting algos look like:

```python
result = []
permMark = set()
tempMark = set()
for node in allNodes:
  if node not in permMark:
    dfs(node)

def dfs(node):
  if node in permMark: return
  if node in tempMark: terminate # cycle detect

  tempMark.add(node)
  for dep in graph[node]:
    dfs(dep)

  tempMark.remove(node)
  permMark.add(node)
  result = [node] + result
```

## Iterative topological sort / Khan's algorithm

- Find a list of "0-indegree nodes" which have no incoming edges.
  These nodes have no dependencies (no incoming edges).
- Initialize an empty list to store the sorted order of nodes.
- While there are still nodes in the "0-indegree nodes" list:
  - a. Remove a node from the "0-indegree nodes" list.
  - b. Add the node to the sorted list.
  - c. For each node connected to the removed node by a directed edge:
    - i. Remove the edge from the graph.
    - ii. If the connected node has no other incoming edges, add it to the
      "0-indegree nodes" list.
- If there are no remaining edges in the graph, the sorted list now contains
  a valid topological order. If there are still edges left, the graph has at
  least one cycle, and topological sorting is not possible.

**What's the rationale for the cycle part?**

- If the algorithm has processed all the nodes with no incoming edges but there
  are still directed edges remaining in the graph, then the graph must have a cycle.
- Why? When Kahn's algorithm encounters a graph with a cycle, it cannot add any
  vertices in the cycle to the "0-indegree nodes" list since each vertex in the
  cycle has at least one incoming edge. As a result, the algorithm cannot
  process these vertices, and they remain unvisited. If there are still edges
  left in the graph after the algorithm has processed all the start nodes, this
  indicates the presence of at least one cycle in the graph, and topological
  sorting is not possible.
