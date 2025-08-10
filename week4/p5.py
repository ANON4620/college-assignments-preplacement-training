def josephus(n, k):
    res = 0
    for i in range(1, n + 1):
        res = (res + k) % i
    return res + 1

if __name__ == "__main__":
    n, k = 5, 3
    print(josephus(n, k))
