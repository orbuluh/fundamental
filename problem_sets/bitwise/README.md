# Bitwise
- [Notes :notebook:](../_notes/bitwise.md)

## [Two's complement](../_notes/bitwise.md#twos-complement)

## [:bulb: 371. Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers/) [:dart:](sum_of_2_ints.h)
<details><summary markdown="span">Question</summary>

```markdown
Given two integers a and b, return the sum of the two integers without using the operators + and -.
```
</details>

------------------------------------------------------------------------------

## basic operations
## [:ok_hand: 190. Reverse Bits](https://leetcode.com/problems/missing-number/) [:dart:](reverse_bits.h)
<details><summary markdown="span">Question</summary>

```markdown
Reverse bits of a given 32 bits unsigned integer.

Input:            n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
```
</details>

------------------------------------------------------------------------------

## [:ok_hand: 338. Counting Bits](https://leetcode.com/problems/counting-bits/) [:dart:](counting_bits.h)
<details><summary markdown="span">Question</summary>

```markdown
Given an integer n, return an array ans of length n + 1 such that
for each i (0 <= i <= n),
ans[i] is the number of 1's in the binary representation of i.

Input: n = 5
Output: [0,1,1,2,1,2]
```
</details>

------------------------------------------------------------------------------

## xor: `a^a = 0; b^0 = b; b^a^a = b`

## [:ok_hand: 268. Missing Number](https://leetcode.com/problems/missing-number/) [:dart:](missing_num.h)
<details><summary markdown="span">Question</summary>

```markdown
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Input: nums = [3,0,1]
Output: 2
```
</details>

------------------------------------------------------------------------------

## [:ok_hand: 645. Set Mismatch](https://leetcode.com/problems/set-mismatch/) [:dart:](set_mismatch.h)
- similar to [268](#ok_hand-268-missing-number-dart)
- check [circular solution here](../sorting/set_mismatch_circular_sort.h)
- there is also mathematical solution ... ignore here...

<details><summary markdown="span">Question</summary>

```markdown
You have a set of integers s, which originally contains all the numbers from 1 to n.

Unfortunately, due to some error, one of the numbers in s got duplicated to
another number in the set, which results in repetition of one number and loss of
another number.

You are given an integer array nums representing the data status of this set
after the error.

Find the number that occurs twice and the number that is missing and
return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]

Example 2:
Input: nums = [1,1]
Output: [1,2]
```
</details>

------------------------------------------------------------------------------

## Reset the last set bit: `x & (x - 1)`

## [:ok_hand: 268. Missing Number](https://leetcode.com/problems/number-of-1-bits/) [:dart:](number_of_setbit.h)
<details><summary markdown="span">Question</summary>

```markdown
Write a function that takes an unsigned integer and
returns the number of '1' bits it has (also known as the Hamming weight).
```
</details>

------------------------------------------------------------------------------

## Detect power of 2: `(x & (x - 1) == 0)`

## [:ok_hand: 1680. Concatenation of Consecutive Binary Numbers](https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/) [:dart:](concat_consecutive_binary_nums.h)
- [(A * B) % C = ((A % C) * (B % C)) % C](../_notes/math.md#modular-multiplication-property)

<details><summary markdown="span">Question</summary>
```markdown
- Given an integer n, return the decimal value of the binary string formed by concatenating the binary representations of 1 to n in order, modulo 10^9 + 7.

Input: n = 3
Output: 27
Explanation: In binary, 1, 2, and 3 corresponds to "1", "10", and "11".
After concatenating them, we have "11011", which corresponds to the decimal value 27.
```
</details>

------------------------------------------------------------------------------
