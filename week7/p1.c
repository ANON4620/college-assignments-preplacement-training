#include <stdio.h>

void printNos(int n) {
    if (n == 0) return;
    printf("%d ", n);
    printNos(n - 1);
}
