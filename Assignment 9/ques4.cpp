#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <functional>
using namespace std;

typedef pair<int,int> P;   

int main() {

    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<P>> adj(V);

    cout << "Enter edges in format: u v weight\n";
    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u].push_back(make_pair(wt, v));
        adj[v].push_back(make_pair(wt, u));  
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    const int INF = numeric_limits<int>::max();
    vector<int> dist(V, INF);
    vector<bool> visited(V, false);

    priority_queue<P, vector<P>, greater<P>> pq; 

    dist[src] = 0;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        P top = pq.top();
        pq.pop();

        int d = top.first;
        int u = top.second;

        if (visited[u]) continue;
        visited[u] = true;

        for (size_t i = 0; i < adj[u].size(); i++) {
            int wt = adj[u][i].first;
            int v = adj[u][i].second;

            if (!visited[v] && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    cout << "\nShortest distances from source " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << " = ";
        if (dist[i] == INF) 
            cout << "INF";
        else 
            cout << dist[i];
        cout << endl;
    }

    return 0;
}
