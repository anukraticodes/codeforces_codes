#include <bits/stdc++.h>
using namespace std;

class kruskals {
public:
    vector<int> rank, parent;

    void dsu(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    int mst(vector<tuple<int, int, int>> edges, int V) {
        dsu(V);

        sort(edges.begin(), edges.end());

        int mstWt = 0;
        for (auto it : edges) {
            int wt, u, v;
            tie(wt, u, v) = it;

            if (findUPar(u) != findUPar(v)) {
                mstWt += wt;
                unionByRank(u, v);
            }
        }
        return mstWt;
    }
};

int prims(int V, vector<vector<pair<int, int>>>& adj) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(V, 0);

    pq.push({0, 0});
    int sum = 0;

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;

        if (vis[node] == 1) continue;

        vis[node] = 1;
        sum += wt;

        for (auto it2 : adj[node]) {
            int adjNode = it2.first;
            int edW = it2.second;
            if (!vis[adjNode]) {
                pq.push({edW, adjNode});
            }
        }
    }
    return sum;
}

int main() {
    int V = 6;
    vector<tuple<int, int, int>> edges = {{4, 0, 1}, {4, 0, 2}, {2, 1, 2}, {3, 2, 3}, {3, 3, 4}, {3, 4, 5}, {2, 2, 5}, {4, 2, 4}};

    vector<vector<pair<int, int>>> adj(V);
    for (auto it : edges) {
        int u, v, wt;
        tie(wt, u, v) = it;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }


    int sum = prims(V, adj);
    cout << "Prim's MST total weight: " << sum << endl;


    kruskals k;
    int sum2 = k.mst(edges, V);
    cout << "Kruskal's MST total weight: " << sum2 << endl;

    return 0;
}
