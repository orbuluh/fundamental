# Sorting

------------------------------------------------------------------------------

## [:bulb: 1996. The Number of Weak Characters in the Game](https://leetcode.com/problems/the-number-of-weak-characters-in-the-game) / [:man_technologist:](count_weaker_char.h)

- [optimal sol](count_weaker_char_o_n_sol.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given a 2D integer array properties where
    properties[i] = [attack_i, defense_i]
represents the properties of the ith character in the game.

A character is said to be weak if any other character has both attack and
defense levels strictly greater than this character's attack and defense levels.

Return the number of weak characters.

Input: properties = [[5,5],[6,3],[3,6]]
Output: 0

Input: properties = [[1,5],[10,4],[4,3]]
Output: 1
Explanation: [4, 3] < [10, 4]

```

</details>

------------------------------------------------------------------------------

## Bucket sort

## [:bulb: 1710. Maximum Units on a Truck](https://leetcode.com/problems/maximum-units-on-a-truck/) / [:man_technologist:](maximum_unit_on_a_truck.h)

<details><summary markdown="span">Question</summary>

```markdown
You are assigned to put some amount of boxes onto one truck.
You are given a 2D array boxTypes, where
- boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:
    - numberOfBoxesi is the number of boxes of type i.
    - numberOfUnitsPerBoxi is the number of units in each box of the type i.
- You are also given an integer truckSize,
  which is the maximum number of boxes that can be put on the truck.
  You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.
- Return the maximum total number of units that can be put on the truck.
```

</details>

------------------------------------------------------------------------------

## Bubble sort

## [:bulb: 899. Orderly Queue](https://leetcode.com/problems/orderly-queue/) / [:man_technologist:](orderly_queue.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given a string s and an integer k.

You can choose one of the first k letters of s and append it at the end of the string.

Return the lexicographically smallest string you could have after applying the mentioned step any number of moves.

Input: s = "cba", k = 1
Output: "acb"
Explanation:
[c]ba
[b]ac
[a]cb


Input: s = "baaca", k = 3
Output: "aaabc"
[baa]ca
[aac]ab
[aaa]bc
```

</details>

------------------------------------------------------------------------------

## Merge sort

## [:bulb: 315. Count of Smaller Numbers After Self](https://leetcode.com/problems/count-of-smaller-numbers-after-self/) / [:man_technologist:](cnt_smaller_num_after_self_mergesort.h)

- check [segment tree solution here](../range_query/segment_tree/cnt_smaller_num_after_self_segmenttree.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given an integer array nums and you have to return a new **counts array**.
The **counts array** has the property where
- counts[i] is the number of smaller elements to the right of nums[i].

Input: nums = [5,2,6,1]
Output: [2,1,1,0]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
```

</details>

------------------------------------------------------------------------------

## Circular sort

## [:ok_hand: 645. Set Mismatch](https://leetcode.com/problems/set-mismatch/) / [:man_technologist:](set_mismatch_circular_sort.h)

- Other solution, problem statement [here](../bitwise/README.md#👌-645-set-mismatch-🎯)

------------------------------------------------------------------------------

## Counting sort

## [:ok_hand: 912. Sort an Array](https://leetcode.com/problems/sort-an-array) / [:man_technologist:](sort_an_array_countingsort.h)

- Also quick sort implementation -> [:man_technologist:](sort_an_array_quicksort.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n))
time complexity and with the smallest space complexity possible.

1 <= nums.length <= 5 * 10^4
-5 * 10^4 <= nums[i] <= 5 * 10^4
```

</details>

------------------------------------------------------------------------------

## Quick select

## [:bulb: 215. Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/) / [:man_technologist:](kth_largest_in_an_array.h) [:snake:](kth_largest_in_an_array.py)

<details><summary markdown="span">Question</summary>

```markdown
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

You must solve it in O(n) time complexity.

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
```

</details>

------------------------------------------------------------------------------
