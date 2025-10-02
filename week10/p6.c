#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int profit;
    int deadline;
} Job;

int compare(const void* a, const void* b) {
    return ((Job*)b)->profit - ((Job*)a)->profit;
}

int find(int parent[], int s) {
    if (parent[s] == s)
        return s;
    return parent[s] = find(parent, parent[s]);
}

int* jobSequencing(int deadline[], int profit[], int n, int* returnSize) {
    Job* jobs = malloc(sizeof(Job) * n);
    int max_deadline = 0;

    for (int i = 0; i < n; i++) {
        jobs[i].profit = profit[i];
        jobs[i].deadline = deadline[i];
        if (deadline[i] > max_deadline)
            max_deadline = deadline[i];
    }

    qsort(jobs, n, sizeof(Job), compare);

    int* parent = malloc(sizeof(int) * (max_deadline + 1));
    for (int i = 0; i <= max_deadline; i++)
        parent[i] = i;

    int count_jobs = 0, total_profit = 0;

    for (int i = 0; i < n; i++) {
        int available_slot = find(parent, jobs[i].deadline);
        if (available_slot > 0) {
            parent[available_slot] = find(parent, available_slot - 1);
            count_jobs++;
            total_profit += jobs[i].profit;
        }
    }

    free(jobs);
    free(parent);

    int* result = malloc(sizeof(int) * 2);
    result[0] = count_jobs;
    result[1] = total_profit;
    *returnSize = 2;
    return result;
}

int main() {
    int deadline[] = {4, 1, 1, 1};
    int profit[] = {20, 10, 40, 30};
    int returnSize;
    int* ans = jobSequencing(deadline, profit, 4, &returnSize);

    printf("[%d, %d]\n", ans[0], ans[1]); // Output: [2, 60]
    free(ans);
    return 0;
}
