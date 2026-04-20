#include <stdio.h>

int max(int a, int b){ return (a>b)? a:b; }

int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d",&n);
    
    int weight[n+1], value[n+1];
    printf("Enter weights: ");
    for(int i=1;i<=n;i++) scanf("%d",&weight[i]);
    
    printf("Enter values: ");
    for(int i=1;i<=n;i++) scanf("%d",&value[i]);
    
    printf("Enter maximum capacity: ");
    scanf("%d",&W);
    
    int K[n+1][W+1];
    
    // Build table K[][] bottom-up
    for(int i=0;i<=n;i++){
        for(int w=0;w<=W;w++){
            if(i==0 || w==0) K[i][w] = 0;
            else if(weight[i] <= w)
                K[i][w] = max(value[i] + K[i-1][w - weight[i]], K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }
    
    printf("Maximum Profit: %d\n", K[n][W]);
    
    // Find items included
    int w = W;
    printf("Items taken: ");
    for(int i=n;i>0 && w>0;i--){
        if(K[i][w] != K[i-1][w]){
            printf("%d ", i);
            w -= weight[i];
        }
    }
    printf("\n");
    return 0;
}
