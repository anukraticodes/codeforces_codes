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
#include <cctype>

using namespace std;
struct DSU{
    vector<int> parent, rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0; i<n; i++) parent[i]=i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int u, int v){
        int pu=find(u), pv=find(v);
        if(pu!=pv){
            if(rank[pu]>rank[pv]) parent[pv]=pu;
            else if(rank[pv]>rank[pu]) parent[pu]=pv;
            else {
                parent[pu]=pv;
                rank[pv]++;
            }
        }
    }
};

long long func(int n, int m, vector<vector<int>>& edges, vector<long long>& gold) {
    DSU dsu(n);
    for(int i=0; i<m; i++){
        dsu.unite(edges[i][0], edges[i][1]);
    }
    unordered_map<int, vector<int>> mp;
    for(int i=0; i<n; i++){
        mp[dsu.find(i)].push_back(i);
    }
    long long sum=0;
    for(auto it:mp){
        long long minval=LONG_LONG_MAX;
        for(auto child:it.second){
           minval=min(minval, gold[child]);
        }
        sum+=minval;
    }
    return sum;    
}

void wushangclan() {
    int n,m;
    cin >> n>>m;
    vector<long long> gold(n);
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        gold[i]=x;
    }
    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin>>x>>y;
        edges[i].push_back(x-1);
        edges[i].push_back(y-1);
    }

    // Output the result
    cout << func(n,m, edges, gold) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    wushangclan();
    return 0;
}
