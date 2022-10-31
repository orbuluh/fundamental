class Solution {
    /*
    Say there are n colors.

    if you think the state is "paint current house as color j"
    it would take more memory space - As when you consider paint
    as color j at house i, you need to consider previous house's
    color for each current color j. so it will become a O(n^2)
    checking to find the minCost of painting house i

    on the other hand, if you think about the state as
    "house i-1 painted with color j", when you are dealing with house i
    you only need to iterate through all the color against prevColor with O(n)

    with below way, the space complexity of this solution is O(m * t * n).
    We access individual cache members up to n times per search node,
    so time complexity is O(m * t * n^2).
    */
  public:
    static constexpr int NA = 1'000'001; // max cost sum == max(m) * max(cost)
    using D1Vec = std::vector<int>;
    using D2Vec = std::vector<D1Vec>;
    using D3Vec = std::vector<D2Vec>;
    D3Vec dp;
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n,
                int target) {
        dp = D3Vec(target + 1, D2Vec(m, D1Vec(n + 1, 0)));
        // color is 1-based, so before houseIdx == 0, assume color is 0
        // will basically make houseIdx color to be different
        const int res = dfs(houses, cost, 0, target, 0);
        return res != NA ? res : -1;
    }

    int dfs(const vector<int>& houses, vector<vector<int>>& cost, int houseIdx,
            int targetLeft, int prevColor) {
        // dfs return the cost needed to the end, when you are at houseIdx with
        // targetLeft group and with a certain prevColor

        // if targetLeft is 0 and you finish all houseIdx, the cost needed is 0
        // here (so you can recursive back with a 0 cost)
        if (houseIdx >= houses.size()) {
            return targetLeft == 0 ? 0 : NA;
        }
        if (targetLeft < 0) {
            return NA;
        }
        if (dp[targetLeft][houseIdx][prevColor] != 0) {
            return dp[targetLeft][houseIdx][prevColor];
        }

        // if the house is painted already...
        const int paintedClr = houses[houseIdx];
        if (paintedClr != 0) {
            return dp[targetLeft][houseIdx][prevColor] =
                       dfs(houses, cost, houseIdx + 1,
                           targetLeft - (prevColor != paintedClr), paintedClr);
        }

        // find the color that can minimize the cost under current state
        int minCost = NA;
        for (int clr = 1; clr <= cost[houseIdx].size(); ++clr) {
            minCost = std::min(minCost,
                               cost[houseIdx][clr - 1] +
                                   dfs(houses, cost, houseIdx + 1,
                                       targetLeft - (prevColor != clr), clr));
        }
        return dp[targetLeft][houseIdx][prevColor] = minCost;
    }
};