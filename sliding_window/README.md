# Sliding window
- highly related to [Monotonic Queue](../monotonic_queue/README.md)

## [:bulb: 1423. Maximum Points You Can Obtain from Cards](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/) [:dart:](max_pts_from_cards.h)
<details><summary markdown="span">Question</summary>

```markdown
There are several cards arranged in a row, and each card has an associated number of points.
The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row.
You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.
Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

Example
Input: cardPoints = [1,2,3,4,5,6,1], k = 3

Output: 12
Explanation:
- After the first step, your score will always be 1.
- However, choosing the rightmost card first will maximize your total score.
- The optimal strategy is to take the three cards on the right,
  giving a final score of 1 + 6 + 5 = 12.
```
</details>




