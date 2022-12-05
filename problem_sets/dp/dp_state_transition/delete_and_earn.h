/*

It's basically like painting house

The relation is

take[n] build from skip[n-1] + n * counter[n]
skip[n] build from max(take[n-1], skip[i-1])?
*/

class Solution {
 public:
  int deleteAndEarn(vector<int>& nums) {
    std::map<int, int> counter;
    for (int n : nums) {
      counter[n] += n;
    }
    auto it = counter.begin();
    int prev = it->first;
    int take = it->second;
    int skip = 0;
    for (it = std::next(counter.begin()); it != counter.end(); ++it) {
      auto& [val, score] = *it;
      int prevScore = std::max(take, skip);
      take = (val == prev + 1 ? skip : prevScore) + score;
      skip = prevScore;
      prev = val;
    }
    return std::max(take, skip);
  }
};