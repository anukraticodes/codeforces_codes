#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

void findMEX(string s) {
    unordered_set<string> substrings;
    int n = s.length();

    // Store all possible substrings up to length 3
    for (int i = 0; i < n; i++) {
        string temp = "";
        for (int j = i; j < min(n, i + 3); j++) { // Only store up to length 3
            temp += s[j];
            substrings.insert(temp);
        }
    }

    // Check for missing single-letter substrings
    for (char c = 'a'; c <= 'z'; c++) {
        string t = string(1, c);
        if (substrings.find(t) == substrings.end()) {
            cout << t << endl;
            return;
        }
    }

    // Check for missing two-letter substrings
    for (char c1 = 'a'; c1 <= 'z'; c1++) {
        for (char c2 = 'a'; c2 <= 'z'; c2++) {
            string t = string(1, c1) + string(1, c2);
            if (substrings.find(t) == substrings.end()) {
                cout << t << endl;
                return;
            }
        }
    }

    // Check for missing three-letter substrings
    for (char c1 = 'a'; c1 <= 'z'; c1++) {
        for (char c2 = 'a'; c2 <= 'z'; c2++) {
            for (char c3 = 'a'; c3 <= 'z'; c3++) {
                string t = string(1, c1) + string(1, c2) + string(1, c3);
                if (substrings.find(t) == substrings.end()) {
                    cout << t << endl;
                    return;
                }
            }
        }
    }
}

void wushangclan() {
    long n;
    cin>>n;
    string s;
    cin >> s;
    findMEX(s);
    // return 0;
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