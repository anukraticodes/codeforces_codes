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
#include <map>
#include <set>
using namespace std;


void wushangclan() {
    long long n, m;
    cin >>n>>m;
    vector<vector<long long>> a(n, vector<long long>(m));
    vector<pair<long long, long long>> sums;
    
    for(int i = 0; i<n; i++) {
        long long sum=0;
        for(int j = 0; j < m; j++) {
            cin>>a[i][j];
            sum+=a[i][j];
        }
        sums.push_back({sum, i});
    }
    
    sort(sums.rbegin(), sums.rend());
    vector<long long> b;
    
    for(auto p: sums) {
        int idx= p.second;
        for(int j=0; j <m; j++) {
            b.push_back(a[idx][j]);
        }
    }
    
       long long score=0;
    long long csum=0;
    
    for(int i= 0; i <n*m; i++) {
        csum+= b[i];
        score+= csum;
    }
    
    cout<<score <<endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore(); 
    while (t--) {
        wushangclan();
    }

    return 0;
}
