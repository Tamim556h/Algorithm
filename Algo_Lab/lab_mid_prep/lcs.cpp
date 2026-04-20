#include <bits/stdc++.h>
using namespace std;

int main() {
    string X, Y;
    cin >> X >> Y;

    int m = X.length();
    int n = Y.length();

    int dp[m + 1][n + 1];

    // Base cases
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = 0;

    // DP computation
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[m][n] << endl;
    return 0;
}
