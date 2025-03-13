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

int func(vector<int>& arr) {
    int cnt1 = 0;
    int a=0, b=0, lefta=5, leftb=5;
    
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            if(arr[i]==1) a++;
            // else if(arr[i]==0) continue;
            else if(arr[i]==-1)a++;
            lefta--;
        } 
        else {
            if(arr[i]==1) b++;
            // else if(arr[i]==0) continue;
            // else if(arr[i]==-1) continue;
            leftb--;
            
        }
        
        if (lefta + a < b) { cnt1 = i + 1; break; }
        if (leftb + b < a) { cnt1 = i + 1; break; }
    }

    // Case 2: Assume team 2 scores on all '?' and team 1 misses
    a=0, b=0, lefta=5, leftb=5;
   
    int cnt2 = 0;
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            if (arr[i] == 1) a++;
            lefta--;
        } 
        else {
            if (arr[i]==1) b++;
            else if(arr[i]==-1) b++;
            leftb--;
        }
        // Check if one team's score is mathematically impossible to surpass
        if (lefta + a < b) { cnt2 = i + 1; break; }
        if (leftb + b < a) { cnt2 = i + 1; break; }
    }

    // If neither case ends early, return the minimum number of kicks
    if (cnt1 == 0 && cnt2 == 0) return 10;
    if (cnt1 == 0) return cnt2;
    if (cnt2 == 0) return cnt1;
    return min(cnt1, cnt2);
}

void wushangclan() {
    vector<int> a(10);
    for(int i = 0; i < 10; i++) {
        char c;
        cin >> c;
        if(c == '?') a[i] = -1;
        else {
            a[i] = c - '0';
        }
    }
    cout << func(a) << endl;
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