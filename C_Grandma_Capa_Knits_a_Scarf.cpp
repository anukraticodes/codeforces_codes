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

bool ispalindrome(string s) {
    string s1 = s; 
    reverse(s1.begin(), s1.end()); 
    return s == s1; 
}

int func(int n, string s) {
   int l=0, r=s.size()-1;

  
   if(ispalindrome(s)) return 0;
   char ch='\0'; int cnt=0, cnt2=0;
   while(l<=r){
      if(s[l]!=s[r]) {
        if(s[l]==ch) {
        l++;
    }
        else if(s[r]==ch){
           r--; 
        }
        else if(ch=='\0'){
        ch=s[l];
        l++;
        }
        else{
            cnt=INT_MAX; break;
        }

        cnt++;
      }
      if(s[l]==s[r]){
          l++;
          r--;
      }
   }
   l=0, r=n-1, ch='\0';
   while(l<=r){
      if(s[l]!=s[r]) {
        if(s[l]==ch) {
          l++; }
        else if(s[r]==ch){
             r--;
                    } 
        else if(ch=='\0'){
        ch=s[r];
        r--;
        }
        else{
            cnt2=INT_MAX; break;
        }
        cnt2++;
      }
      if(s[l]==s[r]){
          l++;
          r--;
      }
   }
   if(cnt==INT_MAX && cnt2==INT_MAX) return -1;
   return min(cnt, cnt2);
}


void wushangclan() {
    int n;
    cin >> n;
    string s;
    cin>>s;
    cout << func(n,s) << '\n';
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
