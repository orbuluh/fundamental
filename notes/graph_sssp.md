# Graph: Single source shortest path / SSSP

**Problems / implementations**

- [here](../graph/graph_sssp/README.md)

## Dijkstra Algorithm

- [Resource](https://youtu.be/pSqmAO-m7Lk)
- An SSSP algorithm for  non-negative edge weights.
  - This ensures once a node is visited, its optimal path can not be improved further by taking an edge through negative weight.
  - Basically ensure the algorithm can act with greedy manner to always select the most promising node.
- Complexity typically `O(E * log(V))`

**Pseudo code**

```markdown
1. Maintain a `dist` array where the distance to every node is `inf`. Mark the `distance` to the start node `s` to be 0.
2. Maintain a PQ with (`distance`, `nodeIdx`) pairs, which tell you node to visit next based on sorted min `distance`.
3. Insert `(0, s)` into PQ and loop while PQ is not empty.
4. Pull out **the next most promising pair** (`distance`, `nodeIdx`)
5. Iterate over all edges outwards from the current node and relax each edge appending a new (`distance`, `nodeIdx`) to PQ for every relaxation
   - (ignoring a pair if `dist` array already find a quicker way to reach the new node)
```

**Building path from Dijkstra**

- Based on above algorithm, keep another array to keep track of the previous node to a current node in dist . Then we could reconstruct the shortest path accordingly.

**Early termination if you just need to reach to specific target node**

- Dijkstra processes each next most promising node in order.
- So if the target node have been reached, its shortest distance will not change as more future nodes are visited.

**Optimization for dense graph**

- **Indexed Priority Queue (IPQ)**
  - The original algorithm insert all the feasible (`distance`, `nodeIdx`) pair in `O(log(n)`, and “lazily” remove stale edges in PQ.
  - When doing this, one `nodeIdx` could have several entires in the PQ, with different value of distance.For dense graph, this would be costly.
  - The “eager” version of Dijkstra **avoids duplicated key-value pairs** and support efficient updates by using IPQ.
  - The difference of using IPQ is that for the same `nodeIdx`, whenever we saw a smaller `distance`, we can simply update the `distance` in the entry instead of making duplicated `nodeIdx` entries in the PQ.

- **D-ary heap for the IPQ**
  - In the context of Dijkstra on dense graph, there are more updates (i.e. `decreaseKey` operation) than `dequeue` operations.
  - A D-ary heap where a node having D children would be more feasible than general binary heap for IPQ. This speeds up decrease key operations at the expense of more costly removals.
  - Ideally improving the whole complexity to `O(E * log(V))` to `O(E * log_{E/V}(V))`




