class Solution:
    def findMin(self, root):
        while root.left:
            root = root.left
        return root

    def deleteNode(self, root, x):
        if not root:
            return root
        if x < root.data:
            root.left = self.deleteNode(root.left, x)
        elif x > root.data:
            root.right = self.deleteNode(root.right, x)
        else:
            if not root.left:
                return root.right
            elif not root.right:
                return root.left
            temp = self.findMin(root.right)
            root.data = temp.data
            root.right = self.deleteNode(root.right, temp.data)
        return root
