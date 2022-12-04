# [Graph: 1. Topological sort](https://en.wikipedia.org/wiki/Topological_sorting)

- a topological sort is a graph traversal in which each node v is visited only after all its dependencies are visited.
- A topological ordering is possible if and only if the graph has no directed cycles, that is, if it is a directed acyclic graph (DAG).
- **Any DAG has at least one topological ordering**, and algorithms are known for constructing **a** topological ordering of **any DAG** in **linear time in the number of nodes plus the number of edges**.
- Topological sorting is **possible even when the DAG has disconnected components**.
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