class Solution:
    def getPairs(self, arr):
        arr.sort()
        res = []
        left, right = 0, len(arr) - 1

        while left < right:
            total = arr[left] + arr[right]
            if total == 0:
                res.append([arr[left], arr[right]])
                left_val, right_val = arr[left], arr[right]
                while left < right and arr[left] == left_val:
                    left += 1
                while left < right and arr[right] == right_val:
                    right -= 1
            elif total < 0:
                left += 1
            else:
                right -= 1

        return res
