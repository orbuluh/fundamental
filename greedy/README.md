# Greedy

## [:ok_hand: 56. Merge Intervals](https://leetcode.com/problems/merge-intervals/) [:dart:](merge_interval.h)
- Related:
  - [759. Employee Free Time](#okhand-759-employee-free-timehttpsleetcodecomproblemsemployee-free-time-dartemployeefreetimeh)
  - [715. Range Module](../binary_search/README.md#bulb-715-range-modulehttpsleetcodecomproblemsrange-module-dartrangemoduleh-notebooksrcs715addrangepng-notebooksrcs715removerangepng)
<details><summary markdown="span">Question</summary>

```markdown
Given an array of intervals where intervals[i] = [starti, endi]
- merge all overlapping intervals,
- and return an array of the **non-overlapping** intervals that cover all the
  intervals in the input.

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
```
</details>

## [:ok_hand: 759. Employee Free Time](https://leetcode.com/problems/employee-free-time/) [:dart:](employee_free_time.h)
- you can also solve this through binary search -> checking `addRange` in [:dart:](../binary_search/range_module.h)
<details><summary markdown="span">Question</summary>

```markdown
- Given a list schedule of employees,
  which represents the working time for each employee.
  - Each employee has a list of non-overlapping Intervals that are itself sorted.
- Return the list of finite intervals representing common,
  positive-length free time for all employees, also in sorted order.

Input: schedule = [[[1,2],[5,6]],
                  [[1,3]],
                  [[4,10]]]
Output: [[3,4]]

Explanation:
- There are a total of three employees,
  and all common free time intervals would be [-inf, 1], [3, 4], [10, inf].
- We discard any intervals that contain inf as they aren't finite.
```
</details>

## [:bulb: 659. Split Array into Consecutive Subsequences](https://leetcode.com/problems/split-array-into-consecutive-subsequences/) [:dart:](split_arr_into_consecutive_seq.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given an integer array nums that is sorted in non-decreasing order.

- Determine if it is possible to split nums into one or more subsequences
  such that both of the following conditions are true:
  - Each subsequence is a consecutive increasing sequence
  - All subsequences have a length of 3 or more.

- Return true if you can split nums according to the above conditions, or false otherwise.

Input: nums = [1,2,3,3,4,5]
Output: true
Explanation: [1, 2, 3], [3, 4, 5]
Input: nums = [1,2,3,3,4,4,5,5]
Output: true
Explanation: [1, 2, 3, 4, 5], [3, 4, 5]
```
</details>


## [:bulb: 135. Candy](https://leetcode.com/problems/candy/) [:dart:](candy.h)

<details><summary markdown="span">Question</summary>

```markdown
There are n children standing in a line.
Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:
- Each child must have at least one candy.
- Children with a higher rating get more candies than their neighbors.
- Return the minimum number of candies you need
```
</details>


## [:bulb: 406. Queue Reconstruction by Height](https://leetcode.com/problems/queue-reconstruction-by-height) [:dart:](queue_reconstruct_by_height.h)
<details><summary markdown="span">Question</summary>

```markdown
You are given an array, which are the attributes of some people in a queue (not necessarily in order).
- Each element ppl[i] = [hi, ki] represents
  -> the ith person of height hi
  -> how many people are in front of this person with height hj >= hi
- Reconstruct and return the queue that is represented by the input array.

Example:
Input: [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]
Output: [[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]

e.g. [4,0] -> height 4 with no one taller or equal in the front
     [5,0] -> height 5 with no one taller or equal in the front
     [2,2] -> height 2 with 2 people taller or equal in the front 
     ....
```
</details>

## [:bulb: 665. Non-decreasing Array](https://leetcode.com/problems/non-decreasing-array/) [:dart:](non_decreasing_array.h)
<details><summary markdown="span">Question</summary>

```markdown
Given an array nums with n integers, check if it could become non-decreasing
    by modifying at most one element.

Input: nums = [4,2,3]
Output: true
```
</details>

## [:bulb: 630. Course Schedule III](https://leetcode.com/problems/course-schedule-iii/) [:dart:](course_schedule_iii.h)

<details><summary markdown="span">Question</summary>

```markdown
There are n different online courses numbered from 1 to n.
You are given an array courses where
- courses[i] = [durationi, lastDayi] indicate that
    - the ith course should be taken continuously for durationi days
    - and must be finished before or on lastDayi.
You will start on the 1st day and you cannot take two or more courses simultaneously.
Return the maximum number of courses that you can take.

e.g. [[1,2],[2,3]]  --> ans = 2
took [1,2], timeUsed = 1 <= 2 is okay to take
took [2,3], timeUsed = 3 <= 3 is okay to take
```
</details>

## [:exploding_head: 1354. Construct Target Array With Multiple Sums](https://leetcode.com/problems/construct-target-array-with-multiple-sums/) [:dart:](construct_target_array_w_multiple_sums.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given an array target of n integers.
From a starting array arr consisting of n 1's, you may perform the following procedure :
- let x be the sum of all elements currently in your array.
- choose index i, such that 0 <= i < n and set the value of arr at index i to x.
  You may repeat this procedure as many times as needed.

- Return true if it is possible to construct the target array from arr, otherwise, return false.

Input: target = [9,3,5]
Output: true
Explanation: Start with arr = [1, 1, 1]
[1, 1, 1], sum = 3 choose index 1
[1, 3, 1], sum = 5 choose index 2
[1, 3, 5], sum = 9 choose index 0
[9, 3, 5] Done
```
</details>
