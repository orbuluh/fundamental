# Sorting

## [:wink: 1710. Maximum Units on a Truck](https://leetcode.com/problems/maximum-units-on-a-truck/) [:dart:](maximum_unit_on_a_truck.h)
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

# Merge sort

## [:bulb: 315. Count of Smaller Numbers After Self](https://leetcode.com/problems/count-of-smaller-numbers-after-self/) [:dart:](cnt_smaller_num_after_self_mergesort.h)
- check [segment tree solution here :dart:](../range_query/segment_tree/cnt_smaller_num_after_self_segmenttree.h)
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
