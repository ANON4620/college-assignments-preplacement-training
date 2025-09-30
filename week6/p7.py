class Solution:
    def rearrangeQueue(self, q):
        n = len(q)
        if n % 2 != 0:
            return q

        half = n // 2
        stack = []

        for _ in range(half):
            stack.append(q.popleft())

        while stack:
            q.append(stack.pop())
        
        for _ in range(half):
            q.append(q.popleft())

        for _ in range(half):
            stack.append(q.popleft())

        while stack:
            q.append(stack.pop())
            q.append(q.popleft())

        return list(q)