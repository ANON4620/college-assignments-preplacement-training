class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def kthFromEnd(head, k):
    first = head
    second = head

    for _ in range(k):
        if not first:
            return -1
        first = first.next

    while first:
        first = first.next
        second = second.next

    return second.data if second else -1

# Example
head = Node(1)
head.next = Node(2)
head.next.next = Node(3)
head.next.next.next = Node(4)
head.next.next.next.next = Node(5)

k = 2
print(kthFromEnd(head, k))
