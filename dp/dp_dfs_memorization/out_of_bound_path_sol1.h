/*
Idea - straightforward - cache result of visiting (i, j) with moveLeft step.
Check the other solution for a different way of thinking (and can save space!)
*/
class Solution {
    int m_ = 0;
    int n_ = 0;
    using Vec1D = std::vector<int>;
    using Vec2D = std::vector<Vec1D>;
    using Vec3D = std::vector<Vec2D>;
    Vec3D cache_;
    static constexpr int mod = 1'000'000'007;
    static constexpr std::array<int, 5> dir = {1, 0, -1, 0, 1};

  public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        m_ = m;
        n_ = n;
        cache_ = Vec3D(m, Vec2D(n, Vec1D(maxMove + 1, -1)));
        return dfs(startRow, startColumn, maxMove);
    }

    int dfs(int i, int j, int moveLeft) {
        if (i < 0 || j < 0 || i >= m_ || j >= n_) {
            return 1;
        }
        if (moveLeft <= 0)
            return 0;
        if (cache_[i][j][moveLeft] >= 0)
            return cache_[i][j][moveLeft];
        int res = 0;
        for (int d = 0; d < 4; ++d) {
            res = (res + dfs(i + dir[d], j + dir[d + 1], moveLeft - 1)) % mod;
        }
        return cache_[i][j][moveLeft] = res;
    }
};