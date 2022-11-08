# Unbounded knapsack like recursion structure

```markdown
- There are fixed set of options and we have unlimited ways to choose each option.
  So it's not the 0/1 "to use or not to use" an option like structure.
- The key is if you make the subproblem being a small set of option, and build up
  more options upon the less one, the subproblem should be independent without
  double counting
- so overall, how you traverse the dp, which dimension to do first matters a lot
  here. Just give below question a try, with switching the looping ordering.
```

## [:bulb: 1155. Number of Dice Rolls With Target Sum](https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/) [:dart:](dice_roll_wth_tgt_sum.h)

- the core idea is basically the same as [518. Coin Change II](#💡-518-coin-change-ii-🎯)

<details><summary markdown="span">Question</summary>

```markdown

You have n dice and each die has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways
(out of the kn total ways) to roll the dice so the sum of the face-up numbers
equals target.

Since the answer may be too large, return it modulo 10^9 + 7.

Example:

Input: n = 2, k = 6, target = 7
Output: 6
Explanation: You throw two dice, each with 6 faces.
There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 518. Coin Change II](https://leetcode.com/problems/coin-change-ii/) [:dart:](coin_change_ii.h)

- [322. Coin Change](coin_change.h) is basically the same problem, just asking min way to construct target.
- the core idea is basically the same as [1155. Number of Dice Rolls With Target Sum](#👌-1155-number-of-dice-rolls-with-target-sum-🎯)

<details><summary markdown="span">Question</summary>

```markdown

You are given an integer array coins representing coins of different
denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount.

If that amount of money cannot be made up by any combination of the coins, return 0.
- You may assume that you have an infinite number of each kind of coin.
- The answer is guaranteed to fit into a signed 32-bit integer.

Example:

Input: amount = 5, coins = [1,2,5]
Output: 4

Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
```

</details>

------------------------------------------------------------------------------

## [:bulb: 91. Decode Ways](https://leetcode.com/problems/decode-ways/) [:dart:](decode_ways.h)

<details><summary markdown="span">Question</summary>

```markdown
A message containing letters from A-Z can be encoded into numbers using the
following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"

To decode an encoded message, all the digits must be grouped then mapped back
into letters using the reverse of the mapping above (there may be multiple ways).

For example, "11106" can be mapped into:
- "AAJF" with the grouping (1 1 10 6)
- "KJF" with the grouping (11 10 6)
- Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into
  'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.
```

</details>

------------------------------------------------------------------------------
