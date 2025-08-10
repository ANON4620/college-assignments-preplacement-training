class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def reverseList(head):
    prev = None
    current = head
    while current:
        next_node = current.next  # store next
        current.next = prev       # reverse pointer
        prev = current            # move prev forward
        current = next_node       # move current forward
    return prev  # new head

def printList(head):
    while head:
        print(head.data, end=" ")
        head = head.next
    print()

# Example usage
head = Node(1)
head.next = Node(2)
head.next.next = Node(3)
head.next.next.next = Node(4)

head = reverseList(head)
printList(head)  # Output: 4 3 2 1
