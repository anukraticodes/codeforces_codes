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

long cnt(vector<long long>& a){
    for(int i=0; i<a.size(); i++){
        if(a[i]-1!=i) return i+1;
    }
    return 0;
}

void func(long n, long k, vector<long long>& a) {
    vector<long long> ans;
    if(n==k){
        for(int i=0; i<n; i++){
            if(i%2!=0) ans.push_back(a[i]);
        }
        ans.push_back(0);
        cout<<cnt(ans)<<endl;
        return;
    }
    for(int i=1; i<=n-k+1; i++){
        if(a[i]!=1) {
            cout<<"1"<<endl;
            return;
        }    
    }
    cout<<"2"<<endl;
}
    

void wushangclan(){
    long n;
    long k;
    cin>>n>>k;
    vector<long long> a(n);
    for(long i=0; i<n; i++){
        cin>>a[i];
    }
    func(n,k, a);
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