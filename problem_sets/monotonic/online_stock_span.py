"""
[[],[100],[80],[60],[70],[60],[75],[85]]
                         ^^^^
                ^^^^^^^^^^^^^^^^^^
          ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

check this example, when 60 is in, all left can't be
span, but you can't just drop it, as, when 75 is in,
not only 60, the previous 70, 60, also brings in.

so you can't simply drop stuff ... but need a way
to speed this up ... how? store a pair of (value, span)

and you should only need to keep the monotonic decreasing
records ... for example ...

100 [(100, 1)]
80  [(100, 1), (80, 1)]
60  [(100, 1), (80, 1), (60, 1)]
70  [(100, 1), (80, 1), (70, 2)]
60  [(100, 1), (80, 1), (70, 2), (60, 1)]
75  [(100, 1), (80, 1), (75, 4)]
85  [(100, 1), (85, 6)]

so basically little bit like compression the possible
span along the way ... till it can't compress - when
it can't compress, it should be an independent span
with different max value in the span basically
"""


class StockSpanner:

    def __init__(self):
        self.span = []

    def next(self, price: int) -> int:
        cur_span = 1
        while self.span and self.span[-1][0] <= price:
            cur_span += self.span[-1][1]
            self.span.pop()
        self.span += [(price, cur_span)]
        # print(price, self.span)
        return cur_span
