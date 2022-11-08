# Greedy

## [:ok_hand: 2178. Maximum Split of Positive Even Integers](https://leetcode.com/problems/maximum-split-of-positive-even-integers/) [:dart:](max_split_of_positive_even_ints.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given an integer finalSum. Split it into a sum of a maximum number of
unique positive even integers.

For example, given finalSum = 12, the following splits are valid
(unique positive even integers summing up to finalSum):
- (12), (2 + 10), (2 + 4 + 6), and (4 + 8).

Among them, (2 + 4 + 6) contains the maximum number of integers.
- Note that finalSum cannot be split into (2 + 2 + 4 + 4) as all the numbers
  should be unique.
- Return a list of integers that represent a valid split containing a maximum
  number of integers. If no valid split exists for finalSum, return an empty list.
- You may return the integers in any order.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 763. Partition Labels](https://leetcode.com/problems/split-array-into-consecutive-subsequences/) [:dart:](split_arr_into_consecutive_seq.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

- Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
- Return a list of integers representing the size of these parts.

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]

Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".

Input: s = "eccbbbbdec"
Output: [10]
```

</details>

------------------------------------------------------------------------------

## [:bulb: 316. Remove Duplicate Letters](https://leetcode.com/problems/remove-duplicate-letters/) [:dart:](remove_duplicate_letters.h)

<details><summary markdown="span">Question</summary>

```markdown
Given a string s,
- remove duplicate letters so that every letter appears once and only once.
- You must make sure your result is the smallest in lexicographical order among all possible results.

Input: s = "bcabc"
Output: "abc"

Input: s = "cbacdcbc"
Output: "acdb"
```

</details>

------------------------------------------------------------------------------

## [:bulb: 659. Split Array into Consecutive Subsequences](https://leetcode.com/problems/partition-labels/) [:dart:](partition_labels.h)

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

------------------------------------------------------------------------------

## [:bulb: 936. Stamping The Sequence](https://leetcode.com/problems/stamping-the-sequence/) [:dart:](stamping_the_seq.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given two strings `stamp` and `target`.

Initially, there is a string `s` of length `target.length` with all `s[i]` == `'?'`.

In one turn, you can place stamp over `s` and
   replace every letter in the `s` with the corresponding letter from `stamp`.

For example, if stamp = "abc" and target = "abcba"
Initially: `s` is `?????`

In one turn you can:
- place stamp at index 0 of `s` to obtain `abc??`,
- then place stamp at index 1 of `s` to obtain `aabc?`
- then place stamp at index 2 of `s` to obtain `aaabc`


- Note that stamp must be fully contained in the boundaries of `s` in order to stamp
  (i.e., you cannot place `stamp` at index 3 of `s`).
- We want to convert s to target using at most `10 * target.length` turns.

Return an array of the index of the left-most letter being stamped at each turn.
If we cannot obtain target from s within `10 * target.length` turns, return an empty array.
```

</details>

------------------------------------------------------------------------------

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

------------------------------------------------------------------------------

## [:bulb: 1578. Minimum Time to Make Rope Colorful](https://leetcode.com/problems/minimum-time-to-make-rope-colorful/) [:dart:](min_time_to_make_rope_colorful.h)

<details><summary markdown="span">Question</summary>

```markdown
Alice has n balloons arranged on a rope.
You are given a 0-indexed string colors where
- colors[i] is the color of the ith balloon.

Alice does not want two consecutive balloons to be of the same color.
- She can remove some balloons from the rope to make it colorful.
- You are given a 0-indexed integer array cost where cost[i] is the time (in seconds) that she needs to remove the ith balloon from the rope.

Return the minimum time to make the rope colorful.

Input: colors = "aabaa", neededTime = [1,2,3,4,1]
Output: 2
Explanation:

Remove the ballons at indices 0 and 4.
Each ballon takes 1 second to remove.
There are no longer two consecutive balloons of the same color.
Total time = 1 + 1 = 2.

```

</details>

------------------------------------------------------------------------------

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

------------------------------------------------------------------------------

## [:bulb: 1383. Maximum Performance of a Team](https://leetcode.com/problems/maximum-performance-of-a-team) [:dart:](max_perf_of_a_team.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given two integers n and k and two integer arrays speed and efficiency
both of length n. There are n engineers numbered from 1 to n.
- speed[i] and efficiency[i] represent the speed and efficiency of the ith
  engineer respectively.

- Choose at most k different engineers out of the n engineers to form a team
  with the maximum performance.

- The performance of a team is the sum of their engineers' speeds multiplied by
  the minimum efficiency among their engineers.

- Return the maximum performance of this team.
- Since the answer can be a huge number, return it modulo 10^9 + 7.

Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 3
Output: 68

Explanation:
This is the same example as the first but k = 3. We can select engineer 1,
engineer 2 and engineer 5 to get the maximum performance of the team. That is,
performance = (2 + 10 + 5) * min(5, 4, 7) = 68.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 871. Minimum Number of Refueling Stops](https://leetcode.com/problems/minimum-number-of-refueling-stops/) [:dart:](min_of_refueling_stops_greedy.h)

- Question statement/other solution [:point_right: here](../dp/README.md#bulb-871-minimum-number-of-refueling-stopshttpsleetcodecomproblemsminimum-number-of-refueling-stops-dartminofrefuelingstopsh)

------------------------------------------------------------------------------

## [:bulb: 665. Non-decreasing Array](https://leetcode.com/problems/non-decreasing-array/) [:dart:](non_decreasing_array.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an array nums with n integers, check if it could become non-decreasing
    by modifying at most one element.

Input: nums = [4,2,3]
Output: true
```

</details>

------------------------------------------------------------------------------

## [:bulb: 2136. Earliest Possible Day of Full Bloom](https://leetcode.com/problems/earliest-possible-day-of-full-bloom/) [:dart:](earliest_possible_day_of_full_bloom.h)

<details><summary markdown="span">Question</summary>

```markdown
You have n flower seeds.

Every seed must be planted first before it can begin to grow, then bloom.

Planting a seed takes time and so does the growth of a seed.

You are given two 0-indexed integer arrays plantTime and growTime, of length n
each:
- PlantTime[i] is the number of full days it takes you to plant the ith seed.
- Every day, you can work on planting exactly one seed.
- You do not have to work on planting the same seed on consecutive days, but
  the planting of a seed is not complete until you have worked plantTime[i] days
  on planting it in total.
- growTime[i] is the number of full days it takes the ith seed to grow after
  being completely planted.
- After the last day of its growth, the flower blooms and stays bloomed forever.

- From the beginning of day 0, you can plant the seeds in any order.
- Return the earliest possible day where all seeds are blooming.

Input: plantTime = [1,4,3], growTime = [2,3,1]
Output: 9

Day       0 1 2 3 4 5 6 7 8 9
Plant1    P G G B
Plant2      P P P P G G G B
Plant3              P P P G B
```

</details>

------------------------------------------------------------------------------

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

------------------------------------------------------------------------------

## [:exploding_head::exploding_head: 218. The Skyline Problem](https://leetcode.com/problems/the-skyline-problem/) [:dart:](the_sky_line.h)

<details><summary markdown="span">Question</summary>

```markdown
A city's skyline is the outer contour of the silhouette formed by
all thebuildings in that city when viewed from a distance.

Given the locations and heights of all the buildings,
return the skyline formed by these buildings collectively.

The geometric information of each building is given in the array buildings
- where buildings[i] = [lefti, righti, heighti]:
  - lefti is the x coordinate of the left edge of the ith building.
  - righti is the x coordinate of the right edge of the ith building.
  - heighti is the height of the ith building.


The skyline should be represented as a list of "key points" sorted by their
x-coordinate in the form [[x1,y1],[x2,y2],...]. Each key point is the left
endpoint of some horizontal segment in the skyline except the last point in the
list, which always has a y-coordinate 0 and is used to mark the skyline's
termination where the rightmost building ends.

Any ground between the leftmost and rightmost buildings should be part of the
skyline's contour.
```

</details>

------------------------------------------------------------------------------
