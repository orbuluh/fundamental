class Solution:
    # backtracking through building up one solution a time (NOT thinking about
    # what's all the combinations on index i). So in each recursion, you are
    # fixing the start_idx, and loop all the possible end_idx, and see if it
    # consists to a palindrome
    def partition(self, s: str) -> List[List[str]]:
        n = len(s)
        _is_palindrome = lambda x: x == x[::-1]

        def _backtrack(start_idx: int, cur_solution: List[str]) -> List[List[str]]:
            if start_idx >= n:
                # need to think it through: you are returning list of list of string
                # cur_solution is just list of string that represents one answer
                return [cur_solution]
            res = []
            for end_idx in range(start_idx, n):
                sub_s = s[start_idx : end_idx + 1]
                if _is_palindrome(sub_s):
                    rec_res = _backtrack(end_idx + 1, cur_solution + [sub_s])
                    if rec_res:
                        # returning list of list of string
                        # so you are appending the elements of rec_res into res
                        res += rec_res
            return res

        return _backtrack(0, [])


class SolutionDP:
    def partition(self, s: str) -> List[List[str]]:
        # Each index j in dp stores the list of all palindrome partitions of
        # s[:j+1].
        dp = [None] * len(s)
        _is_palindrome = lambda x: x == x[::-1]

        def _dfs(end_idx: int):
            if end_idx == 0:
                return [[s[0]]]
            if dp[end_idx]:  # already calculated
                return dp[end_idx]
            res = []
            # considers all possible starting indices and checks if the
            # substring s[i:end_idx+1] is a palindrome.
            for start_idx in range(end_idx + 1):
                sub_s = s[start_idx : end_idx + 1]
                if _is_palindrome(sub_s):
                    if start_idx == 0:
                        res.append([sub_s])
                    else:
                        # if start_idx is not 0, we need to combine the result
                        # with dfs of s[:start_idx - 1] basically
                        res.extend(rec_res + [sub_s] for rec_res in _dfs(start_idx - 1))
            dp[end_idx] = res
            return res

        return _dfs(len(s) - 1)
