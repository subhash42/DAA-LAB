#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent, rank;
};

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Find the subset of an element using union-find
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Perform union of two subsets
void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Kruskal's algorithm to find the Minimum Spanning Tree
void kruskalMST(struct Edge edges[], int V, int E) {
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    qsort(edges, E, sizeof(struct Edge), compare);

    printf("Minimum Spanning Tree:\n");
    for (int i = 0, mstSize = 0; mstSize < V - 1 && i < E; i++) {
        int srcRoot = find(subsets, edges[i].src);
        int destRoot = find(subsets, edges[i].dest);

        if (srcRoot != destRoot) {
            printf("%d -- %d : %d\n", edges[i].src, edges[i].dest, edges[i].weight);
            unionSets(subsets, srcRoot, destRoot);
            mstSize++;
        }
    }

    free(subsets);
}

int main() {
    int V = 4; // Number of vertices
    int E = 5; // Number of edges
    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskalMST(edges, V, E);

    return 0;
}

