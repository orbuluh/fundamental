# Graph: Single source shortest path / SSSP

[**Problem sets :link:**](../graph/graph_sssp/README.md)

## Dijkstra Algorithm

> from [WilliamFiset](https://youtu.be/pSqmAO-m7Lk)
- An SSSP algorithm for  non-negative edge weights.
  - This ensures once a node is visited, its optimal path can not be improved further by taking an edge through negative weight.
  - Basically ensure the algorithm can act with greedy manner to always select the most promising node.
- Complexity typically `O(E * log(V))`

**Pseudo code**

For a graph $G(V, E)$
Initialize for $v \in V$:
- $d[v] <- \infty$: stores len of shortest path to $v$
- $\Pi[v] <- NIL$: stores predecessor of $v$ in shortest path
- $d[s] <- 0$: $s$ is source vertex

Repeat:
- select an edge somehow
  - $Relax(u, v, w)$
Until you can't relax an edge any more

---

Relax(u, v, w):

- if ($d[v]$ > $d[u] + w(u, v)$)
  - $d[v]$ = $d[u] + w(u, v)$
  - $\Pi[v]$ = $u$

---

Or more concretely, it's like:

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

<br/>

---

<br/>

## Bellman Ford Algorithm

> from 1. [MIT OpenCourseWare](https://youtu.be/ozsuci5pIso) 2. [WilliamFiset](https://youtu.be/lyw4FaxrwHg)

**Quick fact**

- BF is generally not ideal for most SSSP problems because it has a time complexity of $O(EV)$.
- It is better to use Dijkstra’s algorithm, which has $O((E+V)log(V))$ when using a binary heap priority queue.
- When do we use BF then? When Dijkstra fail **because a graph has negative weights.**
- BF can detect negative cycles and determine when they occur.

**What does BF want to do?**

![](../srcs/graph_bf_do_what.JPG)

- if negative cycle exists, the path connected to any node on the negative cycle has an undefined shortest path.
- otherwise, it should output the shortest path with fewest node.

**Pseudo code**

For a graph $G(V, E)$
Initialize for $v \in V$:
- $d[v] <- \infty$: stores len of shortest path to $v$
- $\Pi[v] <- NIL$: stores predecessor of $v$ in shortest path
- $d[s] <- 0$: $s$ is source vertex

for $_$ in range($|V| - 1$)
  - for each $edge(u, v) \in E$
    - $Relax(u, v, w)$

for each $edge(u, v) \in E$
  - if $d[v] > d[u] + w(u, v)$
    - Report negative cycle

**Complexity**

- $O(VE)$, where $E = O(V^2)$, hence overall $O(V^3)$


**The intuition and proof**

- Say there exists a shortest path from $v_0$ to $v_k$ with $x$ vertex in the path, then $maximum(x) = |V| - 1$
- Why? because if it's more then $|V| - 1$, it must create cycle for a graph with only $|V|$ nodes!

> **Theorem**: If $G = (V, E)$ contains no negative cycle, then BF must find $d[v] = \delta(s, v)$ for all $v \in V$, where $\delta(s, v)$ is the shortest path from $s$ to a vertex $v$

Let $v \in V$, $p = <v_0, v_1, ..., v_k>$, and $v_0 = S$, $v_k = v$.

- Then this path $p$ is **a** shortest path with minimum number of edges.
- (Note the a, not the, because there could have several shortest path from $S$ to $v$, but we only want to find the one with minimum nodes.)
- No negative cycle implies $p$ is simple, and $k \leq |V| - 1$
- For such path $p$, since it's simple shortest path, for any 2 points $x$, $y$ on the path, their edge($x$, $y$) must be a partial of shortest path as well.
- As the algorithm initialize $d[S] = 0$, you can imagine in each iteration, as you check all the edges, you are just going to find one more edge from source that is on the shortest path. So proof by induction:

  - After 1 iteration, we have $d[v_1] = \delta(s, v_1)$ because we will relax $edge(v_0, v_1)$ in this iteration
  - After 2 iteration, we have $d[v_2] = \delta(s, v_2)$ because we will relax $edge(v_1, v_2)$ in this iteration
  - ...
  - After k iteration, we have $d[v_k] = \delta(s, v_k)$
  - After $|V| - 1$ iteration, all reachable (from $S$) vertexes must have their shortest path $\delta$ values.

> **Corollary**: If a value $d[v]$ failed to converge after $|V| - 1$ passes, then there must exists a negative cycle **reachable from the source $s$**

- After $|V| - 1$ iterations, if we find an edge that can be relaxed, that means current shortest path from $S$ to some vertex $v$ is not simple, e.g. there must exist repeated vertex in the path. 
- And because it has repeated vertex in the path, we find a cycle.
- And this cycle must be a negative weight cycle because I was able to relax the edge and reduce the weight after I added this vertex that causes a cycle.


**Side note**

- BF can either report the shortest path when there is no negative cycle, or report the existence of the negative cycle.
- If you are asking to "not walk the cycle" and report such shortest path, it becomes an NP-hard problem. And this problem is equivalent to find the longest path (which is also, NP-hard).


