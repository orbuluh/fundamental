"""
73,74,75,71,69,72,76,73

monotonic decreasing

need to store index to see the diff!!!
how the stack change ...

(73, 0)
(74, 1) --> see 74, can pup 73, but how far? 1 - 0
(75, 2) --> see 75, can pup 74, how far? 2 - 1
(75, 2) (71, 3) (69, 4)
(75, 2) (72, 5)  --> see 72, pop 69 for 5 - 4, pop 71 for 5 - 3!
(76, 6) --> see 76, pop 72 for 6 - 5, pop 75 for 6 - 2!
(76, 6) (73, 3) --> can't pop, eventually they have value 0!
"""


class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        res = [0] * len(temperatures)
        stk = []
        for i, v in enumerate(temperatures):
            while stk and stk[-1][0] < v:
                idx = stk[-1][1]
                res[idx] = i - idx
                stk.pop()
            stk += [(v, i)]
        return res
