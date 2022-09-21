/*
Check out your rolling hash notes. For a given pattern size k, we build a
hashmap for the original content with all size k window, using rolling hash.

Then for this problem, we can basically use binary search on the window size k
to find the maximum length!

Time complexity becomes O(log(n) * (m + n))
*/

const int basePow = 131;
using std::vector<uint64_t> = std::vector<uint64_t>;
class Solution {
 public:
  int m, n;
  std::vector<uint64_t> hash1, hash2, power;

  uint64_t get(std::vector<uint64_t>& h, int l, int r) {
    // making it a cdf like structure to compute range sum basically
    // h[0] = 0
    // h[1] = h[0] * base + nums[0]
    //      = nums[0]
    // h[2] = h[1] * base + nums[1]
    //      = nums[0] * base + nums[1]
    // h[3] = h[2] * base + nums[2]
    //      = nums[0] * base^2 + nums[1] * base + nums[2]
    // ...
    // say we want the hash of index 0 -> 2
    return h[r] - h[l - 1] * power[r - l + 1];
  }

  bool check(int windowSz) {
    std::unordered_set<uint64_t> seen;
    for (int i = 1; i + windowSz - 1 <= m; i++) {
      seen.insert(get(hash1, i, i + windowSz - 1));
    }
    for (int i = 1; i + windowSz - 1 <= n; i++) {
      if (seen.count(get(hash2, i, i + windowSz - 1))) {
        return true;
      }
    }
    return false;
  }
  void init(vector<int>& nums1, vector<int>& nums2) {
    m = nums1.size(), n = nums2.size();
    hash1 = std::vector<uint64_t>(m + 1, 0);
    hash2 = std::vector<uint64_t>(n + 1, 0);
    power = std::vector<uint64_t>(m + 1, 1);

    for (int i = 1; i <= m; i++) {
      hash1[i] = hash1[i - 1] * basePow + nums1[i - 1];
    }
    for (int i = 1; i <= n; i++) {
      hash2[i] = hash2[i - 1] * basePow + nums2[i - 1];
    }
    for (int i = 1; i <= m; i++) {
      power[i] = power[i - 1] * basePow;
    }
  }

  int findLength(vector<int>& nums1, vector<int>& nums2) {
    init(nums1, nums2);
    int l = 0, r = n;
    while (l < r) {
      int mid = l + ((r - l + 1) >> 1);  // bias to right
      if (check(mid)) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    return r;
  }
