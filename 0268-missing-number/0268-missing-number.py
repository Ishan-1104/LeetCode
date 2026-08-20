class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)+1

        for i in range(0 , n):
            if i not in nums:
                ans = i
        
        return ans
        