#include <stdio.h>
#define V 5

void init(int arr[][V]) {
    int i, j;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            arr[i][j] = 0;
}

void addEdge(int arr[][V], int src, int dest) {
    arr[src][dest] = 1;
    arr[dest][src] = 1; // Assuming undirected graph
}

void printAdjMatrix(int arr[][V]) {
    int i, j;

    printf("Adjacency Matrix:\n");
    printf("   ");
    for (i = 0; i < V; i++)
        printf("%d ", i);
    printf("\n");

    for (i = 0; i < V; i++) {
        printf("%d: ", i);
        for (j = 0; j < V; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int adjMatrix[V][V];

    init(adjMatrix);

    int src, dest;
    char choice;

    printf("Welcome to Graph Representation using Adjacency Matrix\n");
    printf("Please enter edges between vertices (0 to %d).\n", V - 1);
    
    do {
        printf("Enter starting and ending vertices separated by space: ");
        scanf("%d %d", &src, &dest);

        if (src < 0 || src >= V || dest < 0 || dest >= V) {
            printf("Invalid input! Vertices must be between 0 and %d.\n", V - 1);
            continue;
        }
        
        addEdge(adjMatrix, src, dest);

        printf("Edge (%d, %d) added to the graph.\n", src, dest);
        printf("Do you want to add another edge? (y/n): ");
        scanf(" %c", &choice); 

    } while (choice == 'y' || choice == 'Y');

    printAdjMatrix(adjMatrix);

    return 0;
}
