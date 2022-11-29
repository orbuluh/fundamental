class Solution {
    /*
    Idea: If you think the problem more closely, the concept of t doesn't even
    matter. When we are stepping onto a grid where grid[i][j] <= t, we can just
    walk through it. If grid[i][j] > t, we must wait, so t = grid[i][j]. E.g.
    Eventually the value in the grid is what matters.

    So overall it's like finding the path from top-left to bottom-right, where
    you need to minimize the maximum value of the value along the path!

    How do we do this? It's basically like Dijkstra. We try to traverse the next
    smallest value through a PQ. And once we first reach bottom right, we must
    have seen the smallest of the maximum value along the way.

    One small implementation details - you should basically mark a grid visited
    when you put it into the PQ instead of when you actually step on it.
    */
  public:
    std::array<int, 5> dir{1, 0, -1, 0, 1};
    std::vector<std::vector<int>> visit;

    int swimInWater(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid.front().size();
        visit = std::vector<std::vector<int>>(m, std::vector<int>(n, 0));
        using State = std::tuple<int, int, int>;
        std::priority_queue<State, std::vector<State>, std::greater<>> minPq;
        minPq.emplace(std::max(grid[0][0], 0), 0, 0);
        int res = 0;
        while (!minPq.empty()) {
            const auto [t, i, j] = minPq.top();
            minPq.pop();
            res = std::max(res, t);
            if (i == m - 1 && j == n - 1) {
                return res;
            }
            for (int d = 0; d < 4; ++d) {
                int nextI = i + dir[d];
                int nextJ = j + dir[d + 1];
                if (nextI < 0 || nextI >= m || nextJ < 0 || nextJ >= n ||
                    visit[nextI][nextJ]) {
                    continue;
                }
                visit[nextI][nextJ] = true;
                minPq.emplace(grid[nextI][nextJ], nextI, nextJ);
            }
        }
        return res;
    }
};