arr = [2, 3, 2, 3, 5]
n = len(arr)

freq = [0] * n
for num in arr:
    freq[num - 1] += 1

print(freq)
