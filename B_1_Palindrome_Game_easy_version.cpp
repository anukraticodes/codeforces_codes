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


void func(long long n, string s) {
    int cnt_0 = 0;
	for(int i=0;i<n;i++){
		if(s[i]=='0') cnt_0++;
	}
	if(cnt_0 == 1){
		cout << "BOB\n";
		return;
	}
	if(cnt_0%2){
		cout << "ALICE\n";
		return;
	}
	cout << "BOB\n";
	return;
    
}
void wushangclan() {
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

