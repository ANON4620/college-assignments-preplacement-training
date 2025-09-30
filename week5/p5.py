import math

class Solution:
    def evaluatePostfix(self, arr):
        stack = []
        for token in arr:
            if token not in "+-*/^":
                stack.append(int(token))
            else:
                b = stack.pop()
                a = stack.pop()
                if token == '+':
                    stack.append(a + b)
                elif token == '-':
                    stack.append(a - b)
                elif token == '*':
                    stack.append(a * b)
                elif token == '/':
                    stack.append(math.floor(a / b))
                elif token == '^':
                    stack.append(pow(a, b))
        return stack[0]
