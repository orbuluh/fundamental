# Jump table/line

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
