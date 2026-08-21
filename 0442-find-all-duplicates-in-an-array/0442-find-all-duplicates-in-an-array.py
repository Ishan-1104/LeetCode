class Solution(object):
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        freq ={}
        ans = []

        for num in nums:
            freq[num] = freq.get(num,0)+1

            if freq[num] > 1:
                ans.append(num)
                
        return ans