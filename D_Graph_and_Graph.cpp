#include <iostream>
#include <vector>
#include <set>
#include <limits>

using namespace std;
const long long INF = 1e18;

void wushangclan() {
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    s1--; s2--; // Convert to 0-based indexing

    vector<vector<int>> g1(n), g2(n);
    vector<bool> good(n, false);
    set<pair<int, int>> edges;

    int m1;
    cin >> m1;
    for (int i = 0; i < m1; i++) {
        int v, u;
        cin >> v >> u;
        v--; u--;
        if (v > u) swap(v, u);
        edges.insert({v, u});
        g1[v].push_back(u);
        g1[u].push_back(v);
    }

    int m2;
    cin >> m2;
    for (int i = 0; i < m2; i++) {
        int v, u;
        cin >> v >> u;
        v--; u--;
        if (v > u) swap(v, u);
        if (edges.find({v, u}) != edges.end()) {
            good[u] = true;
            good[v] = true;
        }
        g2[u].push_back(v);
        g2[v].push_back(u);
    }

    vector<vector<long long>> d(n, vector<long long>(n, INF));
    d[s1][s2] = 0;

    set<pair<long long, pair<int, int>>> st;
    st.insert({0, {s1, s2}});

    while (!st.empty()) {
        auto it = st.begin();
        int v = it->second.first;
        int u = it->second.second;
        st.erase(it);

        for (auto to1 : g1[v]) {
            for (auto to2 : g2[u]) {
                long long w = abs(to1 - to2);
                if (d[to1][to2] > d[v][u] + w) {
                    st.erase({d[to1][to2], {to1, to2}});
                    d[to1][to2] = d[v][u] + w;
                    st.insert({d[to1][to2], {to1, to2}});
                }
            }
        }
    }

    long long ans = INF;
    for (int i = 0; i < n; i++) {
        if (!good[i]) continue;
        ans = min(ans, d[i][i]);
    }

    if (ans == INF) ans = -1;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        wushangclan();
    }
    return 0;
}
