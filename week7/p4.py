class Solution:
    def series(self, n):
        mod = 10**9 + 7
        fib = [0] * (n + 1)
        fib[0] = 0
        if n > 0:
            fib[1] = 1
        for i in range(2, n + 1):
            fib[i] = (fib[i - 1] + fib[i - 2]) % mod
        return fib
