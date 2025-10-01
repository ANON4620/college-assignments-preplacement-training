'''
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
'''

class Solution:
    def isBST(self, root):
        def helper(node, low, high):
            if not node:
                return True
            if node.data <= low or node.data >= high:
                return False
            return helper(node.left, low, node.data) and helper(node.right, node.data, high)
        
        return helper(root, float('-inf'), float('inf'))
