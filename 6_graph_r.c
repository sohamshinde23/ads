//adjadency list
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

int numVertices;
Node** adjacencyList;

void initializeGraph(int vertices) {
    numVertices = vertices;
    adjacencyList = malloc((vertices + 1) * sizeof(Node*));
    for (int i = 1; i <= vertices; i++) {
        adjacencyList[i] = NULL;
    }
}

void addEdge(int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = adjacencyList[src];
    adjacencyList[src] = newNode;

    newNode = createNode(src);
    newNode->next = adjacencyList[dest];
    adjacencyList[dest] = newNode;
}

void printGraph() {
    for (int v = 1; v <= numVertices; v++) {
        Node* temp = adjacencyList[v];
        printf("Vertex %d:", v);
        while (temp) {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// void freeGraph() {
//     for (int i = 1; i <= numVertices; i++) {
//         Node* temp = adjacencyList[i];
//         while (temp) {
//             Node* next = temp->next;
//             free(temp);
//             temp = next;
//         }
//     }
//     free(adjacencyList);
// }


int main() {
    int numEdges, src, dest;

    printf("Enter the number of vertices: ");
    if (scanf("%d", &numVertices) != 1 || numVertices <= 0) {
        printf("Invalid number of vertices.\n");
        return 1;
    }
    initializeGraph(numVertices);

    printf("Enter the number of edges: ");
    if (scanf("%d", &numEdges) != 1 || numEdges < 0) {
        printf("Invalid number of edges.\n");
        return 1;
    }

    printf("Enter source and destination vertices for each edge:\n");
    for (int i = 0; i < numEdges; i++) {
        printf("Edge %d: ", i + 1);
        if (scanf("%d %d", &src, &dest) != 2 || src < 1 || src > numVertices || dest < 1 || dest > numVertices) {
            printf("Invalid edge.");
            i--; // Repeat this edge input
            continue;
        }
        addEdge(src, dest);
    }

    printf("Adjacency List:\n");
    printGraph();

    //freeGraph(); 

    return 0;
}
//adajacency matrix 
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

   
    printf("Please enter edges between vertices (0 to %d).\n", V - 1);
    
    do {
        printf("Enter starting and ending vertices separated by space: ");
        scanf("%d %d", &src, &dest);

        if (src < 0 || src >= V || dest < 0 || dest >= V) {
            printf("Invalid input! \n", V - 1);
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