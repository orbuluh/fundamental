/*

Compared to the first solution, the idea here is interesting.

Here we no longer keep the result to arrive (i, j), rather, we keep number of
way to arrive (i, j) with certain step. E.g. ways to arrive (i, j) with step k
is the sum of ways to arrive 4 other neighbors with step k - 1!

This method same one - dimension of space as each step depends on previous step
only. But runtime wise it's slower. (Likely because doing DFS only travel to the
place needed.)
*/
class Solution {
    using Vec1D = std::vector<int>;
    using Vec2D = std::vector<Vec1D>;
    static constexpr int mod = 1'000'000'007;
    static constexpr std::array<int, 5> dir = {1, 0, -1, 0, 1};

  public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        Vec2D prevWayToArrive = Vec2D(m, Vec1D(n, 0));
        // witout any step, 1 way to arrive (startRow, startColumn)
        prevWayToArrive[startRow][startColumn] = 1;
        int res = 0;
        for (int step = 1; step <= maxMove; ++step) {
            Vec2D wayToArrive = Vec2D(m, Vec1D(n, 0));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int d = 0; d < 4; ++d) {
                        int nxtI = i + dir[d];
                        int nxtJ = j + dir[d + 1];
                        if (nxtI < 0 || nxtI >= m || nxtJ < 0 || nxtJ >= n) {
                            res = (res + prevWayToArrive[i][j]) % mod;
                        } else {
                            wayToArrive[nxtI][nxtJ] = (
                                wayToArrive[nxtI][nxtJ] + prevWayToArrive[i][j]
                            ) % mod;
                        }
                    }
                }
            }
            std::swap(wayToArrive, prevWayToArrive);
        }
        return res;
    }
};