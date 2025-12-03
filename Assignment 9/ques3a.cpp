#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, wt;
};

int findParent(int node, vector<int> &parent) {
    if (parent[node] == node) return node;
    return parent[node] = findParent(parent[node], parent);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);

    if (rank[u] < rank[v]) parent[u] = v;
    else if (rank[u] > rank[v]) parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++;
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) cin >> edges[i].u >> edges[i].v >> edges[i].wt;

    sort(edges.begin(), edges.end(), [](Edge a, Edge b){
        return a.wt < b.wt;
    });

    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; i++) parent[i] = i;

    int mstWeight = 0;
    cout << "\nKruskal's MST Edges:\n";

    for (auto &e : edges) {
        int pu = findParent(e.u, parent);
        int pv = findParent(e.v, parent);

        if (pu != pv) {
            cout << e.u << " - " << e.v << " (weight " << e.wt << ")\n";
            mstWeight += e.wt;
            unionSet(pu, pv, parent, rank);
        }
    }

    cout << "Total MST Weight = " << mstWeight << endl;
    return 0;
}
