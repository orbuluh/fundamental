/*
dp[i][j] len of nums1[x:i+1] is the same as nums2[y:j+1] (non inclusive close)
then dp[i][j] = 0 if nums1[i] != nums2[j]  (as it needs to be continuous)
                  else 1 + dp[i-1][j-1]

say M = source len, N = pattern len
DP solution has complexity O(M * N) and space complexity of O(N)
hence we do a swap if nums1 is shorter than nums2 to minimize space complexity

*/
class Solution {
 public:
  int findLength(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() < nums2.size()) {
      std::swap(nums1, nums2); // minimize space complexity
    }
    const auto n1Sz = nums1.size();
    const auto n2Sz = nums2.size();
    std::vector<int> dp(n2Sz, 0);
    int maxLen = 0;
    for (int i = 0; i < n1Sz; ++i) {
      std::vector<int> nxtDp(n2Sz, 0);
      for (int j = 0; j < n2Sz; ++j) {
        if (nums1[i] != nums2[j]) continue;
        nxtDp[j] = 1 + ((i > 0 && j > 0) ? dp[j - 1] : 0);
        maxLen = std::max(maxLen, nxtDp[j]);
      }
      std::swap(dp, nxtDp);
    }
    return maxLen;
  }
