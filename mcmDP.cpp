#include <bits/stdc++.h>
using namespace std;

int matrixChainMultiplication(vector<int>& dimensions) {
    int n = dimensions.size() - 1;  // Number of matrices

    // dp[i][j] will store the minimum multiplication cost for matrices from i to j
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Cost is zero when multiplying one matrix
    for (int len = 2; len <= n; ++len) {   // len is the chain length
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                // Compute cost of multiplying from i to k and k+1 to j
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    // Matrix dimensions array (A1 has dimensions dimensions[0] x dimensions[1], A2 has dimensions dimensions[1] x dimensions[2], etc.)
    vector<int> dimensions = {5, 10, 3, 12, 5, 50, 6};  // Example input

    int minCost = matrixChainMultiplication(dimensions);
    cout << "Minimum cost of matrix chain multiplication: " << minCost << endl;

    return 0;
}
