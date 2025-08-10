class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def getIntersectionNode(head1, head2):
    p1, p2 = head1, head2
    while p1 != p2:
        p1 = p1.next if p1 else head2
        p2 = p2.next if p2 else head1
    return p1

if __name__ == "__main__":
    common = Node(8)
    common.next = Node(4)
    common.next.next = Node(5)

    head1 = Node(4)
    head1.next = Node(1)
    head1.next.next = common

    head2 = Node(5)
    head2.next = Node(6)
    head2.next.next = Node(1)
    head2.next.next.next = common

    print(getIntersectionNode(head1, head2).data)  # 8
