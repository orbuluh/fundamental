class Solution {
  // an element is either set 1 or set 2
  // so BF solution will basically be trying 2^n permutation. This is similar to
  // the approach that we do a dfs on nums each time we try to either make the
  // element in set1 or set2 at the end of nums, if sum(set1) == sum(set2),
  // return true otherwise return false
  //
  // can we do better?
  //
  // we calculate the sum of array with O(n)
  // if the sum of array is not even ... there is no chance to achieve
  // otherwise, we try to see if we can use < n elements to build sum / 2
  // The this problem reduced to 0/1 knapsack where element has only one and
  // there is a bounded target to achieve.
  //
  // note that you just want to see if there is a way to form sum / 2, you
  // actually don't even need to see if you can use < n elements. As if you've
  // used all elements, because every element has value > 0, the result can't be
  // sum / 2 - as a result, you can simply make dp array a bitset/vector of bool
 public:
  bool canPartition(vector<int>& nums) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2) return false;
    sum /= 2;
    std::vector<bool> dp(sum + 1, 0);
    std::vector<bool> nxtDp = dp;
    const int sz = nums.size();
    // build the knapsack through adding new item in each direction and try to
    // build the target sum with the existing set of items
    for (auto newVal : nums) {
      for (int tgt = 0; tgt <= sum; ++tgt) {
        // if dp[tgt] is true already -  this means we don't use newVal and we
        // can still build the tgt value here.
        if (nxtDp[tgt] = dp[tgt]) {
          continue;
        } else if (tgt == newVal) { // simply use newVal to form tgt
          nxtDp[tgt] = true;
        } else if (tgt > newVal) {
          // if we can't build tgt without newVal - we can see if we can
          // build target with tgt - newVal, plus the one newVal
          nxtDp[tgt] = nxtDp[tgt] | dp[tgt - newVal];
        }
        // ^^ here, you can also do a reversed loop from sum to newVal + 1
        // just feel like using forward loop is more intuitive
      }
      if (nxtDp[sum]) {
        return true;
      }
      std::swap(dp, nxtDp);
    }
    return false;
  }
};