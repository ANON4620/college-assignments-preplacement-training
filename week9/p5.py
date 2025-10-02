class Solution:
    
    def longestConsecutive(self, arr):
        s = set(arr)
        max_len = 0
        
        for num in arr:
            if num - 1 not in s:
                length = 1
                while num + length in s:
                    length += 1
                max_len = max(max_len, length)
        
        return max_len
