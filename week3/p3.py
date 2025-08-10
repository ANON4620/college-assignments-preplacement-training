class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def deleteNode(head, x):
    if not head:
        return None

    if x == 1:
        return head.next

    prev = head
    for _ in range(x - 2):
        if prev is None:
            return head
        prev = prev.next

    if prev and prev.next:
        prev.next = prev.next.next

    return head

def printList(head):
    temp = head
    while temp:
        print(temp.data, end=" ")
        temp = temp.next
    print()

# Example
head = Node(1)
head.next = Node(3)
head.next.next = Node(4)

head = deleteNode(head, 3)
printList(head)
