/*
    // Intuitively ... you did this first.
    // E.g. Sort the box unit (O(log n)) and calculate.

    // But since the question states that ...
    // 1 <= numberOfBoxesi, numberOfUnitsPerBoxi <= 1000
    // you could actually make the solution to be O(n) with counting sort!

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        std::sort(boxTypes.begin(), boxTypes.end(),
                  [](const auto& b1,
                     const auto& b2) { return b1[1] > b2[1]; });
        int res = 0;
        for (int i = 0; i < boxTypes.size() && truckSize > 0; ++i) {
            res += std::min(boxTypes[i][0], truckSize) * boxTypes[i][1];
            truckSize -= boxTypes[i][0];
        }
        return res;
    }
*/

class Solution {
  public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // 1 <= numberOfBoxesi, numberOfUnitsPerBoxi <= 1000
        std::array<int, 1001> boxCnt{0};
        for (const auto& bt : boxTypes) {
            boxCnt[bt[1]] += bt[0];
        }
        int res = 0;
        for (int unit = 1000; unit > 0 && truckSize > 0; --unit) {
            res += std::min(boxCnt[unit], truckSize) * unit;
            truckSize -= boxCnt[unit];
        }
        return res;
    }
};