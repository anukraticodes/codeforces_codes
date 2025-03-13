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

long long func(long long n, long long k, set<char>& st, string s) {
   long long l=0, r=0;
   long long cnt=0;
   for(r=0; r<n && l<n; r++){
    if(st.find(s[r])==st.end()){
       
        long long no=r-l;
        cnt+=(no*(no+1))/2;
        l=r+1;
    }
   }
   if (l < n) {
        long long length = n - l;
        cnt += (length * (length + 1)) / 2;
    }
   return cnt;
}


long long wushangclan() {
    long long n, k;
    cin >> n>>k;
    string s;
    cin.ignore();
    getline(cin, s);
    set<char> st;
    for(long long i=0; i<k; i++){
        char c;
        cin>>c;
        st.insert(c);
    }
    return func(n,k,st,s);
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout<<wushangclan();
    
    return 0;
}
