/*

If we sort the array to be non-decreasing order,

for example:
[a, b, c, d, e, f, g] and their corresponding costs:
[t, u, v, w, x, y, z]

and assume d is now the base point to be equal to

then the cost is leftCost + rightCost where

leftCost  = t(d - a) + u(d - b) + v(d - c)
          = d(t + u + v) - (ta + ub + vc)

rightCost = x(e - d) + y(f - d) + z(g - d)
          = - d(x + y + z) + (xe + yf + zg)

The idea is that these can be precomputed (DP):
- prefix sum, like (t + u + v) or (x + y + z)
- weighted prefix sum, like (ta + ub + vc) or (xe + yf + zg)


so we will have

0 prefixSum = [t,
1              t + u,
2              t + u + v,
3              t + u + v + w,
4              t + u + v + w + x,
5              t + u + v + w + x + y,
6              t + u + v + w + x + y + z]
---------------------------------------------------
0 weightedPS = [ta + ub + vc + wd + xe + yf + zg,
1                    ub + vc + wd + xe + yf + zg,
2                         vc + wd + xe + yf + zg,
3                              wd + xe + yf + zg,
4                                   xe + yf + zg,
5                                        yf + zg,
6                                             zg]
---------------------------------------------------
then use above example, when d (idx i = 3) is the base point,
the cost consists of

leftCost  = d(t + u + v)               - (ta + ub + vc)
          = nums[i] * prefixSum[i - 1] - (weightedPS[0] - weightedPS[i])

rightCost = - d(x + y + z)                                + (xe + yf + zg)
          = -nums[i] * (prefixSum[sz - 1] - prefixSum[i]) + weightedPS[i + 1]

The fastest solution seems to need some mathmatical proof to show that the base
point must be somewhere in the middle of sorted array ... ignore...
*/

static const int io_trick = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
}();
class Solution {
  struct D {
    int64_t v = 0;
    int64_t c = 0;
  };

 public:
  long long minCost(vector<int>& nums, vector<int>& costs) {
    const int sz = nums.size();
    std::vector<D> data(sz);
    for (int i = 0; i < sz; ++i) {
      data[i].v = nums[i];
      data[i].c = costs[i];
    }
    std::sort(data.begin(), data.end(),
              [](const auto& d1, const auto& d2) { return d1.v < d2.v; });
    std::vector<int64_t> prefixSum(sz);
    std::vector<int64_t> weightedPS(sz);
    prefixSum[0] = data[0].c;
    weightedPS[sz - 1] = data[sz - 1].v * data[sz - 1].c;
    for (int i = 1; i < sz; ++i) {
      prefixSum[i] = prefixSum[i - 1] + data[i].c;
      weightedPS[sz - 1 - i] =
          weightedPS[sz - 1 - i + 1] + data[sz - 1 - i].v * data[sz - 1 - i].c;
    }
    int64_t res = LONG_MAX;
    for (int i = 0; i < sz; ++i) {
      auto leftCost = data[i].v * (i >= 1 ? prefixSum[i - 1] : 0) -
                      (weightedPS[0] - weightedPS[i]);
      auto rightCost = -1 * data[i].v * (prefixSum[sz - 1] - prefixSum[i]) +
                       (i + 1 < sz ? weightedPS[i + 1] : 0);
      res = std::min(leftCost + rightCost, res);
    }
    return res;
  }
};