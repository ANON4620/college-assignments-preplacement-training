class Solution:
    def maxArea(self, mat):
        if not mat:
            return 0

        n, m = len(mat), len(mat[0])
        heights = [0] * m
        max_area = 0

        for row in mat:
            for j in range(m):
                heights[j] = heights[j] + 1 if row[j] == 1 else 0
            max_area = max(max_area, self.largestRectangleArea(heights))

        return max_area

    def largestRectangleArea(self, heights):
        stack = []
        heights.append(0)
        max_area = 0
        for i, h in enumerate(heights):
            while stack and heights[stack[-1]] > h:
                height = heights[stack.pop()]
                width = i if not stack else i - stack[-1] - 1
                max_area = max(max_area, height * width)
            stack.append(i)
        heights.pop()
        return max_area
