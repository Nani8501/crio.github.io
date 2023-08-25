
// C implementation of Depth-First Search (DFS) for a graph

#include<stdio.h>
#include<stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int edges[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
    bool visited[MAX_VERTICES];
} Graph;

// Function to initialize the graph
void initializeGraph(Graph* g, int numVertices) {
    g->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            g->edges[i][j] = 0;
        }
        g->visited[i] = false;
    }
}

// Function to add an edge to the graph
void addEdge(Graph* g, int u, int v) {
    g->edges[u][v] = 1;
    g->edges[v][u] = 1; // Assuming an undirected graph
}

// Depth-First Search
void dfs(Graph* g, int vertex) {
    g->visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < g->numVertices; i++) {
        if (g->edges[vertex][i] == 1 && !g->visited[i]) {
            dfs(g, i);
        }
    }
}

int main() {
    Graph g;
    int numVertices = 7; // Change this according to the graph size
    initializeGraph(&g, numVertices);

    // Add edges to the graph (example)
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 1, 4);
    addEdge(&g, 2, 5);
    addEdge(&g, 2, 6);

    printf("Depth-First Traversal starting from vertex 0: ");
    dfs(&g, 0);

    return 0;
}
              
            
