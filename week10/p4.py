class Solution:
    def getMaxArea(self, arr):
        stack = []
        max_area = 0
        arr.append(0)

        for i, h in enumerate(arr):
            while stack and arr[stack[-1]] > h:
                height = arr[stack.pop()]
                width = i if not stack else i - stack[-1] - 1
                max_area = max(max_area, height * width)
            stack.append(i)

        arr.pop()
        return max_area
