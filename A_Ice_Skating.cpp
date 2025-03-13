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
#include <set>
using namespace std;

struct DSU {
    vector<int> parent, rank;
    
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu != pv) {
            if (rank[pu] > rank[pv]) parent[pv] = pu;
            else if (rank[pu] < rank[pv]) parent[pu] = pv;
            else {
                parent[pv] = pu;
                rank[pu]++;
            }
        }
    }
};

int func(int val, vector<int>& x, vector<int>& y) {
    DSU dsu(val);
    for(int i = 0; i < val; i++) {
        for(int j = i + 1; j < val; j++) {
            if(x[i] == x[j] || y[i] == y[j]) {
                dsu.unite(i, j);
            }
        }
    }
    
    set<int> components;
    for(int i = 0; i < val; i++) {
        components.insert(dsu.find(i));
    }
    
    return components.size() - 1;
}

void wushangclan() {
    int n;
    cin >> n;
    vector<int> x;
    vector<int> y;
    
    for(int i = 0; i < n; i++) {
        int xc, yc;
        cin >> xc >> yc;
        x.push_back(xc);
        y.push_back(yc);
    }
    
    cout << func(n, x, y) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    wushangclan();
    return 0;
}