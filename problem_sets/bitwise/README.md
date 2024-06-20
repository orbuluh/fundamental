# Bitwise

- [Notes :notebook:](../../_notes/bitwise.md)

## [Two's complement](../../_notes/bitwise.md#twos-complement)

## [:bulb: 371. Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers/) / [:man_technologist:](sum_of_2_ints.h)

<details><summary markdown="span">Question</summary>

```markdown
Given two integers a and b, return the sum of the two integers without using the operators + and -.
```

</details>

------------------------------------------------------------------------------

## basic operations

## [:ok_hand: 190. Reverse Bits](https://leetcode.com/problems/missing-number/) / [:man_technologist:](reverse_bits.h)

<details><summary markdown="span">Question</summary>

```markdown
Reverse bits of a given 32 bits unsigned integer.

Input:            n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 338. Counting Bits](https://leetcode.com/problems/counting-bits/) / [:man_technologist:](counting_bits.h)

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

## [:ok_hand: 268. Missing Number](https://leetcode.com/problems/missing-number/) / [:man_technologist:](missing_num.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Input: nums = [3,0,1]
Output: 2
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 645. Set Mismatch](https://leetcode.com/problems/set-mismatch/) / [:man_technologist:](set_mismatch.h)

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

## `odd ^ 1 == odd - 1`, `even ^ 1 == even + 1`

## [:persevere: 540. Single Element in a Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array) / [:man_technologist:](single_element_in_a_sorted_array.h)

- More a binary search problem but the bitwise trick is the enlightening one!

<details><summary markdown="span">Question</summary>

```markdown
You are given a sorted array consisting of only integers where every element
appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
```

</details>

------------------------------------------------------------------------------

## Reset the last set bit: `x & (x - 1)`

## [:ok_hand: 268. Missing Number](https://leetcode.com/problems/number-of-1-bits/) / [:man_technologist:](number_of_setbit.h)

<details><summary markdown="span">Question</summary>

```markdown
Write a function that takes an unsigned integer and
returns the number of '1' bits it has (also known as the Hamming weight).
```

</details>

------------------------------------------------------------------------------

## Detect power of 2: `(x & (x - 1) == 0)`

## [:ok_hand: 1680. Concatenation of Consecutive Binary Numbers](https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/) / [:man_technologist:](concat_consecutive_binary_nums.h)

- [(A * B) % C = ((A % C) * (B % C)) % C](../../_notes/modular.md)

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

## [:ok_hand: 342. Power of Four](https://leetcode.com/problems/power-of-four) / [:snake:](power_of_four.py)

- [(A * B) % C = ((A % C) * (B % C)) % C](../../_notes/modular.md)

<details><summary markdown="span">Question</summary>

```markdown
Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4^x.

```

</details>

------------------------------------------------------------------------------
