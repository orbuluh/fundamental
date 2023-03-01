/*
Clean way to implement quick select is swapping pivot to the end
Then using a for loop and update an index of "firstLarger" accordingly. How?

so firstLarger points to the first number larger than pivot
and the for loop index i should keep scanning the range, and whenever it sees a
value that is <= pivot, it just swap with the firstLarger number

f (first larger)
i (the for loop idx)
        p(ivot)
5 4 1 2 3

f i
5 4 1 2 3  | nothing changed, first larger still point at 5

f   i          f i
5 4 1 2 3 -> 1 4 5 2 3  | e.g. see 1 < 3, swap 1 with the first larger location
  f   i          f
1 4 5 2 3 -> 1 2 5 4 3  | e.g. see 2 < 3, swap 2 with the first larger location

Doing so, when loop breaks, firstLarger index must contain a value that is
larger than the pivot. So you can simply swap pivot with firstLarger.

*/
class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    quickSort(nums, 0, nums.size() - 1);
    return std::move(nums);
  }
  bool hasSorted(vector<int>& nums, int l, int r) {
    // quicksort worst case ... the input has sorted
    // (all have all equal values, which will give you TLE)
    for (int i = l + 1; i <= r; ++i) {
      if (nums[i] < nums[i - 1]) {
        return false;
      }
    }
    return true;
  }

  void quickSort(vector<int>& nums, int l, int r) {
    if (l >= r || hasSorted(nums, l, r)) {
      return;
    }
    // will TLE without random pivot
    int randPivot = rand() % (r - l + 1) + l;
    std::swap(nums[r], nums[randPivot]);
    int pivot = nums[r];
    int firstLarger = l;

    for (int i = l; i < r; ++i) {
      if (nums[i] <= pivot) {
        std::swap(nums[i], nums[firstLarger++]);
      }
    }
    std::swap(nums[firstLarger], nums[r]);
    quickSort(nums, l, firstLarger - 1);
    quickSort(nums, firstLarger + 1, r);
  }
};