""""
- rq is queue that holds all positions of active senators in "Radiant"
- dq is queue that holds all positions of active senators in "Dire".
- The goal is to have the earliest senator of each queue fight each other
    - the one with the earlier position will win.
- The loser is removed from the queue since they are no longer active.
- !!!The winner will go to the end of the queue for the next round.!!!

This is the key, as the one who win actually still have right to vote,
which we can just append it to the end!!! Like a circle of active senate
basically!
"""


class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        rq, dq, n = [], [], len(senate)
        for i, c in enumerate(senate):
            if c == "R":
                rq += [i]
            else:
                dq += [i]

        while rq and dq:
            if rq[0] < dq[0]:
                rq += [n]
            else:
                dq += [n]
            n += 1
            rq.pop(0)
            dq.pop(0)
        return "Radiant" if rq else "Dire"
