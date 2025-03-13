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
using namespace std;

void func(int n, vector<int>& a) {
    if(a[0]==1){
         cout<<n+1<<" ";
        for(int i=1; i<=n; i++) cout<<i<<" ";
        cout<<endl;
        return ;
    }
    if(a[n-1]==0){
        for(int i=1; i<=n; i++) cout<<i<<" ";
        cout<<n+1<<" ";
        cout<<endl;
        return ;
    }
    pair<long, long> p={-1, -1};
    for(int i=0; i<n-1; i++){
       if(a[i]==0 && a[i+1]==1) {
        p={i, i+1};
        break;
       }
    }
    if(p.first==-1 && p.second==-1) {cout<<-1<<endl; return ;}
    for(int i=1; i<=p.first+1; i++) cout<<i<<" ";  // go up to p.first+1
cout<<n+1<<" ";
for(int i=p.second+1; i<=n; i++) cout<<i<<" ";
    cout<<endl;
    
}
void wushangclan() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    func(n,a);
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

