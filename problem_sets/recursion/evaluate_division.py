"""
Tricky thing is invalid cases ...
"""


class Solution:
    def calcEquation(
        self, equations: List[List[str]], values: List[float], queries: List[List[str]]
    ) -> List[float]:
        neighbor = defaultdict(lambda: defaultdict(int))
        for i, (t, d) in enumerate(equations):
            neighbor[t][d] = values[i]
            neighbor[d][t] = 1.0 / values[i]
            neighbor[t][t] = 1.0
            neighbor[d][d] = 1.0

        def dfs(cur, tgt, val, seen):
            if cur not in neighbor:
                return -1.0
            if cur == tgt:
                return val if val is not None else 1.0
            for n, v in neighbor[cur].items():
                if n in seen:
                    continue
                seen.add(n)
                cur_v = v * val if val is not None else v
                ret = dfs(n, tgt, cur_v, seen)
                if ret != -1:
                    return ret
            return -1

        return [dfs(t, d, None, set([t])) for t, d in queries]
