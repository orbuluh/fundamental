# Dynamic programming

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

TODO: [Check the nice collections from discussion thread](https://leetcode.com/discuss/general-discussion/665604/Important-and-Useful-links-from-all-over-the-LeetCode)

- DP for Beginners [Problems | Patterns | Sample Solutions] by @wh0ami
- DP Patterns by @aatalyk
- Knapsack problems by @old_monk
- How to solve DP - String? Template and 4 Steps to be followed by @igooglethings
- Dynamic Programming Questions thread by @karansingh1559
- DP Classification helpful notes by @adityakrverma
- How to approach DP problems by @heroes3001
- Iterative DP for subset sum problems by @yuxiangmusic
- DP problems summary (problem categorization) by @richenyunqi
- Categorization of Leetcode DP problems by @chuka231
- Must do Dynamic Programming Category wise by @mahesh_nagarwal
- Dynamic programming is simple by @omgitspavel
- Dynamic Programming on subsets with examples by @DBabichev
- DP is easy (Thinking process) by @teampark