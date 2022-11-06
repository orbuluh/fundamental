/*
Super mind-blowing way to find the binary search .... The idea is as follows

Supposed we only have one sorted array - the median will basically be the
middle (one/two).

But what if we have 2 sorted array? Say ...

nums1 = x1, x2, ... xm
nums2 = y1, y2, ... yn


then you can imagine, there should exist a cut xc in nums1, and a cut yc in
nums2, where

x1, x2, ... xc | xc+1 ... xm
               x  ~~~~~~~~~~> comparisons between xc, yc+1 AND yc, xc+1
y1, y2, ... yc | yc+1, ...yn

where setL = set([x1 -> xc]) + set([y1 -> yc]) has (m + n) / 2 elements

AND xc < yc+1 and yc < xc+1 -> why?

Then you can be sure setL is the lower part of the full sorted m + n elements
- As xc < yc+1 and xc < xc+1 ensures all xc elements are smaller than
  right set
- same, yc < xc+1 and yc < yc+1 ensures all yc elements are smaller
  than right set)

e.g.   xc is left portion's maximal for nums1, e.g. maxL1
       xc+1 is right portion's minimal for nums1, e.g. minR1
       yc is left portion's maximal for nums2, e.g. maxL2
       yc+1 is right portion's minimal for nums2, e.g. minR2

So we are looking for maxL1 < minR2 and maxL2 < minR1

And when it's the lower part of the full sorted m + n elements, the max of setL,
which equals to the max of (xc, yc), is basically the mid (or one of the mid, if
m + n is even) While min of (xc+1, yc+1) is the other mid.

Also because setL can only have (m + n) / 2 elements, we can binary search on
one array, then wwe can decide the cut point for the other array.

Taking an example,

say nums1 = [1 3 5 7 9] and nums2 = [2 4 6 8], (m + n) / 2 = 4
you want to find xc + yc = 4 elements
--> the min of right part is the mid when m + n is odd

Another example

   xc
[1 3 | 5 7 9]
   yc
[2 4 | 6 8]
--> min of right = min(5, 6) = 5

say nums1 = [1 3 5 7] and nums2 = [2 4 6 8], (m + n) / 2 = 4

--> when m + n is even case, we want to find max of left and min of right

e.g. (max(3, 4) + min(5, 6)) / 2

   xc
[1 3 | 5 7]
   yc
[2 4 | 6 8]


Edge case 1:
xc
[|100]
   yc
[2 4 |6 8]

in this case, xc is 0, meaning nothing in nums1's lower portion. For case like
this, you can just make maxL1 = INT_MIN, so the whole comparison can work as
normal case.

Edge case 2:
  xc
[1|]
   yc
[2 |4 6 8]

in this case, xc is nums1.size(), meaning everything in nums1's is smaller than
in nums2. In this, you can just make minR1 = INT_MAX, then the whole comparison
can work as normal case.
*/
class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
      std::swap(nums1, nums2);
    }
    const int m = nums1.size();
    const int n = nums2.size();
    const bool isEven = (m + n) % 2 == 0;
    const int half = (m + n) / 2;
    int l = 0;
    int r = m;
    while (l <= r) {
      // make cut1 means cut1 of elements on nums1 that are in the lower part
      // then there are half - cut1 elements on nums2 that are in the lower part
      // the last index on nums1: cut1 - 1
      // the last index on nums2: half - cut1 - 1
      int cut1 = l + (r - l) / 2;
      int cut2 = half - cut1;

      // edge case, when non is taken from a portion
      // we can just use INT_MIN/INT_MAX to make sure it won't be taken
      int maxL1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
      int maxL2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
      int minR1 = cut1 == m ? INT_MAX : nums1[cut1];
      int minR2 = cut2 == n ? INT_MAX : nums2[cut2];

      if (maxL1 <= minR2 && maxL2 <= minR1) {
        if (isEven) {
          return (std::max(maxL1, maxL2) + std::min(minR1, minR2)) / 2.0;
        } else {
          return std::min(minR1, minR2);
        }
      } else if (maxL1 > minR2) {
        r = cut1;
      } else {
        l = cut1 + 1;
      }
    }
    return 0.0;  // can't happen
  }
};