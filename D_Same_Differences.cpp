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

long long func(int n, vector<long>& a) {
    // Store frequency of (a[i] - i) seen so far
    map<long long, int> freq;
    long long pairs = 0;
    
    for(int i = 0; i < n; i++) {
        // Calculate a[i] - i
        long long diff = a[i] - i;
        
        // Add pairs with all previous elements that have same difference
        pairs += freq[diff];
        
        // Increment frequency of current difference
        freq[diff]++;
    }
    
    return pairs;
}
void wushangclan() {
    int n;
    cin>>n;
    vector<long> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cout<<func(n,a)<<endl;
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

