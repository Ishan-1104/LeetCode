class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        freq = {0:1}
        current_sum = 0
        ans = 0

        for x in nums:
            current_sum += x

            if current_sum - k in freq:
               ans += freq[current_sum-k]  
            
            freq[current_sum] = freq.get(current_sum , 0) + 1
        
        return ans
        