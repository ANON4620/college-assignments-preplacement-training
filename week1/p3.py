arr = [12, 35, 1, 10, 34, 1]
first, second = -1, -1

for num in arr:
    if num > first:
        second = first
        first = num
    elif num > second and num != first:
        second = num

print(second)
