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

void func(long n) {
    if(n%2!=0){
        cout<<"1"<<" "<<(n-1)/2<<" "<<(n-1)/2<<endl;
        return;
    }
    if(n%4!=0){
        cout<<"2"<<" "<<(n/2)-1<<" "<<(n/2)-1<<endl;
        return;
    }
    cout<<n/2<<" "<<n/4<<" "<<n/4<<endl;

    
}
    

void wushangclan(){
    long n; long k;
    cin>>n>>k;
    func(n);
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