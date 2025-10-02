class QueueUsingTwoStacks:
    def __init__(self):
        self.s1 = []
        self.s2 = []

    def enqueue(self, val):
        self.s1.append(val)

    def dequeue(self):
        if not self.s2:
            while self.s1:
                self.s2.append(self.s1.pop())
        if self.s2:
            self.s2.pop()

    def front(self):
        if not self.s2:
            while self.s1:
                self.s2.append(self.s1.pop())
        return self.s2[-1] if self.s2 else -1


if __name__ == "__main__":
    q = int(input().strip())
    queue = QueueUsingTwoStacks()

    for _ in range(q):
        query = list(map(int, input().split()))
        if query[0] == 1:
            queue.enqueue(query[1])
        elif query[0] == 2:
            queue.dequeue()
        elif query[0] == 3:
            print(queue.front())
