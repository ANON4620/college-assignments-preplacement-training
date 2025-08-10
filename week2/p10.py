def countZeros(A):
    N = len(A)
    count = 0
    i, j = 0, N - 1  # start from top-right
    while i < N and j >= 0:
        if A[i][j] == 0:
            count += (j + 1)  # all elements from col 0 to j are zero
            i += 1
        else:
            j -= 1
    return count

# Example usage
N = int(input())
A = [list(map(int, input().split())) for _ in range(N)]
print(countZeros(A))
