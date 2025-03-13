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

void func(long long n, long long k) {
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        arr[i]=i+1;
        if(arr[i]==n){
            arr[i]-=1;
        }
        else arr[i]+=1;
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void wushangclan() {
    long long n, k;
    cin>>n>>k;
    func(n,k);
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

