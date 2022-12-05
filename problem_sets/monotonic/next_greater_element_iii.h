/*

Say original number is decreasing from front (or say, increasing from the back),
like n = 9753, there can't be a digit permutation that is larger.

Since we are finding the smallest integer that is larger than original number,
let's focus on the pattern from the back (right digits). Ultimately, when we
see a decreasing sequence from the back, we find a place to create a larger
number.

Say it's  6453 --> from back, 5 -> 4 is the first place seeing decreasing
           ^^
So 4 is the place to do a swap. Will it be just swapping the first decreasing
place: 6453 -> 6543? No, the next bigger number is 6534
        ^^      ^^                                  ^^^

What's the pattern here? the first place seeing the decreasing from the back,
call it pivot value, will be a place that could have been bigger.

But to make the number the smallest bigger value, you should swap with a number
that is smallest for what you've seen before pivot, but larger than pivot. Once
pivot value is swapped, to make the number smallest, you eventually sort the
remaining digits decreasingly from back. For example:

    169871
     ^^      ... 6 9 is the first place decreasing
 -->1[69871] ... what you should swap is smallest of [9871] but larger than 6
         ^
 -->17[9861] ... and then once pivot point is swapped with larger value, as
                 the original [9871] is sorted, and the sorted number is the
                 first one larger than pivot value, so after swapping, the
                 [9861] should be sorted as well. And to make it smallest, you
                 basically just need to reverse it: [9861] -> [1689]
 -->17[1689]


This operation can also be done using monotonic increasing stack from the back
it will be like storing the index of element in the stack, when you find the
first new value < stack.top, you keep popping value out of stack the last one
you popped is the one to swap with the new value.

idx: 0 1 2 3 4 5
val: 1 6 9 8 7 1

stk: [5] -> [5,4] -> [5,4,3] -> [5,4,3,2]

then seeing idx 1, value 6, popping out value larger than 6

stk: [5] --> 4 is last one popped, so you need to swap idx 4 and 1

idx: 0 1 2 3 4 5
val: 1 7 9 8 6 1

--> then you sort the idx + 1 = 2 to the end.

*/

class Solution {
 public:
  int nextGreaterElement(int n) {
    std::string nStr = std::to_string(n);
    const int sz = nStr.size();
    std::stack<int> monoIncStk;

    for (int i = sz - 1; i >= 0; --i) {
      if (monoIncStk.empty() || nStr[monoIncStk.top()] <= nStr[i]) {
        monoIncStk.push(i);
        continue;
      }
      int lastPopIdx = monoIncStk.top();
      while (!monoIncStk.empty() && nStr[monoIncStk.top()] > nStr[i]) {
        lastPopIdx = monoIncStk.top();
        monoIncStk.pop();
      }
      std::swap(nStr[i], nStr[lastPopIdx]);
      std::sort(nStr.begin() + i + 1, nStr.end());
      auto res = std::stol(nStr);
      return res > INT_MAX ? -1 : res;  // edge case 2147483486
    }
    return -1;
  }
};