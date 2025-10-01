def superDigit(n, k):
    def helper(num):
        if len(num) == 1:
            return int(num)
        return helper(str(sum(int(d) for d in num)))
    
    initial_sum = sum(int(d) for d in n) * k
    return helper(str(initial_sum))
