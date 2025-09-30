class Solution:
    def reverseFirstK(self, q, k):
        if k > len(q) or k <= 0:
            return q
        stack = []
        for _ in range(k):
            stack.append(q.popleft())
        while stack:
            q.append(stack.pop())
        for _ in range(len(q) - k):
            q.append(q.popleft())
        return q
