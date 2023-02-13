# :shinto_shrine: Fundamentals :shinto_shrine:

:frog: :thinking: :exploding_head: :bulb: :star_struck: :sunrise:

Quote from [HTDP](https://htdp.org/)
> * ... many elements of the general design recipe apply to the design of algorithms ... The key to designing algorithms is the “generation” step, which often means **dividing up the problem. And figuring out a novel way of dividing a problem requires insight.**
> * ... programmers must thoroughly understand the underlying ideas so that they can code up algorithms and have the program **communicate with future readers.** The best way to get acquainted with the idea is to **study a wide range of examples and to develop a sense for the kinds of generative recursions that may show up in the real world.**

<br/>

## [Notes for algo/DS deep-dive :book:](_notes/README.md)


**[Algorithm notes](_notes/tree_traversal.md)**




- Binary search




- Dynamic programming




- Backtracking




- Substring matching




- Graph




- Preorder iterative




- Morris traversal


**[Bitwise](_notes/bitwise.md)**




- Size of integers in C++




- Two's complement




- Reset the last/rightmost set bit: `x & (x - 1)`




- Detect is power of 2: `(x & (x - 1)) == 0`




- Get the last/rightmost set bit: `x - (x & (x - 1))`




- Isolate the least significant bit: `x & (-x)`




- Detect if two integers have opposite signs: `f = (X ^ Y) < 0`




- Common mask




- Bitwise rounding to pow of 2 (useful for memory alignment): `size = (size + alignment-1) & ~(alignment-1)`


**[Data structures](_notes/data_structures.md)**




- (Tree) map are sorted by keys `map`, `set`, `multimap`, `multiset`




- BST




- Binary index tree (BIT)




- Segment tree




- Monotonic Queue/Stack


**[Data structures: All kinds of Heap](_notes/ds_all_kinds_of_heap.md)**




- (Binary) heap




- Binomial heap




- Fibonacci heap


**[Data structures: Union–find data structure](_notes/union_find.md)**





**[Graph: 1. Topological sort](_notes/graph_topological_sort.md)**





**[Graph: 2. Single source shortest path / SSSP](_notes/graph_sssp.md)**




- Generic structure of shortest path (SP)




- Shortest path in DAGs




- Dijkstra Algorithm




- Bellman Ford Algorithm


**[Graph: 3. All pairs shortest path / APSP](_notes/graph_apsp.md)**




- Floyd Warshall Algorithm


**[Graph: 4. Bipartite](_notes/graph_bipartite.md)**





**[Graph: 5. Max flow / min cut / Ford-Fulker method](_notes/graph_max_flow.md)**





**[Math](_notes/math.md)**




- Modular multiplication property




- Sampling algorithms


**[Math: Reservoir sampling](_notes/reservoir_sampling.md)**





**[Range query: Binary indexed tree](_notes/binary_index_tree.md)**





**[Range query: Segment tree](_notes/segment_tree.md)**





**[Substring matching: KMP (Knuth–Morris–Pratt) algorithm for pattern matching](_notes/kmp.md)**





**[Substring matching: Rolling hash](_notes/rolling_hash.md)**






<br/>

# Problems listed: 240

:ok_hand: x 57
:bulb: x 140
:persevere: x 19
:dizzy_face: x 18
:exploding_head: x 6


- [2 pointers](problem_sets/2_ptrs/README.md): 7

- [Backtracking](problem_sets/backtracking/README.md): 18

- [Binary search](problem_sets/binary_search/README.md): 12

- [Bitwise](problem_sets/bitwise/README.md): 7

- [Divide and Conquer](problem_sets/divide_and_conquer/README.md): 4

- [DP: 0/1 knapsack like recursion structure](problem_sets/dp/dp_01_knapsack/README.md): 5

- [DP: DFS + memorization](problem_sets/dp/dp_dfs_memorization/README.md): 7

- [DP: State transition](problem_sets/dp/dp_state_transition/README.md): 10

- [DP: String match](problem_sets/dp/dp_string_match/README.md): 2

- [DP: Subarray (contiguous, Kadane's Algorithm)](problem_sets/dp/dp_subarray_kadane/README.md): 5

- [DP: Subsequence](problem_sets/dp/dp_subseq/README.md): 6

- [DP: Unbounded knapsack like recursion structure](problem_sets/dp/dp_unbounded_knapsack/README.md): 4

- [DP: Misc hard recursion](problem_sets/dp/dp_z_misc_hard_recursion/README.md): 7

- [Data structure design](problem_sets/ds_design/README.md): 5

- [Graph](problem_sets/graph/README.md): 6

- [Graph: Single source shortest path](problem_sets/graph/graph_sssp/README.md): 6

- [Greedy](problem_sets/greedy/README.md): 17

- [Jump table/line](problem_sets/greedy/jump_table/README.md): 6

- [Meeting room like questions](problem_sets/greedy/meeting_room_like/README.md): 7

- [Linked list](problem_sets/linked_list/README.md): 9

- [Math](problem_sets/math/README.md): 9

- [Misc](problem_sets/misc/README.md): 15

- [Monotonic Stack/Queue](problem_sets/monotonic/README.md): 14

- [Range Query](problem_sets/range_query/README.md): 4

- [Binary Indexed Tree](problem_sets/range_query/binary_indexed_tree/README.md): 1

- [Segment tree](problem_sets/range_query/segment_tree/README.md): 3

- [Recursion](problem_sets/recursion/README.md): 16

- [Fixed size sliding window](problem_sets/sliding_window/fixed_size/README.md): 2

- [Sliding window with 2 pointers](problem_sets/sliding_window/with_2_ptrs/README.md): 5

- [Sorting](problem_sets/sorting/README.md): 6

- [Substring matching algorithm](problem_sets/substr_matching/README.md): 1

- [Tree](problem_sets/tree/README.md): 8

- [Trie](problem_sets/trie/README.md): 2

- [Union find](problem_sets/union_find/README.md): 4

---


# [2 pointers](problem_sets/2_ptrs/README.md)


- :ok_hand: 1047. Remove All Adjacent Duplicates In String



- :ok_hand: 151. Reverse Words in a String



- :bulb: 16. 3Sum Closest



- :bulb: 11. Container With Most Water



- :bulb: 1295. Find Median from Data Stream



- :persevere: 777. Swap Adjacent in LR String



- :persevere: 838. Push Dominoes



## Subarray sliding window algorithm



## Circular sort



## Quick select



# [Backtracking](problem_sets/backtracking/README.md)


## State walking



- :ok_hand: 39. Combination Sum



- :ok_hand: 131. Palindrome Partitioning



- :bulb: 93. Restore IP Addresses



- :bulb: 31. Next Permutation



- :bulb: 491. Non-decreasing Subsequences



- :bulb: 473. Matchsticks to Square



- :bulb: 410. Split Array Largest Sum



- :bulb: 465. Optimal Account Balancing



- :bulb: 1088. Confusing Number II



## Grid walking



- :ok_hand: 490. The Maze



- :bulb: 489. Robot Room Cleaner



- :bulb: 417. Pacific Atlantic Water Flow



- :persevere: 1293. Shortest Path in a Grid with Obstacles Elimination



## BFS



- :ok_hand: 841. Keys and Rooms



- :bulb: 1926. Nearest Exit from Entrance in Maze



- :bulb: 1129. Shortest Path with Alternating Colors



## BFS from multiple points



- :bulb: 1162. As Far from Land as Possible



## Backtracking the BFS path



- :persevere: 126. Word Ladder II



## [Backtracking with binary search](../binary_search/README.md#backtracking-x-binary-search)



# [Binary search](problem_sets/binary_search/README.md)


- :ok_hand: 2389. Longest Subsequence With Limited Sum



- :ok_hand: 74. Search a 2D Matrix



- :bulb: 34. Find First and Last Position of Element in Sorted Array



- :bulb: 33. Search in Rotated Sorted Array



- :bulb: 81. Search in Rotated Sorted Array II



- :persevere: 658. Find K Closest Elements



- :persevere: 378. Kth Smallest Element in a Sorted Matrix



- :dizzy_face: 4. Median of Two Sorted Arrays



## Backtracking x Binary search



- :persevere: 1102. Path With Maximum Minimum Value



- :dizzy_face: 410. Split Array Largest Sum



## Interval related questions



- :ok_hand: 729. My Calendar I



- :bulb: 715. Range Module



# [Bitwise](problem_sets/bitwise/README.md)


## [Two's complement](../../_notes/bitwise.md#twos-complement)



- :bulb: 371. Sum of Two Integers



## basic operations



- :ok_hand: 190. Reverse Bits



- :ok_hand: 338. Counting Bits



## xor: `a^a = 0; b^0 = b; b^a^a = b`



- :ok_hand: 268. Missing Number



- :ok_hand: 645. Set Mismatch



## Reset the last set bit: `x & (x - 1)`



- :ok_hand: 268. Missing Number



## Detect power of 2: `(x & (x - 1) == 0)`



- :ok_hand: 1680. Concatenation of Consecutive Binary Numbers



# [Divide and Conquer](problem_sets/divide_and_conquer/README.md)


- :ok_hand: 823. Binary Trees With Factors



- :bulb: 23. Merge k Sorted Lists



- :bulb: 889. Construct Binary Tree from Preorder and Postorder Traversal



- :persevere: 894. All Possible Full Binary Trees



# [DP: 0/1 knapsack like recursion structure](problem_sets/dp/dp_01_knapsack/README.md)


- :bulb: 474. Ones and Zeroes



- :bulb: 416. Partition Equal Subset Sum



- :bulb: 115. Distinct Subsequences



- :bulb: 1235. Maximum Profit in Job Scheduling



- :persevere: 494. Target Sum



# [DP: DFS + memorization](problem_sets/dp/dp_dfs_memorization/README.md)


- :ok_hand: 931. Minimum Falling Path Sum



- :ok_hand: 576. Out of Boundary Paths



- :bulb: 1770. Maximum Score from Performing Multiplication Operations



- :bulb: 494. Target Sum



- :bulb: 871. Minimum Number of Refueling Stops



- :bulb: 1473. Paint House III



- :exploding_head: 1531. String Compression II



# [DP: State transition](problem_sets/dp/dp_state_transition/README.md)


- :ok_hand: 198. House Robber



- :ok_hand: 740. Delete and Earn



- :ok_hand: 309. Best Time to Buy and Sell Stock with Cooldown



- :ok_hand: 1220. Count Vowels Permutation



- :bulb: 188. Best Time to Buy and Sell Stock IV



- :bulb: 799. Champagne Tower



- :bulb: 1335. Minimum Difficulty of a Job Schedule



- :bulb: 1937. Maximum Number of Points with Cost



- :dizzy_face: 790. Domino and Tromino Tiling



- :exploding_head: 818. Race Car



# [DP: String match](problem_sets/dp/dp_string_match/README.md)


- :bulb: 718. Maximum Length of Repeated Subarray



- :bulb: 72. Edit Distance



# [DP: Subarray (contiguous, Kadane's Algorithm)](problem_sets/dp/dp_subarray_kadane/README.md)


- :ok_hand: 53. Maximum Subarray



- :bulb: 918. Maximum Sum Circular Subarray



- :bulb: 363. Max Sum of Rectangle No Larger Than K



- :bulb: 974. Subarray Sums Divisible by K



- :dizzy_face: 2272. Substring With Largest Variance



# [DP: Subsequence](problem_sets/dp/dp_subseq/README.md)


- :bulb: 1143. Longest Common Subsequence



- :bulb: 647. Palindromic Substrings



- :bulb: 516. Longest Palindromic Subsequence



- :bulb: 300. Longest Increasing Subsequence



- :bulb: 1626. Best Team With No Conflicts



- :bulb: 1130. Minimum Cost Tree From Leaf Values



# [DP: Unbounded knapsack like recursion structure](problem_sets/dp/dp_unbounded_knapsack/README.md)


- :ok_hand: 377. Combination Sum IV



- :bulb: 1155. Number of Dice Rolls With Target Sum



- :bulb: 518. Coin Change II



- :bulb: 91. Decode Ways



# [DP: Misc hard recursion](problem_sets/dp/dp_z_misc_hard_recursion/README.md)


- :persevere: 907. Sum of Subarray Minimums



- :dizzy_face: 446. Arithmetic Slices II - Subsequence



- :dizzy_face: 629. K Inverse Pairs Array



- :dizzy_face: 837. New 21 Game



- :exploding_head: 376. Wiggle Subsequence



- :exploding_head: 465. Optimal Account Balancing



## Reroot technique with DP



- :exploding_head: 834. Sum of Distances in Tree



# [Data structure design](problem_sets/ds_design/README.md)


- :ok_hand: 232. Implement Queue using Stacks



- :ok_hand: 380. Insert Delete GetRandom O(1)



- :ok_hand: 692. Top K Frequent Words



- :bulb: 460. LFU Cache



- :persevere: 146. LRU Cache



# [Graph](problem_sets/graph/README.md)


## Bipartite



## Solve bipartition with union-find



- :bulb: 886. Possible Bipartition



## Solve bipartition with dfs validation



- :bulb: 785. Is Graph Bipartite



## Model as graph



- :bulb: 2115. Find All Possible Recipes from Given Supplies



- :dizzy_face: 1153. String Transforms Into Another String



## Connected component



- :bulb: 947. Most Stones Removed with Same Row or Column



## [Topological sort](../../_notes/graph.md#topological-sort)



- :bulb: 269. Alien Dictionary



# [Graph: Single source shortest path](problem_sets/graph/graph_sssp/README.md)


## Dijkstra



- :ok_hand: 743. Network Delay Time



- :bulb: 787. Cheapest Flights Within K Stops



## Grid walking using Dijkstra, "Dijkstra's algorithm is BFS with a priority queue"



- :bulb: 778. Swim in Rising Water



- :bulb: 1102. Path With Maximum Minimum Value



- :bulb: 1514. Path with Maximum Probability



- :bulb: 1631. Path With Minimum Effort



## Bellmon-Ford Specific (e.g. contains negative cycle)



# [Greedy](problem_sets/greedy/README.md)


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



- :bulb: 2136. Earliest Possible Day of Full Bloom



- :dizzy_face: 1354. Construct Target Array With Multiple Sums



- :exploding_head: 218. The Skyline Problem



# [Jump table/line](problem_sets/greedy/jump_table/README.md)


- :ok_hand: 452. Minimum Number of Arrows to Burst Balloons



- :bulb: 45. Jump Game II



- :bulb: 1024. Video Stitching



- :bulb: 1326. Minimum Number of Taps to Open to Water a Garden



- :bulb: 739. Daily Temperatures



- :bulb: 1834. Single-Threaded CPU



# [Meeting room like questions](problem_sets/greedy/meeting_room_like/README.md)


- :bulb: 56. Merge Intervals



- :bulb: 352. Data Stream as Disjoint Intervals



- :bulb: 759. Employee Free Time



- :bulb: 57. Insert Interval



- :bulb: 732. My Calendar III



- :bulb: 630. Course Schedule III



- :bulb: 2402. Meeting Rooms III



# [Linked list](problem_sets/linked_list/README.md)


## Basic operations on linked list



- :ok_hand: 141. Linked List Cycle



- :ok_hand: 206. Reverse Linked List



- :ok_hand: 876. Middle of the Linked List



- :ok_hand: 328. Odd Even Linked List



## Composite operations on linked list



- :bulb: 61. Rotate List



- :bulb: 19. Remove Nth Node From End of List



- :bulb: 92. Reverse Linked List II



- :bulb: 234. Palindrome Linked List



- :bulb: 445. Add Two Numbers II



# [Math](problem_sets/math/README.md)


- :bulb: 462. Minimum Moves to Equal Array Elements II



- :bulb: 2244. Minimum Rounds to Complete All Tasks



- :bulb: 1359. Count All Valid Pickup and Delivery Options



- :bulb: 1071. Greatest Common Divisor of Strings



## Geometry



- :ok_hand: 593. Valid Square



- :ok_hand: 478. Generate Random Point in a Circle



- :bulb: 1610. Maximum Number of Visible Points



- :bulb: 149. Max Points on a Line



## Fisher–Yates shuffle



- :bulb: 384. Shuffle an Array



# [Misc](problem_sets/misc/README.md)


## Great algo to do something



- :ok_hand: 916. Word Subsets



- :ok_hand: 334. Increasing Triplet Subsequence



- :ok_hand: 249. Group Shifted Strings



- :bulb: 1470. Shuffle the Array



- :bulb: 189. Rotate Array



- :bulb: 833. Find And Replace in String



- :bulb: 1209. Remove All Adjacent Duplicates in String II



- :dizzy_face: 2306. Naming a Company



- :dizzy_face: 856. Score of Parentheses



## Nice implementation idea



- :ok_hand: 12. Integer to Roman



## Hard indices manipulation



- :bulb: 48. Rotate Image



- :persevere: 6. Zigzag Conversion



- :persevere: 835. Image Overlap



## Brainteaser



- :bulb: 458. Poor Pigs



- :dizzy_face: 932. Beautiful Array



# [Monotonic Stack/Queue](problem_sets/monotonic/README.md)


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



# [Range Query](problem_sets/range_query/README.md)


## Prefix sum



- :ok_hand: 560. Subarray Sum Equals K



- :bulb: 523. Continuous Subarray Sum



- :bulb: 1664. Ways to Make a Fair Array



## The jump line method



- :bulb: 2158. Amount of New Area Painted Each Day



# [Binary Indexed Tree](problem_sets/range_query/binary_indexed_tree/README.md)


- :ok_hand: 307. Range Sum Query - Mutable



# [Segment tree](problem_sets/range_query/segment_tree/README.md)


- :ok_hand: 307. Range Sum Query - Mutable



- :bulb: 2158. Amount of New Area Painted Each Day



- :dizzy_face: 315. Count of Smaller Numbers After Self



# [Recursion](problem_sets/recursion/README.md)


- :ok_hand: 38. Count and Say



- :ok_hand: 1026. Maximum Difference Between Node and Ancestor



- :ok_hand: 669. Trim a Binary Search Tree



- :ok_hand: 814. Binary Tree Pruning



- :ok_hand: 1443. Minimum Time to Collect All Apples in a Tree



- :bulb: 236. Lowest Common Ancestor of a Binary Tree



- :bulb: 105. Construct Binary Tree from Preorder and Inorder Traversal



- :bulb: 889. Construct Binary Tree from Preorder and Postorder Traversal



- :bulb: 230. Kth Smallest Element in a BST



- :bulb: 222. Count Complete Tree Nodes



- :bulb: 124. Binary Tree Maximum Path Sum



- :bulb: 2246. Longest Path With Different Adjacent Characters



- :bulb: 394. Decode String



- :persevere: 897. Increasing Order Search Tree



- :persevere: 426. Convert Binary Search Tree to Sorted Doubly Linked List



- :dizzy_face: 114. Flatten Binary Tree to Linked List



# [Fixed size sliding window](problem_sets/sliding_window/fixed_size/README.md)


- :bulb: 1423. Maximum Points You Can Obtain from Cards



- :persevere: 30. Substring with Concatenation of All Words



# [Sliding window with 2 pointers](problem_sets/sliding_window/with_2_ptrs/README.md)


- :bulb: 76. Minimum Window Substring



- :bulb: 567. Permutation in String



- :bulb: 904. Fruit Into Baskets



- :bulb: 159. Longest Substring with At Most Two Distinct Characters



- :bulb: 438. Find All Anagrams in a String



# [Sorting](problem_sets/sorting/README.md)


- :bulb: 1996. The Number of Weak Characters in the Game



## Bucket sort



- :bulb: 1710. Maximum Units on a Truck



## Bubble sort



- :bulb: 899. Orderly Queue



## Merge sort



- :bulb: 315. Count of Smaller Numbers After Self



## Circular sort



- :ok_hand: 645. Set Mismatch



## Quick select



- :bulb: 215. Kth Largest Element in an Array



# [Substring matching algorithm](problem_sets/substr_matching/README.md)


- :bulb: 718. Maximum Length of Repeated Subarray



## Sliding window of Substring



# [Tree](problem_sets/tree/README.md)


- :ok_hand: 235. Lowest Common Ancestor of a Binary Search Tree



- :ok_hand: 236. Lowest Common Ancestor of a Binary Tree



- :ok_hand: 297. Serialize and Deserialize Binary Tree



## Tree traversal



- :ok_hand: 144. Binary Tree Preorder Traversal



- :ok_hand: 987. Vertical Order Traversal of a Binary Tree



- :bulb: 94. Binary Tree Inorder Traversal with Iterative



## BST



- :ok_hand: 173. Binary Search Tree Iterator



- :bulb: 653. Two Sum IV - Input is a BST



# [Trie](problem_sets/trie/README.md)


- :bulb: 212. Word Search II



- :dizzy_face: 336. Palindrome Pairs



# [Union find](problem_sets/union_find/README.md)


- :ok_hand: 1971. Find if Path Exists in Graph



- :ok_hand: 990. Satisfiability of Equality Equations



- :bulb: 947. Most Stones Removed with Same Row or Column



- :dizzy_face: 2421. Number of Good Paths



## [Use union-find to solve Bipartition](../graph/README.md#solve-bipartition-with-union-find)


