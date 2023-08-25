
from collections import defaultdict

class Graph:
    def __init__(self, numVertices):
        self.numVertices = numVertices
        self.edges = defaultdict(list)
        self.visited = [False] * numVertices

    def addEdge(self, u, v):
        self.edges[u].append(v)
        self.edges[v].append(u)  # Assuming an undirected graph

    def dfs(self, vertex):
        self.visited[vertex] = True
        print(vertex, end=' ')

        for v in self.edges[vertex]:
            if not self.visited[v]:
                self.dfs(v)

# Example usage
g = Graph(7)  # Change this according to the graph size

# Add edges to the graph (example)
g.addEdge(0, 1)
g.addEdge(0, 2)
g.addEdge(1, 3)
g.addEdge(1, 4)
g.addEdge(2, 5)
g.addEdge(2, 6)

print("Depth-First Traversal starting from vertex 0:", end=' ')
g.dfs(0)
              
