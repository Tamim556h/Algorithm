#include <stdio.h>
#include <stdbool.h>

int main() {
    // Hardcoded array and target sum
    int arr[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int S = 9;

    bool dp[n+1][S+1];

    // Initialize DP table
    for(int i=0;i<=n;i++) dp[i][0]=true; // sum 0 always possible
    for(int j=1;j<=S;j++) dp[0][j]=false; // no element can't make sum>0

    // Fill DP table
    for(int i=1;i<=n;i++){
        for(int j=1;j<=S;j++){
            if(j < arr[i-1])
                dp[i][j] = dp[i-1][j]; // can't include current element
            else
                dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]]; // include or exclude
        }
    }

    if(!dp[n][S]){
        printf("No subset with sum %d exists.\n", S);
        return 0;
    }

    printf("Subset with sum %d exists.\n", S);
    printf("Subset elements = [ ");

    // Traceback to find subset elements
    int i=n, j=S;
    while(j>0 && i>0){
        if(dp[i-1][j]){
            // Current element not included
            i--;
        } else {
            // Current element included
            printf("%d ", arr[i-1]);
            j -= arr[i-1];
            i--;
        }
    }

    printf("]\n");
    return 0;
}
