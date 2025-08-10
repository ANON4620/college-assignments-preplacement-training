#include <stdio.h>

int josephus(int n, int k) {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = (res + k) % i;
    }
    return res + 1;
}

int main() {
    int n = 5, k = 3;
    printf("%d\n", josephus(n, k));
    return 0;
}
