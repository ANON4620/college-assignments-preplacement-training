class Node:
    def __init__(self, coeff, pow):
        self.coeff = coeff
        self.pow = pow
        self.next = None

def addPolynomial(p1, p2):
    head = tail = None
    
    while p1 and p2:
        if p1.pow == p2.pow:
            temp = Node(p1.coeff + p2.coeff, p1.pow)
            p1, p2 = p1.next, p2.next
        elif p1.pow > p2.pow:
            temp = Node(p1.coeff, p1.pow)
            p1 = p1.next
        else:
            temp = Node(p2.coeff, p2.pow)
            p2 = p2.next

        if not head:
            head = tail = temp
        else:
            tail.next = temp
            tail = temp

    while p1:
        tail.next = Node(p1.coeff, p1.pow)
        tail = tail.next
        p1 = p1.next

    while p2:
        tail.next = Node(p2.coeff, p2.pow)
        tail = tail.next
        p2 = p2.next

    return head

def printPolynomial(head):
    while head:
        print(f"{head.coeff}x^{head.pow}", end="")
        if head.next:
            print(" -> ", end="")
        head = head.next
    print()

# Example
poly1 = Node(1, 3)
poly1.next = Node(2, 2)

poly2 = Node(3, 3)
poly2.next = Node(4, 2)

result = addPolynomial(poly1, poly2)
printPolynomial(result)
