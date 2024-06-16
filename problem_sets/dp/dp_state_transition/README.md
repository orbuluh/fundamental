# DP: State transition

## [:ok_hand: 198. House Robber](https://leetcode.com/problems/house-robber) / [:man_technologist:](house_robber.h)

- The classic question for state transition like problems
- Check out the `std::exchange` usage in code!

<details><summary markdown="span">Question</summary>

```markdown
You are a professional robber planning to rob houses along a street.

Each house has a certain amount of money stashed, the only constraint stopping
you from robbing each of them is that adjacent houses have security systems
connected and it will automatically contact the police if two adjacent houses
were broken into on the same night.

Given an integer array nums representing the amount of money of each house,
return the maximum amount of money you can rob tonight without alerting the
police.
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 740. Delete and Earn](https://leetcode.com/problems/delete-and-earn/) / [:man_technologist:](delete_and_earn.h)

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

## [:ok_hand: 309. Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/) / [:man_technologist:](buy_sell_stock_with_cooldown.h)

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

## [:ok_hand: 1220. Count Vowels Permutation](https://leetcode.com/problems/count-vowels-permutation/) / [:man_technologist:](count_vowels_permutation.h)

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

## [:ok_hand: 2466. Count Ways To Build Good Strings](https://leetcode.com/problems/count-ways-to-build-good-strings) / [:man_technologist:](count_ways_to_build_good_str.h)

<details><summary markdown="span">Question</summary>

```markdown
Given the integers zero, one, low, and high, we can construct a string by
- starting with an empty string, and then
- at each step perform either of the following:

- Append the character '0' zero times.
- Append the character '1' one times.

This can be performed any number of times.

A good string is a string constructed by the above process having a length
between low and high (inclusive).

Return the number of different good strings that can be constructed satisfying
these properties.

Since the answer can be large, return it modulo 1e9 + 7.

Input: low = 2, high = 3, zero = 1, one = 2
Output: 5
Explanation: The good strings are "00", "11", "000", "110", and "011".
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 1402. Reducing Dishes](https://leetcode.com/problems/reducing-dishes) / [:man_technologist:](reducing_dishes.h)

<details><summary markdown="span">Question</summary>

```markdown
A chef has collected data on the satisfaction level of his n dishes.
hef can cook any dish in 1 unit of time.

"Like-time coefficient" of a dish is defined as the time taken to cook that dish
including previous dishes multiplied by its satisfaction level i.e.

- time[i] * satisfaction[i].

Return the maximum sum of like-time coefficient that the chef can obtain after
dishes preparation.

Dishes can be prepared in any order and the chef can discard some dishes to get
this maximum value.

Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total
like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
Each dish is prepared in one unit of time.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 983. Minimum Cost For Tickets](https://leetcode.com/problems/minimum-cost-for-tickets) / [:man_technologist:](min_cost_for_tickets.h)

<details><summary markdown="span">Question</summary>

```markdown
You have planned some train traveling one year in advance. The days of the year
in which you will travel are given as an integer array days.
Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:

- a 1-day pass is sold for costs[0] dollars,
- a 7-day pass is sold for costs[1] dollars, and
- a 30-day pass is sold for costs[2] dollars.

The passes allow that many days of consecutive travel.

For example, if we get a 7-day pass on day 2, then we can travel for 7 days:
2, 3, 4, 5, 6, 7, and 8.

Return the minimum number of dollars you need to travel every day in the given
list of days.

Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total, you spent $11 and covered all the days of your travel.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 2140. Solving Questions With Brainpower](https://leetcode.com/problems/solving-questions-with-brainpower/) / [:man_technologist:](solving_questions_with_brainpower.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given a 0-indexed 2D integer array questions where

- questions[i] = [pointsi, brainpoweri].

The array describes the questions of an exam, where you have to process the
questions in order (i.e., starting from question 0) and make a decision whether
to solve or skip each question.

Solving question i will earn you pointsi points but you will be unable to solve
each of the next brainpoweri questions.

If you skip question i, you get to make the decision on the next question.

For example, given questions = [[3, 2], [4, 3], [4, 4], [2, 5]]:

If question 0 is solved, you will earn 3 points but you will be unable to solve
questions 1 and 2.

If instead, question 0 is skipped and question 1 is solved, you will earn 4
points but you will be unable to solve the remaining questions.

Return the maximum points you can earn for the exam.


Input: questions = [[1,1],[2,2],[3,3],[4,4],[5,5]]
Output: 7
Explanation: The maximum points can be earned by solving questions 1 and 4.
- Skip question 0
- Solve question 1: Earn 2 points, will be unable to solve the next 2 questions
- Unable to solve questions 2 and 3
- Solve question 4: Earn 5 points
Total points earned: 2 + 5 = 7. There is no other way to earn 7 or more points.

```

</details>

------------------------------------------------------------------------------

## [:bulb: 1416. Restore The Array](https://leetcode.com/problems/restore-the-array/) / [:man_technologist:](restore_the_array.h)

<details><summary markdown="span">Question</summary>

```markdown
A program was supposed to print an array of integers.

The program forgot to print white spaces and the array is printed as a string of
digits s and all we know is that all integers in the array were in the range
[1, k] and there are no leading zeros in the array.

Given the string s and the integer k, return the number of the possible arrays
that can be printed as s using the mentioned program.

Since the answer may be very large, return it modulo 10^9 + 7.

Input: s = "1317", k = 2000
Output: 8
Explanation: Possible arrays are [1317],[131,7],[13,17],[1,317],[13,1,7],
                                 [1,31,7],[1,3,17],[1,3,1,7]
Input: s = "1000", k = 10
Output: 0
Explanation: There cannot be an array that was printed this way and has all
             integer >= 1 and <= 10.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 188. Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/) / [:man_technologist:](buy_sell_stock_iv.h)

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

## [:bulb: 799. Champagne Tower](https://leetcode.com/problems/champagne-tower/) / [:man_technologist:](champagne_tower.h)

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

## [:bulb: 1335. Minimum Difficulty of a Job Schedule](https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/) / [:man_technologist:](min_difficulty_of_job_schedule.h)

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

## [:bulb: 1937. Maximum Number of Points with Cost](https://leetcode.com/problems/maximum-number-of-points-with-cost/) / [:man_technologist:](max_number_of_pts_with_cost.h)

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

## [:dizzy_face: 123. Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii) / [:snake:](best_time_to_buy_and_sell_stock_iii.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
```

</details>

------------------------------------------------------------------------------

## [:dizzy_face: 790. Domino and Tromino Tiling](https://leetcode.com/problems/domino-and-tromino-tiling/) / [:man_technologist:](domino_and_tromino_tiling.h)

<details><summary markdown="span">Question</summary>

```markdown
You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.

Domino tile:  OO
Tromino tile: OO
              O

Given an integer n, return the number of ways to tile an 2 x n board.
Since the answer may be very large, return it modulo 10^9 + 7.

In a tiling, every square must be covered by a tile.
Two tilings are different if and only if there are two 4-directionally adjacent
cells on the board such that exactly one of the tilings has both squares
occupied by a tile.

Input: n = 3
Output: 5
Explanation:
O XX     O O O    XX O    TT L    T LL
O XX     O O O    XX O    T LL    TT L
```

</details>

------------------------------------------------------------------------------

## [:exploding_head: 818. Race Car](https://leetcode.com/problems/race-car/) / [:man_technologist:](race_car.h)

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
