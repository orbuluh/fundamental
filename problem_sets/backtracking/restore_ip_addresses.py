class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        # you can only add 3 dots
        # remaining dots cnt k
        # remaining s len <= 3(k + 1)
        # and a legit number to use <= 255
        constructing_sol = []
        res = []

        def _backtrack(start_idx: int, remaining_dots: int):
            nonlocal constructing_sol
            nonlocal res
            n = len(s)
            if start_idx == n:
                if remaining_dots == -1:
                    res += [".".join(constructing_sol)]
                return res
            remaining_len = n - start_idx
            if (remaining_dots + 1) * 3 < remaining_len:
                return res
            for j in range(1, 4):
                if start_idx + j > n:
                    break
                if j > 1 and s[start_idx] == "0":
                    break
                num_s = s[start_idx : start_idx + j]
                if int(num_s) <= 255:
                    constructing_sol += [num_s]
                    _backtrack(start_idx + j, remaining_dots - 1)
                    constructing_sol.pop()
            return res

        return _backtrack(0, 3)
