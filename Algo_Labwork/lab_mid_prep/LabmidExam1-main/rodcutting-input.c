#include <stdio.h>

int main() {
    int n;
    printf("Enter rod length: ");
    scanf("%d", &n);

    int price[100]; // price array (1-based indexing)
    printf("Enter prices for length 1 to %d:\n", n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &price[i]);
    }

    int dp[100];  // dp[i] = max profit for rod length i
    int cut[100]; // to store first cut for max profit

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
    printf("\nMaximum Profit = %d\n", dp[n]);

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
