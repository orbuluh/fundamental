# 2 pointers

## [:bulb: 11. Container With Most Water](https://leetcode.com/problems/container-with-most-water/) [:dart:](container_with_most_water.h)
<details><summary markdown="span">Question</summary>

```markdown
You are given an integer array height of length n.
Find two lines that together with the x-axis form a container,
such that the container contains the most water.

Return the maximum amount of water a container can store.
Notice that you may not slant the container.

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49

[1,8,6,2,5,4,8,3,7]
   ^_____________^  yields 7 * 7 = 49, which is the maxArea
```
</details>

------------------------------------------------------------------------------

## [:bulb::bulb: 838. Push Dominoes](https://leetcode.com/problems/push-dominoes/) [:dart:](push_dominoes.h)
<details><summary markdown="span">Question</summary>

```markdown
There are n dominoes in a line
- dominoes[i] = 'L', if the ith domino has fallen to the left,
- dominoes[i] = 'R', if the ith domino has fallen to the right, and
- dominoes[i] = '.', if the ith domino has not been pushed.

- After each second, each domino that is falling to the left pushes the adjacent domino on the left.
- Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.
- When a non-fallen domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.
- For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

Return a string representing the final state.

Input: dominoes = ".L.R...LR..L.."
Output:           "LL.RR.LLRRLL.."

```
</details>

------------------------------------------------------------------------------
