# Greedy

## [:ok_hand: 703. Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream) / [:man_technologist:](kth_largest_in_a_stream.h)

<details><summary markdown="span">Question</summary>

```markdown
Design a class to find the kth largest element in a stream.

Note that it is the kth largest element in the sorted order, not the kth
distinct element.

Implement `KthLargest` class:

`KthLargest(int k, int[] nums)`

- Initializes the object with the integer k and the stream of integers nums.

`int add(int val)`

- Appends the integer val to the stream and returns the element representing
  the kth largest element in the stream.
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock) / [:man_technologist:](best_time_to_buy_and_sell_stock.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given an array prices as price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and
choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction.
If you cannot achieve any profit, return 0.

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit =
6-1 = 5. Note that buying on day 2 and selling on day 1 is not allowed because
you must buy before you sell.
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 881. Boats to Save People](https://leetcode.com/problems/boats-to-save-people) / [:man_technologist:](boats_to_save_people.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given an array people where people[i] is the weight of the ith person,
and an infinite number of boats where each boat can carry a maximum weight of
limit.

Each boat carries at most two people at the same time, provided the sum of the
weight of those people is at most limit.

Return the minimum number of boats to carry every given person.

Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 2178. Maximum Split of Positive Even Integers](https://leetcode.com/problems/maximum-split-of-positive-even-integers/) / [:man_technologist:](max_split_of_positive_even_ints.h)

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

## [:bulb: 134. Gas Station](https://leetcode.com/problems/gas-station) / [:man_technologist:](gas_station.h)

<details><summary markdown="span">Question</summary>

```markdown
There are n gas stations along a circular route,
where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and
- it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station.
- You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index
if you can travel around the circuit once in the clockwise direction,
otherwise return -1. If there exists a solution, it is guaranteed to be unique

Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 763. Partition Labels](https://leetcode.com/problems/split-array-into-consecutive-subsequences/) / [:man_technologist:](split_arr_into_consecutive_seq.h)

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

## [:bulb: 1414. Find the Minimum Number of Fibonacci Numbers Whose Sum Is K](https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/) / [:man_technologist:](min_number_of_fibonacci_sum_is_k.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an integer k, return the minimum number of Fibonacci numbers whose sum is
equal to k. The same Fibonacci number can be used multiple times.

The Fibonacci numbers are defined as:

F1 = 1
F2 = 1
Fn = Fn-1 + Fn-2 for n > 2.
It is guaranteed that for the given constraints we can always find such Fibonacci numbers that sum up to k.

Input: k = 10
Output: 2
Explanation: For k = 10 we can use 2 + 8 = 10.

Input: k = 19
Output: 3
Explanation: For k = 19 we can use 1 + 5 + 13 = 19.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 316. Remove Duplicate Letters](https://leetcode.com/problems/remove-duplicate-letters/) / [:man_technologist:](remove_duplicate_letters.h)

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

## [:bulb: 659. Split Array into Consecutive Subsequences](https://leetcode.com/problems/partition-labels/) / [:man_technologist:](partition_labels.h)

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

## [:bulb: 936. Stamping The Sequence](https://leetcode.com/problems/stamping-the-sequence/) / [:man_technologist:](stamping_the_seq.h)

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

## [:bulb: 1055. Shortest Way to Form String](https://leetcode.com/problems/shortest-way-to-form-string/) / [:man_technologist:](shortest_way_to_form_string_sol1.h)

- also [theoretically faster solution 2 using inverted indicies](shortest_way_to_form_string_sol2.h)

<details><summary markdown="span">Question</summary>

```markdown
A subsequence of a string is a new string that is formed from the original
string by deleting some (can be none) of the characters without disturbing the
relative positions of the remaining characters.
- (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Given two strings source and target, return the minimum number of subsequences
of source such that their concatenation equals target.

If the task is impossible, return -1.

Input: source = "abc", target = "abcbc"
Output: 2
Explanation:
  The target "abcbc" can be formed by "abc" and "bc", which are subsequences of
  source "abc".

Input: source = "abc", target = "acdbc"
Output: -1
Explanation:
  No subsequence of source contains d, so target can't be combined from source.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 135. Candy](https://leetcode.com/problems/candy/) / [:man_technologist:](candy.h)

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

## [:bulb: 1578. Minimum Time to Make Rope Colorful](https://leetcode.com/problems/minimum-time-to-make-rope-colorful/) / [:man_technologist:](min_time_to_make_rope_colorful.h)

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

## [:bulb: 406. Queue Reconstruction by Height](https://leetcode.com/problems/queue-reconstruction-by-height) / [:man_technologist:](queue_reconstruct_by_height.h)

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

## [:bulb: 1383. Maximum Performance of a Team](https://leetcode.com/problems/maximum-performance-of-a-team) / [:man_technologist:](max_perf_of_a_team.h)

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

## [:bulb: 871. Minimum Number of Refueling Stops](https://leetcode.com/problems/minimum-number-of-refueling-stops/) / [:man_technologist:](min_of_refueling_stops_greedy.h)

- Question statement/other solution [:point_right: here](../dp/README.md#bulb-871-minimum-number-of-refueling-stopshttpsleetcodecomproblemsminimum-number-of-refueling-stops-dartminofrefuelingstopsh)

------------------------------------------------------------------------------

## [:bulb: 665. Non-decreasing Array](https://leetcode.com/problems/non-decreasing-array/) / [:man_technologist:](non_decreasing_array.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an array nums with n integers, check if it could become non-decreasing
    by modifying at most one element.

Input: nums = [4,2,3]
Output: true
```

</details>

------------------------------------------------------------------------------

## [:bulb: 502. IPO](https://leetcode.com/problems/ipo) / [:man_technologist:](ipo.h)

<details><summary markdown="span">Question</summary>

```markdown
Suppose LeetCode will start its IPO soon. LeetCode would like to work on some
projects to increase its capital before the IPO.

- Since it has limited resources, it can only finish at most k distinct projects
  before the IPO.
- Help LeetCode design the best way to maximize its total capital after
  finishing at most k distinct projects.

- You are given n projects where the ith project has a pure profit profits[i]
  and a minimum capital of capital[i] is needed to start it.

- Initially, you have w capital.
- When you finish a project, you will obtain its pure profit and the profit will
  be added to your total capital.
- Pick a list of at most k distinct projects from given projects to maximize
  your final capital, and return the final maximized capital.
- The answer is guaranteed to fit in a 32-bit signed integer.

Input: k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
Output: 4

Explanation:
Since your initial capital is 0, you can only start the project indexed 0.
After finishing it you will obtain profit 1 and your capital becomes 1.
With capital 1, you can either start the project indexed 1 or the project
indexed 2. Since you can choose at most 2 projects, you need to finish the
project indexed 2 to get the maximum capital. Therefore, output the final
maximized capital, which is 0 + 1 + 3 = 4.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 2136. Earliest Possible Day of Full Bloom](https://leetcode.com/problems/earliest-possible-day-of-full-bloom/) / [:man_technologist:](earliest_possible_day_of_full_bloom.h)

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

## [:bulb: 2542. Maximum Subsequence Score](https://leetcode.com/problems/maximum-subsequence-score) / [:man_technologist:](maximum_subsequence_score.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given two 0-indexed integer arrays nums1 and nums2 of equal length n and
a positive integer k.

You must choose a subsequence of indices from nums1 of length k.

For chosen indices i0, i1, ..., ik - 1, your score is defined as:

The sum of the selected elements from nums1 multiplied with the minimum of the
selected elements from nums2.

It can defined simply as:

(nums1[i0] + nums1[i1] +...+ nums1[ik - 1]) *
  min(nums2[i0] , nums2[i1], ... ,nums2[ik - 1]).

Return the maximum possible score.

A subsequence of indices of an array is a set that can be derived from the set
{0, 1, ..., n-1} by deleting some or no elements.


Example:

Input: nums1 = [1,3,3,2], nums2 = [2,1,3,4], k = 3
Output: 12

Explanation:
The four possible subsequence scores are:
- We choose the indices 0, 1, and 2 with score = (1+3+3) * min(2,1,3) = 7.
- We choose the indices 0, 1, and 3 with score = (1+3+2) * min(2,1,4) = 6.
- We choose the indices 0, 2, and 3 with score = (1+3+2) * min(2,3,4) = 12.
- We choose the indices 1, 2, and 3 with score = (3+3+2) * min(1,3,4) = 8.

Therefore, we return the max score, which is 12.
```

</details>

------------------------------------------------------------------------------

## [:persevere: 1675. Minimize Deviation in Array](https://leetcode.com/problems/minimize-deviation-in-array) / [:man_technologist:](minimize_deviation_in_array.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given an array nums of n positive integers.

You can perform two types of operations on any element of the array any number of times:

If the element is even, divide it by 2.
- For example, if the array is [1,2,3,4], then you can do this operation on the
  last element, and the array will be [1,2,3,2].

If the element is odd, multiply it by 2.
- For example, if the array is [1,2,3,4], then you can do this operation on the
  first element, and the array will be [2,2,3,4].

The deviation of the array is the maximum difference between any two elements in
the array.

Return the minimum deviation the array can have after performing some number of
operations.


Input: nums = [1,2,3,4]
Output: 1
Explanation: You can transform the array to [1,2,3,2], then to [2,2,3,2], then
the deviation will be 3 - 2 = 1.
```

</details>

------------------------------------------------------------------------------

## [:persevere: 649. Dota2 Senate](https://leetcode.com/problems/dota2-senate) / [:man_technologist:](dota2_senate.h)

<details><summary markdown="span">Question</summary>

```markdown
In the world of Dota2, there are two parties: the Radiant and the Dire.

- The Dota2 senate consists of senators coming from two parties. Now the Senate
  wants to decide on a change in the Dota2 game. The voting for this change is a
  around-based procedure.
- In each round, each senator can exercise one of the two rights:

  - Ban one senator's right:
    A senator can make another senator lose all his rights in this and all the
    following rounds.
  - Announce the victory: If this senator found the senators who still have
    rights to vote are all from the same party, he can announce the victory and
    decide on the change in the game.

- Given a string senate representing each senator's party belonging. The
  character 'R' and 'D' represent the Radiant party and the Dire party.
- Then if there are n senators, the size of the given string will be n.

- The round-based procedure starts from the first senator to the last senator in
  the given order. This procedure will last until the end of voting.
- All the senators who have lost their rights will be skipped during the
  procedure.

- Suppose every senator is smart enough and will play the best strategy for his
  own party. Predict which party will finally announce the victory and change
  the Dota2 game. The output should be "Radiant" or "Dire".


Input: senate = "DDRRR"
Output: "Dire"

Round 0: DDRRR
Round 1: -D--R
Round 2: -D---
```

</details>

------------------------------------------------------------------------------

## [:dizzy_face: 1354. Construct Target Array With Multiple Sums](https://leetcode.com/problems/construct-target-array-with-multiple-sums/) / [:man_technologist:](construct_target_array_w_multiple_sums.h)

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

## [:exploding_head: 218. The Skyline Problem](https://leetcode.com/problems/the-skyline-problem/) / [:man_technologist:](the_sky_line.h)

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
