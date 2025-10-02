class Solution:
    def find(self, parent, s):
        if parent[s] == s:
            return s
        parent[s] = self.find(parent, parent[s])
        return parent[s]

    def jobSequencing(self, deadline, profit):
        n = len(deadline)
        jobs = sorted(zip(profit, deadline), key=lambda x: -x[0])
        max_deadline = max(deadline)

        parent = list(range(max_deadline + 1))

        count_jobs = 0
        total_profit = 0

        for p, d in jobs:
            available_slot = self.find(parent, d)
            if available_slot > 0:
                parent[available_slot] = self.find(parent, available_slot - 1)
                count_jobs += 1
                total_profit += p

        return [count_jobs, total_profit]
