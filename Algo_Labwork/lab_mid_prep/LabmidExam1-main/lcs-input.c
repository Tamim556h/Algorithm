#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

void LCS(char X[], char Y[]) {
    int m = strlen(X);
    int n = strlen(Y);
    int dp[m+1][n+1];

    // Build DP table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {

            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // Length of LCS
    int len = dp[m][n];
    char lcs[len + 1];
    lcs[len] = '\0';

    // Backtracking
    int i = m, j = n;
    while (i > 0 && j > 0) {

        if (X[i-1] == Y[j-1]) {
            lcs[len - 1] = X[i-1];
            i--;
            j--;
            len--;
        } else {
            if (dp[i-1][j] > dp[i][j-1])
                i--;
            else
                j--;
        }
    }

    printf("\nLCS string = %s\n", lcs);
    printf("Length of LCS = %d\n", dp[m][n]);
}

int main() {
    char X[100], Y[100];

    printf("Enter first string: ");
    scanf("%s", X);

    printf("Enter second string: ");
    scanf("%s", Y);

    LCS(X, Y);

    return 0;
}
