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
        dp[i][0] = i;   // delete all

    for (int j = 0; j <= n; j++)
        dp[0][j] = j;   // insert all

    // DP computation
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({
                    dp[i - 1][j],     // delete
                    dp[i][j - 1],     // insert
                    dp[i - 1][j - 1]  // replace
                });
        }
    }

    cout << dp[m][n] << endl;
    return 0;
}
