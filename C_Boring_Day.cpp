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

int func(int n, int l, int r, vector<int>& arr) {
    if(n==0) return 0;
    int i=0, j=0;
    int cnt=0, sum=0;
    for(j=0; j<n; j++){
       sum+=arr[j];
       while(sum>r && i<=j){
        sum-=arr[i];
        i++;
       }
       if(sum>=l && sum<=r) {
        cnt++; sum=0; i=j+1;
       }
    }   
    return cnt;
}

void wushangclan() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> arr;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout << func(n, l, r, arr) << '\n';
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

        // sum+=arr[right];
        // if(sum>=l && sum<=r){
        //     cnt++;
        //     left=right+1;
        //     sum=0;
        // }
        // if(sum>r){
        //     left=right+1;
        //     sum=0;
        // }