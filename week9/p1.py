class Solution:
    def linearProbing(self, arr, m):
        hashtable = [-1] * m
        for val in arr:
            idx = val % m
            start = idx
            while True:
                if hashtable[idx] == -1:
                    hashtable[idx] = val
                    break
                elif hashtable[idx] == val:
                    break
                else:
                    idx = (idx + 1) % m
                    if idx == start:
                        break
        return hashtable
