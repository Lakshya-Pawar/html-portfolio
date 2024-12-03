#include <iostream>
#include<ctime>
#include <vector>
#include <algorithm>
using namespace std;

int LCS(string X, string Y) {
    int m = X.length(), n = Y.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    string X = "AGGTAB", Y = "GXTXAYB";
    
    clock_t time_req = clock();
    cout << "Length of Longest Common Subsequence: " << LCS(X, Y) << endl;
    time_req = clock() - time_req;
    cout << endl << "Execution Time: " << (float)time_req / CLOCKS_PER_SEC << " seconds" << endl;

    return 0;
}
