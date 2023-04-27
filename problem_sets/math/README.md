# Math

## [:bulb: 319. Bulb Switcher](https://leetcode.com/problems/bulb-switcher) / [:man_technologist:](bulb_switcher.h)

<details><summary markdown="span">Question</summary>

```markdown
There are n bulbs that are initially off. You first turn on all the bulbs, then
you turn off every second bulb.

On the third round, you toggle every third bulb (turning on if it's off or
turning off if it's on). For the ith round, you toggle every i bulb. For the nth
round, you only toggle the last bulb.

Return the number of bulbs that are on after n rounds.

Input: n = 5
Output: 2
round 0: 0 0 0 0 0
round 1: 1 1 1 1 1
round 2: 1 0 1 0 1
round 3: 1 0 0 0 1
round 4: 1 0 0 1 1
round 5: 1 0 0 1 0
```

</details>

------------------------------------------------------------------------------

## [:bulb: 462. Minimum Moves to Equal Array Elements II](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/) / [:man_technologist:](minimum_moves_to_equal_array.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an integer array nums of size n,
return the minimum number of moves required to make all array elements equal.

In one move, you can increment or decrement an element of the array by 1.
Example:
INPUT = [1,2,3]
OUTPUT = 2
```

</details>

------------------------------------------------------------------------------

## [:bulb: 2244. Minimum Rounds to Complete All Tasks](https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks) / [:man_technologist:](minimum_rounds_to_complete_all_tasks.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given a 0-indexed integer array tasks, where tasks[i]
represents the difficulty level of a task.

In each round, you can complete either 2 or 3 tasks of the same difficulty level.

Return the minimum rounds required to complete all the tasks, or -1 if it is not
possible to complete all the tasks.

Input: tasks = [2,3,3]
Output: -1
Explanation: There is only 1 task of difficulty level 2, but in each round, you
can only complete either 2 or 3 tasks of the same difficulty level.


Input: tasks = [2,2,3,3,2,4,4,4,4,4]
Output: 4
Explanation: To complete all the tasks, a possible plan is:
- In the first round, you complete 3 tasks of difficulty level 2.
- In the second round, you complete 2 tasks of difficulty level 3.
- In the third round, you complete 3 tasks of difficulty level 4.
- In the fourth round, you complete 2 tasks of difficulty level 4.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 1359. Count All Valid Pickup and Delivery Options](https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/) / [:man_technologist:](count_all_valid_delivery_options.h)

<details><summary markdown="span">Question</summary>

```markdown
Given n orders, each order consist in pickup and delivery services.

Count all valid pickup/delivery possible sequences such that
- delivery(i) is always after of pickup(i).

Since the answer may be too large, return it modulo 10^9 + 7.

Input: n = 2
Output: 6

Explanation: All possible orders:
- (P1,P2,D1,D2), (P1,P2,D2,D1), (P1,D1,P2,D2),
  (P2,P1,D1,D2), (P2,P1,D2,D1), (P2,D2,P1,D1).
- This is an invalid order (P1,D2,P2,D1) because Pickup 2 is after of Delivery 2.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 2348. Number of Zero-Filled Subarrays](https://leetcode.com/problems/number-of-zero-filled-subarrays/) / [:man_technologist:](number_of_zero_filled_subarrays.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an integer array nums, return the number of subarrays filled with 0.

A subarray is a contiguous non-empty sequence of elements within an array.

Input: nums = [1,3,0,0,2,0,0,4]
Output: 6
Explanation:
There are 4 occurrences of [0] as a subarray.
There are 2 occurrences of [0,0] as a subarray.
There is no occurrence of a subarray with a size more than 2 filled with 0. Therefore, we return 6.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 1071. Greatest Common Divisor of Strings](https://leetcode.com/problems/greatest-common-divisor-of-strings) / [:man_technologist:](greatest_common_divisor_of_strings.h)

<details><summary markdown="span">Question</summary>

```markdown
For two strings s and t, we say "t divides s" if and only if
s = t + ... + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2,
return the largest string x such that x divides both str1 and str2.

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
```

</details>

------------------------------------------------------------------------------


## Geometry

## [:ok_hand: 593. Valid Square](https://leetcode.com/problems/valid-square/) / [:man_technologist:](valid_square.h)

<details><summary markdown="span">Question</summary>

```markdown
Given the coordinates of four points in 2D space p1, p2, p3 and p4,
return true if the four points construct a square.

The coordinate of a point pi is represented as [xi, yi].
The input is not given in any order.

A valid square has four equal sides with positive length and four equal angles
(90-degree angles).

Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: true

Input: p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
Output: true
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 478. Generate Random Point in a Circle](https://leetcode.com/problems/generate-random-point-in-a-circle) / [:man_technologist:](gen_random_pt_in_circle.h)

- more of a if you know you know question... take a note anyway

<details><summary markdown="span">Question</summary>

```markdown
Given the radius and the position of the center of a circle, implement the
function `randPoint` which generates a uniform random point inside the circle.

Implement the Solution class:

`Solution(double radius, double x_center, double y_center)`
- initializes the object with the radius of the circle radius and the position
  of the center (x_center, y_center).
`randPoint()`
- returns a random point inside the circle.

A point on the circumference of the circle is considered to be in the circle.
The answer is returned as an array [x, y].
```

</details>

------------------------------------------------------------------------------

## [:bulb: 1610. Maximum Number of Visible Points](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/) / [:man_technologist:](max_of_visible_pts.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given an array points, an integer angle, and your location, where
- location = [posx, posy]
- points[i] = [xi, yi]

You can see some set of points if, for each point, the angle formed by
- the point, your position, and the immediate east direction from your position
is in your field of view.

Initially, you are facing directly east from your position
- e.g. 0 degree against +x axis initially
- your visible range is basically from [-degree/2, degree/2] initially.
- but you can rotate your self counter clockwise for d degree, when you do so,
  your visible range is [d - degree/2, d + degree /2]

There can be multiple points at one coordinate.
There may be points at your location, and in such case, you can always see these points regardless of your rotation.

Points do not obstruct/block your vision to other points.
- (For example, say you are at (0, 0), degree is 90, point (1, 1) won't block you
seeing point(2, 2))

Return the maximum number of points you can see.

Input: points = [[1,0],[2,1]], angle = 13, location = [1,1]
Output: 1
```

</details>

------------------------------------------------------------------------------

## [:bulb: 149. Max Points on a Line](https://leetcode.com/problems/max-points-on-a-line) / [:man_technologist:](max_pts_on_a_line.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an array of points where points[i] = [xi, yi]
represents a point on the X-Y plane,
return the maximum number of points that lie on the same straight line.

Input: points = [[0,8],[1,1],[2,2],[3,3]]
Output: 3
```

</details>

------------------------------------------------------------------------------


## Fisher–Yates shuffle

## [:bulb: 384. Shuffle an Array](https://leetcode.com/problems/shuffle-an-array/) / [:man_technologist:](shuffle_an_array.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an integer array nums, design an algorithm to randomly shuffle the array.

- All permutations of the array should be equally likely as a result of the shuffling.
```

</details>

------------------------------------------------------------------------------

## Reservoir sampling

## [:bulb: 382. Linked List Random Node](https://leetcode.com/problems/linked-list-random-node) / [:man_technologist:](linked_list_random_node.h)

<details><summary markdown="span">Question</summary>

```markdown
Given a singly linked list, return a random node's value from the linked list.

- Each node must have the same probability of being chosen.

Implement the `Solution` class:

`Solution(ListNode head)`:
- Initializes the object with the head of the singly-linked list head.
`int getRandom()`:
- Chooses a node randomly from the list and returns its value.
- All the nodes of the list should be equally likely to be chosen.
```

</details>