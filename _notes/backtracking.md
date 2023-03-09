# Backtracking

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