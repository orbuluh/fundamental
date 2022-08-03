# Binary search
- [Notes :notebook:](../basics/algorithms.md#binary-search)

## [:bulb: 34. Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) [:dart:](first_and_last_pos_of_tgt_in_arr.h)
<details><summary markdown="span">Question</summary>

```markdown
Given an array of integers nums sorted in non-decreasing order,
find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.
```
</details>


## [:bulb: 81. Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/) [:dart:](search_in_rotated_sorted_arr.h)

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


## [:bulb: 715. Range Module](https://leetcode.com/problems/range-module/) [:dart:](range_module.h) [:notebook:](../srcs/715.addRange.png) [:notebook:](../srcs/715.removeRange.png)
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
