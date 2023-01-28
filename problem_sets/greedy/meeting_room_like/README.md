# Meeting room like questions

## [:bulb: 56. Merge Intervals](https://leetcode.com/problems/merge-intervals/) / [:man_technologist:](merge_interval.h)

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

## [:bulb: 352. Data Stream as Disjoint Intervals](https://leetcode.com/problems/data-stream-as-disjoint-intervals) / [:man_technologist:](data_stream_as_disjoint_intervals.h)

<details><summary markdown="span">Question</summary>

```markdown
Given a data stream input of non-negative integers a1, a2, ..., an,
summarize the numbers seen so far as a list of disjoint intervals.

Implement the SummaryRanges class:

`SummaryRanges() `Initializes the object with an empty stream.
`void addNum(int value)` Adds the integer value to the stream.
`int[][] getIntervals()` Returns a summary of the integers in the stream
  currently as a list of disjoint intervals [starti, endi].
  The answer should be sorted by starti.

Input
["SummaryRanges", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals"]
[[], [1], [], [3], [], [7], [], [2], [], [6], []]
Output
[null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7, 7]], null, [[1, 3], [7, 7]], null, [[1, 3], [6, 7]]]

Explanation
SummaryRanges summaryRanges = new SummaryRanges();
summaryRanges.addNum(1);      // arr = [1]
summaryRanges.getIntervals(); // return [[1, 1]]
summaryRanges.addNum(3);      // arr = [1, 3]
summaryRanges.getIntervals(); // return [[1, 1], [3, 3]]
summaryRanges.addNum(7);      // arr = [1, 3, 7]
summaryRanges.getIntervals(); // return [[1, 1], [3, 3], [7, 7]]
summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
summaryRanges.getIntervals(); // return [[1, 3], [7, 7]]
summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
summaryRanges.getIntervals(); // return [[1, 3], [6, 7]]
```

</details>

------------------------------------------------------------------------------

## [:bulb: 759. Employee Free Time](https://leetcode.com/problems/employee-free-time/) / [:man_technologist:](employee_free_time.h)

- you can also solve this through binary search -> checking `addRange` in / [:man_technologist:](../binary_search/range_module.h)

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

## [:bulb: 57. Insert Interval](https://leetcode.com/problems/insert-interval/) / [:man_technologist:](insert_interval.h)

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

## [:bulb: 732. My Calendar III](https://leetcode.com/problems/my-calendar-iii/) / [:man_technologist:](my_calendar_iii.h)

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

## [:bulb: 630. Course Schedule III](https://leetcode.com/problems/course-schedule-iii/) / [:man_technologist:](course_schedule_iii.h)

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

## [:bulb: 2402. Meeting Rooms III](https://leetcode.com/problems/meeting-rooms-iii/) / [:man_technologist:](meeting_room_iii.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given an integer n. There are n rooms numbered from 0 to n - 1.

You are given a 2D integer array meetings where meetings[i] = [starti, endi]
means that a meeting will be held during the
half-closed time interval [starti, endi).

All the values of starti are unique.

Meetings are allocated to rooms in the following manner:

- Each meeting will take place in the unused room with the lowest number.
- If there are no available rooms, the meeting will be delayed until a room
  becomes free.
- The delayed meeting should have the same duration as the original meeting.
- When a room becomes unused, meetings that have an earlier original start time
  should be given the room.

Return the number of the room that held the most meetings.
If there are multiple rooms, return the room with the lowest number.

Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
Output: 0
Explanation:
- At time 0, both rooms are not being used. The first meeting starts in room 0.
- At time 1, only room 1 is not being used. The second meeting starts in room 1.
- At time 2, both rooms are being used. The third meeting is delayed.
- At time 3, both rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 1 finishes. The third meeting starts in room 1 for the time period [5,10).
- At time 10, the meetings in both rooms finish. The fourth meeting starts in room 0 for the time period [10,11).

Both rooms 0 and 1 held 2 meetings, so we return 0.
```

</details>

------------------------------------------------------------------------------
