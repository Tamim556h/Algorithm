#include <stdio.h>

int main() {
    int n = 4; // rod length
    int price[] = {0, 1, 5, 8, 9}; // 1-based indexing: price[1]=1, price[2]=5...
    int dp[10]; // dp[i] = max profit for rod length i
    int cut[10]; // to store first cut for max profit

    dp[0] = 0; // base case

    // Bottom-up DP
    for (int i = 1; i <= n; i++) {
        int max = -1;
        for (int j = 1; j <= i; j++) {
            if (price[j] + dp[i - j] > max) {
                max = price[j] + dp[i - j];
                cut[i] = j; // first cut length for max profit
            }
        }
        dp[i] = max;
    }

    // print maximum profit
    printf("Maximum Profit = %d\n", dp[n]);

    // print cuts
    printf("Cuts: ");
    int temp = n;
    while (temp > 0) {
        printf("%d ", cut[temp]);
        temp -= cut[temp];
    }
    printf("\n");

    return 0;
}
