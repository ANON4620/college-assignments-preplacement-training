class myQueue:
    def __init__(self, n):
        self.arr = [0] * n
        self.capacity = n
        self.front = 0
        self.rear = -1
        self.size = 0

    def isEmpty(self):
        return self.size == 0

    def isFull(self):
        return self.size == self.capacity

    def enqueue(self, x):
        if not self.isFull():
            self.rear = (self.rear + 1) % self.capacity
            self.arr[self.rear] = x
            self.size += 1

    def dequeue(self):
        if not self.isEmpty():
            self.front = (self.front + 1) % self.capacity
            self.size -= 1

    def getFront(self):
        if self.isEmpty():
            return -1
        return self.arr[self.front]

    def getRear(self):
        if self.isEmpty():
            return -1
        return self.arr[self.rear]
