# Algorithm notes

## Dynamic programming
- DP's goal is finding **overlapping sub-problems** that can be memorized.
  - To memorize the sub-problems, each of them is basically a "DP state" (a.k.a optimal substructure), where the state is represented by parameters.
  - You need to think about what parameters could contribute a "unique" state.
  - The state, or the result of a subproblem should be unique:
    - It should not matter where you come from. If you reach state with specific set of parameters, the result is the same.
  - The main difference between DP and divide and conquer is that DP tries out multiple choices of smaller subproblems, subproblems generally recur across different recursive calls; In most divide-and-conquer algorithms, all the subproblems are distinct and there’s no point in caching their solutions.
- Another way to think about DP is: **Suppose someone handed us an optimal solution to us. What must it look like?**