class Solution:
    def nextLargerElement(self, arr):
        n = len(arr)
        result = [-1] * n
        stack = []

        for i in range(n):
            while stack and arr[i] > arr[stack[-1]]:
                index = stack.pop()
                result[index] = arr[i]
            stack.append(i)

        return result
