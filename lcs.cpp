#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string t1, string t2) {
    int n = t1.size(), m = t2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Fill the dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (t1[i - 1] == t2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Construct the LCS from dp table
    int i = n, j = m;
    string lcs;
    while (i > 0 && j > 0) {
        if (t1[i - 1] == t2[j - 1]) {
            lcs += t1[i - 1];
            i--; j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(lcs.begin(), lcs.end());

    // Print the LCS
    cout << "Longest Common Subsequence: " << lcs << endl;
    return dp[n][m];
}

int main() {
    string t1, t2;
    cout << "Enter first string: ";
    cin >> t1;
    cout << "Enter second string: ";
    cin >> t2;

    int length = longestCommonSubsequence(t1, t2);
    cout << "Length of LCS: " << length << endl;

    return 0;
}
