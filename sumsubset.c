#include <stdio.h>

// Function to find subsets with sum equal to targetSum using backtracking
void findSubsetsWithSum(int set[], int n, int targetSum, int currentSum, int index, int subset[], int subsetSize) {
    if (currentSum == targetSum) {
        // Print the subset with the required sum
        for (int i = 0; i < subsetSize; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    }

    if (index == n || currentSum > targetSum) {
        return; // Backtrack if index exceeds array size or current sum becomes greater than target sum
    }

    // Include the current element in the subset
    subset[subsetSize] = set[index];
    findSubsetsWithSum(set, n, targetSum, currentSum + set[index], index + 1, subset, subsetSize + 1);

    // Exclude the current element from the subset
    findSubsetsWithSum(set, n, targetSum, currentSum, index + 1, subset, subsetSize);
}

// Driver code
int main() {
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    int subset[6]; // Assuming maximum size of set is 6
    findSubsetsWithSum(set, n, sum, 0, 0, subset, 0);
    return 0;
}
