#include <stdio.h>

int main() {
    int n;
    printf("Enter number of steps: ");
    scanf("%d", &n);

    int dp[n+1];

    // Base cases
    dp[0] = 1; // 0 step: 1 way
    dp[1] = 1; // 1 step: 1 way

    if(n >= 2)
        dp[2] = 2; // 2 steps: 1+1 or 2

    // Fill DP array
    for(int i=3; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    printf("Number of ways to reach step %d: %d\n", n, dp[n]);

    return 0;
}
