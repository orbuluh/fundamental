# Algorithm notes

## Dynamic programming

- DP's goal is finding **overlapping sub-problems** that can be memorized.
  - To memorize the sub-problems, each of them is basically a "DP state" (a.k.a optimal substructure), where the state is represented by parameters.
- You need to think about what parameters could contribute a **"unique" state.**
- The state, or the result of a subproblem need to be unique:
  - It should not matter where you come from. If you reach state with specific set of parameters, the result is the same.
  - As it's unique, you can memorize it and return without recomputing in constant time - which is what DP is about, **optimizing a brute-force search such that the overlapped subproblem isn't recomputed through memorization.**
- The main difference between DP and divide and conquer is that DP tries out multiple choices of smaller subproblems, subproblems generally recur across different recursive calls.
  - In most divide-and-conquer algorithms, all the subproblems are distinct and there’s no point in caching their solutions.
- Another way to think about DP is: **Suppose someone handed us an optimal solution to us. What must it look like?**
- [Nice video](https://youtu.be/aPQY__2H3tE) with its five steps of solving DP:

```markdown
1. Visualize subproblems (should be a acyclic graph)
2. Find appropriate subproblems
3. Find relationships among subproblems
4. Generalize the relationships
5. Implementing by solving subproblems in order.
```

## Backtracking

- 3 main components
  - **choice**: decisions to make in each step
  - **constraints**: your decision is restricted somehow
  - **goal**: eventually converge to a goal

**Backtracking v.s. DFS**

- Backtracking is something that happens during search, but it also refers to a specific problem-solving technique where a lot of backtracking is done. [src](https://stackoverflow.com/a/3156208/4924135)
  - The more specific usage refers to a problem-solving strategy that is similar to depth-first search but backtracks when it realizes that it's not worth continuing down some subtree.
  - a naive DFS blindly visits each node until it reaches the goal. Yes, it "backtracks" on leaf nodes. But a backtracker also backtracks on useless branches.
- Backtracking is DFS for implicit tree, while DFS is backtracking without pruning. [src](https://stackoverflow.com/a/17891070/4924135)
  - When the search space of a problem is visited by backtracking, the implicit tree gets traversed and pruned in the middle of it.
  - Yet for DFS, the tree/graph it deals with is explicitly constructed and unacceptable cases have already been thrown, i.e. pruned, away before any search is done.

## Substring matching

- [KMP :notebook:](kmp.md)
- [Rolling hash :notebook:](rolling_hash.md)

## Graph

- check [:notebook:](graph.md)
