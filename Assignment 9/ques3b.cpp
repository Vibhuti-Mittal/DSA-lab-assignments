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
    if (!(cin >> V)) return 0;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<P>> adj(V);
    cout << "Enter edges (u v weight) with 0-based vertices:\n";
    for (int i = 0; i < E; ++i) {
        int u, v, wt;
        cin >> u >> v >> wt;
       
        adj[u].push_back(make_pair(wt, v));
        adj[v].push_back(make_pair(wt, u));
    }

    const int INF = numeric_limits<int>::max();
    vector<int> key(V, INF);       
    vector<int> parent(V, -1);     
    vector<bool> inMST(V, false);

    priority_queue<P, vector<P>, greater<P>> pq;

    int start = 0; 
    key[start] = 0;
    pq.push(make_pair(0, start));

    int mstWeight = 0;
    cout << "\nPrim's MST Edges:\n";

    while (!pq.empty()) {
        P top = pq.top(); pq.pop();
        int currKey = top.first;
        int u = top.second;

        if (inMST[u]) continue;
        inMST[u] = true;
        mstWeight += currKey;

        if (parent[u] != -1) {
            cout << parent[u] << " - " << u << " (weight " << currKey << ")\n";
        }

        for (size_t i = 0; i < adj[u].size(); ++i) {
            int wt = adj[u][i].first;
            int v  = adj[u][i].second;

            if (!inMST[v] && wt < key[v]) {
                key[v] = wt;
                parent[v] = u;
                pq.push(make_pair(key[v], v));
            }
        }
    }

    cout << "Total MST Weight = " << mstWeight << "\n";
    return 0;
}
