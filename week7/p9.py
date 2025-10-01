def count(s, k):
    n = len(s)
    ans = 0
    freq = [0] * 26
    distinctCnt = 0
    i = 0

    for j in range(n):
        freq[ord(s[j]) - ord('a')] += 1
        if freq[ord(s[j]) - ord('a')] == 1:
            distinctCnt += 1

        while distinctCnt > k:
            freq[ord(s[i]) - ord('a')] -= 1
            if freq[ord(s[i]) - ord('a')] == 0:
                distinctCnt -= 1
            i += 1

        ans += j - i + 1

    return ans

def countSubstr(s, k):
    ans = count(s, k) - count(s, k - 1)
    return ans

if __name__ == "__main__":
    s = "abc"
    k = 2
    print(countSubstr(s, k))
