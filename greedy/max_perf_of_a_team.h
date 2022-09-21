/*
- solution from discussion, which is really clever. The calculation is:
  sum(speeds) * min(efficiency)
- So if you sort all the information with efficiency - and loop through each one
  by one, you are sure that the later information you encounter, it must have
  a <= efficiency seen so far.
- but there could have a case that smaller efficiency having a larger speed? It
  is easy, you simply just need to kick out the one with smallest speed along
  the way, when the data you collect has more than k people!
- E.g. you can do this in a greedy way now!! (Dang!)
*/

class Solution {
  static constexpr int mod = 1'000'000'007;

 public:
  int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency,
                     int k) {
    // NOTE: for this profile struct, there is no need to make it a max priority
    // queue and top and pop. it's just much slower overal. There is no need to
    // do those operations in the fiinal loop anyway
    std::vector<pair<int, int>> profiles;
    for (int i = 0; i < efficiency.size(); ++i) {
      profiles.emplace_back(efficiency[i], speed[i]);
    }
    std::sort(profiles.begin(), profiles.end(), greater<pair<int, int>>());
    int64_t sum = 0;
    int64_t maxPerf = 0;
    std::priority_queue<int, std::vector<int>, std::greater<>> minSpeed;
    for (auto& [eff, speed] : profiles) {
      if (minSpeed.size() == k) {
        sum -= minSpeed.top();
        minSpeed.pop();
      }
      sum += speed;
      minSpeed.push(speed);
      maxPerf = std::max(maxPerf, (sum * eff));
    }
    return maxPerf % mod;
  }
