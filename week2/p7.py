def multiplyPolynomials(A, B):
    n = len(A)
    m = len(B)
    res = [0] * (n + m - 1)
    for i in range(n):
        for j in range(m):
            res[i + j] += A[i] * B[j]
    return res

# Example
A = [5, 0, 10, 6]
B = [1, 2, 4]
print(multiplyPolynomials(A, B))

A = [1, 9, 3, 4, 7]
B = [4, 0, 2, 5]
print(multiplyPolynomials(A, B))
