#include <iostream>
#include <vector>
using namespace std;

void wushangclan() {
    long long n,m;
    cin >> n>>m;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long b;
    cin >> b;

    if(n== 1) {
        cout<<"YES"<<endl;
        return;
    }

    vector<bool> used(n, false);
    
    for(int i = 0; i < n-1; i++) {
        if(!used[i] && a[i] > a[i+1]) {
            long long x=b-a[i];
            if(x<=a[i+1]) {
                a[i]= x;
                used[i]=1;
            } 
            else{
                x=b-a[i+1];
                if(x>=a[i]) {
                    a[i+1]=x;
                    used[i+1]=1;
                } else {
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
    }
    
    for(int i=0; i< n-1;i++) {
        if(a[i]>a[i+1]) {
            cout<<"NO"<<endl;
            return;
        }
    }
    
    cout<<"YES"<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        wushangclan();
    }
    return 0;
}