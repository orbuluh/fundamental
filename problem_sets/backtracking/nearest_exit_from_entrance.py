class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        m, n = len(maze), len(maze[0])
        to_visit = [(*entrance, 0)]
        maze[entrance[0]][entrance[1]] = "+"
        while to_visit:
            i, j, s = to_visit.pop(0)
            # can't be entrance and on the border
            if (i != entrance[0] or j != entrance[1]) and (
                i == 0 or j == 0 or i == m - 1 or j == n - 1
            ):
                return s
            for di, dj in [[0, 1], [-1, 0], [0, -1], [1, 0]]:
                ni, nj = i + di, j + dj
                if (
                    ni >= 0
                    and ni <= m - 1
                    and nj >= 0
                    and nj <= n - 1
                    and maze[ni][nj] != "+"
                ):
                    # note, once put into to_visit, it's essentially the
                    # shortest way to arrive on this cell, so you don't need
                    # to care about other route coming to this one.
                    maze[ni][nj] = "+"
                    to_visit += [(ni, nj, s + 1)]
        return -1
