class Solution {
    /*
    The hard part is that the equal value is NOT average but medium.

    Why? The idea is:

    consider you randomly pick a value x to be the final meeting point.
    say there are m points on the left of x, and n point on the right of x
    ....   x .........
    m pts        n pts  -> say moving all pts to x take S operations

    if we move x to x' = x + 1

    -> then moving all pts to x' will take S + m - n operations
       (e.g. all points to the right of x reduce 1 operations,
          and all points to the left of x increase 1 operations)

    so as long as right side has more points, we can keep moving x to the right and
    decrease the overall sum of operations. And we can see that the optimum point will
    be the median, where m == n, and we no longer can decrease the S

    What about the case that there are even number of points?
    say, medianIdx = (size-1) / 2

    In this case, final points could be nums[medianIdx] or nums[medianIdx + 1].
    it's basically like:
        you divide whole array to 2,
        -> move all left array to be equal to nums[medianIdx]
        -> move all right array to be equal to nums[medianIdx + 1]
    then moving all right side to be equal to nums[medianIdx] is the same as
         moving all left side to be equal to nums[medianIdx + 1]

    consider [1 2 4 9 9 10]
    -> [4 4 4 | 9 9 9]
    ->  making them [4 4 4 4 4 4] or [9 9 9 9 9 9] are need extra abs(9 - 4) * 3
    */
public:
    int minMoves2(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        const auto sz = nums.size();
        const int medianIdx = (sz - 1) / 2;  // ele 5 -> idx 2, ele 4 -> idx 1, ...
        const auto medianVal = nums[medianIdx];
        return std::accumulate(nums.begin(), nums.end(), 0,
                            [&](int x, int y) { return x + std::abs(y - medianVal); });

    }
// taking average failed at -> 1 0 0 8 6
    // [3,0,6,2,4,7,0,0]
    //  0 0 0 2 3 4 6 7
    // 6 + 4 + 3 + 1  14, 
};