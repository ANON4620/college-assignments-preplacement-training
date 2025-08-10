#include <stdio.h>

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    int seqList[1000][1000] = {0};
    int sizes[1000] = {0};
    int lastAnswer = 0;
    int result[1000], resCount = 0;

    for (int i = 0; i < q; i++) {
        int t, x, y;
        scanf("%d %d %d", &t, &x, &y);
        int idx = (x ^ lastAnswer) % n;
        if (t == 1) {
            seqList[idx][sizes[idx]++] = y;
        } else if (t == 2) {
            lastAnswer = seqList[idx][y % sizes[idx]];
            result[resCount++] = lastAnswer;
        }
    }

    for (int i = 0; i < resCount; i++) {
        printf("%d\n", result[i]);
    }

    return 0;
}
