class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.bottom = None

# Merge two sorted bottom lists
def merge(a, b):
    if not a:
        return b
    if not b:
        return a

    if a.data < b.data:
        result = a
        result.bottom = merge(a.bottom, b)
    else:
        result = b
        result.bottom = merge(a, b.bottom)
    result.next = None  # remove next references
    return result

# Flatten the list
def flatten(root):
    if not root or not root.next:
        return root
    root.next = flatten(root.next)
    root = merge(root, root.next)
    return root

# Print bottom list
def printList(node):
    while node:
        print(node.data, end=" ")
        node = node.bottom
    print()

# Example usage
if __name__ == "__main__":
    head = Node(5)
    head.bottom = Node(7)
    head.bottom.bottom = Node(8)
    head.bottom.bottom.bottom = Node(30)

    head.next = Node(10)
    head.next.bottom = Node(20)

    head.next.next = Node(19)
    head.next.next.bottom = Node(22)
    head.next.next.bottom.bottom = Node(50)

    head.next.next.next = Node(28)
    head.next.next.next.bottom = Node(35)
    head.next.next.next.bottom.bottom = Node(40)
    head.next.next.next.bottom.bottom.bottom = Node(45)

    head = flatten(head)
    printList(head)
