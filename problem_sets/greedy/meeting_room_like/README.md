# Meeting room like questions

## [:ok_hand: 56. Merge Intervals](https://leetcode.com/problems/merge-intervals/) [:dart:](merge_interval.h)

- Also check: [715. Range Module](../../binary_search/README.md#💡-715-range-module-🎯)

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

------------------------------------------------------------------------------

## [:ok_hand: 1024. Video Stitching](https://leetcode.com/problems/video-stitching/) [:dart:](video_stitching.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given a series of video clips from a sporting event that lasted time
seconds.

These video clips can be overlapping with each other and have varying lengths.

Each video clip is described by an array clips where
- clips[i] = [starti, endi] indicates that
  the ith clip started at starti and ended at endi.

Return the minimum number of clips needed so that we can cut the clips into
segments that cover the entire sporting event [0, time].

If the task is impossible, return -1.

Input: clips = [[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]], time = 10
Output: 3

Explanation: We take the clips [0,2], [8,10], [1,9]; a total of 3 clips.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 759. Employee Free Time](https://leetcode.com/problems/employee-free-time/) [:dart:](employee_free_time.h)

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

------------------------------------------------------------------------------

## [:bulb: 57. Insert Interval](https://leetcode.com/problems/insert-interval/) [:dart:](insert_interval.h)

- you complicate it to be a bisect question but in reality you don't need to...
- and BF solution is actually harder than you think if you are not doing it correctly...

<details><summary markdown="span">Question</summary>

```markdown
You are given an array of non-overlapping intervals intervals where
- intervals[i] = [starti, endi] represent
- the start and the end of the ith interval
- and intervals is sorted in ascending order by starti.

You are also given an interval newInterval = [start, end]
that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is
- **still sorted in ascending order by starti** and
- intervals still **does not have any overlapping intervals** (merge overlapping intervals if necessary).

Return intervals after the insertion.

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
```

</details>

------------------------------------------------------------------------------

## [:bulb: 732. My Calendar III](https://leetcode.com/problems/my-calendar-iii/) [:dart:](my_calendar_iii.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given an array of non-overlapping intervals intervals where
- intervals[i] = [starti, endi] represent
- the start and the end of the ith interval
- and intervals is sorted in ascending order by starti.

You are also given an interval newInterval = [start, end]
that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is
- **still sorted in ascending order by starti** and
- intervals still **does not have any overlapping intervals** (merge overlapping intervals if necessary).

Return intervals after the insertion.

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
```

</details>

------------------------------------------------------------------------------

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

------------------------------------------------------------------------------