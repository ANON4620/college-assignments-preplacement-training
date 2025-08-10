class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def isCircular(head):
    if not head:
        return True
    temp = head.next
    while temp and temp != head:
        temp = temp.next
    return temp == head

if __name__ == "__main__":
    head = Node(5)
    head.next = Node(2)
    head.next.next = head
    print(isCircular(head))  # True

    head2 = Node(1)
    head2.next = Node(2)
    head2.next.next = None
    print(isCircular(head2))  # False
