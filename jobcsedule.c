#include <stdio.h>
#include <stdlib.h>

// Structure to represent a job
struct Job {
    int id;
    int deadline;
    int profit;
};

// Comparison function to sort jobs in descending order of profit
int compare(const void* a, const void* b) {
    return ((struct Job*)b)->profit - ((struct Job*)a)->profit;
}

// Function to find the maximum profit by scheduling jobs
void jobScheduling(struct Job jobs[], int n) {
    qsort(jobs, n, sizeof(struct Job), compare);

    int result[n];
    int slots[n];

    for (int i = 0; i < n; i++) {
        slots[i] = -1; // Initialize slots as empty
    }

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slots[j] == -1) {
                slots[j] = i;
                result[i] = j;
                break;
            }
        }
    }

    printf("Job sequence: ");
    for (int i = 0; i < n; i++) {
        if (slots[i] != -1) {
            printf("%d ", jobs[slots[i]].id);
        }
    }
    printf("\nTotal Profit: ");
    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        if (slots[i] != -1) {
            totalProfit += jobs[slots[i]].profit;
        }
    }
    printf("%d\n", totalProfit);
}

int main() {
    struct Job jobs[] = {
        {1, 2, 100},
        {2, 1, 19},
        {3, 2, 27},
        {4, 1, 25},
        {5, 3, 15}
    };

    int n = sizeof(jobs) / sizeof(jobs[0]);

    jobScheduling(jobs, n);

    return 0;
}

