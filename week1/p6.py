arr = [10, 20, 30, 40, 50]

is_sorted = True
for i in range(1, len(arr)):
    if arr[i] < arr[i - 1]:
        is_sorted = False
        break

print(is_sorted)
