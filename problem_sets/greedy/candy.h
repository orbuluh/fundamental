class Solution {
    // key idea: we only increase when neighbor is larger.
    // by what this question is asking for, we do it in 2 pass:
    // firstly, each child has 1 candy
    // then in first pass, we ensure higher rating right child has higher score
    // than left (otherwise, we can keep it as 1 candy). So this gives us:
    // rating     3 4 5 6 6 5 4 3 2
    // candy  --> 1 2 3 4 1 1 1 1 1
    // then in the second pass, we make sure higher rating left child has higher
    // score than right (otherwise, keep the current value) candy
    //            1 2 3 4 5 4 3 2 1  <---
    //
    // In the second pass, we keep the larger value of right + 1 or its current
    // value. As its current value ensure to be larger than its left, if nums[i]
    // > nums[i-1], from the first pass consider:
    //   R:      3 4 3 2 1
    //  1st: --> 1 2 1 1 1
    //  2nd:     1 4 3 2 1 <--
    // or
    //   R:      1 2 3 3 2
    //  1st: --> 1 2 3 1 1
    //  2nd:     1 2 3 2 1
  public:
    int candy(vector<int>& ratings) {
        const auto n = ratings.size();
        std::vector<int> candy(n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1])
                candy[i] = candy[i - 1] + 1;
        }
        int res = candy[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1])
                candy[i] = std::max(candy[i + 1] + 1, candy[i]);
            res += candy[i];
        }
        return res;
    }
};