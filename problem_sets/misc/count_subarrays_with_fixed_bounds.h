/*

Every time we hit a number outside of range, it's a new start of searching.

So we can basically focus on this question first:

if we have a range number that are all inclusive, how do we count the number?

How to count? The magic formula from top voted post...@lee215, @vikas007

```
std::min(minAt, maxAt) - start + 1;
```

Below example have minK= 1, maxK = 5. We only start to add new findings if min
and max are found.

[5 1]    --> start = 0, minAt = 1, maxAt = 0, min(minAt, maxAt) = 0

Consider result of adding one valid number in front of 1

[2 5 1]  --> start = 0, minAt = 2, maxAt = 1, min(minAt, maxAt) = 1
   ^__      from the std::min(minAt, maxAt) to start, they all forming valid new
 ^____      subarray

Consider result of adding extra number in front

[3 2 5 1]  --> start = 0, minAt = 3, maxAt = 2 min(minAt, maxAt) = 2
     ^__    from the std::min(minAt, maxAt) to start, they all forming valid new
   ^____    subarray
^_______

Consider result of adding extra number at the end:
start = 0, minAt = 3, maxAt = 2, min(minAt, maxAt) = 2
[3 2 5 1 2]  --> no change, you still add 3
     ^____
   ^______
^_________


The beauty of the formula is when you see next minK or maxK ...
start = 0, minAt = 3, maxAt = 5, min(minAt, maxAt) = 3

[3 2 5 1 2 5]
       ^____
     ^______
   ^________
 ^__________


if you see extra 5 next, it won't impact:
start = 0, minAt = 3, maxAt = 6, min(minAt, maxAt) = 3

[3 2 5 1 2 5 5]
       ^______
     ^________
   ^__________
 ^____________


But if you see extra 1 next, it will update the boundary again:
start = 0, minAt = 7, maxAt = 6, min(minAt, maxAt) = 6

[3 2 5 1 2 5 5 1]
             ^__
           ^____
         ^______
       ^________
     ^__________
   ^____________
 ^______________


How to think of the magic formula to capture this behavior from beginning???
No idea now though...
*/
class Solution {
 public:
  long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    int minAt = -1;
    int maxAt = -1;
    int start = 0;
    const int sz = nums.size();
    long long res = 0;
    for (int i = 0; i < sz; ++i) {
      const int n = nums[i];
      if (n < minK || n > maxK) {
        minAt = maxAt = -1;
        start = i + 1;
      }
      if (n == minK) {
        minAt = i;
      }
      if (n == maxK) {
        maxAt = i;
      }
      if (minAt != -1 && maxAt != -1) {
        res += std::min(minAt, maxAt) - start + 1;
      }
    }
    return res;
  }
};