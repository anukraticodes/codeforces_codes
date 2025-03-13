#include <bits/stdc++.h>
using namespace std;

void bellmanFord(int V, vector<vector<pair<int, int>>>& adj, int source) {
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    for (int i = 1; i < V; ++i) {
        for (int u = 0; u < V; ++u) {
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (int u = 0; u < V; ++u) {
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                cout << "Graph contains a negative weight cycle" << endl;
                return;
            }
        }
    }

    // Print distances
    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; ++i) {
        cout << i << " \t\t ";
        if (dist[i] == INT_MAX)
            cout << "not reachable" << endl;
        else
            cout << dist[i] << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pair<int, int>>> adj(V);

    cout << "Enter the edges (u, v, weight):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    int source = 0;
    bellmanFord(V, adj, source);

    return 0;
}
