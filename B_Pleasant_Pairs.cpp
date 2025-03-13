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
    long long ans = 0;
    
    for (int i = 0; i < n; i++) {
        long long value = a[i];

        // Check multiples of `value` that could form valid `j`
        for (long long k = value; k <= 2 * n; k += value) {
            long long j = k - (i + 1); // Calculate the potential `j` (1-based)

            if (j > i+1 && j <=n && a[j-1] == k / value) {
                ans++;
            }
        }
    }

    return ans;
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

