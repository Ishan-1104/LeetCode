class Solution(object):
    def findKthSmallest(self, coins, k):
        """
        :type coins: List[int]
        :type k: int
        :rtype: int
        """
        def gcd(a, b):
            while b:
                a, b = b, a % b
            return a

        def count(x):
            n = len(coins)
            ans = 0

            for mask in range(1, 1 << n):

                bits = 0
                lcm = 1

                for i in range(n):

                    if mask & (1 << i):
                        bits += 1

                        g = gcd(lcm, coins[i])
                        lcm = lcm // g * coins[i]

                        if lcm > x:
                            break

                if lcm <= x:
                    if bits % 2 == 1:
                        ans += x // lcm
                    else:
                        ans -= x // lcm

            return ans

        left = 1
        right = min(coins) * k

        while left < right:

            mid = (left + right) // 2

            if count(mid) >= k:
                right = mid
            else:
                left = mid + 1

        return left