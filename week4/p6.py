class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def sortedInsert(head, data):
    new_node = Node(data)
    if not head:
        new_node.next = new_node
        return new_node
    curr = head
    while True:
        if curr.data <= data <= curr.next.data:
            break
        if curr.data > curr.next.data and (data >= curr.data or data <= curr.next.data):
            break
        curr = curr.next
        if curr == head:
            break
    new_node.next = curr.next
    curr.next = new_node
    return head

def printList(head):
    temp = head
    if head:
        while True:
            print(temp.data, end=" ")
            temp = temp.next
            if temp == head:
                break
    print()

if __name__ == "__main__":
    head = Node(1)
    head.next = Node(4)
    head.next.next = Node(7)
    head.next.next.next = Node(9)
    head.next.next.next.next = head
    head = sortedInsert(head, 5)
    printList(head)
