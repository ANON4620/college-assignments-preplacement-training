arr = [1, 2, 0, 4, 3, 0, 5, 0]

count = 0  # position for next non-zero element
for i in range(len(arr)):
    if arr[i] != 0:
        arr[count] = arr[i]
        count += 1

while count < len(arr):
    arr[count] = 0
    count += 1

print(arr)
