class Solution:
    def findSubarray(self, arr):
        prefix_sum = 0
        freq = {0: 1}
        count = 0

        for num in arr:
            prefix_sum += num
            if prefix_sum in freq:
                count += freq[prefix_sum]
            freq[prefix_sum] = freq.get(prefix_sum, 0) + 1

        return count
