/*
quick select way ...

idea, utilize quick select - eventually find a pivot that is at index sz - k, as
quick select only guarantee element on pivot's left is smaller (not sorted), and
right is larger (not sorted).

The advantage, compared to normal quick sort partition, is that as we are
looking element at sz - k, we will know which portion of data to recursively
check.

One caveat is how you implement the partition - the key is making random pivot
to be at the end of array. Doing this will make the whole thing much clear.
(Originally you try to make the first one the random pivot ... which complicated
the whole implementation...)

So quick select will be like:
- quickSelect(start, end, targetIdx):
- making pivot at the end index, pivotVal = nums[end]
- making a pointer p to represent first number larger than pivotVal
- loop the array from begin to end - 1
    - if nums[i] is <= pivotVal, we swap with nums[p] and p++ as nums[p] is
      supposed to contains the first larger number
    - else:
      we simply keep iterating the array till the end - 1

say: input: [3,5,1,2,6,4], k = 2
Goal is finding pivot @ index = 6 - k = 4

quickSelect(start = 0, end = 5, targetIdx = 4):
- pivot[end] == 4
 p
[3,5,1,2,6,4]
 i         ^

   p
[3,5,1,2,6,4]
     i     ^   i is smaller than 4, swap with p and p++, i++

     p
[3,1,5,2,6,4]
       i   ^   i is smaller than 4, swap with p and p++, i++

       p
[3,1,2,5,6,4]
         i ^  is  is larger than, continue and finish looping begin to end - 1

Then because we know first larger is at p, we should swap with pivotVal (4)
this eventually make sure the pivotVal is at the right index (3)
       p
[3,1,2,4,6,5]
       ^

But since index 3 is smaller than our targetIdx, we know we should check the
right hand side, e.g. p + 1 to end

quickSelect(start = p + 1 = 4, end = 5, targetIdx = 4)

and we do the same thing till we swap pivot value to targetIdx!

Also same logic, when it's at the left hand side, it should do
quickSelect(start, end = p - 1, targetIdx)

*/
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
  }

  int quickSelect(vector<int>& nums, int begin, int end, int targetIdx) {
    if (begin == end) {  // must equal to targetIdx
      return nums[begin];
    }
    int pivotVal = nums[end];
    int firstLarger = begin;
    for (int i = begin; i < end; ++i) {
      if (nums[i] <= pivotVal) {
        std::swap(nums[i], nums[firstLarger++]);
      }
    }
    std::swap(nums[end], nums[firstLarger]);
    if (firstLarger == targetIdx) {
      return nums[targetIdx];
    } else if (firstLarger < targetIdx) {
      return quickSelect(nums, firstLarger + 1, end, targetIdx);
    } else {
      return quickSelect(nums, begin, firstLarger - 1, targetIdx);
    }
  }
};

/*
side note: heapify the input with max priority queue with O(n) then pop k
numbers with klog(k) is actually much quicker in leetcode OJ. The problem
description of O(n) algorithm has to use quick select.

Note that quick select is amortized O(n), as ideally it's like
O(n) + O(n/2) + O(n/4) .... ~ O(2n) = O(n)
*/