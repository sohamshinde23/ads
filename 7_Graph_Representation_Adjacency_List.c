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
    adjacencyList = malloc(vertices * sizeof(Node*));
    for (int i = 0; i < vertices; i++) {
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
    for (int v = 0; v < numVertices; v++) {
        Node* temp = adjacencyList[v];
        printf("Vertex %d:", v);
        while (temp) {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int numEdges, src, dest;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    initializeGraph(numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter source and destination vertices for each edge:\n");
    for (int i = 0; i < numEdges; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }

    printf("Adjacency List:\n");
    printGraph();

    return 0;
}


