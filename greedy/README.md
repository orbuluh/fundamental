# Greedy

## [:bulb: 665. Non-decreasing Array](https://leetcode.com/problems/non-decreasing-array/)
- [:bookmark:](non_decreasing_array.h)
```txt
Given an array nums with n integers, check if it could become non-decreasing
    by modifying at most one element.

Input: nums = [4,2,3]
Output: true
```

## [:bulb: 630. Course Schedule III](https://leetcode.com/problems/course-schedule-iii/)
- [:bookmark:](course_schedule_iii.h)
```txt
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

## [:exploding_head: 1354. Construct Target Array With Multiple Sums](https://leetcode.com/problems/construct-target-array-with-multiple-sums/)
- [:bookmark:](construct_target_array_w_multiple_sums.h)
```txt
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
