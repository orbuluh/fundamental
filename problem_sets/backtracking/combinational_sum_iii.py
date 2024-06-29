class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        def backtrack(i, cur_res, tgt):
            nonlocal res
            if tgt == 0:
                if len(cur_res) == k:
                    res += [cur_res]
                return
            if i == 10 or len(cur_res) >= k:
                return
            # solution including i
            backtrack(i + 1, cur_res + [i], tgt - i)
            # solution not including i
            backtrack(i + 1, cur_res, tgt)

        res = []
        backtrack(1, [], n)
        return res
