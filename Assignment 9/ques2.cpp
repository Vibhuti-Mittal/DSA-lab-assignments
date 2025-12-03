#include <iostream>
#include <vector>
using namespace std;

void DFSUtil(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbour : adj[node]) {
        if (!visited[neighbour]) {
            DFSUtil(neighbour, adj, visited);
        }
    }
}

void DFS(int start, vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);

    cout << "DFS Traversal starting from node " << start << ": ";
    DFSUtil(start, adj, visited);
    cout << endl;
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    int start;
    cout << "Enter starting vertex for DFS: ";
    cin >> start;

    DFS(start, adj, V);

    return 0;
}
