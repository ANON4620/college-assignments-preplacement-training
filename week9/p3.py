class Solution:
    def countDistinct(self, arr, k):
        n = len(arr)
        freq = {}
        res = []

        for i in range(k):
            freq[arr[i]] = freq.get(arr[i], 0) + 1
        res.append(len(freq))

        for i in range(k, n):
            left = arr[i-k]
            freq[left] -= 1
            if freq[left] == 0:
                del freq[left]

            right = arr[i]
            freq[right] = freq.get(right, 0) + 1

            res.append(len(freq))

        return res
