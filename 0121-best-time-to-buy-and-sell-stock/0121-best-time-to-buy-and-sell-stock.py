class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        profit = 0
        minPrice =  float('inf')

        for price in prices:
            minPrice = min(price , minPrice)

            profit = max(profit , price-minPrice)

        return profit
