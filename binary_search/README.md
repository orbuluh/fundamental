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