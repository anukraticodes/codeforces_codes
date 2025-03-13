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

void func(long n, long m, set<long>& v) {
    long i;
    for(i=1; i<=n; i++){
            if(v.find(i)==v.end()){
                break;
            }
    }
    for(int j=1; j<=n; j++){
        if(j!=i)
        cout<<i<<" "<<j<<endl;
    }
}
    

void wushangclan(){
    long n, m;
    cin>>n>>m;
    set<long> v;
    for(int i=0; i<m; i++){
        int x,y,z;
        cin>>x;
        cin>>z;
        v.insert(z);
        cin>>y;
    }
    func(n,m,v);
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