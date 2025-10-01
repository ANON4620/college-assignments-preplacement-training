#include <stdio.h>
#include <string.h>

int count(char s[], int k) {
    int n = strlen(s), ans = 0;
    int freq[26] = {0};
    int distinctCnt = 0, i = 0;

    for (int j = 0; j < n; j++) {
        freq[s[j] - 'a']++;
        if (freq[s[j] - 'a'] == 1)
            distinctCnt++;

        while (distinctCnt > k) {
            freq[s[i] - 'a']--;
            if (freq[s[i] - 'a'] == 0)
                distinctCnt--;
            i++;
        }
        ans += j - i + 1;
    }
    return ans;
}

int countSubstr(char s[], int k) {
    return count(s, k) - count(s, k - 1);
}

int main() {
    char s[] = "abc";
    int k = 2;
    printf("%d\n", countSubstr(s, k));
    return 0;
}
