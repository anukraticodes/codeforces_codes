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

string toLower(const string &s) {
    string result = s;
    for (char &c : result) {
        c = tolower(c);
    }
    return result;
}

pair<string, string> extractNames(const string &chain) {
    size_t pos = chain.find(" reposted ");
    string name1 = chain.substr(0, pos); 
    string name2 = chain.substr(pos + 10);
    return {toLower(name1), toLower(name2)};
}

int dfs(int node, vector<vector<int>> &adj, vector<bool> &vis) {
    vis[node] = true;
    int maxLen = 1;
    for (int neighbor : adj[node]) {
        if (!vis[neighbor]) {
            maxLen = max(maxLen, 1 + dfs(neighbor, adj, vis));
        }
    }
    vis[node] = false;
    return maxLen;
}

int func(int n, vector<string> &chain) {
    unordered_map<string, int> mp;
    int cnt = 0;

    // Map names to unique IDs
    for (int i = 0; i < n; i++) {
        pair<string, string> names = extractNames(chain[i]);
        string name1 = names.first;
        string name2 = names.second;

        if (mp.find(name1) == mp.end()) mp[name1] = cnt++;
        if (mp.find(name2) == mp.end()) mp[name2] = cnt++;
    }

    // Build adjacency list
    vector<vector<int>> adj(mp.size());
    for (int i = 0; i < n; i++) {
        pair<string, string> names = extractNames(chain[i]);
        string name1 = names.first;
        string name2 = names.second;

        adj[mp[name2]].push_back(mp[name1]); // Directed edge from name2 to name1
    }

    // Find the longest path using DFS
    int maxLen = 0;
    vector<bool> vis(mp.size(), false);
    for (int i = 0; i < mp.size(); i++) {
        maxLen = max(maxLen, dfs(i, adj, vis));
    }

    return maxLen;
}

void wushangclan() {
    int n;
    cin >> n;
    vector<string> chain;

    // Read the input
    cin.ignore(); // Ignore the newline after n
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        chain.push_back(s);
    }

    // Output the result
    cout << func(n, chain) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    wushangclan();
    return 0;
}
