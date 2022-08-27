/*

You were stuck at the backtrace implementation as it needs to
take the min of max of result ...

Need to think for recursion on the subproblem, it would be like
before idx, it doesn't matter, you just need to find that supposed
you are trying to find a group starting from idx, and you are solving
the same question - e.g. need to find the min of max sum among the
remaining groups. You don't need to return the max sum from the
recursion, it's not what you need for the question. You just need to
find given certain situation, what would be the best possible way to
split the result ...

Compared to the optimal solution (0 ms runtime)... this one took 2800ms
check the optimal binary search solution...

The complexity here is O(N*N*m) where N = nums.size()
*/
class Solution {
 public:
  int totalGroup = 0;
  std::unordered_map<int, int> cache;

  int splitArray(vector<int>& nums, int m) {
    totalGroup = m;
    return dfs(nums, 0, m);
  }

  int dfs(vector<int>& nums, int idx, int groupLeft) {
    if (groupLeft == 1) {
      return std::accumulate(nums.begin() + idx, nums.end(), 0);
    }
    auto key = idx * totalGroup + groupLeft;
    auto it = cache.find(key);
    if (it != cache.end()) return it->second;

    int groupSum = 0;

    // after selecting the group here, you still need to build up
    // groupLeft - 1 groups, and you will at least need to leave
    // groupLeft - 1 elements to make sure that. e.g. x being the
    // lastIdx you can use to form the group in this iteration ...
    // nums.size() - 1 - (x + 1) + 1 = groupLeft - 1
    // x = n - 1 - 1 + 1 + 1 - groupLeft = n - groupLeft

    int minOfMaxSum = INT_MAX;
    for (int i = idx; i <= nums.size() - groupLeft; ++i) {
      // adding one elelemnt a time to the group
      groupSum += nums[i];
      // assuming the group is ursing element from idx to i (inclusive)
      // - we try to find the min value of the max sum of the remaining
      // elements with one less group
      int minOfMaxOfRemain = dfs(nums, i + 1, groupLeft - 1);
      // given using [idx, i] as one group, the max group sum value
      // from this group and the remaining
      int maxGroupSum = std::max(minOfMaxOfRemain, groupSum);
      // among all ways of split, which one give you the min of max
      minOfMaxSum = std::min(maxGroupSum, minOfMaxSum);
    }

    return cache[key] = minOfMaxSum;
  }
};
