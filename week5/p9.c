#include <stdio.h>
#include <string.h>

int countMinReversals(char expr[]) {
    int length = strlen(expr);
    if (length % 2 != 0) {
        return -1;
    }

    int left_brace = 0, right_brace = 0;

    for (int i = 0; i < length; i++) {
        if (expr[i] == '{') {
            left_brace++;
        } else {
            if (left_brace == 0) {
                right_brace++;
            } else {
                left_brace--;
            }
        }
    }

    int ans = (left_brace + 1) / 2 + (right_brace + 1) / 2;
    return ans;
}

int main() {
    char expr[] = "}{{}}{{{";
    printf("%d\n", countMinReversals(expr));
    return 0;
}
