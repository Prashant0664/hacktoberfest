#include <bits/stdc++.h>;
using namespace std;

class Graph
{
    int V;
    vector<list<int>> adj;

public:
    Graph(int V);
    // Function to add an edge to graph
    void addEdge(int v, int w);
    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::BFS(int s)
{
    vector<bool> visited(V, false);
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);

    while (!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
         // Get all adjacent vertices of the dequeued
        // vertex s.
        // If an adjacent has not been visited,
        // then mark it visited and enqueue it
        for (auto adjacent : adj[s])
        {
            if (!visited[adjacent])
            {
                visited[adjacent] = true;
                queue.push_back(adjacent);
            }
        }
    }
}

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    // Taking user Input
    Graph g(V);

    cout << "Enter " << E << " edges in the format 'source destination':" << endl;
    for (int i = 0; i < E; ++i)
    {
        int src, dest;
        cin >> src >> dest;
        g.addEdge(src, dest);
    }
    // Create a graph given
    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    cout << "Breadth First Traversal starting from vertex " << startVertex << ":\n";
    g.BFS(startVertex);

    return 0;
}
