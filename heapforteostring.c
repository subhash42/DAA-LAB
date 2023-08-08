#include <stdio.h>
#include <string.h>

// Structure to represent a patient
struct Patient {
    char name[50];
    int age;
    char disease[50];
};

// Function to heapify a subtree rooted at index i.
// n is the size of the heap.
void heapify(struct Patient arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && strcmp(arr[left].name, arr[largest].name) > 0)
        largest = left;

    // If right child is larger than the largest so far
    if (right < n && strcmp(arr[right].name, arr[largest].name) > 0)
        largest = right;

    // If largest is not root
    if (largest != i) {
        struct Patient temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Main function to perform heap sort
void heapSort(struct Patient arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        struct Patient temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    struct Patient patients[5];

    // Input patient details
    for (int i = 0; i < 5; i++) {
        printf("Enter details for patient %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", patients[i].name);
        printf("Age: ");
        scanf("%d", &patients[i].age);
        printf("Disease: ");
        scanf("%s", patients[i].disease);
    }

    // Sort patients based on name using Heap Sort
    heapSort(patients, 5);

    printf("\nSorted patients based on name:\n");
    for (int i = 0; i < 5; i++) {
        printf("Name: %s, Age: %d, Disease: %s\n", patients[i].name, patients[i].age, patients[i].disease);
    }

    return 0;
}
