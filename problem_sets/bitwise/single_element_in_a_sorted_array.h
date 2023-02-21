/*
https://leetcode.com/problems/single-element-in-a-sorted-array/solutions/100732/short-compare-nums-i-with-nums-i-1/comments/538136

Starting from index 0, which is even, every number has to appear in pairs
(ideally): even-odd, even-odd, even-odd..... until it's broken by the single
number.

So if you check any odd-index and the even-index just before it, you can know
whether the single element comes in the array after the odd-index or before the
odd-index.

For instance: if I check index 5, and it's previous 4, if they are equal, that
automatically means that 0-1, 2-3, 4-5 etc are all in pairs, so the single
element would be in the array arr[6:end].

So we adjust low = mid +1 and proceed. If it wasn't equal that means that one
among 0-1, 2-3, 4-5 is a single element.

The cool trick that @StefanPochmann is using is to quickly figure out this
odd-and-previous-even (or equivalently even-and_next-odd depending on m),
quickly using xor, which is damn smart!

odd xor 1 = odd-1
even xor 1 = even+1
*/
class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] == nums[mid ^ 1]) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return nums[l];
  }

//--------------------------------------------------------------------------
  int singleNonDuplicate_yours(vector<int>& nums) {
    // your original submission ... works as well
    // if there is only 1 number, it's the answer
    // if 3 number
    // a a b -> [a] [ab] -> [][b] -> b
    // a b b -> [a] [bb] -> [a]
    //
    // idea: if firstPart.end == secondPart.begin, pop both out from search
    // then work on the odd portion

    int l = 0;
    int r = nums.size() - 1;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] == nums[mid + 1]) {
        // pop firstPart.end and secondPart.begin
        // firstPart becomes l to mid - 1
        // secondPart becomes mid + 2 to r
        if ((mid - l) % 2) {  // firstPart is odd, we going to search firstPart
          r = mid - 1;
        } else {  // secondPart is odd, we going to search secondPart
          l = mid + 2;
        }
      } else {
        if ((mid - l + 1) % 2) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
    }
    return nums[l];
  }
};