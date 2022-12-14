# :shinto_shrine: Fundamentals :shinto_shrine:

:frog: :thinking: :exploding_head: :bulb: :star_struck: :sunrise:

Quote from [HTDP](https://htdp.org/)
> * ... many elements of the general design recipe apply to the design of algorithms ... The key to designing algorithms is the “generation” step, which often means **dividing up the problem. And figuring out a novel way of dividing a problem requires insight.**
> * ... programmers must thoroughly understand the underlying ideas so that they can code up algorithms and have the program **communicate with future readers.** The best way to get acquainted with the idea is to **study a wide range of examples and to develop a sense for the kinds of generative recursions that may show up in the real world.**

<br/>

## [Notes for algo/DS deep-dive :book:](_notes/README.md)


**[Algorithm notes](_notes/algorithms.md)**




- Binary search




- Dynamic programming




- Backtracking




- Morris traversal




- Substring matching




- Graph


**[Bitwise](_notes/bitwise.md)**




- Size of integers in C++




- Two's complement




- Reset the last/rightmost set bit: `x & (x - 1)`




- Detect is power of 2: `(x & (x - 1)) == 0`




- Get the last/rightmost set bit: `x - (x & (x - 1))`




- Isolate the least significant bit: `x & (-x)`




- Detect if two integers have opposite signs: `f = (X ^ Y) < 0`




- Common mask


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

# Problems listed: 202

- [2 pointers](problem_sets/2_ptrs/README.md): 10

- [Backtracking](problem_sets/backtracking/README.md): 12

- [Binary search](problem_sets/binary_search/README.md): 11

- [Bitwise](problem_sets/bitwise/README.md): 7

- [Divide and Conquer](problem_sets/divide_and_conquer/README.md): 4

- [DP: 0/1 knapsack like recursion structure](problem_sets/dp/dp_01_knapsack/README.md): 5

- [DP: DFS + memorization](problem_sets/dp/dp_dfs_memorization/README.md): 7

- [DP: State transition](problem_sets/dp/dp_state_transition/README.md): 9

- [DP: String match](problem_sets/dp/dp_string_match/README.md): 2

- [DP: Subarray (contiguous, Kadane's Algorithm)](problem_sets/dp/dp_subarray_kadane/README.md): 3

- [DP: Subsequence](problem_sets/dp/dp_subseq/README.md): 4

- [DP: Unbounded knapsack like recursion structure](problem_sets/dp/dp_unbounded_knapsack/README.md): 4

- [DP: Misc hard recursion](problem_sets/dp/dp_z_misc_hard_recursion/README.md): 6

- [Data structure design](problem_sets/ds_design/README.md): 3

- [Graph](problem_sets/graph/README.md): 5

- [Graph: Single source shortest path](problem_sets/graph/graph_sssp/README.md): 5

- [Greedy](problem_sets/greedy/README.md): 16

- [Meeting room like questions](problem_sets/greedy/meeting_room_like/README.md): 7

- [Linked list](problem_sets/linked_list/README.md): 9

- [Math](problem_sets/math/README.md): 6

- [Misc: some great algo to do something](problem_sets/misc/README.md): 12

- [Monotonic Stack/Queue](problem_sets/monotonic/README.md): 13

- [Range Query](problem_sets/range_query/README.md): 4

- [Binary Indexed Tree](problem_sets/range_query/binary_indexed_tree/README.md): 1

- [Segment tree](problem_sets/range_query/segment_tree/README.md): 3

- [Recursion](problem_sets/recursion/README.md): 14

- [Sliding window](problem_sets/sliding_window/README.md): 2

- [Sorting](problem_sets/sorting/README.md): 6

- [Substring matching algorithm](problem_sets/substr_matching/README.md): 1

- [Tree](problem_sets/tree/README.md): 7

- [Trie](problem_sets/trie/README.md): 2

- [Union find](problem_sets/union_find/README.md): 2

---


# [2 pointers](problem_sets/2_ptrs/README.md)


- :ok_hand: 1047. Remove All Adjacent Duplicates In String



- :ok_hand: 151. Reverse Words in a String



- :thinking: 16. 3Sum Closest



- :thinking: 11. Container With Most Water



- :persevere: 777. Swap Adjacent in LR String



- :persevere: 838. Push Dominoes



## Circular sort



## Quick select



## Substring window algorithm



- :thinking: 76. Minimum Window Substring



- :thinking: 159. Longest Substring with At Most Two Distinct Characters



- :thinking: 438. Find All Anagrams in a String



- :thinking: 1295. Find Median from Data Stream



# [Backtracking](problem_sets/backtracking/README.md)


## State walking



- :ok_hand: 39. Combination Sum



- :thinking: 31. Next Permutation



- :thinking: 473. Matchsticks to Square



- :thinking: 410. Split Array Largest Sum



- :thinking: 465. Optimal Account Balancing



- :thinking: 1088. Confusing Number II



## Grid walking



- :ok_hand: 490. The Maze



- :thinking: 489. Robot Room Cleaner



- :thinking: 417. Pacific Atlantic Water Flow



- :persevere: 1293. Shortest Path in a Grid with Obstacles Elimination



## BFS



- :thinking: 1926. Nearest Exit from Entrance in Maze



## Backtracking the BFS path



- :persevere: 126. Word Ladder II



## [Backtracking with binary search](../binary_search/README.md#backtracking-x-binary-search)



# [Binary search](problem_sets/binary_search/README.md)


- :ok_hand: 74. Search a 2D Matrix



- :thinking: 34. Find First and Last Position of Element in Sorted Array



- :thinking: 33. Search in Rotated Sorted Array



- :thinking: 81. Search in Rotated Sorted Array II



- :persevere: 658. Find K Closest Elements



- :persevere: 378. Kth Smallest Element in a Sorted Matrix



- :dizzy_face: 4. Median of Two Sorted Arrays



## Backtracking x Binary search



- :persevere: 1102. Path With Maximum Minimum Value



- :dizzy_face: 410. Split Array Largest Sum



## Interval related questions



- :ok_hand: 729. My Calendar I



- :thinking: 715. Range Module



# [Bitwise](problem_sets/bitwise/README.md)


## [Two's complement](../../_notes/bitwise.md#twos-complement)



- :thinking: 371. Sum of Two Integers



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



- :thinking: 23. Merge k Sorted Lists



- :thinking: 889. Construct Binary Tree from Preorder and Postorder Traversal



- :persevere: 894. All Possible Full Binary Trees



# [DP: 0/1 knapsack like recursion structure](problem_sets/dp/dp_01_knapsack/README.md)


- :thinking: 474. Ones and Zeroes



- :persevere: 494. Target Sum



- :thinking: 416. Partition Equal Subset Sum



- :thinking: 115. Distinct Subsequences



- :thinking: 1235. Maximum Profit in Job Scheduling



# [DP: DFS + memorization](problem_sets/dp/dp_dfs_memorization/README.md)


- :ok_hand: 931. Minimum Falling Path Sum



- :ok_hand: 576. Out of Boundary Paths



- :thinking: 1770. Maximum Score from Performing Multiplication Operations



- :thinking: 494. Target Sum



- :thinking: 871. Minimum Number of Refueling Stops



- :thinking: 1473. Paint House III



- :exploding_head: 1531. String Compression II



# [DP: State transition](problem_sets/dp/dp_state_transition/README.md)


- :ok_hand: 198. House Robber



- :ok_hand: 740. Delete and Earn



- :ok_hand: 309. Best Time to Buy and Sell Stock with Cooldown



- :ok_hand: 1220. Count Vowels Permutation



- :thinking: 188. Best Time to Buy and Sell Stock IV



- :thinking: 799. Champagne Tower



- :thinking: 1335. Minimum Difficulty of a Job Schedule



- :thinking: 1937. Maximum Number of Points with Cost



- :exploding_head: 818. Race Car



# [DP: String match](problem_sets/dp/dp_string_match/README.md)


- :thinking: 718. Maximum Length of Repeated Subarray



- :thinking: 72. Edit Distance



# [DP: Subarray (contiguous, Kadane's Algorithm)](problem_sets/dp/dp_subarray_kadane/README.md)


- :ok_hand: 53. Maximum Subarray



- :thinking: 363. Max Sum of Rectangle No Larger Than K



- :dizzy_face: 2272. Substring With Largest Variance



# [DP: Subsequence](problem_sets/dp/dp_subseq/README.md)


- :thinking: 647. Palindromic Substrings



- :thinking: 516. Longest Palindromic Subsequence



- :thinking: 300. Longest Increasing Subsequence



- :thinking: 1130. Minimum Cost Tree From Leaf Values



# [DP: Unbounded knapsack like recursion structure](problem_sets/dp/dp_unbounded_knapsack/README.md)


- :ok_hand: 377. Combination Sum IV



- :thinking: 1155. Number of Dice Rolls With Target Sum



- :thinking: 518. Coin Change II



- :thinking: 91. Decode Ways



# [DP: Misc hard recursion](problem_sets/dp/dp_z_misc_hard_recursion/README.md)


- :persevere: 907. Sum of Subarray Minimums



- :dizzy_face: 446. Arithmetic Slices II - Subsequence



- :dizzy_face: 629. K Inverse Pairs Array



- :dizzy_face: 837. New 21 Game



- :exploding_head: 376. Wiggle Subsequence



- :exploding_head: 465. Optimal Account Balancing



# [Data structure design](problem_sets/ds_design/README.md)


- :ok_hand: 380. Insert Delete GetRandom O(1)



- :ok_hand: 692. Top K Frequent Words



- :persevere: 146. LRU Cache



# [Graph](problem_sets/graph/README.md)


## Bipartite



- :thinking: 785. Is Graph Bipartite



## Model as graph



- :thinking: 2115. Find All Possible Recipes from Given Supplies



- :dizzy_face: 1153. String Transforms Into Another String



## Connected component



- :thinking: 947. Most Stones Removed with Same Row or Column



## [Topological sort](../../_notes/graph.md#topological-sort)



- :thinking: 269. Alien Dictionary



# [Graph: Single source shortest path](problem_sets/graph/graph_sssp/README.md)


## Dijkstra



- :ok_hand: 743. Network Delay Time



## Grid walking using Dijkstra, "Dijkstra's algorithm is BFS with a priority queue"



- :thinking: 778. Swim in Rising Water



- :thinking: 1102. Path With Maximum Minimum Value



- :thinking: 1514. Path with Maximum Probability



- :thinking: 1631. Path With Minimum Effort



## Bellmon-Ford Specific (e.g. contains negative cycle)



# [Greedy](problem_sets/greedy/README.md)


- :ok_hand: 2178. Maximum Split of Positive Even Integers



- :thinking: 763. Partition Labels



- :thinking: 1414. Find the Minimum Number of Fibonacci Numbers Whose Sum Is K



- :thinking: 316. Remove Duplicate Letters



- :thinking: 659. Split Array into Consecutive Subsequences



- :thinking: 936. Stamping The Sequence



- :thinking: 1055. Shortest Way to Form String



- :thinking: 135. Candy



- :thinking: 1578. Minimum Time to Make Rope Colorful



- :thinking: 406. Queue Reconstruction by Height



- :thinking: 1383. Maximum Performance of a Team



- :thinking: 871. Minimum Number of Refueling Stops



- :thinking: 665. Non-decreasing Array



- :thinking: 2136. Earliest Possible Day of Full Bloom



- :dizzy_face: 1354. Construct Target Array With Multiple Sums



- :exploding_head: 218. The Skyline Problem



# [Meeting room like questions](problem_sets/greedy/meeting_room_like/README.md)


- :ok_hand: 56. Merge Intervals



- :ok_hand: 1024. Video Stitching



- :thinking: 759. Employee Free Time



- :thinking: 57. Insert Interval



- :thinking: 732. My Calendar III



- :thinking: 630. Course Schedule III



- :thinking: 2402. Meeting Rooms III



# [Linked list](problem_sets/linked_list/README.md)


## Basic operations on linked list



- :ok_hand: 141. Linked List Cycle



- :ok_hand: 206. Reverse Linked List



- :ok_hand: 876. Middle of the Linked List



- :ok_hand: 328. Odd Even Linked List



## Composite operations on linked list



- :thinking: 61. Rotate List



- :thinking: 19. Remove Nth Node From End of List



- :thinking: 92. Reverse Linked List II



- :thinking: 234. Palindrome Linked List



- :thinking: 445. Add Two Numbers II



# [Math](problem_sets/math/README.md)


- :thinking: 462. Minimum Moves to Equal Array Elements II



- :thinking: 1359. Count All Valid Pickup and Delivery Options



## Geometry



- :ok_hand: 593. Valid Square



- :ok_hand: 478. Generate Random Point in a Circle



- :thinking: 1610. Maximum Number of Visible Points



## Fisher–Yates shuffle



- :thinking: 384. Shuffle an Array



# [Misc: some great algo to do something](problem_sets/misc/README.md)


- :ok_hand: 916. Word Subsets



- :ok_hand: 334. Increasing Triplet Subsequence



- :ok_hand: 249. Group Shifted Strings



- :thinking: 189. Rotate Array



- :thinking: 833. Find And Replace in String



- :thinking: 1209. Remove All Adjacent Duplicates in String II



- :dizzy_face: 856. Score of Parentheses



## Nice implementation idea



- :ok_hand: 12. Integer to Roman



## Hard indices manipulation



- :thinking: 48. Rotate Image



- :persevere: 835. Image Overlap



## Brainteaser



- :thinking: 458. Poor Pigs



- :dizzy_face: 932. Beautiful Array



# [Monotonic Stack/Queue](problem_sets/monotonic/README.md)


- :thinking: 496. Next Greater Element I



- :thinking: 503. Next Greater Element II



- :thinking: 556. Next Greater Element III



- :thinking: 239. Sliding Window Maximum



- :thinking: 1696. Jump Game VI



- :thinking: 901. Online Stock Span



- :thinking: 84. Largest Rectangle in Histogram



- :thinking: 853. Car Fleet



- :persevere: 2454. Next Greater Element IV



- :persevere: 2289. Steps to Make Array Non-decreasing



- :persevere: 907. Sum of Subarray Minimums



- :dizzy_face: 1776. Car Fleet II



- :dizzy_face: 1130. Minimum Cost Tree From Leaf Values



# [Range Query](problem_sets/range_query/README.md)


## Prefix sum



- :ok_hand: 560. Subarray Sum Equals K



- :thinking: 523. Continuous Subarray Sum



- :thinking: 1664. Ways to Make a Fair Array



## The jump line method



- :thinking: 2158. Amount of New Area Painted Each Day



# [Binary Indexed Tree](problem_sets/range_query/binary_indexed_tree/README.md)


- :ok_hand: 307. Range Sum Query - Mutable



# [Segment tree](problem_sets/range_query/segment_tree/README.md)


- :ok_hand: 307. Range Sum Query - Mutable



- :thinking: 2158. Amount of New Area Painted Each Day



- :dizzy_face: 315. Count of Smaller Numbers After Self



# [Recursion](problem_sets/recursion/README.md)


- :ok_hand: 38. Count and Say



- :ok_hand: 1026. Maximum Difference Between Node and Ancestor



- :ok_hand: 669. Trim a Binary Search Tree



- :ok_hand: 814. Binary Tree Pruning



- :thinking: 236. Lowest Common Ancestor of a Binary Tree



- :thinking: 105. Construct Binary Tree from Preorder and Inorder Traversal



- :thinking: 889. Construct Binary Tree from Preorder and Postorder Traversal



- :thinking: 230. Kth Smallest Element in a BST



- :thinking: 222. Count Complete Tree Nodes



- :thinking: 124. Binary Tree Maximum Path Sum



- :thinking: 394. Decode String



- :persevere: 897. Increasing Order Search Tree



- :persevere: 426. Convert Binary Search Tree to Sorted Doubly Linked List



- :dizzy_face: 114. Flatten Binary Tree to Linked List



# [Sliding window](problem_sets/sliding_window/README.md)


- :thinking: 1423. Maximum Points You Can Obtain from Cards



- :persevere: 30. Substring with Concatenation of All Words



# [Sorting](problem_sets/sorting/README.md)


- :wink: 1710. Maximum Units on a Truck



- :thinking: 1996. The Number of Weak Characters in the Game



## Bubble sort



- :thinking: 899. Orderly Queue



## Merge sort



- :thinking: 315. Count of Smaller Numbers After Self



## Circular sort



- :ok_hand: 645. Set Mismatch



## Quick select



- :thinking: 215. Kth Largest Element in an Array



# [Substring matching algorithm](problem_sets/substr_matching/README.md)


- :thinking: 718. Maximum Length of Repeated Subarray



## Sliding window of Substring



# [Tree](problem_sets/tree/README.md)


- :ok_hand: 235. Lowest Common Ancestor of a Binary Search Tree



- :ok_hand: 236. Lowest Common Ancestor of a Binary Tree



- :ok_hand: 297. Serialize and Deserialize Binary Tree



## Tree traversal



- :ok_hand: 987. Vertical Order Traversal of a Binary Tree



- :thinking: 94. Binary Tree Inorder Traversal with Iterative



## BST



- :ok_hand: 173. Binary Search Tree Iterator



- :thinking: 653. Two Sum IV - Input is a BST



# [Trie](problem_sets/trie/README.md)


- :thinking: 212. Word Search II



- :dizzy_face: 336. Palindrome Pairs



# [Union find](problem_sets/union_find/README.md)


- :ok_hand: 990. Satisfiability of Equality Equations



- :thinking: 947. Most Stones Removed with Same Row or Column


