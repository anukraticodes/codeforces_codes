#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <string>
#include <map>
#include <set>
using namespace std;


void wushangclan() {
    long long n, m, k;
    string s;
    char lw, hi;
    cin >> n >> m >> k;
    
    if (k > n + m) {
        cout << "-1" << endl;
        return;
    }
    
    // Case 2: If k = n + m, only possible if all characters are same
    if (k == n + m) {
        if (n > 0 && m == 0) {
            cout << string(n, '0') << endl;
            return;
        }
        if (m > 0 && n == 0) {
            cout << string(m, '1') << endl;
            return;
        }
        cout << "-1" << endl;
        return;
    }
    
    // Case 3: If k > max(n, m), impossible in most cases
    if (k > max(n, m)) {
        cout << "-1" << endl;
        return;
    }
    
    // Case 4: If k ≤ max(n, m), we can construct a valid string
    string result;
    result.reserve(n + m);  // Reserve space for efficiency
    
    if (n >= m) {
        // If we have more or equal zeros
        if (k <= n) {
            long long zeros_left = n;
            long long ones_left = m;
            
            while (zeros_left > 0 || ones_left > 0) {
                // Add k zeros (or remaining zeros if less than k)
                long long zeros_to_add = min(k, zeros_left);
                result.append(zeros_to_add, '0');
                zeros_left -= zeros_to_add;
                
                // Add one 1 if available
                if (ones_left > 0) {
                    result.push_back('1');
                    ones_left--;
                }
            }
            cout << result << endl;
            return;
        }
    } else {
        // If we have more ones
        if (k <= m) {
            long long zeros_left = n;
            long long ones_left = m;
            
            while (zeros_left > 0 || ones_left > 0) {
                // Add k ones (or remaining ones if less than k)
                long long ones_to_add = min(k, ones_left);
                result.append(ones_to_add, '1');
                ones_left -= ones_to_add;
                
                // Add one 0 if available
                if (zeros_left > 0) {
                    result.push_back('0');
                    zeros_left--;
                }
            }
            cout << result << endl;
            return;
        }
    }
    
    cout << "-1" << endl;
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