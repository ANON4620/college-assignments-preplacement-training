class Solution:
    def infixtoPostfix(self, s):
        def precedence(op):
            if op == '^':
                return 3
            if op in ('*', '/'):
                return 2
            if op in ('+', '-'):
                return 1
            return 0

        def isRightAssociative(op):
            return op == '^'

        stack = []
        result = []

        for ch in s:
            if ch.isalnum():
                result.append(ch)
            elif ch == '(':
                stack.append(ch)
            elif ch == ')':
                while stack and stack[-1] != '(':
                    result.append(stack.pop())
                stack.pop()
            else:
                while (stack and precedence(stack[-1]) > precedence(ch)) or \
                      (stack and precedence(stack[-1]) == precedence(ch) and not isRightAssociative(ch)):
                    if stack[-1] == '(':
                        break
                    result.append(stack.pop())
                stack.append(ch)

        while stack:
            result.append(stack.pop())

        return "".join(result)
