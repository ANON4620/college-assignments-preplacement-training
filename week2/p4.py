mat = [
    [1, 1, 1, 1],
    [2, 2, 2, 2],
    [3, 3, 3, 3],
    [4, 4, 4, 4]
]
n = len(mat)

for i in range(n):
    for j in range(i + 1, n):
        mat[i][j], mat[j][i] = mat[j][i], mat[i][j]

for row in mat:
    print(row)
