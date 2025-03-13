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
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

void func(int n, int m, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    int y=0;
    for(int i=0; i<n; i++){
        if(adj[i].size()==1) y++;
    }
    int x=(n-y-1);
    cout<<x<<" "<<y/x<<endl;
    
}

void wushangclan() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> edges(m);
    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        edges[i].push_back(x-1);
        edges[i].push_back(y-1);
    }
    func(n,m,edges);
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

