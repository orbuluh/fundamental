/*
each day you can either plant a new one or keep planting what you are working
when plant is growing, you can plant other. So once it's planted - it's no
longer in you decision of the day afterwards (it's just affecting the result)


So maybe we would want to sort with grow time first?
e.g. the longer the grow time, the earlier we might consider to finish
and if grow time are the same, we just do the shorter planting time first?

      a b c
Plant 1 4 3
Grow  2 3 1


0 1 2 3 4 5 6 7 8 9
P P P P G G G B        ... b
        P G G B        ... a
          P P P G B    ... c

      a b c d
Plant 1 2 3 2
Grow  2 1 2 1

0 1 2 3 4 5 6 7 8 9
P P P G G B             ... c
      P G G B           ... a
        P P G B         ... b
            P P G B     ... d

*/
class Solution {
 public:
  int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
    std::vector<std::pair<int, int>> plants;
    for (int i = 0; i < plantTime.size(); ++i) {
      plants.emplace_back(std::make_pair(growTime[i], plantTime[i]));
    }
    std::sort(plants.begin(), plants.end(), [](const auto& p1, const auto& p2) {
      return p1.first > p2.first;
    });

    int lastPlantTime = -1;
    int maxFinish = 0;
    for (const auto& p : plants) {
      // Example: 2 plants:
      //  1. grow: 4, plant: 3
      //  2. grow: 2, plant: 2
      // 0 1 2 3 4 5 6 7 8 9
      // P P P P G G G B        ... 1
      //         P G G G B      ... 2
      // for example, first plant time is 4, -1 + 4 = 3 is the time (index) it's
      // planted then second plant time is 1, 1 + 3 = 4 is the time (index) it's
      // planted
      lastPlantTime += p.second;
      // first plant is done at 3, 3 + grow + 1 = 7 is the time plant 1 bloom
      // second plant is done at 4, 4 + grow + 1 = 8 is the time plant 2 bloom
      // at the end we try to find the latest/max bloom time
      maxFinish = std::max(maxFinish, lastPlantTime + p.first + 1);
    }
    return maxFinish;
  }
};