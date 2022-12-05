class Solution {
  public:
    int subarraySum(vector<int>& nums, int k) {
        // The idea of using counter is that counter record the times we've seen
        // for a value.
        //
        // Say we are checking nums[i], and checking how many times
        // counter[curSum[i] - k] has been seen in the previous range sum,
        // the value in the counter will be the number of times we can use
        // curSum[i] - X, where X is equal to curSum[i] - k, and exists before
        // seeing i.
        std::unordered_map<int, int> counter;
        int curSum = 0;
        int res = 0;
        // small trick here, for the case that curSum == k,
        // it's like curSum - k == 0 exists as well
        // and with adding this up, you don't need other branch in the below
        // loop, you can always just exam whether curSum - k is seen.
        counter[0] = 1;
        for (auto n : nums) {
            curSum += n;
            if (auto it = counter.find(curSum - k); it != counter.end())
                res += it->second;
            // add the counter after adding the res
            // as curSum - k might == curSum, but we want
            // to add the counter before checking on n
            counter[curSum] += 1;
        }
        return res;
    }
};