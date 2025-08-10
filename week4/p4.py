class Node:
    def __init__(self, value):
        self.data = value
        self.next = None

# Function to insert a node at a specific position in a circular linked list
def insertAtPosition(last, data, pos):
    if last is None:
        # If the list is empty
        if pos != 1:
            print("Invalid position!")
            return last
        # Create a new node and make it point to itself
        new_node = Node(data)
        last = new_node
        last.next = last
        return last

    # Create a new node with the given data
    new_node = Node(data)

    # curr will point to head initially
    curr = last.next

    if pos == 1:
        # Insert at the beginning
        new_node.next = curr
        last.next = new_node
        return last

    # Traverse the list to find the insertion point
    for i in range(1, pos - 1):
        curr = curr.next

        # If position is out of bounds
        if curr == last.next:
            print("Invalid position!")
            return last

    # Insert the new node at the desired position
    new_node.next = curr.next
    curr.next = new_node

    # Update last if the new node is inserted at the end
    if curr == last:
        last = new_node

    return last

# Function to print the circular linked list
def print_list(last):
    if last is None:
        return

    head = last.next
    while True:
        print(head.data, end=" ")
        head = head.next
        if head == last.next:
            break
    print()

if __name__ == "__main__":
    # Create circular linked list: 2, 3, 4
    first = Node(2)
    first.next = Node(3)
    first.next.next = Node(4)

    last = first.next.next
    last.next = first

    print("Original list: ", end="")
    print_list(last)

    # Insert elements at specific positions
    data = 5
    pos = 2
    last = insertAtPosition(last, data, pos)
    print("List after insertions: ", end="")
    print_list(last)