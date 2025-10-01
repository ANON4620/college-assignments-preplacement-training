int superDigit(char* n, int k) {
    long long sum = 0;
    for (int i = 0; n[i] != '\0'; i++) {
        sum += n[i] - '0';
    }
    sum *= k;

    while (sum >= 10) {
        long long temp = sum;
        long long new_sum = 0;
        while (temp > 0) {
            new_sum += temp % 10;
            temp /= 10;
        }
        sum = new_sum;
    }

    return (int)sum;
}
