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

void func(int n, vector<long long>& a) {
    if(n == 1) {
        cout << a[0] << endl;
        return;
    }
    sort(a.begin(), a.end());
    pair<int, int> p;
    long long ans=INT_MAX;
    for(int i=0; i<n-1; i++){
        long long diff=a[i+1]-a[i];
        if(diff<ans){
            ans=diff;
            p={i,i+1};
        }
    }
    vector<long long> v;
    v.push_back(a[p.first]);
    for(int i=p.second+1; i<n; i++) v.push_back(a[i]);
    for(int i=0; i<p.first; i++) v.push_back(a[i]);
    v.push_back(a[p.second]);
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    cout<<endl;
}
void wushangclan() {
    int n;
    cin>>n;
    vector<long long> a(n);
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
