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
#include <numeric>
using namespace std;

void func(long long n, vector<long long>& arr) {
    set<long long> st(arr.begin(), arr.end());
    long long esum=0;
    for(long long i=0; i<2*n; i+=2){
        esum+=arr[i];
    }
    long long osum=0;
    for(long long i=1; i<2*n; i+=2){
        osum+=arr[i];
    }
    if (st.find(abs(esum - osum)) == st.end()){
    cout<<abs(esum-osum)<<" ";
    for(long long i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return;
  } 
for(long long i=0; i<n; i++) esum+=arr[i];
for(long long i=n; i<2*n; i++) osum+=arr[i];
cout<<abs(esum-osum)<<" ";
for(int i=0; i<2*n; i+=2) cout<<arr[i]<<" ";
for(int i=1; i<2*n; i+=2) cout<<arr[i]<<" ";
cout<<endl;

}

void wushangclan() {
    long long n;
    cin>>n;
    vector<long long> arr(2*n);
    for(long long i=0; i<2*n; i++){
        cin>>arr[i];
    }
    func(n,arr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        wushangclan();
    }
    return 0;
}

