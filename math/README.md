# Math

## [:bulb: 462. Minimum Moves to Equal Array Elements II](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/) [:dart:](minimum_moves_to_equal_array.h)

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

## [:bulb: 1359. Count All Valid Pickup and Delivery Options](https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/) [:dart:](count_all_valid_delivery_options.h)

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

## Geometry

## [:ok_hand: 593. Valid Square](https://leetcode.com/problems/valid-square/) [:dart:](valid_square.h)

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

## [:bulb: 1610. Maximum Number of Visible Points](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/) [:dart:](max_of_visible_pts.h)

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

## Fisher–Yates shuffle

## [:bulb: 384. Shuffle an Array](https://leetcode.com/problems/shuffle-an-array/) [:dart:](shuffle_an_array.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an integer array nums, design an algorithm to randomly shuffle the array.

- All permutations of the array should be equally likely as a result of the shuffling.
```

</details>

------------------------------------------------------------------------------
