# Graph: 3. All pairs shortest path / APSP

## Floyd Warshall Algorithm

- from [WilliamFiset](https://youtu.be/4NQ3HnhyNfQ)


**Idea**

- Gradually build up all intermediate route between node i and j to find the optimal path.

```txt
    __  c __
  /         \
 /           v
a ---------->b

```

- Say we are finding shortest path among a -> b. Suppose there is a third node, c, such that `w(a, c) + w(c, b) < w(a, b)`, then we should route through intermediate c instead of go straight a -> b
- The goal is to eventually consider going through all possible intermediate nodes on paths of different length. So for all pairs O(V^2), we check the possibility of putting an intermediate node, so the overall complexity is O(V^3)
- This can basically be done with DP, where `DP[k][i][j]` stores the result of trying intermediate node from node i to node k as the intermediate node of i -> j
- In the outmost loop, it's on the k dimension, which means you are trying a new intermediate node. So it's guaranteed that it's not an overlapped subproblem.

**The DP recurrence**


```cpp
Assume m[i][j] is the adjacent matrix of the graph
dp[k][i][j] = m[i][k] iff k == 0

Otherwise

dp[k][i][j] = min(
  dp[k-1][i][j], // The best distance from i to j while routing through [0, k-1]
  dp[k-1][i][k] + dp[k-1][k][j] // The best distance routing through k
                                // while reutilizing the solution we built up before
)
```

- As each time you are adding a new intermediate node, you can actually just keep an O(V^2) DP matrix and do the swap technique after each iteration.
- So space complexity should be O(V^2)