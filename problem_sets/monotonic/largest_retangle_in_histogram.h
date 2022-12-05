/*
Observation 1:

A rectangle can contribute to its higher right, but bounded by
the lowest height within the width.
- for example: [5 6 2], both rectangle 5 and 6 can contribute to
  rectangle with height 2

Observation 2:

When do a "height" becomes useless? When it encounters lower right.
- for example: [5 6 2], both rectangle 5 and 6 can contribute to
  rectangle with height 2, not 5 and 6

How do we combine both observations?

We keep a monotonically increasing stack for height. At the same
time, we keep a valid start point for the corresponding height.

When we encounter lower right, we pop the height, but we can extend
the valid start point of the lower right to the start point of the
popped height!

For example: [5 6 2 7]
idx 0: check: 5 -> stack: [(5, 0)]
idx 1: check: 6 -> stack: [(5, 0), (6, 1)]
idx 2: check: 2 ->
      1. pop (6, 1) as 2 is its lower right.
      2. we are now at idx 2, height 6 rectangle can only have width
         idx - 1 = 1, so maxArea = (INT_MIN, 6) = 6
      3. update height 2's valid start point to the popped one, 1
      4. pop (5, 0) as 2 is still its lower right.
      5. height 5 rectangle have width idx - 0 = 2, maxArea =
         max(6, 2 * 5) = 10
      6. update height 2's valid start point to the popped one, 0
      7. nothing in stack, push (2, 0). (Note: We don't need to
         calculate the area of height 2 yet.)
idx 3: check 7 -> stack [(2, 0) (7, 3)]

Now, what is left in the stack basically means the height could
extend to the right most edge (e.g. like edge idx = size = 4)

So
pop (7, 3), the area it contributes is 7 * (4 - 3) = 7
pop (2, 0), the are it contributes is 2 * (4 - 0) = 8
The biggest is 10
*/

class Solution {
  struct Rectangle {
    int height = 0;
    int validFrom = -1;
  };

 public:
  int largestRectangleArea(vector<int>& heights) {
    std::stack<Rectangle> monoIncStk;
    int maxArea = INT_MIN;
    int w = heights.size();
    for (int i = 0; i < w; ++i) {
      int h = heights[i];
      int validFrom = i;
      while (!monoIncStk.empty() && monoIncStk.top().height > h) {
        const auto& top = monoIncStk.top();
        validFrom = top.validFrom;
        maxArea = std::max(maxArea, top.height * (i - validFrom));
        monoIncStk.pop();
      }
      monoIncStk.push({h, validFrom});
    }
    while (!monoIncStk.empty()) {
      const auto& top = monoIncStk.top();
      maxArea = std::max(maxArea, top.height * (w - top.validFrom));
      monoIncStk.pop();
    }
    return maxArea;
  }
};