class Solution:
    def celebrity(self, mat):
        n = len(mat)
        a, b = 0, n - 1

        while a < b:
            if mat[a][b] == 1:
                a += 1
            else:
                b -= 1

        cand = a
        for i in range(n):
            if i != cand and (mat[cand][i] == 1 or mat[i][cand] == 0):
                return -1
        return cand
