/*
[1 2 3 2 1 5]

mono decreasing stack, with (val, idx) pair
pop if smaller, update index diff
[(1,0)]
[(2,1)] ... pop (1,0), update ans[0] = 1 - 0
[(3,2)] ... pop (2,1), update ans[1] = 2 - 1
[(3,2)(2,3)(1,4)]
[(5,5)] ... pop (1,4), update ans[4] = 5 - 4
            pop (2,3), update ans[3] = 5 - 3
            pop (3,2), update ans[2] = 5 - 2

Check greedy/daily_temperatures.h for even optimize solution
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int sz = temperatures.size();
        std::vector<int> ans(sz, 0);
        std::stack<std::pair<int, int>> monoDecStk;
        for (int i = 0; i < sz; ++i) {
            while (!monoDecStk.empty() && monoDecStk.top().first <
temperatures[i]) { auto preIdx = monoDecStk.top().second; monoDecStk.pop();
                ans[preIdx] = i - preIdx;
            }
            monoDecStk.emplace(temperatures[i], i);
        }
        return ans;
    }
};