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

int func(int n, int m, vector<vector<int>>& edges) {
    vector<set<int>> adj(n);
    unordered_map<int, int> mp;
    for(int i=0; i<m; i++){
        adj[edges[i][0]].insert(edges[i][1]);
        mp[edges[i][0]]++;
        adj[edges[i][1]].insert(edges[i][0]);
        mp[edges[i][1]]++;
    }
    int cnt=0;
    while(!mp.empty()){
        
        vector<int> v={};
        for(auto node:mp){
        if(node.second==1) v.push_back(node.first);           
        }

        if(v.empty()) {
            if(!mp.empty())
            break;
        }
        cnt++;
        for(int i=0; i<v.size(); i++) {
            if(adj[v[i]].empty()) continue;
            int neighbor = *adj[v[i]].begin();
            adj[v[i]].erase(neighbor);
            adj[neighbor].erase(v[i]);
            mp.erase(v[i]);
            if(--mp[neighbor] == 0) {
                mp.erase(neighbor);
            }
        }
    }
    return cnt;
    }

void wushangclan() {
    int n, m;
    cin >> n >>m;
    vector<vector<int>> edges(m);
    
    for(int i = 0; i < m; i++) {
        int x, y;
        cin>>x>>y;
        edges[i].push_back(x-1);
        edges[i].push_back(y-1);
    }
    
    cout << func(n, m, edges) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    wushangclan();
    return 0;
}