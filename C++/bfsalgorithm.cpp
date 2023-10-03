#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// Define a class to represent a graph using adjacency list
class Graph {
    int V; // Number of vertices

    // Array of vectors to represent adjacency list
    vector<vector<int>> adj;

public:
    Graph(int v); // Constructor
    void addEdge(int v, int w); // Function to add an edge to the graph
    void BFS(int s); // Breadth-First Search starting from vertex s
};

Graph::Graph(int v) {
    V = v;
    adj.resize(v);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v's list
}

void Graph::BFS(int s) {
    // Mark all vertices as not visited
    vector<bool> visited(V, false);

    // Create a queue for BFS
    queue<int> q;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        // Dequeue a vertex from the queue and print it
        s = q.front();
        cout << s << " ";
        q.pop();

        // Get all adjacent vertices of the dequeued vertex s
        // If an adjacent vertex has not been visited, mark it
        // visited and enqueue it
        for (const auto& neighbor : adj[s]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
int main() {
    // Create a graph
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);

    cout << "Breadth-First Traversal (starting from vertex 0): ";
    g.BFS(0);

    return 0;
}
