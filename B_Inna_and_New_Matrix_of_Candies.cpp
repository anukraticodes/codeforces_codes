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

int findmin(unordered_map<int, int>& mp){
    int mini=INT_MAX;
    for(auto it:mp){  
        mini=min(mini, it.second);
    } 
    return mini;
}

int func(unordered_map<int, int>& mp) {
    
    int cnt=0;
    while(!mp.empty()){
        int x=findmin(mp);
        for (auto it = mp.begin(); it != mp.end();) {
    it->second -= x;
    if (it->second == 0) {
        it = mp.erase(it);
    } else {
        ++it;
    }
    }
        cnt++;
    }
    return cnt;
   
}


int wushangclan() {
    int n, m;
    cin >> n>>m;
    unordered_map<int, int> mp;
    
    for(int i=0; i<n; i++){
           int d,can;
        for(int j=0; j<m; j++){
           char c;
           cin>>c;
           if(c=='G') {d=j;}
           if(c=='S') {can=j;}
        }
        if(can<d) return -1;
        mp[i]=can-d;
    }
    return func(mp);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout<<wushangclan();
    
    return 0;
}
