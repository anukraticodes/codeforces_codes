#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

void dijkstra(int src, vector<vector<pii>>& adj, vector<int>& dist) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pii>> adj(V);
    vector<int> dist(V, INT_MAX);

    cout << "Enter the edges (u, v, weight):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    dijkstra(src, adj, dist);

    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << " : " << dist[i] << endl;
    }

    return 0;
}
