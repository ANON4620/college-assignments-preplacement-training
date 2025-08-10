mat = [
    [1, 0, 3],
    [0, 0, 4],
    [6, 0, 0]
]

m, n = len(mat), len(mat[0])
zero_count = sum(1 for i in range(m) for j in range(n) if mat[i][j] == 0)

if zero_count > (m * n) // 2:
    print("Yes")
else:
    print("No")
