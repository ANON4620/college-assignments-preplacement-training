from collections import Counter
import heapq

class Solution:
    def topKFrequent(self, arr, k):
        freq = Counter(arr)
        heap = []

        for num, count in freq.items():
            heapq.heappush(heap, (-count, -num))

        res = []
        for _ in range(k):
            res.append(-heapq.heappop(heap)[1])

        return res
