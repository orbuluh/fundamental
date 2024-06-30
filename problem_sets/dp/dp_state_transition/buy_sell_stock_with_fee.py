class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        sell, buy = 0, float("-inf")
        for p in prices:
            prev_sell = sell
            sell = max(buy + p, sell)
            buy = max(sell - p - fee, buy)
        return sell
