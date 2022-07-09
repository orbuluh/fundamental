# Heap
## Quick facts
- The tree maintain either parent >= child or parent <= child. **Not left <= parent <= right.**
- **Heapify is O(n)**
- insert is O(log(n))
- HeapSort is O(nlog(n))
### more about [:link: `heapify`](https://stackoverflow.com/questions/9755721/how-can-building-a-heap-be-on-time-complexity)
- [:link: siftUp/siftDown animation](https://youtu.be/5iBUTMWGtIQ)
- siftDown and siftUp are themselves O(log(n))
- The number of operations required for siftDown and siftUp is proportional to the distance the node may have to move.
- If we are going to choose either siftdown or siftup, we choose to siftdown (e.g. sift top node down), as tree has fewer node at the top, and more node at the bottom.
- [My notes :orange_book:](../srcs/heapify.jpeg) -> from [src](http://www.cs.umd.edu/~meesh/351/mount/lectures/lect14-heapsort-analysis-part.pdf)


# Dynamic programming
- DP's goal is finding **overlapping sub-problems** that can be memorized.
  - To memorize the sub-problems, each of them is basically a "DP state" (a.k.a optimal substructure), where the state is represented by parameters.
  - You need to think about what parameters could contribute a "unique" state.
  - The state, or the result of a subproblem should be unique:
    - It should not matter where you come from. If you reach state with specific set of parameters, the result is the same.
  - The main difference between DP and divide and conquer is that DP tries out multiple choices of smaller subproblems, subproblems generally recur across different recursive calls; In most divide-and-conquer algorithms, all the subproblems are distinct and there’s no point in caching their solutions.
- Another way to think about DP is: **Suppose someone handed us an optimal solution to us. What must it look like?**