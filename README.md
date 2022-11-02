# :shinto_shrine: Fundamentals :shinto_shrine:

## [Notes for algo/DS deep-dive :book:](notes/README.md)

:frog: :thinking: :exploding_head: :bulb: :star_struck: :sunrise:

Quote from [HTDP](https://htdp.org/)
> * ... many elements of the general design recipe apply to the design of algorithms ... The key to designing algorithms is the “generation” step, which often means **dividing up the problem. And figuring out a novel way of dividing a problem requires insight.**
> * ... programmers must thoroughly understand the underlying ideas so that they can code up algorithms and have the program **communicate with future readers.** The best way to get acquainted with the idea is to **study a wide range of examples and to develop a sense for the kinds of generative recursions that may show up in the real world.**

<br/>

# Problems listed: 145

- [2_ptrs](2_ptrs/README.md): 6

- [backtracking](backtracking/README.md): 9

- [binary_search](binary_search/README.md): 9

- [bitwise](bitwise/README.md): 7

- [d_and_d](d_and_d/README.md): 3

- [dp](dp/README.md): 4

- [dp/dp_01_knapsack](dp/dp_01_knapsack/README.md): 4

- [dp/dp_dfs_memorization](dp/dp_dfs_memorization/README.md): 7

- [dp/dp_state_transition](dp/dp_state_transition/README.md): 7

- [dp/dp_subarray_kadane](dp/dp_subarray_kadane/README.md): 3

- [dp/dp_subseq](dp/dp_subseq/README.md): 3

- [dp/dp_unbounded_knapsack](dp/dp_unbounded_knapsack/README.md): 2

- [ds_design](ds_design/README.md): 2

- [graph](graph/README.md): 3

- [greedy](greedy/README.md): 19

- [linked_list](linked_list/README.md): 7

- [math](math/README.md): 3

- [misc](misc/README.md): 11

- [monotonic_queue](monotonic_queue/README.md): 4

- [range_query](range_query/README.md): 3

- [range_query/binary_indexed_tree](range_query/binary_indexed_tree/README.md): 1

- [range_query/segment_tree](range_query/segment_tree/README.md): 3

- [recursion](recursion/README.md): 8

- [sliding_window](sliding_window/README.md): 2

- [sorting](sorting/README.md): 5

- [substr_matching](substr_matching/README.md): 1

- [tree](tree/README.md): 7

- [trie](trie/README.md): 1

- [union_find](union_find/README.md): 1

---


# [2_ptrs](2_ptrs/README.md)


## 2 pointers



- :bulb: 16. 3Sum Closest



- :bulb: 11. Container With Most Water



- :bulb::bulb: 838. Push Dominoes



## Circular sort



## Quick select



## Substring window algorithm



- :bulb: 76. Minimum Window Substring



- :bulb: 159. Longest Substring with At Most Two Distinct Characters



- :bulb: 438. Find All Anagrams in a String



# [backtracking](backtracking/README.md)


## Backtracking [:notebook:](../notes/algorithms.md#backtracking)



- :bulb: 31. Next Permutation



- :bulb: 473. Matchsticks to Square



- :bulb: 410. Split Array Largest Sum



- :bulb: 778. Swim in Rising Water



- :bulb: 489. Robot Room Cleaner



- :bulb: 417. Pacific Atlantic Water Flow



- :bulb: 465. Optimal Account Balancing



- :bulb::bulb: 1293. Shortest Path in a Grid with Obstacles Elimination



## Back tracking the BFS path



- :bulb::bulb: 126. Word Ladder II



# [binary_search](binary_search/README.md)


## Binary search



- :ok_hand: 74. Search a 2D Matrix



- :bulb: 34. Find First and Last Position of Element in Sorted Array



- :bulb: 33. Search in Rotated Sorted Array



- :bulb: 81. Search in Rotated Sorted Array II



- :bulb::bulb: 658. Find K Closest Elements



- :bulb::bulb: 378. Kth Smallest Element in a Sorted Matrix



- :exploding_head: 410. Split Array Largest Sum



## Interval related questions



- :ok_hand: 729. My Calendar I



- :bulb: 715. Range Module



# [bitwise](bitwise/README.md)


## Bitwise



## [Two's complement](../notes/bitwise.md#twos-complement)



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



# [d_and_d](d_and_d/README.md)


## Divide and Conquer



- :ok_hand: 823. Binary Trees With Factors



- :bulb: 23. Merge k Sorted Lists



- :bulb::bulb: 894. All Possible Full Binary Trees



# [dp](dp/README.md)


## Dynamic programming [:notebook:](../notes/algorithms.md#dynamic-programming)



## [0/1 knapsack like recursion structure](dp/dp_01_knapsack/README.md)



## [Unbounded knapsack like recursion structure](dp/dp_unbounded_knapsack/README.md)



## [State transition](dp/dp_state_transition/README.md)



## [DFS + memorization](dp/dp_dfs_memorization/README.md)



## [Subarray (contiguous, Kadane's Algorithm)](dp/dp_subarray_kadane/README.md)



## [Subsequence](dp/dp_subseq/README.md)



## Really tricky dp recursion



- :exploding_head: 629. K Inverse Pairs Array



- :exploding_head: 837. New 21 Game



- :exploding_head: :exploding_head: 376. Wiggle Subsequence



- :exploding_head: :exploding_head: 465. Optimal Account Balancing



# [dp/dp_01_knapsack](dp/dp_01_knapsack/README.md)


## 0/1 knapsack like recursion structure



- :bulb: 474. Ones and Zeroes



- :bulb::bulb: 494. Target Sum



- :bulb: 416. Partition Equal Subset Sum



- :bulb: 115. Distinct Subsequences



# [dp/dp_dfs_memorization](dp/dp_dfs_memorization/README.md)


## DFS + memorization



- :ok_hand: 377. Combination Sum IV



- :bulb: 1770. Maximum Score from Performing Multiplication Operations



- :bulb: 494. Target Sum



- :ok_hand: 576. Out of Boundary Paths



- :bulb: 871. Minimum Number of Refueling Stops



- :bulb: 1473. Paint House III



- :exploding_head::exploding_head: 1531. String Compression II



# [dp/dp_state_transition](dp/dp_state_transition/README.md)


## State transition



- :ok_hand: 309. Best Time to Buy and Sell Stock with Cooldown



- :ok_hand: 1220. Count Vowels Permutation



- :thinking: 188. Best Time to Buy and Sell Stock IV



- :bulb: 1335. Minimum Difficulty of a Job Schedule



- :bulb: 1937. Maximum Number of Points with Cost



- :bulb: 91. Decode Ways



- :exploding_head::exploding_head: 818. Race Car



# [dp/dp_subarray_kadane](dp/dp_subarray_kadane/README.md)


## Subarray (contiguous, Kadane's Algorithm)



- :ok_hand: 53. Maximum Subarray



- :bulb: 363. Max Sum of Rectangle No Larger Than K



- :exploding_head: 2272. Substring With Largest Variance



# [dp/dp_subseq](dp/dp_subseq/README.md)


## Subsequence



- :bulb: 647. Palindromic Substrings



- :bulb: 516. Longest Palindromic Subsequence



- :bulb: 300. Longest Increasing Subsequence



# [dp/dp_unbounded_knapsack](dp/dp_unbounded_knapsack/README.md)


## Unbounded knapsack like recursion structure



- :bulb: 1155. Number of Dice Rolls With Target Sum



- :bulb: 518. Coin Change II



# [ds_design](ds_design/README.md)


## Data structure design



- :ok_hand: 692. Top K Frequent Words



- :bulb::bulb: 146. LRU Cache



# [graph](graph/README.md)


## Graph [:notebook:](../notes/algorithms.md#dynamic-programming)



## Bipartite



- :bulb: 785. Is Graph Bipartite



## Dijkstra



## Model as graph



- :bulb: 2115. Find All Possible Recipes from Given Supplies



- :exploding_head: 1153. String Transforms Into Another String



# [greedy](greedy/README.md)


## Greedy



- :ok_hand: 56. Merge Intervals



- :ok_hand: 759. Employee Free Time



- :ok_hand: 1024. Video Stitching



- :bulb: 57. Insert Interval



- :bulb: 732. My Calendar III



- :bulb: 763. Partition Labels



- :bulb: 316. Remove Duplicate Letters



- :bulb: 659. Split Array into Consecutive Subsequences



- :bulb: 936. Stamping The Sequence



- :bulb: 135. Candy



- :bulb: 1578. Minimum Time to Make Rope Colorful



- :bulb: 406. Queue Reconstruction by Height



- :bulb: 1383. Maximum Performance of a Team



- :bulb: 871. Minimum Number of Refueling Stops



- :bulb: 665. Non-decreasing Array



- :bulb: 630. Course Schedule III



- :bulb: 2136. Earliest Possible Day of Full Bloom



- :exploding_head: 1354. Construct Target Array With Multiple Sums



- :exploding_head::exploding_head: 218. The Skyline Problem



# [linked_list](linked_list/README.md)


## Linked list



- :ok_hand: 141. Linked List Cycle



- :ok_hand: 206. Reverse Linked List



- :bulb: 61. Rotate List



- :bulb: 19. Remove Nth Node From End of List



- :bulb: 92. Reverse Linked List II



- :bulb: 234. Palindrome Linked List



- :bulb: 445. Add Two Numbers II



# [math](math/README.md)


## Math



- :bulb: 462. Minimum Moves to Equal Array Elements II



- :bulb: 1359. Count All Valid Pickup and Delivery Options



## Geometry



- :bulb: 1610. Maximum Number of Visible Points



# [misc](misc/README.md)


## Misc, some great algo to do something



- :ok_hand: 916. Word Subsets



- :ok_hand: 334. Increasing Triplet Subsequence



- :ok_hand: 249. Group Shifted Strings



- :bulb: 189. Rotate Array



- :bulb: 833. Find And Replace in String



- :bulb: 1209. Remove All Adjacent Duplicates in String II



- :exploding_head: 856. Score of Parentheses



## Nice implementation idea



- :ok_hand: 12. Integer to Roman



## Hard indices manipulation



- :bulb: 48. Rotate Image



- :bulb::bulb: 835. Image Overlap



## Brainteaser



- :bulb: 458. Poor Pigs



# [monotonic_queue](monotonic_queue/README.md)


## Monotonic Queue [:notebook:](../notes/README.md#monotonic-queue)



- :bulb: 239. Sliding Window Maximum



- :bulb: 1696. Jump Game VI



- :bulb: 853. Car Fleet



- :exploding_head: 1776. Car Fleet II



# [range_query](range_query/README.md)


## Range Query



## Prefix sum



- :ok_hand: 560. Subarray Sum Equals K



- :bulb: 523. Continuous Subarray Sum



## The jump line method



- :bulb: 2158. Amount of New Area Painted Each Day



## [Segment tree](range_query/segment_tree/README.md)



## [Binary indexed tree](binary_indexed_tree/segment_tree/README.md)



# [range_query/binary_indexed_tree](range_query/binary_indexed_tree/README.md)


## Binary Indexed Tree



- :ok_hand: 307. Range Sum Query - Mutable



# [range_query/segment_tree](range_query/segment_tree/README.md)


## Segment tree



- :ok_hand: 307. Range Sum Query - Mutable



- :bulb: 2158. Amount of New Area Painted Each Day



- :exploding_head: 315. Count of Smaller Numbers After Self



# [recursion](recursion/README.md)


## Recursion



- :ok_hand: 38. Count and Say



- :ok_hand: 669. Trim a Binary Search Tree



- :ok_hand: 814. Binary Tree Pruning



- :bulb: 236. Lowest Common Ancestor of a Binary Tree



- :bulb: 105. Construct Binary Tree from Preorder and Inorder Traversal



- :bulb::bulb: 897. Increasing Order Search Tree



- :bulb::bulb: 426. Convert Binary Search Tree to Sorted Doubly Linked List



- :exploding_head: 114. Flatten Binary Tree to Linked List



# [sliding_window](sliding_window/README.md)


## Sliding window



- :bulb: 1423. Maximum Points You Can Obtain from Cards



- :bulb::bulb: 30. Substring with Concatenation of All Words



# [sorting](sorting/README.md)


## Sorting



- :wink: 1710. Maximum Units on a Truck



- :bulb: 1996. The Number of Weak Characters in the Game



## Merge sort



- :bulb: 315. Count of Smaller Numbers After Self



## Circular sort



- :ok_hand: 645. Set Mismatch



## Quick select



- :bulb: 215. Kth Largest Element in an Array



# [substr_matching](substr_matching/README.md)


## Substring matching algorithm



- :bulb: 718. Maximum Length of Repeated Subarray



## Sliding window of Substring



# [tree](tree/README.md)


## Tree



- :ok_hand: 235. Lowest Common Ancestor of a Binary Search Tree



- :ok_hand: 236. Lowest Common Ancestor of a Binary Tree



- :ok_hand: 297. Serialize and Deserialize Binary Tree



## Tree traversal



- :ok_hand: 987. Vertical Order Traversal of a Binary Tree



- :bulb: 94. Binary Tree Inorder Traversal with Iterative



## BST



- :ok_hand: 173. Binary Search Tree Iterator



- :bulb: 653. Two Sum IV - Input is a BST



# [trie](trie/README.md)


## Trie



- :exploding_head: 336. Palindrome Pairs



# [union_find](union_find/README.md)


## Union find [:notebook:](../notes/union_find.md)



- :ok_hand: 990. Satisfiability of Equality Equations


