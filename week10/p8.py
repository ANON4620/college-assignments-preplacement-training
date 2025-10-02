#!/bin/python3

import math
import os
import random
import re
import sys
from collections import defaultdict

#
# Complete the 'sherlockAndAnagrams' function below.
#
# The function is expected to return an INTEGER.
# The function accepts STRING s as parameter.
#

def sherlockAndAnagrams(s):
    freq = defaultdict(int)
    n = len(s)

    for length in range(1, n):
        for start in range(n - length + 1):
            sub = s[start:start+length]
            freq["".join(sorted(sub))] += 1

    count = 0
    for key in freq:
        f = freq[key]
        count += f * (f - 1) // 2

    return count

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input().strip())

    for q_itr in range(q):
        s = input()

        result = sherlockAndAnagrams(s)

        fptr.write(str(result) + '\n')

    fptr.close()
