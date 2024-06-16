class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        # recursion where you try to take one number x, and recursion with
        # target - x in each recursion, you basically try to bring one x that
        # is still valid
        candidates.sort()
        return self.dfsHelper(candidates, target, 0)

    def dfsHelper(
        self, candidates: List[int], target: int, start_idx: int
    ) -> List[List[int]]:
        if target == 0:
            return [[]]  # this will make sure the `for r in rec_res` works
        # when there is really nothing, for r in rec_res won't add anything
        res = []
        for i in range(start_idx, len(candidates)):
            c = candidates[i]
            if c > target:
                break
            rec_res = self.dfsHelper(candidates, target - c, i)
            res += [[c] + r for r in rec_res]
        return res


class SolutionDP:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        # dp[t] is combinations to form target t
        dp = [[] for _ in range(target + 1)]
        # adding new candidate in each iteration and see how it contributes to
        # the solution - there should be no duplication and you build the
        # answer bottom up basically.
        for c in candidates:
            for t in range(c, target + 1):
                if c == t:
                    dp[t] += [[c]]
                if c < t:
                    for combination in dp[t - c]:
                        dp[t] += [combination + [c]]
        return dp[target]
