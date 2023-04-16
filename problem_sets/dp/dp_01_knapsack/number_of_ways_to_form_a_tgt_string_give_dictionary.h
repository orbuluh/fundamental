/*
Essentially a to take at index i or not, knapsack problem.
Critical thing to speed-up is building the frequency counter.

So for wordIdx i, even several words words[x][i] match the current char in
target[tgtIdx], you only need to count once.
*/
class Solution {
  int tSz = 0;
  int numWrds = 0;
  int wSz = 0;
  std::vector<std::vector<int>> dp;
  std::vector<std::array<long, 26>> freq;
  std::string_view tgt;
  static constexpr int mod = 1'000'000'000 + 7;

 public:
  int numWays(vector<string>& words, string target) {
    tSz = target.size();
    numWrds = words.size();
    wSz = words.front().size();
    dp = std::vector<std::vector<int>>(wSz, std::vector<int>(tSz, -1));
    // making freq a long type so simpler to multiply later
    freq = std::vector<std::array<long, 26>>(wSz, std::array<long, 26>{});
    tgt = target;
    for (int i = 0; i < wSz; ++i) {
      for (int j = 0; j < numWrds; ++j) {
        freq[i][words[j][i] - 'a']++;
      }
    }
    return dfs(0, 0);
  }

  int dfs(int wrdIdx, int tgtIdx) {
    if (tgtIdx >= tSz) {
      return 1;
    }
    if (wrdIdx >= wSz || (tSz - tgtIdx > wSz - wrdIdx)) {
      return 0;
    }
    if (dp[wrdIdx][tgtIdx] != -1) {
      return dp[wrdIdx][tgtIdx];
    }
    // not taking words[x][wrdIdx] to form the target for x in [0, numWrds)
    int res = dfs(wrdIdx + 1, tgtIdx);

    // taking words[x][wrdIdx] only if char match tgt[tgtIdx]
    const int charIdx = tgt[tgtIdx] - 'a';
    if (freq[wrdIdx][charIdx]) {
      // how many words having the match has pre-computed by the freq already
      res += (freq[wrdIdx][charIdx] * dfs(wrdIdx + 1, tgtIdx + 1)) % mod;
    }
    return dp[wrdIdx][tgtIdx] = res % mod;
  }
};