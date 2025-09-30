class Node:
    def __init__(self, new_data):
        self.data = new_data
        self.next = None 

class myStack:

    def __init__(self):
        self.top = None
        self.count = 0

    def isEmpty(self):
        return self.top is None

    def push(self, x):
        newNode = Node(x)
        newNode.next = self.top
        self.top = newNode
        self.count += 1

    def pop(self):
        if self.isEmpty():
            return -1
        val = self.top.data
        self.top = self.top.next
        self.count -= 1
        return val

    def peek(self):
        if self.isEmpty():
            return -1
        return self.top.data

    def size(self):
        return self.count
