/*
You are checking the min and max in a subsequence.

min and max in [1, 2, 3, 4, 5] and [5, 2, 1, 3, 4] are all the same, it's just
1 and 5.

With this observation, the key thing to really simplify the problem is that you
can sort the input. And then you just need to find for every valid pair of min
max, how many numbers are in between. Then 2^(between numbers) is the count that
you will add up to the answer.

The std::once_call was trying to reduce the repeated pre-compute process. But
seems like it's not that matter. the
ios_base::sync_with_stdio(false), cin.tie(nullptr); trick is the critical part.
Did it anyway.
*/

class Solution {
  static constexpr int mod = 1e9 + 7;
  static std::once_flag flag;
  static std::vector<int> modedCnt;
  static void init() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    modedCnt = std::vector<int>(1e5 + 1, 1);
    for (int i = 1; i <= 1e5; ++i) {
      modedCnt[i] = modedCnt[i - 1] * 2 % mod;
    }
  }

 public:
  int numSubseq(vector<int>& nums, int target) {
    std::call_once(flag, init);
    const int sz = nums.size();
    std::sort(nums.begin(), nums.end());
    int l = 0;
    int r = sz - 1;
    int cnt = 0;
    while (l <= r) {
      while (r >= 0 && nums[l] + nums[r] > target) {
        r--;
      }
      if (r - l >= 0) {
        cnt = (cnt + modedCnt[r - l]) % mod;
      }
      l++;
    }
    return cnt;
  }
};

std::once_flag Solution::flag = {};
std::vector<int> Solution::modedCnt;
