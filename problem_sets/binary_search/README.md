# Binary search

- [Notes :notebook:](../../_notes/binary_search.md)
- Quick tip: always think binary search as "finding first occurrence" or "finding last occurrence". As there is only one solution to the answer when you always think in this way. And it applies to "finding occurrence" question as well.

------------------------------------------------------------------------------

## [:ok_hand: 1011. Capacity To Ship Packages Within D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days) / [:man_technologist:](capacity_to_ship_packages_within_d_days.h)

<details><summary markdown="span">Question</summary>

```markdown
A conveyor belt has packages that must be shipped from one port to another
within days days.

The ith package on the conveyor belt has a weight of weights[i].

Each day, we load the ship with packages on the conveyor belt (in the order
given by weights). We may not load more weight than the maximum weight capacity
of the ship.

Return the least weight capacity of the ship that will result in all the
packages on the conveyor belt being shipped within days days.

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15

Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5
days like this:

1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of
capacity 14 and splitting the packages into parts like
(2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 2389. Longest Subsequence With Limited Sum](https://leetcode.com/problems/longest-subsequence-with-limited-sum) / [:man_technologist:](longest_subseq_with_limited_sum.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given an integer array nums of length n, and
              an integer array queries of length m.

Return an array answer of length m where
answer[i] is the maximum size of a subsequence that you can take from nums
such that the sum of its elements is less than or equal to queries[i].

A subsequence is an array that can be derived from another array by deleting
some or no elements without changing the order of the remaining elements.

Input: nums = [4,5,2,1], queries = [3,10,21]
Output: [2,3,4]

Explanation: We answer the queries as follows:
- The subsequence [2,1] has a sum less than or equal to 3.
  It can be proven that 2 is the maximum size of such a subsequence, so answer[0] = 2.
- The subsequence [4,5,1] has a sum less than or equal to 10.
  It can be proven that 3 is the maximum size of such a subsequence, so answer[1] = 3.
- The subsequence [4,5,2,1] has a sum less than or equal to 21.
  It can be proven that 4 is the maximum size of such a subsequence, so answer[2] = 4.
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 74. Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/) / [:man_technologist:](search_in_2d_mat.h)

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

## [:ok_hand: 2187. Minimum Time to Complete Trips](https://leetcode.com/problems/minimum-time-to-complete-trips) / [:man_technologist:](min_time_to_complete_trips.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given an array time where time[i] denotes the time taken by the ith bus
to complete one trip.

- Each bus can make multiple trips successively; that is, the next trip can
  start immediately after completing the current trip.
- Each bus operates independently; that is, the trips of one bus do not
  influence the trips of any other bus.

You are also given an integer totalTrips, which denotes the number of trips all
buses should make in total. Return the minimum time required for all buses to
complete at least totalTrips trips.

Input: time = [1,2,3], totalTrips = 5
Output: 3
Explanation:
- At time t = 1, the number of trips completed by each bus are [1,0,0].
  The total number of trips completed is 1 + 0 + 0 = 1.
- At time t = 2, the number of trips completed by each bus are [2,1,0].
  The total number of trips completed is 2 + 1 + 0 = 3.
- At time t = 3, the number of trips completed by each bus are [3,1,1].
  The total number of trips completed is 3 + 1 + 1 = 5.
So the minimum time needed for all buses to complete at least 5 trips is 3.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 34. Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) / [:man_technologist:](first_and_last_pos_of_tgt_in_arr.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an array of integers nums sorted in non-decreasing order,
find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 33. Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/) / [:man_technologist:](search_in_rotated_sorted_arr.h)

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

## [:bulb: 81. Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/) / [:man_technologist:](search_in_rotated_sorted_arr_ii.h)

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

## [:bulb: 2439. Minimize Maximum of Array](https://leetcode.com/problems/minimize-maximum-of-array/) / [:man_technologist:](min_of_max_of_array.h)

- There is an optimal math solution ...check [here](../math/min_of_max_of_array_math.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given a 0-indexed array nums comprising of n non-negative integers.

In one operation, you must:

Choose an integer i such that 1 <= i < n and nums[i] > 0.
- Decrease nums[i] by 1.
- Increase nums[i - 1] by 1.

Return the minimum possible value of the maximum integer of nums after
performing any number of operations.

Input: nums = [3,7,1,6]
Output: 5

Explanation:
One set of optimal operations is as follows:
1. Choose i = 1, and nums becomes [4,6,1,6].
2. Choose i = 3, and nums becomes [4,6,2,5].
3. Choose i = 1, and nums becomes [5,5,2,5].
The maximum integer of nums is 5. It can be shown that the maximum number cannot
be less than 5. Therefore, we return 5.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 1268. Search Suggestions System](https://leetcode.com/problems/search-suggestions-system/) / [:snake:](search_suggestions_system.py)

<details><summary markdown="span">Question</summary>

```markdown
You are given an array of strings products and a string searchWord.

Design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return a list of lists of the suggested products after each character of searchWord is typed.


Example 1:

Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"].
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"].
After typing mou, mous and mouse the system suggests ["mouse","mousepad"].
Example 2:

Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
Explanation: The only word "havana" will be always suggested while typing the search word.
```

</details>

------------------------------------------------------------------------------

## [:persevere: 1802. Maximum Value at a Given Index in a Bounded Array](m-value-at-a-given-index-in-a-bounded-array) / [:man_technologist:](m_value_at_a_given_index_in_a_bound_arr.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given three positive integers: n, index, and maxSum.

You want to construct an array `nums` (0-indexed) that satisfies the following
conditions:

- nums.length == n
- nums[i] is a positive integer where 0 <= i < n.
- abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1.
- The sum of all the elements of nums does not exceed maxSum.
- nums[index] is maximized.

- Return nums[index] of the constructed array.

Input: n = 4, index = 2,  maxSum = 6
Output: 2
Explanation: nums = [1,2,2,1] is one array that satisfies all the conditions.

Input: n = 6, index = 1,  maxSum = 10
Output: 3
nums = [2, 3, 2, 1, 1, 1]
```

</details>

------------------------------------------------------------------------------

## [:persevere: 658. Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements/) / [:man_technologist:](find_k_closest.h)

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

## [:persevere: 378. Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/) / [:man_technologist:](kth_small_ele_in_sorted_matrix.h)

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

## [:dizzy_face: 4. Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/) / [:man_technologist:](median_of_2_sorted_arrays.h)

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

## Backtracking x Binary search

## [:persevere: 1102. Path With Maximum Minimum Value](https://leetcode.com/problems/path-with-maximum-minimum-value) / [:man_technologist:](path_with_maximum_min_value_dfs_bs.h)

- check problem description and Dijkstra like solution [here](../graph/graph_sssp/README.md#💡-1102-path-with-maximum-minimum-value-🎯)

## [:dizzy_face: 410. Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/) / [:man_technologist:](split_arr_largest_sum_bs.h)

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

## Interval related questions

## [:ok_hand: 729. My Calendar I](https://leetcode.com/problems/my-calendar-i/) / [:man_technologist:](my_calendar_i.h)

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

## [:bulb: 715. Range Module](https://leetcode.com/problems/range-module/) / [:man_technologist:](range_module.h)

- [:notebook: addRange pic](../../srcs/715.addRange.png) [:notebook: removeRange pic](../../srcs/715.removeRange.png)

<details><summary markdown="span">Question</summary>
- Similar question: [759. Employee Free Time](https://leetcode.com/problems/employee-free-time/), can use the same method. But have a faster solution in / [:man_technologist:](../greedy/employee_free_time.h)

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
