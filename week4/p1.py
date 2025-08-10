# Python Program to insert a node at the beginning of doubly
# linked list


class Node:
    def __init__(self, new_data):
        self.data = new_data
        self.next = None
        self.prev = None

# Function to insert a new node at the front of doubly linked list
def insert_at_front(head, new_data):
    
    # Create a new node
    new_node = Node(new_data)

    # Make next of new node as head
    new_node.next = head

    # Change prev of head node to new node
    if head is not None:
        head.prev = new_node

    # Return the new node as the head of the doubly linked list
    return new_node

def print_list(head):
    curr = head
    while curr is not None:
        print(f" {curr.data}", end='')
        curr = curr.next
    print()  
    
if __name__ == "__main__":
  
    # Create a hardcoded doubly linked list:
    # 2 <-> 3 <-> 4 -> NULL
    head = Node(2)
    head.next = Node(3)
    head.next.prev = head
    head.next.next = Node(4)
    head.next.next.prev = head.next

    # Print the original list
    print("Original Linked List:", end='')
    print_list(head)

    # Insert a new node at the front of the list
    print("After inserting Node at the front:", end='')
    data = 1
    head = insert_at_front(head, data)

    # Print the updated list
    print_list(head)