#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], int sptSet[], int V) {
    int min = INT_MAX, min_index;
    
    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    
    return min_index;
}

// Function to print the constructed distance array
void printSolution(int dist[], int V) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

// Function to implement Dijkstra's algorithm for a graph represented using adjacency matrix
void dijkstra(int **graph, int src, int V) {
    int dist[V], sptSet[V];

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }
    
    dist[src] = 0; // Distance of source vertex from itself is always 0
    
    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V); // Pick the minimum distance vertex from the set of vertices not yet processed.
        sptSet[u] = 1; // Mark the picked vertex as processed
        
        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
    
    // Print the constructed distance array
    printSolution(dist, V);
}

int main() {
    int V;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);

    // Allocating memory for the adjacency matrix
    int **graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        graph[i] = (int *)malloc(V * sizeof(int));

    // Taking input for the graph
    printf("Enter the adjacency matrix of the graph (%d x %d):\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);
    
    // Run Dijkstra's algorithm
    dijkstra(graph, src, V);
    
    // Free dynamically allocated memory
    for (int i = 0; i < V; i++)
        free(graph[i]);
    free(graph);
    
    return 0;
}


/*
Enter the number of vertices in the graph: 4
Enter the adjacency matrix of the graph (4 x 4):
0 1 5 6
4 5 3 8
9 6 1 2
3 5 4 6
*/