#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char s[]) {
    int n = strlen(s);
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    char s[] = "abba";
    if (isPalindrome(s))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}
