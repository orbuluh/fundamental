/*

The score is defined as

sum(nums1[i], nums1[j], ...nums1[k])       <--- sum
  x
  min(nums2[i], nums2[j], ... nums2[k])    <--- multiplier


What do the equation suggests?

1. If we processed nums2 value in descending order, we don't even need to bother
   finding the multiplier, the new index x, must provide the multiplier nums2[x]

2. Say we processed nums2 value in descending order, we are always making
   multiplier smaller. As a result, the only chance we can get a better score is
   making sum larger. And the only chance to make sum larger is kicking the
   smallest nums1 value out. Say among the k chosen indices, nums1[y] is the
   smallest, we are guaranteed to be safe to remove the impact of nums2[y], as
   nums2[y] just can't be smaller than the new nums2[x] (as we processes nums2
   value in descending order).

3. So we can just greedily searching the possible combination this way... just
   update the result when we find a larger score.

*/

class Solution {
 public:
  long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
    const int sz = nums1.size();
    std::vector<std::pair<int, int>> num2Num1;
    num2Num1.reserve(sz);
    for (int i = 0; i < sz; ++i) {
      num2Num1.emplace_back(nums2[i], nums1[i]);
    }
    std::sort(num2Num1.begin(), num2Num1.end(), std::greater());
    std::priority_queue<int, std::vector<int>, std::greater<int>> minPqForNum1;
    long long curSum = 0;
    long long maxVal = 0;
    for (const auto& [n2, n1] : num2Num1) {
      if (minPqForNum1.size() == k) {
        curSum -= minPqForNum1.top();
        minPqForNum1.pop();
      }
      minPqForNum1.push(n1);
      curSum += n1;
      if (minPqForNum1.size() == k) {
        maxVal = std::max(maxVal, curSum * n2);
      }
    }
    return maxVal;
  }
};