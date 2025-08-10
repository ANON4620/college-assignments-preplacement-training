class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def removeCycle(head):
    slow, fast = head, head
    cycleFound = False

    # Detect cycle
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            cycleFound = True
            break

    if not cycleFound:
        return True  # No cycle present

    # Find start of cycle
    slow = head
    prev = None
    while slow != fast:
        prev = fast
        slow = slow.next
        fast = fast.next

    # Break the cycle
    prev.next = None
    return True

# Example: 1 -> 3 -> 4, pos = 2
head = Node(1)
head.next = Node(3)
head.next.next = Node(4)
head.next.next.next = head.next  # loop

print(str(removeCycle(head)).lower())
