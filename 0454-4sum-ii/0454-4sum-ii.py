class Solution(object):
    def fourSumCount(self, nums1, nums2, nums3, nums4):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type nums3: List[int]
        :type nums4: List[int]
        :rtype: int
        """
        mp = {}

        for a in nums1:
            for b in nums2:
                s = a+b
                mp[s] = mp.get(s,0)+1
        
        ans = 0

        for c in nums3:
            for d in nums4:
                t = -(c+d)

                if t in mp:
                    ans += mp[t]
        
        return ans