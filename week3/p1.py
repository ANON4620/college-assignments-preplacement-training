class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def insertAtEnd(head, x):
    new_node = Node(x)
    if head is None:
        return new_node  # empty list case
    temp = head
    while temp.next:
        temp = temp.next
    temp.next = new_node
    return head

# Helper to print linked list
def printList(head):
    temp = head
    while temp:
        print(temp.data, end="->" if temp.next else "")
        temp = temp.next
    print()

# Example usage
n = int(input())
values = list(map(int, input().split()))
x = int(input())

head = None
tail = None
for val in values:
    node = Node(val)
    if head is None:
        head = tail = node
    else:
        tail.next = node
        tail = node

head = insertAtEnd(head, x)
printList(head)
