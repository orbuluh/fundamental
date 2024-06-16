class DisjoinSet:
    def __init__(self, n):
        self.parents = [None] * n
        self.cnt = n

    def find(self, x):
        if not self.parents[x]:
            self.parents[x] = x
        elif self.parents[x] == x:
            pass
        else:
            self.parents[x] = self.find(self.parents[x])
        return self.parents[x]

    def union(self, x, y):
        r_x = self.find(x)
        r_y = self.find(y)
        if r_x != r_y:
            self.parents[r_x] = r_y
            self.cnt -= 1


class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        dj = DisjoinSet(n)
        for i in range(n):
            for j in range(i + 1, n):
                if isConnected[i][j]:
                    dj.union(i, j)
        return dj.cnt


class SolutionDFS:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        seen = set()

        def _dfs(x: int):
            nonlocal seen, n
            if x in seen:
                return
            seen.add(x)
            for i in range(n):
                if i == x:
                    continue
                if isConnected[x][i]:
                    _dfs(i)

        cnt = 0
        for i in range(n):
            if i not in seen:
                _dfs(i)
                cnt += 1
        return cnt
