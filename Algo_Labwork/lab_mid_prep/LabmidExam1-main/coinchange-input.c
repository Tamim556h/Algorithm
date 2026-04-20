#include <stdio.h>
#include <limits.h>  // For INT_MAX

// min function using if-else
int min(int a, int b) {
    if(a < b)
        return a;
    else
        return b;
}

int main() {
    int n, amount;

    // User input for number of coins
    printf("Enter number of coin types: ");
    scanf("%d", &n);

    int coins[n];

    // User input for coin values
    printf("Enter the coin values separated by space: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    // User input for target amount
    printf("Enter the amount: ");
    scanf("%d", &amount);

    int dp[amount + 1];
    int lastCoin[amount + 1];  // store last coin used for amount i

    // Initialize dp array
    dp[0] = 0;
    lastCoin[0] = -1;

    for(int i = 1; i <= amount; i++) {
        dp[i] = INT_MAX;
        lastCoin[i] = -1;
    }

    // DP loop
    for(int i = 1; i <= amount; i++) {
        for(int j = 0; j < n; j++) {
            if(i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                if(dp[i - coins[j]] + 1 < dp[i]) {
                    dp[i] = dp[i - coins[j]] + 1;
                    lastCoin[i] = coins[j];
                }
            }
        }
    }

    if(dp[amount] == INT_MAX) {
        printf("Cannot make the amount with given coins\n");
    } else {
        printf("Minimum coins needed: %d\n", dp[amount]);
        printf("Coins used: ");

        // Backtrack to print coins
        int temp = amount;
        while(temp > 0) {
            printf("%d ", lastCoin[temp]);
            temp -= lastCoin[temp];
        }
        printf("\n");
    }

    return 0;
}
