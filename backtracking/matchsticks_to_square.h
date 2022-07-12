class Solution {
  public:
    int edgeLen = 0;
    int n = 0;
    std::vector<bool> visited;
    bool makesquare(vector<int>& matchsticks) {
        int sumOfLen =
            std::accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sumOfLen % 4 != 0)
            return false;
        //------------------------------------
        n = matchsticks.size();
        edgeLen = sumOfLen / 4;
        sort(matchsticks.begin(), matchsticks.end());
        if (matchsticks.back() > edgeLen)
            return false;
        visited = std::vector<bool>(n, false);
        //------------------------------------
        return backtrack(matchsticks, 0, 0, 4);
    }

    bool backtrack(vector<int>& matchsticks, int searchStart, int curLen,
                   int edgeRemain) {
        if (edgeRemain == 1)
            return true; // if you can form 3 edges, then the remain edge must
                         // be true
        if (curLen == edgeLen) {
            // when finding next edge ...
            // -> move searchStart back to 0
            // -> move curLen back to 0
            // -> edgeRemain - 1
            return backtrack(matchsticks, 0, 0, edgeRemain - 1);
        }

        for (int j = searchStart; j < n; ++j) {
            if (visited[j])
                continue;
            if (curLen + matchsticks[j] > edgeLen)
                break;
            visited[j] = true;
            // try to use stick j at current edge
            if (backtrack(matchsticks, j + 1, curLen + matchsticks[j],
                          edgeRemain))
                return true;
            // here, stick j just can't be used for current edge
            visited[j] = false;
        }
        return false;
    }
};