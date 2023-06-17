/*
arr1 needs to be strictly increasing. if we are going to swap something
in arr2, we should swap value as small as possible. So we sort arr2 first.

then we can use dfs + memorization...in each state where you've searched till
idx1 - 1 in arr1 and have used idx2 in arr2 ... you are trying to find the next
state through either swapping idx1 with next valid value in arr2, or just use
idx1 if arr1 is strictly increasing at the moment.

TODO: This could be rewrite as LIS way with bottom up, but just keep it simple
      for now...
*/
class Solution {
  short dp[2001][2001][2] = {};
  static constexpr short noSolution = 2002;

 public:
  int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
    std::sort(arr2.begin(), arr2.end());
    const auto res = dfs(arr1, arr2, 0, 0, false);
    return res >= noSolution ? -1 : res;
  }

  short dfs(const vector<int>& arr1, const vector<int>& arr2, int idx1,
            int idx2, bool prevFromSwapped) {
    if (idx1 >= arr1.size()) {
      return 0;
    }
    int prevVal =
        prevFromSwapped ? arr2[idx2] : (idx1 == 0 ? INT_MIN : arr1[idx1 - 1]);
    // skip value that is <= prevVal, as we need strictly increasing. Plus arr2
    // is sorted.
    idx2 = std::upper_bound(std::begin(arr2) + idx2, std::end(arr2), prevVal) -
           std::begin(arr2);
    auto& stateRes = dp[idx1][idx2][prevFromSwapped];
    if (stateRes) {
      return stateRes;
    }
    stateRes = noSolution;
    if (idx2 < arr2.size()) {
      stateRes = std::min(
          stateRes,
          // res of swapping arr2[idx2] with arr1[idx1], and continue dfs
          static_cast<short>(dfs(arr1, arr2, idx1 + 1, idx2, true) + 1));
    }
    // res of not swapping anything from arr2, and arr1 itself is increasing
    // already
    if (prevVal < arr1[idx1]) {
      stateRes = std::min(stateRes, dfs(arr1, arr2, idx1 + 1, idx2, false));
    }
    return stateRes;
  }
};