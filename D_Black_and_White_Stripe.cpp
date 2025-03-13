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

int func(int n, int k, string s) {
    if (k > s.size()) return -1; // Check for invalid k
    int l = 0, r, ans = INT_MAX;
    unordered_map<char, int> mp;
    int size = 0;

    for (r = 0; r < s.size(); r++) {
        size++;
        mp[s[r]]++;

        if (size == k) {
            ans = min(ans, mp['W']); // Count of 'W' in the current window
        } else if (size > k) {
            mp[s[l]]--;
            l++;
            size--;
            ans = min(ans, mp['W']);
        }
    }

    return ans == INT_MAX ? -1 : ans; // Return -1 if no valid substring is found
}

void wushangclan() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    cout << func(n, k, s) << '\n';
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

