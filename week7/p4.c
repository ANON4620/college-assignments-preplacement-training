#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int* series(int n, int* returnSize) {
    int* fib = (int*)malloc((n + 1) * sizeof(int));
    fib[0] = 0;
    if (n > 0) fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }

    *returnSize = n + 1;
    return fib;
}
