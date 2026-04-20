#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, S;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    int arr[100];
    printf("Enter %d elements:\n", n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    printf("Enter target sum: ");
    scanf("%d", &S);

    bool dp[n+1][S+1];

    // initialize DP table
    for(int i=0;i<=n;i++) dp[i][0]=true; // sum 0 always possible
    for(int j=1;j<=S;j++) dp[0][j]=false; // sum>0 with 0 elements impossible

    // fill DP table
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

    // traceback to find subset elements
    int i=n, j=S;
    while(j>0 && i>0){
        if(dp[i-1][j]){
            // current element not included
            i--;
        } else {
            // current element included
            printf("%d ", arr[i-1]);
            j -= arr[i-1];
            i--;
        }
    }

    printf("]\n");
    return 0;
}
