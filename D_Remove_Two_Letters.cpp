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
#include <set>
using namespace std;

void func(long long n, string s) {
    set<string> st;
    for(long long i=0; i<n-1; i++){
        string prefix=s.substr(0,i);
        string suffix=s.substr(i+2, n-i-2);
        st.insert(prefix+suffix);
    }  
    // for(string it:st) cout<<it<<" ";
    // cout<<endl; 
    cout<<st.size()<<endl;
}
    

void wushangclan(){
    long long n; 
    cin>>n;
    string s;
    cin.ignore();
    getline(cin, s);
    func(n, s);
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