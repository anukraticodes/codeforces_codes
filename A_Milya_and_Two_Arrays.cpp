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

void func(long n, vector<long long>& a, vector<long long>& b) {
    unordered_map<long long, long long> mp1;
    for(auto i:a){
        mp1[i]++;
    }
    unordered_map<long long, long long> mp2;
    for(auto j:b){
        mp2[j]++;
    }
    if(mp1.size()>=3 || mp2.size()>=3){
        cout<<"YES"<<endl;
        return;
    }
    if(mp1.size()+mp2.size()>=4) {cout<<"YES"<<endl;
    return;
    }
    cout<<"NO"<<endl;
}
    

void wushangclan(){
    long n;
    cin>>n;
    vector<long long> a(n), b(n);
    for(long i=0; i<n; i++){
        cin>>a[i];
    }
    for(long i=0; i<n; i++){
        cin>>b[i];
    }
    func(n, a, b);
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