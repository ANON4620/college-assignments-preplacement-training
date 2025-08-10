class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

def deleteNode(head, x):
    if head is None:
        return None
    if x == 1:
        head = head.next
        if head:
            head.prev = None
        return head
    curr = head
    for _ in range(x - 1):
        curr = curr.next
    if curr.next:
        curr.next.prev = curr.prev
    if curr.prev:
        curr.prev.next = curr.next
    return head

def printList(head):
    while head:
        print(head.data, end=" <--> " if head.next else "")
        head = head.next
    print()

if __name__ == "__main__":
    # Creating linked list: 1 <--> 5 <--> 2 <--> 9
    head = Node(1)
    n2 = Node(5)
    n3 = Node(2)
    n4 = Node(9)
    head.next = n2
    n2.prev = head
    n2.next = n3
    n3.prev = n2
    n3.next = n4
    n4.prev = n3

    print("Original list:")
    printList(head)

    x = 1
    head = deleteNode(head, x)

    print(f"After deleting node at position {x}:")
    printList(head)
