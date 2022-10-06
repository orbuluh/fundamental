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

# Geometry

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
