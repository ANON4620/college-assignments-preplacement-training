def countMinReversals(expr):
    length = len(expr)
    if length % 2 != 0:
        return -1
    left_brace = 0
    right_brace = 0

    for char in expr:
        if char == '{':
            left_brace += 1
        else:
            if left_brace == 0:
                right_brace += 1
            else:
                left_brace -= 1

    ans = (left_brace + 1) // 2 + (right_brace + 1) // 2
    return ans

s = "}{{}}{{{"
print(countMinReversals(s))
