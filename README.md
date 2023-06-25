# :shinto_shrine: Fundamentals :shinto_shrine:

:frog: :thinking: :exploding_head: :bulb: :star_struck: :sunrise:

Quote from [HTDP](https://htdp.org/)
> * ... many elements of the general design recipe apply to the design of algorithms ... The key to designing algorithms is the “generation” step, which often means **dividing up the problem. And figuring out a novel way of dividing a problem requires insight.**
> * ... programmers must thoroughly understand the underlying ideas so that they can code up algorithms and have the program **communicate with future readers.** The best way to get acquainted with the idea is to **study a wide range of examples and to develop a sense for the kinds of generative recursions that may show up in the real world.**

<br/>

## Cpp perfomance trick

- Use when the perfomance distribution is skewed by the trick...

```cpp
static const int io_trick = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
}();
```

<details><summary markdown="span">Explain</summary>

- The `std::cin.tie(nullptr)` and `std::cout.tie(nullptr)` calls are used to untie the `cin` and `cout` streams, respectively, from the `cout` stream.
- By default, the `std::cin` stream is tied to the `std::cout` stream, meaning that when you perform an input operation, the output stream is flushed.
- This can cause a performance overhead, especially in situations where you have a mix of input and output operations.
- By untying the streams, you avoid the unnecessary flushing and improve the overall performance.
- Declaring the `io_trick` variable as `static` in this context serves two purposes:
  - Initialization Guarantee:
    - By declaring the variable as `static`, it ensures that the initialization of the variable will happen only once during the program's lifetime.
    - The lambda function will be invoked and executed during this initialization.
    - This guarantees that the I/O trick is applied early on in the program before any input/output operations occur.
  - Scope Limitation:
    - By making the `io_trick` variable `static`, its scope is limited to the current translation unit (source file).
    - It prevents the variable from being accessible or visible to other translation units.
    - This can be desirable in situations where you want to ensure that the I/O trick is applied only in a specific file or module and does not affect the behavior of other parts of the program.


</summary></details>

## [:book: Notes for algo/DS deep-dive](_notes/README.md)

## :thinking: Problems listed: 317 ... :ok_hand: x 89 :bulb: x 170 :persevere: x 33 :dizzy_face: x 19 :exploding_head: x 6



### [2 pointers](problem_sets/2_ptrs/README.md): 10

<details><summary>Questions</summary>


  
  - :ok_hand: 946. Validate Stack Sequences
  

  
  - :ok_hand: 2390. Removing Stars From a String
  

  
  - :ok_hand: 1047. Remove All Adjacent Duplicates In String
  

  
  - :ok_hand: 151. Reverse Words in a String
  

  
  - :bulb: 16. 3Sum Closest
  

  
  - :bulb: 1498. Number of Subsequences That Satisfy the Given Sum Condition
  

  
  - :bulb: 11. Container With Most Water
  

  
  - :bulb: 1295. Find Median from Data Stream
  

  
  - :persevere: 777. Swap Adjacent in LR String
  

  
  - :persevere: 838. Push Dominoes
  

  
  ## Subarray sliding window algorithm
  

  
  ## Circular sort
  

  
  ## Quick select
  


</details>



### [Backtracking](problem_sets/backtracking/README.md): 24

<details><summary>Questions</summary>


  
  ## State walking
  

  
  - :ok_hand: 39. Combination Sum
  

  
  - :ok_hand: 131. Palindrome Partitioning
  

  
  - :bulb: 93. Restore IP Addresses
  

  
  - :bulb: 31. Next Permutation
  

  
  - :bulb: 491. Non-decreasing Subsequences
  

  
  - :bulb: 473. Matchsticks to Square
  

  
  - :bulb: 410. Split Array Largest Sum
  

  
  - :bulb: 465. Optimal Account Balancing
  

  
  - :bulb: 2477. Minimum Fuel Cost to Report to the Capital
  

  
  - :bulb: 1088. Confusing Number II
  

  
  ## Grid walking
  

  
  - :ok_hand: 490. The Maze
  

  
  - :bulb: 1254. Number of Closed Islands
  

  
  - :bulb: 489. Robot Room Cleaner
  

  
  - :bulb: 417. Pacific Atlantic Water Flow
  

  
  - :persevere: 1293. Shortest Path in a Grid with Obstacles Elimination
  

  
  ## BFS
  

  
  - :ok_hand: 841. Keys and Rooms
  

  
  - :ok_hand: 1345. Jump Game IV
  

  
  - :ok_hand: 1091. Shortest Path in Binary Matrix
  

  
  - :bulb: 662. Maximum Width of Binary Tree
  

  
  - :bulb: 1926. Nearest Exit from Entrance in Maze
  

  
  - :bulb: 1129. Shortest Path with Alternating Colors
  

  
  - :bulb: 934. Shortest Bridge
  

  
  ## BFS from multiple points
  

  
  - :bulb: 1162. As Far from Land as Possible
  

  
  ## Backtracking the BFS path
  

  
  - :persevere: 126. Word Ladder II
  

  
  ## [Backtracking with binary search](../binary_search/README.md#backtracking-x-binary-search)
  


</details>



### [Binary search](problem_sets/binary_search/README.md): 15

<details><summary>Questions</summary>


  
  - :ok_hand: 1011. Capacity To Ship Packages Within D Days
  

  
  - :ok_hand: 2389. Longest Subsequence With Limited Sum
  

  
  - :ok_hand: 74. Search a 2D Matrix
  

  
  - :ok_hand: 2187. Minimum Time to Complete Trips
  

  
  - :bulb: 34. Find First and Last Position of Element in Sorted Array
  

  
  - :bulb: 33. Search in Rotated Sorted Array
  

  
  - :bulb: 81. Search in Rotated Sorted Array II
  

  
  - :bulb: 2439. Minimize Maximum of Array
  

  
  ## [:persevere: 1802. Maximum Value at a Given Index in a Bounded Array](m-value-at-a-given-index-in-a-bounded-array) / [:man_technologist:](m_value_at_a_given_index_in_a_bound_arr.h)
  

  
  - :persevere: 658. Find K Closest Elements
  

  
  - :persevere: 378. Kth Smallest Element in a Sorted Matrix
  

  
  - :dizzy_face: 4. Median of Two Sorted Arrays
  

  
  ## Backtracking x Binary search
  

  
  - :persevere: 1102. Path With Maximum Minimum Value
  

  
  - :dizzy_face: 410. Split Array Largest Sum
  

  
  ## Interval related questions
  

  
  - :ok_hand: 729. My Calendar I
  

  
  - :bulb: 715. Range Module
  


</details>



### [Bitwise](problem_sets/bitwise/README.md): 8

<details><summary>Questions</summary>


  
  ## [Two's complement](../../_notes/bitwise.md#twos-complement)
  

  
  - :bulb: 371. Sum of Two Integers
  

  
  ## basic operations
  

  
  - :ok_hand: 190. Reverse Bits
  

  
  - :ok_hand: 338. Counting Bits
  

  
  ## xor: `a^a = 0; b^0 = b; b^a^a = b`
  

  
  - :ok_hand: 268. Missing Number
  

  
  - :ok_hand: 645. Set Mismatch
  

  
  ## `odd ^ 1 == odd - 1`, `even ^ 1 == even + 1`
  

  
  - :persevere: 540. Single Element in a Sorted Array
  

  
  ## Reset the last set bit: `x & (x - 1)`
  

  
  - :ok_hand: 268. Missing Number
  

  
  ## Detect power of 2: `(x & (x - 1) == 0)`
  

  
  - :ok_hand: 1680. Concatenation of Consecutive Binary Numbers
  


</details>



### [Divide and Conquer](problem_sets/divide_and_conquer/README.md): 5

<details><summary>Questions</summary>


  
  - :ok_hand: 823. Binary Trees With Factors
  

  
  - :bulb: 109. Convert Sorted List to Binary Search Tree
  

  
  - :bulb: 23. Merge k Sorted Lists
  

  
  - :bulb: 889. Construct Binary Tree from Preorder and Postorder Traversal
  

  
  - :persevere: 894. All Possible Full Binary Trees
  


</details>



### [DP: 0/1 knapsack like recursion structure](problem_sets/dp/dp_01_knapsack/README.md): 8

<details><summary>Questions</summary>


  
  - :bulb: 474. Ones and Zeroes
  

  
  - :bulb: 416. Partition Equal Subset Sum
  

  
  - :bulb: 115. Distinct Subsequences
  

  
  - :bulb: 1235. Maximum Profit in Job Scheduling
  

  
  - :bulb: 2218. Maximum Value of K Coins From Piles
  

  
  - :bulb: 1639. Number of Ways to Form a Target String Given a Dictionary
  

  
  - :persevere: 879. Profitable Schemes
  

  
  - :persevere: 494. Target Sum
  


</details>



### [DP: DFS + memorization](problem_sets/dp/dp_dfs_memorization/README.md): 13

<details><summary>Questions</summary>


  
  - :ok_hand: 931. Minimum Falling Path Sum
  

  
  - :ok_hand: 576. Out of Boundary Paths
  

  
  - :ok_hand: 2328. Number of Increasing Paths in a Grid
  

  
  - :bulb: 1770. Maximum Score from Performing Multiplication Operations
  

  
  - :bulb: 494. Target Sum
  

  
  - :bulb: 871. Minimum Number of Refueling Stops
  

  
  - :bulb: 1473. Paint House III
  

  
  - :bulb: 1187. Make Array Strictly Increasing
  

  
  - :bulb: 1575. Count All Possible Routes
  

  
  ## [:persevere: 1547. Minimum Cost to Cut a Stick
  

  
  - :persevere: 1140. Stone Game II
  

  
  - :persevere: 1406. Stone Game III
  

  
  - :persevere: 1444. Number of Ways of Cutting a Pizza
  

  
  - :exploding_head: 1531. String Compression II
  


</details>



### [DP: State transition](problem_sets/dp/dp_state_transition/README.md): 15

<details><summary>Questions</summary>


  
  - :ok_hand: 198. House Robber
  

  
  - :ok_hand: 740. Delete and Earn
  

  
  - :ok_hand: 309. Best Time to Buy and Sell Stock with Cooldown
  

  
  - :ok_hand: 1220. Count Vowels Permutation
  

  
  - :ok_hand: 2466. Count Ways To Build Good Strings
  

  
  - :ok_hand: 1402. Reducing Dishes
  

  
  - :bulb: 983. Minimum Cost For Tickets
  

  
  - :bulb: 2140. Solving Questions With Brainpower
  

  
  - :bulb: 1416. Restore The Array
  

  
  - :bulb: 188. Best Time to Buy and Sell Stock IV
  

  
  - :bulb: 799. Champagne Tower
  

  
  - :bulb: 1335. Minimum Difficulty of a Job Schedule
  

  
  - :bulb: 1937. Maximum Number of Points with Cost
  

  
  - :dizzy_face: 790. Domino and Tromino Tiling
  

  
  - :exploding_head: 818. Race Car
  


</details>



### [DP: String match](problem_sets/dp/dp_string_match/README.md): 4

<details><summary>Questions</summary>


  
  - :bulb: 718. Maximum Length of Repeated Subarray
  

  
  - :bulb: 72. Edit Distance
  

  
  - :bulb: 1035. Uncrossed Lines
  

  
  - :dizzy_face: 87. Scramble String
  


</details>



### [DP: Subarray (contiguous, Kadane's Algorithm)](problem_sets/dp/dp_subarray_kadane/README.md): 5

<details><summary>Questions</summary>


  
  - :ok_hand: 53. Maximum Subarray
  

  
  - :bulb: 918. Maximum Sum Circular Subarray
  

  
  - :bulb: 363. Max Sum of Rectangle No Larger Than K
  

  
  - :bulb: 974. Subarray Sums Divisible by K
  

  
  - :dizzy_face: 2272. Substring With Largest Variance
  


</details>



### [DP: Subsequence](problem_sets/dp/dp_subseq/README.md): 8

<details><summary>Questions</summary>


  
  - :bulb: 1027. Longest Arithmetic Subsequence
  

  
  - :bulb: 1143. Longest Common Subsequence
  

  
  - :bulb: 1964. Find the Longest Valid Obstacle Course at Each Position
  

  
  - :bulb: 647. Palindromic Substrings
  

  
  - :bulb: 516. Longest Palindromic Subsequence
  

  
  - :bulb: 300. Longest Increasing Subsequence
  

  
  - :bulb: 1626. Best Team With No Conflicts
  

  
  - :bulb: 1130. Minimum Cost Tree From Leaf Values
  


</details>



### [DP: Unbounded knapsack like recursion structure](problem_sets/dp/dp_unbounded_knapsack/README.md): 4

<details><summary>Questions</summary>


  
  - :ok_hand: 377. Combination Sum IV
  

  
  - :bulb: 1155. Number of Dice Rolls With Target Sum
  

  
  - :bulb: 518. Coin Change II
  

  
  - :bulb: 91. Decode Ways
  


</details>



### [DP: Misc hard recursion](problem_sets/dp/dp_z_misc_hard_recursion/README.md): 11

<details><summary>Questions</summary>


  
  - :persevere: 2448. Minimum Cost to Make Array Equal
  

  
  - :persevere: 1569. Number of Ways to Reorder Array to Get Same BST
  

  
  - :persevere: 1799. Maximize Score After N Operations
  

  
  - :persevere: 907. Sum of Subarray Minimums
  

  
  - :persevere: 956. Tallest Billboard
  

  
  - :dizzy_face: 446. Arithmetic Slices II - Subsequence
  

  
  - :dizzy_face: 629. K Inverse Pairs Array
  

  
  - :dizzy_face: 837. New 21 Game
  

  
  - :exploding_head: 376. Wiggle Subsequence
  

  
  - :exploding_head: 465. Optimal Account Balancing
  

  
  ## Reroot technique with DP
  

  
  - :exploding_head: 834. Sum of Distances in Tree
  


</details>



### [Data structure design](problem_sets/ds_design/README.md): 6

<details><summary>Questions</summary>


  
  - :ok_hand: 232. Implement Queue using Stacks
  

  
  - :ok_hand: 380. Insert Delete GetRandom O(1)
  

  
  - :ok_hand: 692. Top K Frequent Words
  

  
  - :ok_hand: 2336. Smallest Number in Infinite Set
  

  
  - :bulb: 460. LFU Cache
  

  
  - :persevere: 146. LRU Cache
  


</details>



### [Graph](problem_sets/graph/README.md): 12

<details><summary>Questions</summary>


  
  - :ok_hand: 1557. Minimum Number of Vertices to Reach All Nodes
  

  
  ## Bipartite
  

  
  ## Solve bipartition with union-find
  

  
  - :bulb: 886. Possible Bipartition
  

  
  ## Solve bipartition with dfs validation
  

  
  - :bulb: 785. Is Graph Bipartite
  

  
  ## Model as graph
  

  
  - :ok_hand: 1376. Time Needed to Inform All Employees
  

  
  - :bulb: 2101. Detonate the Maximum Bombs
  

  
  - :bulb: 2115. Find All Possible Recipes from Given Supplies
  

  
  - :dizzy_face: 1153. String Transforms Into Another String
  

  
  ## Connected component
  

  
  - :ok_hand: 2492. Minimum Score of a Path Between Two Cities
  

  
  - :bulb: 947. Most Stones Removed with Same Row or Column
  

  
  ## Use concept in Tarjan's SCC
  

  
  - :persevere: 2360. Longest Cycle in a Graph
  

  
  ## [Topological sort](../../_notes/graph/graph_topological_sort.md)
  

  
  - :bulb: 269. Alien Dictionary
  

  
  - :bulb: 1857. Largest Color Value in a Directed Graph
  


</details>



### [Graph: Single source shortest path](problem_sets/graph/graph_sssp/README.md): 6

<details><summary>Questions</summary>


  
  ## Dijkstra
  

  
  - :ok_hand: 743. Network Delay Time
  

  
  - :bulb: 787. Cheapest Flights Within K Stops
  

  
  ## Grid walking using Dijkstra, "Dijkstra's algorithm is BFS with a priority queue"
  

  
  - :bulb: 778. Swim in Rising Water
  

  
  - :bulb: 1102. Path With Maximum Minimum Value
  

  
  - :bulb: 1514. Path with Maximum Probability
  

  
  - :bulb: 1631. Path With Minimum Effort
  

  
  ## Bellmon-Ford Specific (e.g. contains negative cycle)
  


</details>



### [Greedy](problem_sets/greedy/README.md): 24

<details><summary>Questions</summary>


  
  - :ok_hand: 703. Kth Largest Element in a Stream
  

  
  - :ok_hand: 121. Best Time to Buy and Sell Stock
  

  
  - :ok_hand: 881. Boats to Save People
  

  
  - :ok_hand: 2178. Maximum Split of Positive Even Integers
  

  
  - :bulb: 134. Gas Station
  

  
  - :bulb: 763. Partition Labels
  

  
  - :bulb: 1414. Find the Minimum Number of Fibonacci Numbers Whose Sum Is K
  

  
  - :bulb: 316. Remove Duplicate Letters
  

  
  - :bulb: 659. Split Array into Consecutive Subsequences
  

  
  - :bulb: 936. Stamping The Sequence
  

  
  - :bulb: 1055. Shortest Way to Form String
  

  
  - :bulb: 135. Candy
  

  
  - :bulb: 1578. Minimum Time to Make Rope Colorful
  

  
  - :bulb: 406. Queue Reconstruction by Height
  

  
  - :bulb: 1383. Maximum Performance of a Team
  

  
  - :bulb: 871. Minimum Number of Refueling Stops
  

  
  - :bulb: 665. Non-decreasing Array
  

  
  - :bulb: 502. IPO
  

  
  - :bulb: 2136. Earliest Possible Day of Full Bloom
  

  
  - :bulb: 2542. Maximum Subsequence Score
  

  
  - :persevere: 1675. Minimize Deviation in Array
  

  
  - :persevere: 649. Dota2 Senate
  

  
  - :dizzy_face: 1354. Construct Target Array With Multiple Sums
  

  
  - :exploding_head: 218. The Skyline Problem
  


</details>



### [Jump table/line](problem_sets/greedy/jump_table/README.md): 6

<details><summary>Questions</summary>


  
  - :ok_hand: 452. Minimum Number of Arrows to Burst Balloons
  

  
  - :bulb: 45. Jump Game II
  

  
  - :bulb: 1024. Video Stitching
  

  
  - :bulb: 1326. Minimum Number of Taps to Open to Water a Garden
  

  
  - :bulb: 739. Daily Temperatures
  

  
  - :bulb: 1834. Single-Threaded CPU
  


</details>



### [Meeting room like questions](problem_sets/greedy/meeting_room_like/README.md): 7

<details><summary>Questions</summary>


  
  - :bulb: 56. Merge Intervals
  

  
  - :bulb: 352. Data Stream as Disjoint Intervals
  

  
  - :bulb: 759. Employee Free Time
  

  
  - :bulb: 57. Insert Interval
  

  
  - :bulb: 732. My Calendar III
  

  
  - :bulb: 630. Course Schedule III
  

  
  - :bulb: 2402. Meeting Rooms III
  


</details>



### [Linked list](problem_sets/linked_list/README.md): 11

<details><summary>Questions</summary>


  
  ## Basic operations on linked list
  

  
  - :ok_hand: 141. Linked List Cycle
  

  
  - :ok_hand: 142. Linked List Cycle II
  

  
  - :ok_hand: 206. Reverse Linked List
  

  
  - :ok_hand: 876. Middle of the Linked List
  

  
  - :ok_hand: 328. Odd Even Linked List
  

  
  - :ok_hand: 1721. Swapping Nodes in a Linked List
  

  
  ## [:bulb: 382. Linked List Random Node](https://leetcode.com/problems/linked-list-random-node)
  

  
  ## Composite operations on linked list
  

  
  - :bulb: 61. Rotate List
  

  
  - :bulb: 19. Remove Nth Node From End of List
  

  
  - :bulb: 92. Reverse Linked List II
  

  
  - :bulb: 234. Palindrome Linked List
  

  
  - :bulb: 445. Add Two Numbers II
  


</details>



### [Math](problem_sets/math/README.md): 12

<details><summary>Questions</summary>


  
  - :bulb: 319. Bulb Switcher
  

  
  - :bulb: 462. Minimum Moves to Equal Array Elements II
  

  
  - :bulb: 2244. Minimum Rounds to Complete All Tasks
  

  
  - :bulb: 1359. Count All Valid Pickup and Delivery Options
  

  
  - :bulb: 2348. Number of Zero-Filled Subarrays
  

  
  - :bulb: 1071. Greatest Common Divisor of Strings
  

  
  ## Geometry
  

  
  - :ok_hand: 593. Valid Square
  

  
  - :ok_hand: 478. Generate Random Point in a Circle
  

  
  - :bulb: 1610. Maximum Number of Visible Points
  

  
  - :bulb: 149. Max Points on a Line
  

  
  ## Fisher–Yates shuffle
  

  
  - :bulb: 384. Shuffle an Array
  

  
  ## Reservoir sampling
  

  
  - :bulb: 382. Linked List Random Node
  


</details>



### [Misc](problem_sets/misc/README.md): 19

<details><summary>Questions</summary>


  
  ## Good for practice
  

  
  - :ok_hand: 71. Simplify Path
  

  
  ## Great algo to do something
  

  
  - :ok_hand: 916. Word Subsets
  

  
  - :ok_hand: 334. Increasing Triplet Subsequence
  

  
  - :ok_hand: 249. Group Shifted Strings
  

  
  - :bulb: 1470. Shuffle the Array
  

  
  - :bulb: 189. Rotate Array
  

  
  - :bulb: 833. Find And Replace in String
  

  
  - :bulb: 1209. Remove All Adjacent Duplicates in String II
  

  
  - :persevere: 2444. Count Subarrays With Fixed Bounds
  

  
  - :dizzy_face: 2306. Naming a Company
  

  
  - :dizzy_face: 856. Score of Parentheses
  

  
  ## Nice implementation idea
  

  
  - :ok_hand: 1539. Kth Missing Positive Number
  

  
  - :ok_hand: 12. Integer to Roman
  

  
  - :ok_hand: 443. String Compression
  

  
  ## Hard indices manipulation
  

  
  - :bulb: 48. Rotate Image
  

  
  - :persevere: 6. Zigzag Conversion
  

  
  - :persevere: 835. Image Overlap
  

  
  ## Brainteaser
  

  
  - :bulb: 458. Poor Pigs
  

  
  - :dizzy_face: 932. Beautiful Array
  


</details>



### [Monotonic Stack/Queue](problem_sets/monotonic/README.md): 14

<details><summary>Questions</summary>


  
  - :bulb: 739. Daily Temperatures
  

  
  - :bulb: 496. Next Greater Element I
  

  
  - :bulb: 503. Next Greater Element II
  

  
  - :bulb: 556. Next Greater Element III
  

  
  - :bulb: 239. Sliding Window Maximum
  

  
  - :bulb: 1696. Jump Game VI
  

  
  - :bulb: 901. Online Stock Span
  

  
  - :bulb: 84. Largest Rectangle in Histogram
  

  
  - :bulb: 853. Car Fleet
  

  
  - :persevere: 2454. Next Greater Element IV
  

  
  - :persevere: 2289. Steps to Make Array Non-decreasing
  

  
  - :persevere: 907. Sum of Subarray Minimums
  

  
  - :dizzy_face: 1776. Car Fleet II
  

  
  - :dizzy_face: 1130. Minimum Cost Tree From Leaf Values
  


</details>



### [Range Query](problem_sets/range_query/README.md): 4

<details><summary>Questions</summary>


  
  ## Prefix sum
  

  
  - :ok_hand: 560. Subarray Sum Equals K
  

  
  - :bulb: 523. Continuous Subarray Sum
  

  
  - :bulb: 1664. Ways to Make a Fair Array
  

  
  ## The jump line method
  

  
  - :bulb: 2158. Amount of New Area Painted Each Day
  


</details>



### [Binary Indexed Tree](problem_sets/range_query/binary_indexed_tree/README.md): 1

<details><summary>Questions</summary>


  
  - :ok_hand: 307. Range Sum Query - Mutable
  


</details>



### [Segment tree](problem_sets/range_query/segment_tree/README.md): 3

<details><summary>Questions</summary>


  
  - :ok_hand: 307. Range Sum Query - Mutable
  

  
  - :bulb: 2158. Amount of New Area Painted Each Day
  

  
  - :dizzy_face: 315. Count of Smaller Numbers After Self
  


</details>



### [Recursion](problem_sets/recursion/README.md): 24

<details><summary>Questions</summary>


  
  - :ok_hand: 38. Count and Say
  

  
  - :ok_hand: 1026. Maximum Difference Between Node and Ancestor
  

  
  - :ok_hand: 669. Trim a Binary Search Tree
  

  
  - :ok_hand: 783. Minimum Distance Between BST Nodes
  

  
  - :ok_hand: 226. Invert Binary Tree
  

  
  - :ok_hand: 101. Symmetric Tree
  

  
  - :ok_hand: 814. Binary Tree Pruning
  

  
  - :ok_hand: 129. Sum Root to Leaf Numbers
  

  
  - :ok_hand: 1443. Minimum Time to Collect All Apples in a Tree
  

  
  - :bulb: 236. Lowest Common Ancestor of a Binary Tree
  

  
  - :bulb: 105. Construct Binary Tree from Preorder and Inorder Traversal
  

  
  - :bulb: 106. Construct Binary Tree from Inorder and Postorder Traversal
  

  
  - :bulb: 889. Construct Binary Tree from Preorder and Postorder Traversal
  

  
  - :bulb: 230. Kth Smallest Element in a BST
  

  
  - :bulb: 222. Count Complete Tree Nodes
  

  
  - :bulb: 958. Check Completeness of a Binary Tree
  

  
  - :bulb: 124. Binary Tree Maximum Path Sum
  

  
  - :bulb: 2246. Longest Path With Different Adjacent Characters
  

  
  - :bulb: 1372. Longest ZigZag Path in a Binary Tree
  

  
  - :bulb: 394. Decode String
  

  
  - :bulb: 427. Construct Quad Tree
  

  
  - :persevere: 897. Increasing Order Search Tree
  

  
  - :persevere: 426. Convert Binary Search Tree to Sorted Doubly Linked List
  

  
  - :dizzy_face: 114. Flatten Binary Tree to Linked List
  


</details>



### [Fixed size sliding window](problem_sets/sliding_window/fixed_size/README.md): 3

<details><summary>Questions</summary>


  
  - :ok_hand: 2090. K Radius Subarray Averages
  

  
  - :bulb: 1423. Maximum Points You Can Obtain from Cards
  

  
  - :persevere: 30. Substring with Concatenation of All Words
  


</details>



### [Sliding window with 2 pointers](problem_sets/sliding_window/with_2_ptrs/README.md): 5

<details><summary>Questions</summary>


  
  - :bulb: 76. Minimum Window Substring
  

  
  - :bulb: 567. Permutation in String
  

  
  - :bulb: 904. Fruit Into Baskets
  

  
  - :bulb: 159. Longest Substring with At Most Two Distinct Characters
  

  
  - :bulb: 438. Find All Anagrams in a String
  


</details>



### [Sorting](problem_sets/sorting/README.md): 7

<details><summary>Questions</summary>


  
  - :bulb: 1996. The Number of Weak Characters in the Game
  

  
  ## Bucket sort
  

  
  - :bulb: 1710. Maximum Units on a Truck
  

  
  ## Bubble sort
  

  
  - :bulb: 899. Orderly Queue
  

  
  ## Merge sort
  

  
  - :bulb: 315. Count of Smaller Numbers After Self
  

  
  ## Circular sort
  

  
  - :ok_hand: 645. Set Mismatch
  

  
  ## Counting sort
  

  
  - :ok_hand: 912. Sort an Array
  

  
  ## Quick select
  

  
  - :bulb: 215. Kth Largest Element in an Array
  


</details>



### [Substring matching algorithm](problem_sets/substr_matching/README.md): 2

<details><summary>Questions</summary>


  
  - :bulb: 28. Find the Index of the First Occurrence in a String
  

  
  - :bulb: 718. Maximum Length of Repeated Subarray
  

  
  ## Sliding window of Substring
  


</details>



### [Tree](problem_sets/tree/README.md): 11

<details><summary>Questions</summary>


  
  - :ok_hand: 235. Lowest Common Ancestor of a Binary Search Tree
  

  
  - :ok_hand: 236. Lowest Common Ancestor of a Binary Tree
  

  
  - :ok_hand: 297. Serialize and Deserialize Binary Tree
  

  
  - :ok_hand: 652. Find Duplicate Subtrees
  

  
  ## Tree traversal
  

  
  - :ok_hand: 144. Binary Tree Preorder Traversal
  

  
  - :ok_hand: 103. Binary Tree Zigzag Level Order Traversal
  

  
  - :ok_hand: 987. Vertical Order Traversal of a Binary Tree
  

  
  - :ok_hand: 530. Minimum Absolute Difference in BST
  

  
  - :bulb: 94. Binary Tree Inorder Traversal with Iterative
  

  
  ## BST
  

  
  - :ok_hand: 173. Binary Search Tree Iterator
  

  
  - :bulb: 653. Two Sum IV - Input is a BST
  


</details>



### [Trie](problem_sets/trie/README.md): 3

<details><summary>Questions</summary>


  
  - :ok_hand: 208. Implement Trie (Prefix Tree)
  

  
  ## [211. Design Add and Search Words Data Structure](https://leetcode.com/problems/design-add-and-search-words-data-structure) / [:man_technologist:](design_add_and_search_ds.h)
  

  
  - :bulb: 212. Word Search II
  

  
  - :dizzy_face: 336. Palindrome Pairs
  


</details>



### [Union find](problem_sets/union_find/README.md): 7

<details><summary>Questions</summary>


  
  - :ok_hand: 1971. Find if Path Exists in Graph
  

  
  - :ok_hand: 990. Satisfiability of Equality Equations
  

  
  - :ok_hand: 839. Similar String Groups
  

  
  - :bulb: 1579. Remove Max Number of Edges to Keep Graph Fully Traversable
  

  
  - :bulb: 947. Most Stones Removed with Same Row or Column
  

  
  - :persevere: 1697. Checking Existence of Edge Length Limited Paths
  

  
  - :dizzy_face: 2421. Number of Good Paths
  

  
  ## [Use union-find to solve Bipartition](../graph/README.md#solve-bipartition-with-union-find)
  


</details>


