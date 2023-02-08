# Jump table/line

## [:ok_hand: 452. Minimum Number of Arrows to Burst Balloons](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons) / [:man_technologist:](min_num_of_arrows_to_burst_balloons.h)

<details><summary markdown="span">Question</summary>

```markdown
There are some spherical balloons taped onto a flat wall that represents the XY-plane.

The balloons are represented as a 2D integer array points where

points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches
between xstart and xend. You do not know the exact y-coordinates of the balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from
different points along the x-axis.

A balloon with xstart and xend is burst by an arrow shot at x
- if xstart <= x <= xend.

There is no limit to the number of arrows that can be shot.
A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to
burst all balloons.

Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
```

</details>

------------------------------------------------------------------------------

## [:bulb: 45. Jump Game II](https://leetcode.com/problems/jump-game-ii/) / [:man_technologist:](jump_game_ii.h)

<details><summary markdown="span">Question</summary>

```markdown
ou are given a 0-indexed array of integers nums of length n.
You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i.
In other words, if you are at nums[i], you can jump to any nums[i + j] where:

- 0 <= j <= nums[i] and
- i + j < n

Return the minimum number of jumps to reach nums[n - 1].
The test cases are generated such that you can reach nums[n - 1].

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

</details>

------------------------------------------------------------------------------


## [:bulb: 1024. Video Stitching](https://leetcode.com/problems/video-stitching/) / [:man_technologist:](video_stitching.h)

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

## [:bulb: 1326. Minimum Number of Taps to Open to Water a Garden](https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden) / [:man_technologist:](min_number_of_taps_to_water_garden.h)

<details><summary markdown="span">Question</summary>

```markdown
There is a one-dimensional garden on the x-axis.
The garden starts at the point 0 and ends at the point n. (i.e The length of the garden is n).

There are n + 1 taps located at points [0, 1, ..., n] in the garden.

Given an integer n and an integer array ranges of length n + 1 where

ranges[i] (0-indexed) means
the i-th tap can water the area [i - ranges[i], i + ranges[i]] if it was open.

Return the minimum number of taps that should be open to water the whole garden,
If the garden cannot be watered return -1.

Input: n = 5, ranges = [3,4,1,1,0,0]
Output: 1
Explanation: The tap at point 0 can cover the interval [-3,3]
The tap at point 1 can cover the interval [-3,5]
The tap at point 2 can cover the interval [1,3]
The tap at point 3 can cover the interval [2,4]
The tap at point 4 can cover the interval [4,4]
The tap at point 5 can cover the interval [5,5]
Opening Only the second tap will water the whole garden [0,5]
```

</details>

------------------------------------------------------------------------------

## [:bulb: 739. Daily Temperatures](https://leetcode.com/problems/daily-temperatures) / [:man_technologist:](daily_temperatures.h)

- The more intuitive way might be monotonic decreasing queue -> check [here](../../monotonic/daily_temperatures_monostk.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an array of integers temperatures represents the daily temperatures,
return an array answer such that answer[i] is the number of days you have to
wait after the ith day to get a warmer temperature.

If there is no future day for which this is possible, keep answer[i] == 0 instead.

Input: temperatures = [73,74,75,71,69,72,76,73]
Output:                [1,1, 4, 2, 1, 1, 0, 0]
```

</details>

------------------------------------------------------------------------------

## [:bulb: 1834. Single-Threaded CPU](https://leetcode.com/problems/single-threaded-cpu) / [:man_technologist:](single_threaded_cpu.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given n​​​​​​ tasks labeled from 0 to n - 1 represented by a 2D integer array tasks,
where tasks[i] = [enqueueTime_i, processingTime_i] means that

- the i​​​​​​th​​​​ task will be available to process at enqueueTime_i and
- will take processingTime_i to finish processing.

You have a single-threaded CPU that can process at most one task at a time and
will act in the following way:

- If the CPU is idle and there are no available tasks to process, the CPU remains idle.
- If the CPU is idle and there are available tasks, the CPU will choose the one with the shortest processing time.
- If multiple tasks have the same shortest processing time, it will choose the task with the smallest index.

Once a task is started, the CPU will process the entire task without stopping.
The CPU can finish a task then start a new one instantly.
Return the order in which the CPU will process the tasks.

Input: tasks = [[1,2],[2,4],[3,2],[4,1]]
Output: [0,2,3,1]
Explanation: The events go as follows:
- At time = 1, task 0 is available to process. Available tasks = {0}.
- Also at time = 1, the idle CPU starts processing task 0. Available tasks = {}.
- At time = 2, task 1 is available to process. Available tasks = {1}.
- At time = 3, task 2 is available to process. Available tasks = {1, 2}.
- Also at time = 3, the CPU finishes task 0 and starts processing task 2 as it is the shortest. Available tasks = {1}.
- At time = 4, task 3 is available to process. Available tasks = {1, 3}.
- At time = 5, the CPU finishes task 2 and starts processing task 3 as it is the shortest. Available tasks = {1}.
- At time = 6, the CPU finishes task 3 and starts processing task 1. Available tasks = {}.
- At time = 10, the CPU finishes task 1 and becomes idle.
```

</details>

------------------------------------------------------------------------------

