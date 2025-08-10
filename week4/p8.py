# Python program to pairwise swap elements
# in a given linked list

class Node:
    def __init__(self, val):
        self.data = val
        self.next = None

# Recursive function to swap data of nodes in pairs
def pairwiseSwap(head):
    
    # Base case: if the list is empty or 
    # has only one node, no swap
    if head is None or head.next is None:
        return

    # Swap the data of the current node with the next node
    head.data, head.next.data = head.next.data, head.data

    # Recursion for the next pair
    pairwiseSwap(head.next.next)

def printList(head):
    curr = head
    while curr:
        print(curr.data, end=" ")
        curr = curr.next
    print()

if __name__ == "__main__":
    
    # Creating the linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> None
    head = Node(1)
    head.next = Node(2)
    head.next.next = Node(3)
    head.next.next.next = Node(4)
    head.next.next.next.next = Node(5)
    head.next.next.next.next.next = Node(6)

    pairwiseSwap(head)
    
    printList(head)