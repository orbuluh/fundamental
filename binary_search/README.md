# Binary search

- [Notes :notebook:](../notes/algorithms.md#binary-search)

## [:ok_hand: 74. Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/) [:dart:](search_in_2d_mat.h)

<details><summary markdown="span">Question</summary>

```markdown
Write an efficient algorithm that searches for a value target in an m x n
integer matrix matrix. This matrix has the following properties:
- Integers in each row are sorted from left to right.
- The first integer of each row is greater than the last integer of the previous row.

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
```

</details>

------------------------------------------------------------------------------

## [:bulb: 34. Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) [:dart:](first_and_last_pos_of_tgt_in_arr.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an array of integers nums sorted in non-decreasing order,
find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 33. Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/) [:dart:](search_in_rotated_sorted_arr.h)

<details><summary markdown="span">Question</summary>

```markdown
integer array nums sorted in ascending order (**with distinct** values) and then
possibly rotated at an unknown pivot index k (1 <= k < nums.length)

For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3
and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target,
return the index of target if it is in nums, or -1 if it is not in nums.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 81. Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/) [:dart:](search_in_rotated_sorted_arr_ii.h)

<details><summary markdown="span">Question</summary>

```markdown
say nums is a sorted (increasing) integer array.
Before being passed to your function,
nums is rotated at an unknown pivot index k.

Given the array nums after the rotation and an integer target,
return true if target is in nums, or false if it is not in nums.

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
```

</details>

------------------------------------------------------------------------------

## [:bulb::bulb: 658. Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements/) [:dart:](find_k_closest.h)

<details><summary markdown="span">Question</summary>

```markdown
Given a sorted integer array arr, two integers k and x,
return the k closest integers to x in the array. (x might not in the array)

The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

- |a - x| < |b - x|, or
- |a - x| == |b - x| and a < b

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]

Input: arr = [1,1,1,10,10,10], k = 1, x = 9
Output: [10]
```

</details>

------------------------------------------------------------------------------

## [:bulb::bulb: 378. Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/) [:dart:](kth_small_ele_in_sorted_matrix.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an n x n matrix where
- each of the rows and columns is sorted in ascending order

return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order
- Not the kth distinct element.

You must find a solution with a memory complexity better than O(n^2).

Input: matrix = [[1, 5,  9],
                 [10,11,13],
                 [12,13,15]], k = 8

Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15],
             and the 8th smallest number is 13
```

</details>

------------------------------------------------------------------------------

## [:exploding_head: 4. Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/) [:dart:](median_of_2_sorted_arrays.h)

- the twisted way to use binary search holly ...

<details><summary markdown="span">Question</summary>

```markdown
Given two sorted arrays nums1 and nums2 of size m and n respectively,
return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).


Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
```

</details>

------------------------------------------------------------------------------

# Backtracking x Binary search

## [:bulb::bulb: 1102. Path With Maximum Minimum Value](https://leetcode.com/problems/path-with-maximum-minimum-value) [:dart:](path_with_maximum_min_value_dfs_bs.h)

- check problem description and Dijkstra like solution [here](../graph/graph_sssp/README.md#💡-1102-path-with-maximum-minimum-value-🎯)


## [:exploding_head: 410. Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/) [:dart:](split_arr_largest_sum_bs.h)

- (Although much slower ...) Try doing backtrack for this one! --> [check code here](../backtracking/split_arr_largest_sum_bt.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an array nums which consists of non-negative integers and an integer m,
you can split the array into m non-empty continuous subarrays.

Write an algorithm to **minimize** the **largest sum among these m subarrays**.

Input: nums = [7,2,5,10,8], m = 2
Output: 18
- The best way is to split it into [7,2,5] and [10,8],
- where the largest sum among the two subarrays is only 18.
```

</details>

------------------------------------------------------------------------------

# Interval related questions

## [:ok_hand: 729. My Calendar I](https://leetcode.com/problems/my-calendar-i/) [:dart:](my_calendar_i.h)

- you can also consider to use `std::set::upper_bound` or `std::map::upper_bound` as they are ordered.

<details><summary markdown="span">Question</summary>

```markdown
You are implementing a program to use as your calendar.
We can add a new event if adding the event will not cause a double booking.

A double booking happens when two events have some non-empty intersection

- The event can be represented as a pair of integers start and end
  that represents a booking on the half-open interval [start, end)
- the range of real numbers x such that start <= x < end.

Input
["MyCalendar", "book", "book", "book"]
[[], [10, 20], [15, 25], [20, 30]]

Output
[null, true, false, true]
```

</details>

------------------------------------------------------------------------------

## [:bulb: 715. Range Module](https://leetcode.com/problems/range-module/) [:dart:](range_module.h)

- [:notebook:](../srcs/715.addRange.png) [:notebook:](../srcs/715.removeRange.png)

<details><summary markdown="span">Question</summary>
- Similar question: [759. Employee Free Time](https://leetcode.com/problems/employee-free-time/), can use the same method. But have a faster solution in [:dart:](../greedy/employee_free_time.h)

```markdown
A Range Module is a module that tracks ranges of numbers.
Design a data structure to track the ranges represented as half-open intervals and query about them.

A half-open interval [left, right) denotes all the real numbers x where left <= x < right.

Implement the RangeModule class:

- RangeModule() Initializes the object of the data structure.
- void addRange(int left, int right)
    - Adds the half-open interval [left, right), tracking every real number in that interval.
- void removeRange(int left, int right)
    - Stops tracking every real number currently being tracked in the half-open interval [left, right).
- boolean queryRange(int left, int right)
    - Returns true if every real number in the interval [left, right) is currently being tracked, and false otherwise.
- INPUT:
    - ["addRange", "removeRange", "queryRange", "queryRange", "queryRange"]
    - [ [10, 20],    [14, 16],      [10, 14],      [13, 15],    [16, 17]]
- OUTPUT:
    - null, null, null, true, false, true]
- (final ranges: [10 14)[16, 20])
```

</details>

------------------------------------------------------------------------------
