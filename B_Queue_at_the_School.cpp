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

string func(vector<int>& children,int n, int m) {
    // for(auto i:children) cout<<i<<" ";
    while(m--){
        for(int i=0; i<n-1; i++){
            if(children[i]==0 && children[i+1]==1) {
                swap(children[i], children[i+1]);
                i++;
            }

        }
    }
    string ans="";
    for(int i=0; i<children.size(); i++)
    if(children[i]==0) ans+="B";
    else ans+="G";
    return ans;
    }

void wushangclan() {
    int n, m;
    cin >> n >>m;
    vector<int> children;
    for(int i=0; i<n; i++){
        char c;
        cin>>c;
        if(c=='G') children.push_back(1);
        if(c=='B') children.push_back(0);
    }
    
    
    cout << func(children, n, m) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    wushangclan();
    return 0;
}