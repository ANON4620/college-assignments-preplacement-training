def diagonalSum(N, M):
    return sum(M[i][i] for i in range(N))

T = int(input())
for _ in range(T):
    N = int(input())
    elements = list(map(int, input().split()))
    M = [elements[i * N:(i + 1) * N] for i in range(N)]
    print(diagonalSum(N, M))
