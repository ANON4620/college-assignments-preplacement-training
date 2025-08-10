class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def hasCycle(head):
    slow = head
    fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            return True
    return False

# Example: 1 -> 3 -> 4, pos = 2
head = Node(1)
head.next = Node(3)
head.next.next = Node(4)
head.next.next.next = head.next  # loop to node 2

print(str(hasCycle(head)).lower())
