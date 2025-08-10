class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

def reverseDLL(head):
    if not head:
        return None
    curr = head
    temp = None
    while curr:
        temp = curr.prev
        curr.prev = curr.next
        curr.next = temp
        curr = curr.prev
    if temp:
        head = temp.prev
    return head

def printList(head):
    while head:
        print(head.data, end=" <-> " if head.next else "")
        head = head.next
    print()

if __name__ == "__main__":
    head = Node(3)
    n2 = Node(4)
    n3 = Node(5)
    head.next = n2
    n2.prev = head
    n2.next = n3
    n3.prev = n2

    print("Original list:")
    printList(head)

    head = reverseDLL(head)

    print("Reversed list:")
    printList(head)
