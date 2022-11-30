# State transition

## [:ok_hand: 740. Delete and Earn](https://leetcode.com/problems/delete-and-earn/) [:dart:](delete_and_earn.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given an integer array nums.

You want to maximize the number of points you get by performing the following operation any number of times:

- Pick any nums[i] and delete it to earn nums[i] points.
- Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.

Return the maximum number of points you can earn by applying the above operation some number of times.

Input: nums = [3,4,2]
Output: 6
Explanation: You can perform the following operations:
- Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
- Delete 2 to earn 2 points. nums = [].
You earn a total of 6 points.

Input: nums = [2,2,3,3,3,4]
Output: 9
Explanation: You can perform the following operations:
- Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
- Delete a 3 again to earn 3 points. nums = [3].
- Delete a 3 once more to earn 3 points. nums = [].
You earn a total of 9 points.
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 309. Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/) [:dart:](buy_sell_stock_with_cooldown.h)

<details><summary markdown="span">Question</summary>

```markdown
- You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve.

You may complete as many transactions as you like (i.e., buy one and sell one
share of the stock multiple times) with the following restrictions:
- After you sell your stock, you cannot buy stock on the next day
  (i.e., cool-down one day).
- You may not engage in multiple transactions simultaneously
  (i.e., you must sell the stock before you buy again).
- Different sequences are counted as different combinations.

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cool-down, buy, sell]
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 1220. Count Vowels Permutation](https://leetcode.com/problems/count-vowels-permutation/) [:dart:](count_vowels_permutation.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a' or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a 'u'.
Each vowel 'u' may only be followed by an 'a'.
Since the answer may be too large, return it modulo 10^9 + 7.

Input: n = 2
Output: 10
Explanation: All possible strings are:
"ea", "ia", "ua",
"ae", "ie",
"ei", "oi",
"io",
"iu", "ou"
```

</details>

------------------------------------------------------------------------------

## [:thinking: 188. Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/) [:dart:](buy_sell_stock_iv.h)

- although understand the solution, looping in k still feel unintuitive...

<details><summary markdown="span">Question</summary>

```markdown
- You are given an integer array prices where prices[i] is the price of a given
  stock on the ith day, and an integer k.
- Find the maximum profit you can achieve. You may complete at most k transactions.
- Note: You may not engage in multiple transactions simultaneously
  (i.e., you must sell the stock before you buy again).

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
             Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 799. Champagne Tower](https://leetcode.com/problems/champagne-tower/) [:dart:](champagne_tower.h)

<details><summary markdown="span">Question</summary>

```markdown
We stack glasses in a pyramid, where
the first row has 1 glass,
the second row has 2 glasses, and so on until the 100th row.

Each glass holds one cup of champagne.

Then, some champagne is poured into the first glass at the top.

When the topmost glass is full, any excess liquid poured will fall equally to
the glass immediately to the left and right of it.

When those glasses become full, any excess champagne will fall equally to
the left and right of those glasses, and so on.

(A glass at the bottom row has its excess champagne fall on the floor.)

For example, after one cup of champagne is poured, the top most glass is full.
         [1]

After two cups of champagne are poured, the two glasses on the second row are
half full.
         [1]
     [0.5]  [0.5]


After three cups of champagne are poured, those two cups become full
, there are 3 full glasses total now.
         [1]
       [1]  [1]


After four cups of champagne are poured, the third row has the middle glass half
full, and the two outside glasses are a quarter full

         [1]
       [1]  [1]
[0.25]   [0.5]  [0.25]
```

</details>

------------------------------------------------------------------------------

## [:bulb: 1335. Minimum Difficulty of a Job Schedule](https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/) [:dart:](min_difficulty_of_job_schedule.h)

<details><summary markdown="span">Question</summary>

```markdown
You want to schedule a list of jobs in d days.
- Jobs are dependent (i.e To work on the ith job, you have to finish all the jobs j where 0 <= j < i).
- You have to finish at least one task every day.
- The difficulty of a job schedule is the sum of difficulties of each day of the d days.
- The difficulty of a day is the maximum difficulty of a job done on that day.

You are given an integer array jobDifficulty and an integer d.
The difficulty of the ith job is jobDifficulty[i].

Return the minimum difficulty of a job schedule.
If you cannot find a schedule for the jobs return -1.

Input: jobDifficulty = [6,5,4,3,2,1], d = 2
Output: 7
Explanation:
day-1: 6, 5, 4, 3, 2 --> with day 1 difficulty = 6.
day-2: 1 --> with day 2 difficulty = 1.
The difficulty of the schedule = 6 + 1 = 7

Input: jobDifficulty = [9,9,9], d = 4
Output: -1
Explanation: If you finish a job per day you will still have a free day.
you cannot find a schedule for the given jobs.

```

</details>

------------------------------------------------------------------------------

## [:bulb: 1937. Maximum Number of Points with Cost](https://leetcode.com/problems/maximum-number-of-points-with-cost/) [:dart:](max_number_of_pts_with_cost.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given an m x n integer matrix points (0-indexed).

Starting with 0 points, you want to maximize the number of points you can get from the matrix.
To gain points, you must pick one cell in each row.

Picking the cell at coordinates (r, c) will add points[r][c] to your score.

However, for every two adjacent rows r and r + 1 (where 0 <= r < m - 1), picking
cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from
your score.

Return the maximum number of points you can achieve.

Input: points = [[1,2,3],
                [1,5,1],
                [3,1,1]]
Output: 9

Explanation:
Optimal cells to pick: (0, 2), (1, 1), and (2, 0).
where you add 3 + 5 + 3 = 11 to your score from each row
However, and subtract abs(2 - 1) + abs(1 - 0) = 2
Your final score is 11 - 2 = 9.
```

</details>

------------------------------------------------------------------------------

## [:exploding_head::exploding_head: 818. Race Car](https://leetcode.com/problems/race-car/) [:dart:](race_car.h)

<details><summary markdown="span">Question</summary>

```markdown
Your car starts at position 0 and speed +1 on an infinite number line.
Your car can go into negative positions.
Your car drives automatically according to a sequence of instructions
- 'A' (accelerate):
  - `position += speed`
  - `speed *= 2`
- 'R' (reverse):
  - Your position stays the same, but ...
  - If your speed is positive then `speed = -1`
  - else: `speed = 1`

Given a target position target, return the length of the shortest sequence of instructions to get there.

Input: target = 6
Output: 5
Explanation:
- The shortest instruction sequence is "AAARA".
- Your position goes from 0 --> 1 --> 3 --> 7 -->  7 -->  6
- Your speed goes from    1 --> 1 --> 2 --> 4 --> -1 --> -2
```

</details>

------------------------------------------------------------------------------
