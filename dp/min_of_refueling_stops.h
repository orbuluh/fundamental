class Solution {
    /*
    dp[i] - longest distance we can get with i sty

    // (Not the best solution for this one. Check README)
    */
  public:
    int minRefuelStops(int target, int startFuel,
                       vector<vector<int>>& stations) {
        std::array<long, 501> dp{};
        dp[0] = startFuel;
        for (int i = 0; i < stations.size(); ++i) {
            // for each station, you can come from somewhere before
            const int pos = stations[i][0];
            const int gas = stations[i][1];
            // when you are at station i, you maximally stay i times before
            // and you could have reached i from any of the step before
            // as long as previous station provide large enough gas
            for (int stayCnt = i; stayCnt >= 0 && dp[stayCnt] >= pos;
                 stayCnt--) {
                // if you can arrive i with j step, and with j step you can
                // reach x then with extra one stay at i, you should reach
                // x + gas(i). Note that dp element kept updating in O(N^2)
                dp[stayCnt + 1] = std::max(dp[stayCnt + 1], dp[stayCnt] + gas);
            }
        }
        for (int stayCnt = 0; stayCnt <= stations.size(); ++stayCnt)
            if (dp[stayCnt] >= target)
                return stayCnt;
        return -1;
    }
};