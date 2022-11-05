# Graph

# [Topological sort](https://en.wikipedia.org/wiki/Topological_sorting)

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

# SSSP: Dijkstra Algorithm (Single Source Shortest Path)

- [Resource](https://youtu.be/pSqmAO-m7Lk)
- An SSSP algorithm for  non-negative edge weights.
  - This ensures once a node is visited, its optimal path can not be improved further by taking an edge through negative weight.
  - Basically ensure the algorithm can act with greedy manner to always select the most promising node.
- Complexity typically `O(E * log(V))`

## Pseudo code

1. Maintain a `dist` array where the distance to every node is `inf`. Mark the `distance` to the start node `s` to be 0.
2. Maintain a PQ with (`nodeIdx`, `distance`) pairs, which tell you node to visit next based on sorted min `distance`.
3. Insert (s, 0) into PQ and loop while PQ is not empty. Pull out **the next most promising pair** (`nodeIdx`, `distance`)
4. Iterate over all edges outwards from the current node and relax each edge appending a new (`nodeIdx`, `distance`) to PQ for every relaxation
   - (ignoring a pair if `dist` array already find a quicker way to reach the new node)

## Building path from Dijkstra

- Based on above algorithm, keep another array to keep track of the previous node to a current node in dist . Then we could reconstruct the shortest path accordingly.

## Early termination if you just need to reach to specific target node

- Dijkstra processes each next most promising node in order.
- So if the target node have been reached, its shortest distance will not change as more future nodes are visited.

## Optimization for dense graph

### Indexed Priority Queue (IPQ)

- The original algorithm insert all the feasible (`nodeIdx`, `distance`) pair in `O(log(n)`, and “lazily” remove stale edges in PQ.
- When doing this, one `nodeIdx` could have several entires in the PQ, with different value of distance. For dense graph, this would be costly.
- The “eager” version of Dijkstra avoids duplicated key-value pairs and support efficient updates by using IPQ.
- The difference of using IPQ is that for the same `nodeIdx`, whenever we saw a smaller `distance`, we can simply update the `distance` in the entry instead of making duplicated `nodeIdx` entries in the PQ.

### D-ary heap for the IPQ

- In the context of Dijkstra on dense graph, there are more updates (i.e. decreaseKey operation) than dequeue operations.
- A D-ary heap where a node having D children would be more feasible than general binary heap for IPQ. This speeds up decrease key operations at the expense of more costly removals.
- Ideally improving the whole complexity to `O(E * log(V))` to `O(E * log_{E/V}(V))`
