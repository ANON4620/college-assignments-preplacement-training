class Node:
    def __init__(self, new_data):
        self.data = new_data
        self.next = None

class myQueue:
    def __init__(self):
        self.front = None
        self.rear = None
        self.count = 0

    def isEmpty(self):
        return self.count == 0

    def enqueue(self, x):
        newNode = Node(x)
        if self.rear is None:
            self.front = self.rear = newNode
        else:
            self.rear.next = newNode
            self.rear = newNode
        self.count += 1

    def dequeue(self):
        if self.isEmpty():
            return
        self.front = self.front.next
        if self.front is None:
            self.rear = None
        self.count -= 1

    def getFront(self):
        if self.isEmpty():
            return -1
        return self.front.data

    def size(self):
        return self.count
