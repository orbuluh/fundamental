class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        """
        The problem say, you may complete at most two transactions.
        So you only have 2 transactions to make among this period.

        I can't really understand the dp recursion solution ...

        but there is another state transition DP solution...

        buy1 and sell1 are used to track the best outcomes after the first
        transaction (buying and then selling).

        buy2 and sell2 then track the best outcomes after potentially
        completing a second transaction (buying again and then selling again).

        the first time you buy, your total asset will becomes -p1
        the first time you sell, your total asset becomes p2 + buy1
        the second time you buy, your total asset becomes sell1 -p3
        the second time you sell, your total asset becomes p4 + buy2


        """
        # set buy* to min because it's expected that the first time you buy
        # something, your total asset becomes negative. And you just want to
        # record that negative state so you can derive the later states.
        buy1 = buy2 = float("-inf")
        # the first time you sell with profit, the number should be positive
        # so you are setting sell* initial value to 0, so it can be updated the
        # first time something profitable happens
        sell1 = sell2 = 0
        for p in prices:
            # after initialization, it's a matter of tracking what the best
            # could have happened along the way.
            buy1 = max(buy1, -p)
            sell1 = max(sell1, p + buy1)
            buy2 = max(buy2, sell1 - p)
            sell2 = max(sell2, p + buy2)
        # why not return max(sell2, sell1)? can't really rationale???
        return sell2
