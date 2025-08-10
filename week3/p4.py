class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def searchKey(head, key):
    while head:
        if head.data == key:
            return True
        head = head.next
    return False

# Example
head = Node(1)
head.next = Node(2)
head.next.next = Node(3)
head.next.next.next = Node(4)

key = 3
print("true" if searchKey(head, key) else "false")
