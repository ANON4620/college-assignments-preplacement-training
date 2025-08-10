def is_identity_matrix(mat):
    n = len(mat)
    for i in range(n):
        for j in range(n):
            if i == j and mat[i][j] != 1:  # diagonal element check
                return False
            elif i != j and mat[i][j] != 0:  # non-diagonal check
                return False
    return True

# Example usage
n = int(input())
mat = [list(map(int, input().split())) for _ in range(n)]
print(is_identity_matrix(mat))
