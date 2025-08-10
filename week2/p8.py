def dynamicArray(n, queries):
    seqList = [[] for _ in range(n)]
    lastAnswer = 0
    result = []

    for q in queries:
        t, x, y = q
        idx = (x ^ lastAnswer) % n
        if t == 1:
            seqList[idx].append(y)
        elif t == 2:
            lastAnswer = seqList[idx][y % len(seqList[idx])]
            result.append(lastAnswer)
    return result

# Sample Input
n, q = 2, 5
queries = [[1,0,5],[1,1,7],[1,0,3],[2,1,0],[2,1,1]]
ans = dynamicArray(n, queries)
for a in ans:
    print(a)
