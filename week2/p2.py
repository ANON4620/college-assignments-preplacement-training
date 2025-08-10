mat = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8]
]
n = len(mat)

# Transpose the matrix
for i in range(n):
    for j in range(i + 1, n):
        mat[i][j], mat[j][i] = mat[j][i], mat[i][j]

# Reverse each column
for j in range(n):
    top, bottom = 0, n - 1
    while top < bottom:
        mat[top][j], mat[bottom][j] = mat[bottom][j], mat[top][j]
        top += 1
        bottom -= 1

# Print rotated matrix
for row in mat:
    print(row)
