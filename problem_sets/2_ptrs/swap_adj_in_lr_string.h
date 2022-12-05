/*
DFS greedy replace will actually have problem for simple case like

XXL
LXX

One thing to note is that you can only replace "XL" in s with "LX"
(NOT "LX" with "XL")

- which means, you are always shifting L to left,
- (and similarly, you are always shifting R to right)

- Also, there is no option for RL/LR switch, which means
  "L can never across R", for example,
  RXL -> XRL -> you can't switch RL,
  RXL -> RLX -> still, you can't switch

- This gives us an idea that you can actually ignore the X and just check that
  when we remove all the X, is start and end are basically the same. (Or say,
  if the relative position of L and R are the same in start and end.)

To do this, the idea is using 2 pointers, one on start (p1), one on end (p2)
Each iteration, you try to move pointer to the first non-X char

start = LXXLXRLXXL
        ^  ^ ^^  ^
end   = XLLXRXLXLX
         ^^ ^ ^ ^

As we are skipping 'X', in each iteration, when we compare the start[p1] v.s.
end[p2] they must be both 'L' or 'R', (otherwise there is a different number of
L and R that we've seen so far, or a different relative position of L and R)
for example:

start = XXL
end   = XXR

Then because we know start[p1] == end[p2], we further check...

if start[p1] == 'L'(== end[p2]), then, because L can only be moved to the left
in start, p2 should be <= p1

start = LXX
end =   XXL   ... can't switch

start = XXL
end =   LXX   ... good to switch

on the other hand, if start[p2] == 'R'(== end[p2]), because R can only be moved
to the right, p1 should be <= p2

start = XXR
end =   RXX   ... can't switch

start = RXX
end =   XXR   ... good to switch

*/
class Solution {
 public:
  bool canTransform(string start, string end) {
    int sz = start.size();
    int p1 = 0;
    int p2 = 0;
    while (p1 < sz || p2 < sz) {
      while (p1 < sz && start[p1] == 'X') {
        p1++;
      }
      while (p2 < sz && end[p2] == 'X') {
        p2++;
      }
      // only one exhaust, must have different non-X
      if ((p1 >= sz) ^ (p2 >= sz)) {
        return false;
      }
      if (start[p1] != end[p2]) {
        return false;
      }
      if (start[p1] == 'L' && p2 > p1) {
        return false;
      }
      if (start[p1] == 'R' && p1 > p2) {
        return false;
      }
      p1++;
      p2++;
    }
    return true;
  }
};