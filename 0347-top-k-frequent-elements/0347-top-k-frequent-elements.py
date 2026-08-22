class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        freq = {}

        for x in nums:
            freq[x] = freq.get(x,0)+1

        heap = []

        for x in freq:
            heapq.heappush(heap , (freq[x] , x))
        
            if len(heap) > k :
                heapq.heappop(heap)
            
        return[x[1] for x in heap]
        