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
        e.g.  sell2 represents the maximum profit achievable after completing
        ___at most___ two transactions

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
        # why not return max(sell2, sell1)? because sell2 means the max profit
        # you will get considering at max 2 transactions, which includes the
        # case that there is only 1 transaction!
        return sell2


class SolutionDP2:
    def maxProfit(self, prices: List[int]) -> int:
        """
        Say dp[k, j] is max total asset with at most k transactions on j-th day.
        if we don't trade then the total asset is same as previous day:
            dp[k, j-1]       ... case 1

        if we bought the share on i-th day where i=[0..j-1]
        and sell the share on j-th day make total asset:
            prices[j] - prices[i] + dp[k-1, i-1]   ... case 2

        where dp[k-1, i-1] is the total asset you hold before day i, and with
        at most k - 1 transactions.


        So the recursion will be:
        max(case1, case2) = max(
            dp[k, j-1],
            max(prices[j] - prices[i] + dp[k-1, i-1] where i is 0 to j - 1
        )
        so while you iterating j (the later index), in case 2, you know that
        you want to keep track of this value, so you don't need to loop the
        smaller index i where i < j again, this can be consider the
        max_total_asset_seen = -prices[i] + dp[k - 1, i - 1]

        check https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/solutions/135704/detail-explanation-of-dp-solution
        this solution, through simplify to 1D dp array, and rename variable,
        will become first solution ... (mind blow ...)
        The solution is not using max_total_asset_seen but the reverse
        of min_diff_total_asset? but not as straightforward?
        and why init as -prices[0] also not clear yet...
        """

        if not prices:
            return
        dp = [[0] * len(prices) for _ in range(3)]
        max_total_asset_seen = [-prices[0]] * 3  # why? need to think ...
        n = len(prices)
        for j in range(1, n):
            for k in [1, 2]:
                max_total_asset_seen[k] = max(
                    max_total_asset_seen[k], -prices[j] + dp[k - 1][j - 1]
                )
                dp[k][j] = max(dp[k][j - 1], prices[j] + max_total_asset_seen[k])
        return dp[2][-1]
