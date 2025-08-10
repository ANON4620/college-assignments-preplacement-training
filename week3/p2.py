class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def insertInMiddle(head, x):
    new_node = Node(x)
    if not head:
        return new_node

    slow = head
    fast = head.next

    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next

    new_node.next = slow.next
    slow.next = new_node
    return head

def printList(head):
    temp = head
    while temp:
        print(temp.data, end=" ")
        temp = temp.next
    print()

# Example
head = Node(1)
head.next = Node(2)
head.next.next = Node(4)

head = insertInMiddle(head, 3)
printList(head)
