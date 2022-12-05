class Solution {
  public:
    /*
    Consider: [0,1,0,3,2,3]

    you can't just use monoQ to do this, why?
    it would be like [0, 1] -> [0, 3] -> [0, 2, 3]
    but the longest will be [0 1 2 3]. E.g. when you see the second 0
    you can't just pop everything >= it out, as those could have formed
    a longer sequence.

    Beautiful solution ...

    dp[i] = minimum value that can form a seq with len i + 1

    so same question would be:

  dp_idx 0 1 2 3
      dp 0
loop arr   1
      |  0
      |      3
      |      2
      v        3

    question - can we say dp[2] = 2 when we see 2?
    Yes, because if after 2, there is something even larger
    it's guaranteed to be okay to put it after to form a longer sequence!

    */
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> dp;
        dp.reserve(nums.size() / 2);
        for (auto n : nums) {
            auto it = std::lower_bound(dp.begin(), dp.end(), n);
            if (it == dp.end()) {
                dp.push_back(n);
            } else if (*it > n) {
                *it = n;
            }
        }
        return dp.size();
    }
};