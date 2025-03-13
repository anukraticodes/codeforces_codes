#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <climits>
#include <string>
#include<utility>
using namespace std;

void wushangclan() {
    int n, m;
    cin >> n >> m;
    string c[n+1];
    for (int i = 1; i <= n; i++) cin >> c[i], c[i] = "-" + c[i];
    vector<pair<int, int>> jda[n+2][m+2];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (c[i][j] == 'U') jda[i-1][j].push_back({i, j});
            if (c[i][j] == 'R') jda[i][j+1].push_back({i, j});
            if (c[i][j] == 'D') jda[i+1][j].push_back({i, j});
            if (c[i][j] == 'L') jda[i][j-1].push_back({i, j});
        }
    }
    int vis[n+2][m+2] = {};
    queue<pair<int, int>> q;
    for (int j = 0; j <= m+1; j++) vis[0][j] = 1, q.push({0, j});
    for (int i = 1; i <= n+1; i++) vis[i][0] = 1, q.push({i, 0});
    for (int j = 1; j <= m+1; j++) vis[n+1][j] = 1, q.push({n+1, j});
    for (int i = 1; i <= n; i++) vis[i][m+1] = 1, q.push({i, m+1});
    while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    int i = p.first, j = p.second;
    for (const auto& elem : jda[i][j]) {
        int a = elem.first, b = elem.second;
        if (vis[a][b] == 0) {
            vis[a][b] = 1;
            q.push({a, b});
        }
    }
}

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (c[i][j] == '?' && vis[i-1][j] && vis[i][j+1] && vis[i+1][j] && vis[i][j-1]) vis[i][j] = 1;
        }
    }
    int ans = n * m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (vis[i][j] == 1) ans -= 1;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        wushangclan();
    }
    return 0;
}


