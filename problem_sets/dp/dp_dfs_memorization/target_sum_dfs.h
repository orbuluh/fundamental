/*
DFS method + memorization is much intuitive.
For making it a bottom up question ... check target_sum_bottom_up.h

The simple ordered_map of ordered_map to form 2D hash map here.
If you want to check the 2D hashmap, check below uncommented part.
The core of algorithm are the same.

class Solution {
 public:
  std::unordered_map<int, std::unordered_map<int, int>> dp;

  int findTargetSumWays(vector<int>& nums, int target) {
    return dfs(nums, 0, target);
  }

  int dfs(const vector<int>& nums, int idx, int diffToTgt) {
    if (idx == nums.size()) {
      return diffToTgt == 0;
    }
    auto it = dp.find(idx);
    if (it != dp.end()) {
      auto it2 = it->second.find(diffToTgt);
      if (it2 != it->second.end()) {
        return it2->second;
      }
    }
    const int asPos = dfs(nums, idx + 1, diffToTgt - nums[idx]);
    const int asNeg = dfs(nums, idx + 1, diffToTgt + nums[idx]);
    return dp[idx][diffToTgt] = asPos + asNeg;
  }
};
*/

struct State {
  int idx = 0;
  int diffToTgt = 0;
  // Note: don't missed the const, function signature matters
  bool operator==(const State& otherS) const {
    return idx == otherS.idx && diffToTgt == otherS.diffToTgt;
  }
};

using StateHashMap = std::unordered_map<State, int>;

namespace std {
template <>
struct hash<State> {
  // Note: don't missed the const, function signature matters
  std::size_t operator()(const State& s) const {
    return std::hash<int>()(s.idx) ^ std::hash<int>()(s.diffToTgt);
  }
};
}  // namespace std

class Solution {
 public:
  StateHashMap dp;

  int findTargetSumWays(vector<int>& nums, int target) {
    return dfs(nums, State{0, target});
  }

  int dfs(const vector<int>& nums, State s) {
    if (s.idx == nums.size()) {
      return s.diffToTgt == 0;
    }
    auto it = dp.find(s);
    if (it != dp.end()) {
      return it->second;
    }
    const int asPos = dfs(nums, State{s.idx + 1, s.diffToTgt - nums[s.idx]});
    const int asNeg = dfs(nums, State{s.idx + 1, s.diffToTgt + nums[s.idx]});
    return dp[s] = asPos + asNeg;
  }
};