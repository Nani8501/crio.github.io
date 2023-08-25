import java.util.*;

public class DFS {
    private int numVertices;
    private boolean[][] edges;
    private boolean[] visited;

    public DFS(int numVertices) {
        this.numVertices = numVertices;
        edges = new boolean[numVertices][numVertices];
        visited = new boolean[numVertices];
    }

    public void addEdge(int u, int v) {
        edges[u][v] = true;
        edges[v][u] = true; // Assuming an undirected graph
    }

    public void dfs(int vertex) {
        visited[vertex] = true;
        System.out.print(vertex + " ");

        for (int i = 0; i < numVertices; i++) {
            if (edges[vertex][i] && !visited[i]) {
                dfs(i);
            }
        }
    }

    public static void main(String[] args) {
        DFS g = new DFS(7); // Change this according to the graph size

        // Add edges to the graph (example)
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 3);
        g.addEdge(1, 4);
        g.addEdge(2, 5);
        g.addEdge(2, 6);

        System.out.print("Depth-First Traversal starting from vertex 0: ");
        g.dfs(0);
    }
}
