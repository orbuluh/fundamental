/*
use binary search to find the start point of the k size window.

the final idx that can form the window is
    sz - 1 - idx + 1 = k, idx = sz - k
So R is initialized as sz - k, L is initialized as 0

Then how to move the l and r?

  (1) x <= arr[mid], which means x is <= the current window.

                   |-- size k window --|
   L, ..., x, ..., mid, ..., mid + k - 1, mid + k, ... R

   As window will always include x, for window to include x, the start point of
   the window (e.g. mid, a.k.a candidate of window start idx) can only left
   shift, hence we move the high bound R = mid.

   Put it another way, if window start at mid + 1, it means x can never be
   included, which makes the window not the optimal one.

  (2) x >= arr[mid + k], which means mid + k should be included into the window
           |-- size k window --|
   L, ..., mid, ..., mid + k - 1, mid + k, ..., x, ... R

   for window to include x, the start point of the window can only right shift
   L = mid + 1 (as mid just can't be a starting point, because mid + k is
   outside the window starting from mid, as graph shown)

  (3) else (arr[mid] < x < arr[mid + k])

           |------- size k window ------|
   L, ..., mid, ..., x, ... , mid + k - 1, mid + k, ... R

   so now, the window start at mid, and mid + k is outside of the window.
   and we know x is inside the current window. When should we include mid + k,
   e.g. right shift the starting point?

   Only if distance(arr[mid + k] - x) < distance(arr[mid] - x)
   when this happens, we make L = mid + 1
   otherwise, we know mid + k just can't be a good starting point, which means
   mid will become the upper bound of starting index. So R = mid
*/
class Solution {
 public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int l = 0;
    int r = arr.size() - k;
    while (l < r) {
      int mid = l + (r - l) / 2;  // a.k.a candidate for window start
      if (x <= arr[mid]) {
        r = mid;
      } else if (x >= arr[mid + k]) {
        l = mid + 1;
      } else {
        if (std::abs(arr[mid + k] - x) < std::abs(arr[mid] - x)) {
          l = mid + 1;
        } else {
          r = mid;
        }
      }
    }
    return std::vector(arr.begin() + l, arr.begin() + l + k);
  }
};