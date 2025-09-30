from collections import deque

class Solution:
    def orangesRotting(self, mat):
        n = len(mat)
        m = len(mat[0]) if n else 0
        q = deque()
        fresh = 0
        for i in range(n):
            for j in range(m):
                if mat[i][j] == 2:
                    q.append((i, j))
                elif mat[i][j] == 1:
                    fresh += 1
        if fresh == 0:
            return 0
        time = 0
        directions = [(-1,0),(1,0),(0,-1),(0,1)]
        while q:
            size = len(q)
            changed = False
            for _ in range(size):
                x, y = q.popleft()
                for dx, dy in directions:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < n and 0 <= ny < m and mat[nx][ny] == 1:
                        mat[nx][ny] = 2
                        fresh -= 1
                        q.append((nx, ny))
                        changed = True
            if changed:
                time += 1
        return time if fresh == 0 else -1
