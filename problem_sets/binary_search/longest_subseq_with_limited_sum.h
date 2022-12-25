/*
nothing to do with subsequence actually
greedy sum from smallest number to get the max size

[4 5 2 1] -> [1 2 4 5]
      cdf -> [1 3 7 12]

then binary search --> the index of first larger than target
will equal to the size of elements in front of it, which is
what we want in answer. So use upper_bound will give us
direct answer.
*/

class Solution {
 public:
  vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    std::sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); ++i) {
      nums[i] += nums[i - 1];
    }
    std::transform(queries.begin(), queries.end(), queries.begin(), [&](int e) {
      return std::upper_bound(nums.begin(), nums.end(), e) - nums.begin();
    });
    return queries;
  }
};