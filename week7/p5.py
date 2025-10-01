class Solution:
    def towerOfHanoi(self, n, fromm, to, aux):
        if n == 0:
            return 0
        # Move n-1 disks from 'fromm' to 'aux'
        moves = self.towerOfHanoi(n-1, fromm, aux, to)
        # Move nth disk from 'fromm' to 'to'
        moves += 1
        # Move n-1 disks from 'aux' to 'to'
        moves += self.towerOfHanoi(n-1, aux, to, fromm)
        return moves