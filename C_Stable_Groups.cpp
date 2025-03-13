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
using lli = long long;

lli func(lli n, lli k, lli x, vector<lli>& arr) {
    sort(arr.begin(), arr.end());
    vector<lli> b;

    // Find gaps larger than x
    for (lli i = 0; i < n - 1; i++) {
        if (arr[i + 1] - arr[i] > x) 
            b.push_back(arr[i + 1] - arr[i]);
    }

    // If no large gaps, return 1 (all belong to one group)
    if (b.empty()) return 1;

    // Sort gaps
    sort(b.begin(), b.end());
    lli i = 0;

    // Try to merge groups using `k`
    while (i < b.size()) {
        lli groups_needed = ((b[i]-1)/ x); 
        if (groups_needed <= k) {
            k -= groups_needed;
            i++;
        } else break;
    }

    return b.size() - i + 1;
}

void wushangclan() {
    lli n,x;
    lli k;
    cin >> n >>k>>x;
    vector<lli> arr(n);
    for(lli i=0; i<n; i++){
        lli a;
        cin>>a;
        arr[i]=a;
    }
    
    
    cout << func(n,k,x,arr) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    wushangclan();
    return 0;
}