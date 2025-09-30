class StackQueue:
    def __init__(self):
        self.s1 = []
        self.s2 = []

    def push(self, B):
        # Enqueue operation: push into first stack
        self.s1.append(B)

    def pop(self):
        # Dequeue operation: pop from second stack
        if not self.s2:
            while self.s1:
                self.s2.append(self.s1.pop())
        if not self.s2:
            return -1
        return self.s2.pop()
