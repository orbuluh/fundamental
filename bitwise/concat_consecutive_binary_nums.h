class Solution {
 public:
  static constexpr int mod = 1'000'000'007;
  int concatenatedBinary(int n) {
    int bitsNeed = 0;
    long res = 0;
    for (int i = 1; i <= n; ++i) {
      if ((i & (i - 1)) == 0) {
        bitsNeed++;
      }
      res = ((res << bitsNeed) % mod) + i;
    }
    return res % mod;
  }
};
