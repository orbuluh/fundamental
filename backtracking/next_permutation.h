/*
Idea: Think about how to use backtrack to generate all permutation

idx: 0 1 2 3
     1 2 3 4 -> before reaching this 1 2 3 4 state, you were at
                pos 2, and you have 2 number left, 3 and 4, you pick
                3 first, then you put 4 at the end. So when you back track
                you will be at position 2, taking 4, and 3 at the end. Hence
     1 2 4 3 -> Then to backtrack this one, you go back to idx2, and the
                only 2 option 3, 4 has been tried, so you further go back to
                idx 1, there were 3 options: 2, 3, 4. And you've finished the
                case of picking 2 at idx1, so you tried next: 3, then in idx2
                you have 2 choices [2, 4], you pick the 2, then the end, 4
     1 3 2 4  ....

As how backtrack works, you will see that ... from the right most, if it's
monotonically increasing to the left, that portion is basically in an "finished
state" of the number before it ...for example, [4 3] in [1 2 4 3] basically mean
it's a finished state of previous number 2. And to find the next permutation,
it would be checking in [2 4 3], what's the next bigger number - e.g. 3, then
the remaining should be ascending -> [3 2 4] to form the "first state" of using
3 as the first number.

With this in mind, taking 1 2 3 4 again, it would be like 4 is the end of
monotonically increasing from right, so you need to tweak [3 4] and find the
next larger than 3, which is 4, so next permutation of the permutation is [4 3]
and the remaining are the same, e.g. [1 2 4 3]

*/

class Solution {
  public:
    void nextPermutation(vector<int>& nums) {
        int flipIdx = nums.size() - 1;
        // note the case like [5, 1, 1], the <= equation makes
        // flipIdx to correctly go to 0. As 1, 1 won't create
        // other permutation
        while (flipIdx >= 1 && nums[flipIdx] <= nums[flipIdx - 1]) {
            flipIdx--;
        }
        if (flipIdx == 0) { // the last permutation,
            std::reverse(nums.begin(), nums.end());
            return;
        }
        //
        for (int i = nums.size() - 1; i >= flipIdx; --i) {
            // find the first larger than flipIdx - 1, swap and
            // sort the remaining portion should give us the result.
            if (nums[i] > nums[flipIdx - 1]) {
                std::swap(nums[i], nums[flipIdx - 1]);
                std::sort(nums.begin() + flipIdx, nums.end());
                return;
            }
        }
        // for example, nums = [1, 1], only one permutation
        // return is the result
    }
};