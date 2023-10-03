#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Define a class to represent a graph using adjacency list
class Graph {
    int V; // Number of vertices

    // Array of vectors to represent adjacency list
    vector<vector<int>> adj;

public:
    Graph(int v); // Constructor
    void addEdge(int v, int w); // Function to add an edge to the graph
    void DFS(int s); // Depth-First Search starting from vertex s
};

Graph::Graph(int v) {
    V = v;
    adj.resize(v);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v's list
}

void Graph::DFS(int s) {
    // Mark all vertices as not visited
    vector<bool> visited(V, false);

    // Create a stack for DFS
    stack<int> st;

    // Push the starting vertex onto the stack
    st.push(s);

    while (!st.empty()) {
        // Pop a vertex from the stack and print it
        s = st.top();
        st.pop();

        if (!visited[s]) {
            cout << s << " ";
            visited[s] = true;
        }

        // Get all adjacent vertices of the popped vertex s
        // If an adjacent vertex has not been visited, push it onto the stack
        for (const auto& neighbor : adj[s]) {
            if (!visited[neighbor]) {
                st.push(neighbor);
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

    cout << "Depth-First Traversal (starting from vertex 0): ";
    g.DFS(0);

    return 0;
}
