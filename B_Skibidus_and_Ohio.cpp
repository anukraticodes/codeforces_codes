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

void func(string s) {
    int cnt=0;
    for(int i=0; i<s.size()-1; i++){
        if(s[i]==s[i+1]) cnt++;
    }
    if(cnt==0) {
        cout<<s.size()<<endl;
        return ;
    }
    cout<<"1"<<endl;

}

void wushangclan() {
    string s;
    getline(cin, s);  
    func(s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore(); 
    while (t--) {
        wushangclan();
    }

    return 0;
}
