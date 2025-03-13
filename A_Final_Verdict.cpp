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
#include <numeric>
using namespace std;

void func(int n, int x, vector<int>& arr) {
    long long csum = 0;
    csum =accumulate(arr.begin(), arr.end(), 0LL);
    if(csum==n*x) cout<<"YES";
    else cout<<"NO";
    cout<<endl;
}

void wushangclan() {
    int n, x;
    cin>>n>>x;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    func(n,x, arr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        wushangclan();
    }
    return 0;
}

