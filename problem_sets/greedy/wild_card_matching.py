"""
This is a glob matching ...

Greedy solution from top-vote

last_star: track the position of the last encountered * in the pattern p
idx_after_last_star_match: the index in s after the last successful match with *

e.g.
s: a c d s c d
p: * c d

after the first match of the *, last_star = 0 and idx_after_last_star_match = 0

   [  note that here, once you hit *, you could match nothing.
      consider test case s = adceb, and p = *a*b               ]

continue,  when we come to i = 3 and j = 3, we know that the previous match of *
is actually wrong,  (the first branch of DFS we take is wrong)
so we can go back from next possible - e.g. we move pointer back to
idx_after_last_star_match + 1, so that the last_star basically match one more char
"""


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        last_star = idx_after_last_star_match = -1
        p_idx = s_idx = 0
        n, m = len(s), len(p)
        while s_idx < n:
            if p_idx < m and (p[p_idx] == s[s_idx] or p[p_idx] == "?"):
                # a simple match
                p_idx += 1
                s_idx += 1
            elif p_idx < m and p[p_idx] == "*":
                # first (next) star match
                last_star = p_idx
                # note * could be 0 match, so we could
                # start a new match right on s_idx.
                # and also, you are not s_idx++
                idx_after_last_star_match = s_idx
                p_idx += 1
            elif last_star != -1:
                # reset p_idx back as previous choice isn't
                # giving us answer
                p_idx = last_star + 1
                idx_after_last_star_match += 1
                s_idx = idx_after_last_star_match
            else:
                return False
        # could be any amount of * trailing ...
        while p_idx < m and p[p_idx] == "*":
            p_idx += 1
        return p_idx == m
